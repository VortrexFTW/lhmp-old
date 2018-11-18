// (C) LHMP Team 2013-2016; Licensed under Apache 2; See LICENSE;;

#ifndef __PED_H
#define	__PED_H

#include "CEntity.h"
#include "lhmp_structures.h"
#include <d3d8.h>

class CVehicle;

class CPed : public CEntity
{
protected:
	bool		isOnFoot;
	byte		isSpawned;
	byte		isDucking;
	byte		isAiming;
	byte		isCarAnim;
	int			animId;

	float		floatRot;

	// interpolation
	Vector3D	actual, previous;
	// weapons
	int			currentWep;
	SWeapon		weapon[8];

public:
	int			InCar;

public:
	CPed();
	~CPed();

	LPDIRECT3DTEXTURE8		nametag;		// TODO move to private

	void		SetIsOnFoot(bool);
	bool		IsOnFoot();

	void		UpdateGameObject();
	void		SetDucking(byte);
	void		SetAiming(byte);
	void		SetActive(bool);
	void		SetCarAnim(bool);
	bool		IsCarAnim();

	bool		IsActive();
	void		SetSkinId(int id);
	int			GetSkin();
	//int			GetState();
	float		GetHealth();
	void		SetHealth(float health);
	byte		IsDucking();

	void		SetAnim(int);
	int			GetAnim();
	void		SetUpInterpolation();
	void		Interpolate();

	virtual Vector3D GetPosition();
	bool		HasBase();
	Vector3D	GetPEDFramePosition();

	// Weapon actions
	SWeapon* GetWeapon(int);
	int	 GetCurrentWeapon();
	void SetCurrentWeapon(int);
	void AddWeapon(int, int, int);
	void DeleteWeapon(int);
	void SwitchWeapon(int);
	void OnShoot();
	void OnThrowGranade();
	void ClearWeapons();

	void gCheckWeapons();

	// ped vehicle
	CVehicle* GetVehicle(void);
};
#endif
