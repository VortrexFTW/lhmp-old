#include "CCore.h"
extern CCore* g_CCore;

void increaseLimits(void) {
	unsigned long uiNewVehicleLimit = 10000;
	char *pNewEntries = new char[2098 * uiNewVehicleLimit];
	updateAddresses(pNewEntries, uiMafiaGameVehiclePoolAddresses);
}

template <size_t uiInnerDimensionSize>
void updateAddresses(void *pNewDataStart, unsigned long pAddresses[][uiInnerDimensionSize], unsigned long uiMaxAddrMatch = 0xFFFFFF)
{
	unsigned long uiNewAddr = (unsigned long)pNewDataStart;
	for (unsigned long i = 0; i < sizeof(pAddresses) / uiInnerDimensionSize; i++)
	{
		unsigned long i2 = 0;
		unsigned long uiAddrMatch;
		unsigned long uiNewAddr2 = uiNewAddr + i;
		while ((uiAddrMatch = pAddresses[i][i2]) != 0)
		{
			if (uiAddrMatch <= uiMaxAddrMatch)
			{
				unsigned long lpflOldProtect, lpflOldProtect2;
				VirtualProtect((LPVOID)uiAddrMatch, 4, PAGE_EXECUTE_READWRITE, &lpflOldProtect);
				*(unsigned long*)uiAddrMatch = uiNewAddr2;
				VirtualProtect((LPVOID)uiAddrMatch, 4, lpflOldProtect, &lpflOldProtect2);
			}

			i2++;
		}
	}
}
