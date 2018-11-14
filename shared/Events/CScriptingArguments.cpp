#include "CScriptingArguments.h"

// count
unsigned int	CScriptingArguments::GetCount(void)
{
	return m_vecArguments.size();
}

// arguments and VM
void	CScriptingArguments::PushToVM(HSQUIRRELVM vm)
{
	for(CScriptingArgument *pArgument : m_vecArguments)
		pArgument->PushToVM(vm);
}

void	CScriptingArguments::ReadFromVM(HSQUIRRELVM vm)
{
	SQInteger iArgumentCount = sq_gettop(vm) - 3;
	for (int i = 0; i < iArgumentCount; i++)
	{
		CScriptingArgument *pScriptingArgument = new CScriptingArgument;
		pScriptingArgument->ReadFromVM(vm, 2 + i);
		m_vecArguments.push_back(pScriptingArgument);
	}
}

// add argument
void	CScriptingArguments::AddBoolean(bool bValue)
{
	m_vecArguments.push_back(new CScriptingArgument(SCRIPTING_ARG_BOOLEAN, new bool(bValue)));
}

void	CScriptingArguments::AddNumber(float fNumber)
{
	m_vecArguments.push_back(new CScriptingArgument(SCRIPTING_ARG_NUMBER, new float(fNumber)));
}

void	CScriptingArguments::AddNull(void)
{
	m_vecArguments.push_back(new CScriptingArgument(SCRIPTING_ARG_NULL, nullptr));
}

void	CScriptingArguments::AddString(std::string strString)
{
	m_vecArguments.push_back(new CScriptingArgument(SCRIPTING_ARG_STRING, new std::string(strString)));
}