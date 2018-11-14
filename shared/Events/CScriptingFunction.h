#pragma once

#include "squirrel.h"
#include "CScriptingArguments.h"

class CScriptingFunction
{
public:
	HSQOBJECT	m_hObject;
	
public:
	CScriptingFunction(HSQUIRRELVM vm, int iIndex);
	
	void	Call(HSQUIRRELVM vm, CScriptingArguments *pScriptArgs);
};