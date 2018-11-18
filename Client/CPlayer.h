#pragma once

#include "CPed.h"

class CPlayer : public CPed
{
public:
	int				ourID;
	char			sName[80];
	unsigned int	nickColor;
	int				ping;

public:
	CPlayer(void);

	void			SetName(char *nm);
	char*			GetName(void);

	void			SetPing(int);
	int				GetPing(void);

	void			SetNickColor(unsigned int);
	unsigned int	GetNickColor(void);

	void			EnterVehicle(CVehicle *pVehicle, int);
	void			EnterVehicleFast(CVehicle *pVehicle, int);
	void			RemoveFromVehicle(void);
	void			RemoveFromVehicleFast(void);
};