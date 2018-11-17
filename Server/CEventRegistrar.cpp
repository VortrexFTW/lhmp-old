#include "CCore.h"
#include "CEventRegistrar.h"
#include "Events/CEventPool.h"

extern CCore* g_CCore;

void	CEventRegistrar::Init(void)
{
	CEventPool *pEventPool = g_CCore->GetEventPool();
	
	pEventPool->AddEvent("OnServerInit");
	
	pEventPool->AddEvent("OnDoorChange");
	
	pEventPool->AddEvent("OnVehicleCreate");
	pEventPool->AddEvent("OnVehicleEngineChange");
	pEventPool->AddEvent("OnVehicleLightsChange");
	pEventPool->AddEvent("OnVehicleDelete");
	pEventPool->AddEvent("OnVehicleDamage");
	pEventPool->AddEvent("OnVehicleShot");
	pEventPool->AddEvent("OnVehicleExplode");
	pEventPool->AddEvent("OnVehicleUpdate");
	pEventPool->AddEvent("OnOccupiedVehicleUpdate");

	pEventPool->AddEvent("OnPlayerConnect");
	pEventPool->AddEvent("OnPlayerDiscOnnect");
	pEventPool->AddEvent("OnPlayerChangeWeapon");
	pEventPool->AddEvent("OnPlayerDropWeapon");
	pEventPool->AddEvent("OnPlayerAddWeapon");
	pEventPool->AddEvent("OnPlayerRespawn");
	pEventPool->AddEvent("OnPlayerHit");
	pEventPool->AddEvent("OnPlayerDeath");
	pEventPool->AddEvent("OnPlayerThrowGrenade");
	pEventPool->AddEvent("OnPlayerShoot");
	pEventPool->AddEvent("OnPlayerUpdate");
	pEventPool->AddEvent("OnPlayerJackedVehicle");
	pEventPool->AddEvent("OnPlayerEnteredVehicle");
	pEventPool->AddEvent("OnPlayerExitingVehicle");
	pEventPool->AddEvent("OnPlayerExitedVehicle");
	pEventPool->AddEvent("OnPlayerKeyPress");
	pEventPool->AddEvent("OnPlayerCommand");
	pEventPool->AddEvent("OnPlayerChat");
	pEventPool->AddEvent("OnPlayerSkinChange");
}