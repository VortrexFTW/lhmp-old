#pragma once

#include "EScriptingArgumentType.h"

class CScriptingArgument
{
public:
	unsigned long	m_uiType;
	void			*m_pValue;
	
public:
	CScriptingArgument(EScriptingArgumentType uiType, void *pValue);
	
	void	PushToVM(void);
	void	ReadFromVM(void);
};