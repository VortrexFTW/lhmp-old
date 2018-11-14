#include "CEventPool.h"

using namespace std;

void	CEventPool::New(CEvent *pEvent)
{
	m_umapEventsByName[pEvent->m_strName] = pEvent;
}

void	CEventPool::Delete(CEvent *pEvent)
{
	m_umapEventsByName.erase(pEvent->m_strName);
}

CEvent*	CEventPool::GetEventByName(string strEventName)
{
	if(m_umapEventsByName.find(strEventName) != m_umapEventsByName.end())
		return m_umapEventsByName[strEventName];
	return nullptr;
}