#pragma once

#include <string>
#include <unordered_map>
#include "CEvent.h"

class CEventPool
{
public:
	void	New(CEvent *pEvent);
	void	Delete(CEvent *pEvent);
	
	CEvent*	GetEventByName(std::string strEventName);
	
private:
	std::unordered_map<std::string, CEvent*>	m_umapEventsByName;
};