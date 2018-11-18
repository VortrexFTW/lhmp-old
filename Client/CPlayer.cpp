#include "CCore.h"
#include "CPlayer.h"

extern CCore* g_CCore;

CPlayer::CPlayer(void) :
	CPed(),
	ping(-1)
{
	sprintf(sName, "Player");
}

// name
void CPlayer::SetName(char *nm)
{
	sprintf(this->sName, "%s", nm);
}

char* CPlayer::GetName(void)
{
	return this->sName;
}

// ping
void CPlayer::SetPing(int p)
{
	ping = p;
}

int CPlayer::GetPing(void)
{
	return ping;
}

// nick colour
void		CPlayer::SetNickColor(unsigned int color)
{
	this->nickColor = color;
	if (this->nametag != NULL)
	{
		this->nametag->Release();
		this->nametag = NULL;
	}
}
unsigned int CPlayer::GetNickColor(void)
{
	return this->nickColor;
}

// player vehicle
void CPlayer::EnterVehicle(CVehicle *pVehicle, int seatId)
{
	//if (!isSpawned)
	//	return;

	DWORD car = pVehicle->GetEntity();
	if (!car)
		return;

	DWORD ped = GetEntity();
	DWORD vehId = InCar;

	char buff[255];
	sprintf(buff, "%x %d %d", ped, vehId, seatId);
	g_CCore->GetLog()->AddLog(buff);

	/*	if (car == NULL)
	g_CCore->GetLog()->AddLog("GivePTC - car doesnt exist");
	return;*/
	_asm
	{
		MOV ESI, car
		//MOV EBP, obj
		MOV EAX, seatId
		PUSH 0; / Arg4 = 00000000
		PUSH EAX; | Arg3
		PUSH 1; | Arg2 = 00000001
		PUSH ESI; | Arg1 = 0E830248	// auto
		//MOV ECX, EBP; |	// ped
		MOV ECX, ped
		MOV EAX, 0x004A26D0
		CALL EAX;  Game.004A26D0; \Game.004A26D0
	}
}

void CPlayer::EnterVehicleFast(CVehicle *pVehicle, int seatId)
{
	//if (!isSpawned)
	//	return;

	DWORD car = pVehicle->GetEntity();
	if (!car)
		return;

	DWORD ped = GetEntity();
	DWORD vehId = InCar;

	char buff[255];
	sprintf(buff, "GivePlayerToCarFast %x %d %d", ped, vehId, seatId);
	g_CCore->GetLog()->AddLog(buff);
	if (ped == NULL)
		return;
	CVehicle* carObject = g_CCore->GetVehiclePool()->Return(vehId);
	if (carObject != NULL)
	{
		DWORD car = carObject->GetEntity();
		if (car != NULL && seatId != -1)
		{
			_asm
			{
				MOV EAX, seatId
				PUSH EAX; / Arg2 = 00000000
				MOV EAX, car
				PUSH EAX; | Arg1
				MOV ESI, ped
				MOV ECX, ESI; |
				MOV EAX, 0x0049E580
				CALL EAX;  Game.0049E580; \Game.0049E580
			}
		}
	}
}

void CPlayer::RemoveFromVehicle(void)
{
	//if (!isSpawned)
	//	return;

	CVehicle *pVehicle = GetVehicle();
	if (!pVehicle)
		return;
	DWORD car = pVehicle->GetEntity();
	if (!car)
		return;

	DWORD ped = GetEntity();
	DWORD vehId = InCar;

	char buff[255];
	sprintf(buff, "%x %d", ped, vehId);
	g_CCore->GetLog()->AddLog(buff);

	//if (car == NULL)
	//	g_CCore->GetLog()->AddLog("KickPFC - car doesnt exist");
	//return;

	InCar = -1;
	SetIsOnFoot(true);

	_asm
	{
		mov edi, ped
		mov ecx, car
		mov EBX, 0x0
		PUSH EBX; / Arg4 = 00000000
		PUSH EBX; | Arg3
		PUSH 2; | Arg2 = 00000002
		PUSH ECX; | Arg1	auto
		MOV ECX, EDI; |
		MOV EAX, 0x004A26D0
		CALL EAX;  Game.004A26D0; \Game.004A26D0
	}
}

void CPlayer::RemoveFromVehicleFast(void)
{
	//if (!isSpawned)
	//	return;

	CVehicle *pVehicle = GetVehicle();
	if (!pVehicle)
		return;
	DWORD car2 = pVehicle->GetEntity();
	if (!car2)
		return;

	DWORD ped = GetEntity();

	char buff[255];
	sprintf(buff, "%x", ped);
	
	InCar = -1;
	SetIsOnFoot(true);

	DWORD car = NULL;
	_asm {
		mov ECX, ped
		mov eax, DWORD PTR DS : [ECX + 0x98]
		mov car, eax
	}
	if (car != NULL)
	{
		_asm
		{
			MOV ECX, ped
			MOV EAX, 0x004A1770
			CALL EAX
		}
	}
	else
	{
		g_CCore->GetLog()->AddLog("[Err] Player is not in car");
	}
}