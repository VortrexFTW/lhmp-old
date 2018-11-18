#pragma once

#include "CPlayer.h"

class CPlayerPool
{
private:
	CPlayer*	playerpool[100];
public:
	CPlayerPool();
	~CPlayerPool();
	void		New(int);
	CPlayer*	Return(int);
	int			GetPlayerIdByBase(DWORD);
	void		Delete(int);
};