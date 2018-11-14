#include "CScriptingFunction.h"

CScriptingFunction::CScriptingFunction(HSQUIRRELVM vm, int iIndex)
{
	sq_getstackobj(vm, iIndex, &m_hObject);
	sq_addref(vm, &m_hObject);
}

void	CScriptingFunction::Call(HSQUIRRELVM vm, CScriptingArguments *pScriptArgs)
{
	pScriptArgs->PushToVM(vm);
	SQRESULT Result2 = sq_call(vm, pScriptArgs->GetCount(), SQFalse, SQTrue);
}