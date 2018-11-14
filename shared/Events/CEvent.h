#pragma once

#include <string>
#include <vector>
#include "squirrel.h"
#include "CScriptingFunction.h"
#include "CScriptingArguments.h"

class CEvent
{
public:
	std::string							m_strName;
	std::vector<CScriptingFunction*>	m_vecBoundFunctions;
	
public:
	void	BindFunction(CScriptingFunction *pScriptingFunction);
	void	UnbindFunction(CScriptingFunction *pScriptingFunction);

	void	Trigger(HSQUIRRELVM vm, CScriptingArguments *pScriptArgs);
};