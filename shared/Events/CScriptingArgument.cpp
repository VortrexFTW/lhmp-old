#include <string>
#include "CScriptingArgument.h"

// constructors
CScriptingArgument::CScriptingArgument(void)
{
}

CScriptingArgument::CScriptingArgument(EScriptingArgumentType uiType, void *pValue) :
	m_uiType(uiType),
	m_pValue(pValue)
{
}

// argument and VM
void	CScriptingArgument::PushToVM(HSQUIRRELVM vm)
{
	switch (m_uiType)
	{
	case SCRIPTING_ARG_BOOLEAN:
		sq_pushbool(vm, (*(bool*)m_pValue) ? SQTrue : SQFalse);
		break;
	case SCRIPTING_ARG_NUMBER:
		sq_pushfloat(vm, (SQFloat)(*(float*)m_pValue));
		break;
	case SCRIPTING_ARG_NULL:
		sq_pushnull(vm);
		break;
	case SCRIPTING_ARG_STRING:
	{
		std::string *pString = (std::string*)m_pValue;
		sq_pushstring(vm, (const SQChar*)pString->c_str(), pString->length());
		break;
	}
	}
}

void	CScriptingArgument::ReadFromVM(HSQUIRRELVM vm, int iStackIndex)
{
	int iType = sq_gettype(vm, iStackIndex);
	switch (iType)
	{
	case OT_BOOL:
		m_uiType = SCRIPTING_ARG_BOOLEAN;
		m_pValue = new SQBool;
		sq_getbool(vm, iStackIndex, (SQBool*)m_pValue);
		break;
	case OT_FLOAT:
		m_uiType = SCRIPTING_ARG_NUMBER;
		m_pValue = new SQFloat;
		sq_getfloat(vm, iStackIndex, (SQFloat*)m_pValue);
		break;
	case OT_NULL:
		m_uiType = SCRIPTING_ARG_NULL;
		m_pValue = nullptr;
		break;
	case OT_STRING:
	{
		m_uiType = SCRIPTING_ARG_STRING;
		m_pValue = new std::string;
		const SQChar *pString2 = nullptr;
		sq_getstring(vm, iStackIndex, &pString2);
		SQInteger iStringLength = sq_getsize(vm, iStackIndex);
		((std::string*)m_pValue)->assign((char*)pString2, iStringLength);
		break;
	}
	}
}