#pragma once

#include "squirrel.h"
#include "CScriptingArguments.h"

class CScriptingFunction
{
public:
	HSQUIRRELVM	m_vm;
	HSQOBJECT	m_hObject;
	
public:
	CScriptingFunction(HSQUIRRELVM vm, int iIndex);
	
	void	Call(CScriptingArguments *pScriptArgs);
};