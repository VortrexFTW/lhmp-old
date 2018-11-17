// (C) LHMP Team 2013-2016; Licensed under Apache 2; See LICENSE;;

#include "inject.h"
#define _WIN32_WINNT _WIN32_WINNT_WINXP
HMODULE InjectDLL(DWORD ProcessID, char* dllName)
{
	HANDLE Proc;
	HANDLE Thread;
	char buf[50] = { 0 };
	LPVOID RemoteString, LoadLibAddy;
	HMODULE hModule = NULL;
	DWORD dwOut;

	if (!ProcessID)
	{
		MessageBoxA(NULL, "Injection failed - no process id", "Error", MB_OK | MB_ICONERROR);
		return false;
	}
	Proc = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, 0, ProcessID);
	//Proc = OpenProcess(PROCESS_ALL_ACCESS, 0, ProcessID);

	if (!Proc)
	{
		sprintf_s(buf, "OpenProcess() failed: %d", GetLastError());
		MessageBoxA(NULL, buf, "Loader", NULL);
		return false;
	}

	LoadLibAddy = (LPVOID)GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryW");
	if (!LoadLibAddy) {
		sprintf_s(buf, "LoadLibraryW GetModule failed");
		MessageBoxA(NULL, buf, "Loader", NULL);
		return false;
	}


	RemoteString = (LPVOID)VirtualAllocEx(Proc, NULL, strlen(dllName), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (!RemoteString) {
		sprintf_s(buf, "VirtualAllocEx failed");
		MessageBoxA(NULL, buf, "Loader", NULL);
		return false;
	}

	if (!WriteProcessMemory(Proc, (LPVOID)RemoteString, dllName, strlen(dllName), NULL)) {
		sprintf_s(buf, "WriteProcessMemory failed");
		MessageBoxA(NULL, buf, "Loader", NULL);
		return false;
	}

	Thread = CreateRemoteThread(Proc, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibAddy, (LPVOID)RemoteString, NULL, NULL);
	if (!Thread) {
		sprintf_s(buf, "CreateRemoteThread failed: %d", GetLastError());
		MessageBoxA(NULL, buf, "Loader", NULL);
		return false;
	}
	else {
		while (WaitForSingleObject(Thread, 0) != WAIT_OBJECT_0)
		{
			Sleep(10);
		}

		bool b = false;
		while (b = GetExitCodeThread(Thread, &dwOut)) {
			if (dwOut != STILL_ACTIVE) {
				hModule = (HMODULE)dwOut;
				break;
			}
		}
		if (!b)
		{
			sprintf_s(buf, "GetExitCodeThread failed: %d", GetLastError());
			MessageBoxA(NULL, buf, "Loader", NULL);
		}
	}

	CloseHandle(Thread);
	CloseHandle(Proc);

	if (!hModule)
	{
		MessageBoxA(NULL, "Injection failed - no module", "Error", MB_OK | MB_ICONERROR);
	}

	return hModule;
}