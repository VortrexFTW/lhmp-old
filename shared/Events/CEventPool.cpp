#include "CEventPool.h"

using namespace std;

// constructors
CEventPool::CEventPool(void)
{
}

// existence
void	CEventPool::AddEvent(std::string strEventName)
{
	CEvent *pEvent = new CEvent;
	pEvent->m_strName = strEventName;
	m_umapEventsByName[strEventName] = pEvent;
}

void	CEventPool::RemoveEvent(CEvent *pEvent)
{
	m_umapEventsByName.erase(pEvent->m_strName);
	delete pEvent;
}

// fetch
CEvent*	CEventPool::GetEventByName(string strEventName)
{
	if(m_umapEventsByName.find(strEventName) != m_umapEventsByName.end())
		return m_umapEventsByName[strEventName];
	return nullptr;
}

// trigger
void	CEventPool::Trigger(string strEventName)
{
	CScriptingArguments scriptingArguments;
	Trigger(strEventName, scriptingArguments);
}

void	CEventPool::Trigger(string strEventName, CScriptingArguments& scriptingArguments)
{
	CEvent *pEvent = GetEventByName(strEventName);
	if (!pEvent)
		return;
	pEvent->Trigger(scriptingArguments);
}