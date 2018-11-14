#pragma once

#include <string>
#include <unordered_map>
#include "squirrel.h"
#include "CEvent.h"
#include "CScriptingArguments.h"

class CEventPool
{
public:
	CEventPool(void);

	void	AddEvent(std::string strEventName);
	void	RemoveEvent(CEvent *pEvent);

	CEvent*	GetEventByName(std::string strEventName);
	
	void	Trigger(std::string strEventName);
	void	Trigger(std::string strEventName, CScriptingArguments& args);

private:
	std::unordered_map<std::string, CEvent*>	m_umapEventsByName;
};