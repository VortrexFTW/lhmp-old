#include "CCore.h"
#include "CEventRegistrar.h"
#include "Events/CEventPool.h"

extern CCore* g_CCore;

void	CEventRegistrar::Init(void)
{
	CEventPool *pEventPool = g_CCore->GetEventPool();
	
	pEventPool->AddEvent("onBlah");
}