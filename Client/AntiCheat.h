// (C) LHMP Team 2013-2016; Licensed under Apache 2; See LICENSE;;

#pragma once

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <psapi.h>
#include <string.h>
#include <iostream>

void ACScanFromPath(WCHAR cPath[MAX_PATH]);
void ACScanModules();
void ACMainThread();
void ACSpeedhack();
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);

HANDLE hProcessSelf;

// Blacklisted checksums
DWORD dwACBlacklist[];