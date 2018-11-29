// (C) LHMP Team 2013-2016; Licensed under Apache 2; See LICENSE;;

#include "CConsole.h"
#include "CCore.h"

#include <lhmp_tools.h>
#ifndef _WIN32
	#include <pthread.h>
	extern pthread_t tid;
#endif // _WIN32
extern CCore *g_CCore;

#ifdef _WIN32
void ConsoleThread() {
#else
void* ConsoleThread(void *arg){
#endif // _WIN32
	while (1)
	{
		g_CCore->GetConsole()->Tick();
		RakSleep(50);
	}
}

void CConsole::Init()
{
	// init selfstanding thread for console input
	#ifdef _WIN32
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&ConsoleThread, 0, NULL, NULL);
	#else
		pthread_create(&tid, NULL, &ConsoleThread, NULL);
	#endif
}

void CConsole::Tick()
{
	// load input from console
	char buff[256];
	std::cin.getline(buff, 255);
	std::cin.clear();

	// split input into command - variables
	char command[256];
	memset(command, 0x0, 256);
	char varlist[512] = "";
	memset(varlist, 0x0, 512);
	char *pch;
	pch = strchr(buff, ' ');
	if (pch == NULL)
	{
		memcpy(command, buff, strlen(buff));
	}
	else {
		memcpy(command, buff, (pch - buff));
		command[(pch - buff)] = '\0';
		memcpy(varlist, pch + 1, strlen(pch));
	}

	this->ProcessConsoleCommand(command, varlist);
}

void CConsole::ProcessConsoleCommand(const char* command, const char* varlist) {
	if (strcmp(command, "exit") == 0 || strcmp(command, "quit") == 0)
	{
		g_CCore->GetLog()->AddNormalLog("Exit");
		g_CCore->GetNetworkManager()->GetPeer()->Shutdown(100, 0, IMMEDIATE_PRIORITY);
#ifdef _WIN32
		TerminateProcess(GetCurrentProcess(), 0);
#else
		exit(0);
#endif
	}
	else if (strcmp(command, "help") == 0)
	{
		g_CCore->GetLog()->AddNormalLog("List of commands:");
		g_CCore->GetLog()->AddNormalLog("-> help:\t show this help again");
		g_CCore->GetLog()->AddNormalLog("-> kick:\t kick player");
		g_CCore->GetLog()->AddNormalLog("-> kickall:\t kick all players");
		g_CCore->GetLog()->AddNormalLog("-> msg:\t\t send a message to all players");
		g_CCore->GetLog()->AddNormalLog("-> load:\t load a new gamemode");
		g_CCore->GetLog()->AddNormalLog("-> reload:\t reload current gamemode");
		g_CCore->GetLog()->AddNormalLog("-> exit:\t shutdown server");
		g_CCore->GetLog()->AddNormalLog("-> quit:\t shutdown server");
	}
	else if (strcmp(command, "kick") == 0)
	{
		if (strlen(varlist) == 0 || Tools::isStringNumeric((char*)varlist) == false)
		{
			g_CCore->GetLog()->AddNormalLog("Usage: kick <ID>");
		}
		else
		{
			// kick player from server
			CPlayer* player = g_CCore->GetPlayerPool()->Return(atoi(varlist));
			if (player != NULL) {
				SystemAddress sa = g_CCore->GetNetworkManager()->GetSystemAddressFromID(atoi(varlist));
				g_CCore->GetNetworkManager()->GetPeer()->CloseConnection(sa, true);
			}
			else
			{
				g_CCore->GetLog()->AddNormalLog("Could not kick player. Given ID not found !");
			}
		}
	}
	else if (strcmp(command, "kickall") == 0)
	{
		// kick all players from server
		if (strlen(varlist) == 0 || Tools::isStringNumeric((char*)varlist) == false)
		{
			int pocet = 0;
			for (int i = 0; i < MAX_PLAYERS; i++)
			{
				CPlayer* player = g_CCore->GetPlayerPool()->Return(i);
				if (player != NULL) {
					SystemAddress sa = g_CCore->GetNetworkManager()->GetSystemAddressFromID(i);
					g_CCore->GetNetworkManager()->GetPeer()->CloseConnection(sa, true);
					pocet++;
				}
			}
			g_CCore->GetLog()->AddNormalLog("Kicked player count: %d", pocet);
		}
	}
	else if (strcmp(command, "msg") == 0)
	{
		// send admin message to all players
		if (strlen(varlist) == 0)
		{
			g_CCore->GetLog()->AddNormalLog("Usage: msg <some message to all players>");
		}
		else
		{
			char message[250];
			sprintf(message, "#ff0000[Server]:#fffFFF %s", varlist);
			g_CCore->GetNetworkManager()->SendMessageToAll(message);
			g_CCore->GetLog()->AddNormalLog("[Server]: %s", varlist);
		}
	}
	else if (strcmp(command, "reload") == 0)
	{
		g_CCore->ReloadGamemode();
	}
	else if (strcmp(command, "load") == 0)
	{
		//g_CCore->GetLog()->AddNormalLog("Varlist[%d]: '%s'",strlen(varlist),varlist);
		if (strlen(varlist) == 0)
		{
			g_CCore->GetLog()->AddNormalLog("Usage: load <gamemode>");
		}
		else
		{
			g_CCore->ChangeModeTo((char*)varlist);
		}
	}
	else if (strcmp(command, "pc") == 0)
	{
		// get real player count
		int pocet = 0;
		for (int i = 0; i < MAX_PLAYERS; i++)
		{
			CPlayer* player = g_CCore->GetPlayerPool()->Return(i);
			if (player != NULL)
				pocet++;
		}
		g_CCore->GetLog()->AddNormalLog("Player count: %d", pocet);
	}
	else
	{
		CScriptingArguments EventArgs;
		EventArgs.AddString(command);
		EventArgs.AddString(varlist);
		g_CCore->GetEventPool()->Trigger("OnConsoleCommand", EventArgs);
		//g_CCore->GetScripts()->onConsoleCommand(command, varlist);
	}
}
