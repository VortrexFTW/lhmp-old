// (C) LHMP Team 2013-2016; Licensed under Apache 2; See LICENSE;;

#ifndef _CSQUIRREL_H
#define _CSQUIRREL_H

#include <stdarg.h>
#include <stdio.h>
#include <squirrel.h>
#include <sqstdio.h>
#include <sqstdaux.h>
#include <iostream>
#include <vector>

#include <sqstdstring.h>
#include <sqstdmath.h>
#include <sqstdsystem.h>

/*#ifdef SQUNICODE
#define scvprintf vwprintf
#else
#define scvprintf vprintf
#endif
void printfunc(HSQUIRRELVM v, const SQChar *s, ...);


#include "sq_functions.h"
*/

// defined below
class CScript;
class CSquirrel
{
public:
	HSQUIRRELVM p_VM;
	// Constructor
	CSquirrel();
	// Startup a new client script
	// IF SUCCESS, new script is added into script pool
	void LoadClientScript(wchar_t* scriptname);

	// Delete all scripts
	void DeleteScripts();

	void BlockInput(bool);
	bool isInputBlocked();

	void HideChat(bool);
	bool isChatHidden();
	

	/* --------------- Callbacks ------------*/
	// called when game renders
	void onRender();
	void onKeyDown(unsigned int key);
	void onSpawn();
	void callClientFunc(wchar_t* scriptname, wchar_t* scriptfunc, BitStream* message);
private:
	// Register all native functions and constants
	void PrepareMachine(SQVM* pVM);
	// functions used to register constants and functions, used in InitVM
	//void RegisterFunction(HSQUIRRELVM pVM, char * szFunc, SQFUNCTION func, int params, const char * szTemplate);
	void RegisterVariable(HSQUIRRELVM pVM, const wchar_t * szVarName, bool bValue);
	void RegisterVariable(HSQUIRRELVM pVM, const wchar_t * szVarName, int iValue);
	void RegisterVariable(HSQUIRRELVM pVM, const wchar_t * szVarName, float fValue);
	void RegisterVariable(HSQUIRRELVM pVM, const wchar_t * szVarName, const wchar_t * szValue);

	// client-side scripts pool
	//std::vector <CScript> p_scriptPool;
	CScript* p_scriptPool[100];

	bool blockInput;
	bool hideChat;

};

class CScript
{
public:
	// Create new instance with @scriptname name and @pvm virtual machine instance
	CScript(HSQUIRRELVM INpvm,wchar_t* INname)
	{
		this->p_VM = INpvm;
		wcscpy(this->name, INname);
	}
	~CScript()
	{
		if (this->p_VM)
			sq_close(this->p_VM);
	}
	HSQUIRRELVM GetVirtualMachine()
	{
		return this->p_VM;
	}
	wchar_t* GetName()
	{
		return this->name;
	}
private:
	HSQUIRRELVM p_VM;
	wchar_t name[500];
};

#endif