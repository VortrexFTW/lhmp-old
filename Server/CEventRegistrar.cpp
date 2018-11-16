#include "CCore.h"
#include "CEventRegistrar.h"
#include "Events/CEventPool.h"

extern CCore* g_CCore;

void	CEventRegistrar::Init(void)
{
	CEventPool *pEventPool = g_CCore->GetEventPool();
	
	pEventPool->AddEvent("onBlah");
	pEventPool->AddEvent("onPlayerEnteredVehicle");
	pEventPool->AddEvent("onPlayerExitingVehicle");
	pEventPool->AddEvent("onPlayerExitedVehicle");
	pEventPool->AddEvent("onVehicleUpdate");
	pEventPool->AddEvent("onPlayerUpdate");
	pEventPool->AddEvent("OnPlayerJackedVehicle");
	pEventPool->AddEvent("OnVehicleEngineChange");
	pEventPool->AddEvent("OnVehicleLightsChange");
	pEventPool->AddEvent("OnVehicleDelete");
	pEventPool->AddEvent("OnVehicleDamage");
	pEventPool->AddEvent("OnVehicleShotDamage");
	pEventPool->AddEvent("OnVehicleExplode");
	pEventPool->AddEvent("OnDoorChange");
	pEventPool->AddEvent("OnPlayerKeyPress");
	pEventPool->AddEvent("OnVehicleCreate");
	pEventPool->AddEvent("OnPlayerHit");
	pEventPool->AddEvent("OnPlayerDeath");
	pEventPool->AddEvent("OnPlayerThrowGrenade");
	pEventPool->AddEvent("OnPlayerShoot");
	pEventPool->AddEvent("OnPlayerChangeWeapon");
	pEventPool->AddEvent("OnPlayerDropWeapon");
	pEventPool->AddEvent("OnPlayerAddWeapon");
	pEventPool->AddEvent("OnPlayerRespawn");
	pEventPool->AddEvent("OnOccupiedVehicleUpdate");
}