#pragma once

#include "squirrel.h"
#include "EScriptingArgumentType.h"

class CScriptingArgument
{
public:
	unsigned long	m_uiType;
	void			*m_pValue;
	
public:
	CScriptingArgument(void);
	CScriptingArgument(EScriptingArgumentType uiType, void *pValue);
	
	void	PushToVM(HSQUIRRELVM vm);
	void	ReadFromVM(HSQUIRRELVM vm, int iStackIndex);
};