#pragma once

#include <string>
#include <vector>
#include "squirrel.h"
#include "CScriptingArgument.h"

class CScriptingArguments
{
public:
	std::vector<CScriptingArgument*>		m_vecArguments;

public:
	unsigned int	GetCount(void);

	void	PushToVM(HSQUIRRELVM vm);
	void	ReadFromVM(HSQUIRRELVM vm);
	
	void	AddBoolean(bool bValue);
	void	AddNumber(float fNumber);
	void	AddNull(void);
	void	AddString(std::string strString);
};