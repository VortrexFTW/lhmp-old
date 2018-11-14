#include "CScriptingArgument.h"

CScriptingArgument::CScriptingArgument(EScriptingArgumentType uiType, void *pValue) :
	m_uiType(uiType),
	m_pValue(pValue)
{
}

void	CScriptingArgument::PushToVM(void)
{
}

void	CScriptingArgument::ReadFromVM(void)
{
}