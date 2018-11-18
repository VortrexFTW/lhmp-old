#include "CCore.h"
#include "CPlayerPool.h"

extern CCore *g_CCore;

CPlayerPool::CPlayerPool()
{
	for(int i = 0; i < MAX_PLAYERS;i++)
		playerpool[i] = NULL;
	//playerpool = new CPlayer*[100];
}
CPlayerPool::~CPlayerPool()
{
	delete[] & playerpool;
}
void CPlayerPool::New(int index)
{
	if(playerpool[index] == 0)
	{
		CPlayer* pointer = new CPlayer;
		playerpool[index] = pointer;
		g_CCore->GetEngineStack()->AddMessage(ES_CREATEPLAYER,index);
	} else
	{
		CPed *ped = playerpool[index];
		/*if (ped->GetEntity() == 0)
		{
			g_CCore->GetEngineStack()->AddMessage(ES_CREATEPLAYER,index);
		} else
		{
			g_CCore->GetChat()->AddMessage("Allready done");
		}*/
		g_CCore->GetEngineStack()->AddMessage(ES_CREATEPLAYER, index);
		ped->SetActive(1);
	}
}

CPlayer* CPlayerPool::Return(int slot)
{
	return playerpool[slot];
}

int CPlayerPool::GetPlayerIdByBase(DWORD base)
{
	for (int i = 0; i < MAX_PLAYERS; i++)
	{
		CPlayer* player = this->Return(i);
		if(player == NULL) continue;
		if (player->GetEntity() == base) return i;
	}
	return -1;
}

void CPlayerPool::Delete(int index)
{
	delete playerpool[index];
	playerpool[index] = NULL;
}