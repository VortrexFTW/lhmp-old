#include "CEvent.h"

// bound existence
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

// trigger
void	CEvent::Trigger(CScriptingArguments *pScriptArgs)
{
	for (CScriptingFunction *pScriptingFunction : m_vecBoundFunctions)
	{
		pScriptingFunction->Call(pScriptArgs);
	}
}