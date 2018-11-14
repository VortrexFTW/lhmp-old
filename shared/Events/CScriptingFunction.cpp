#include "CScriptingFunction.h"

// constructors
CScriptingFunction::CScriptingFunction(HSQUIRRELVM vm, int iIndex)
{
	m_vm = vm;
	sq_getstackobj(vm, iIndex, &m_hObject);
	sq_addref(vm, &m_hObject);
}

// call
void	CScriptingFunction::Call(CScriptingArguments *pScriptArgs)
{
	sq_pushobject(m_vm, m_hObject);
	sq_pushroottable(m_vm);
	pScriptArgs->PushToVM(m_vm);
	SQRESULT Result2 = sq_call(m_vm, pScriptArgs->GetCount() + 1, SQFalse, SQTrue);
	sq_poptop(m_vm);
}