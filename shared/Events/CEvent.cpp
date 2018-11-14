#include "CEvent.h"

void	CEvent::BindFunction(CScriptingFunction *pScriptingFunction)
{
	m_vecBoundFunctions.push_back(pScriptingFunction);
}

void	CEvent::UnbindFunction(CScriptingFunction *pScriptingFunction)
{
	auto it = std::find(m_vecBoundFunctions.begin(), m_vecBoundFunctions.end(), pScriptingFunction);
	if(it != m_vecBoundFunctions.end())
	{
		m_vecBoundFunctions.erase(it);
	}
}

void	CEvent::Trigger(HSQUIRRELVM vm, CScriptingArguments *pScriptArgs)
{
	for(CScriptingFunction *pScriptingFunction : m_vecBoundFunctions)
	{
		pScriptingFunction->Call(vm, pScriptArgs);
	}
}