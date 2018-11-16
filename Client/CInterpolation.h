// (C) LHMP Team 2013-2016; Licensed under Apache 2; See LICENSE;;

#ifndef __C_INTERPOLATION
#define __C_INTERPOLATION
#include <lhmp_structures.h>

class CEntity;

class CInterpolation {
	Vector3D		InterPosition, InterRotation, InterRotation2;

	RakNet::TimeMS	timestamp;
	RakNet::TimeMS	timeLastMessage;
	RakNet::TimeMS	timeDiff;
	RakNet::TimeMS	interpolationTick;

	Vector3D		actualPos, actualRot, actualRot2, previousPos, previousRot, previousRot2;
	CEntity*		entity;

public:
	CInterpolation();
	void		SetTimestamp(RakNet::TimeMS);

	void		SetUpInterpolation(CEntity *pEntity, Vector3D position);
	void		SetUpInterpolation(Vector3D position);
	void		SetUpInterpolationRot(Vector3D rotation);
	void		SetUpInterpolationRotVehicle(Vector3D rotation, Vector3D rotation2);

	Vector3D	Interpolate();
	Vector3D	InterpolateRot();
	Vector3D	InterpolateRotVehicle();
	Vector3D	InterpolateRotVehicle2();
	Vector3D	GetTempVect();
	Vector3D	GetInterVect();
	Vector3D	GetPosition();

	void		SetPosition(Vector3D pos);
	float		Lerp(float v0, float v1, float t);

	void		SetEntity(CEntity *pEntity);
	CEntity*	GetEntity(void);

	Vector3D	GetEntityPosition(void);
	Vector3D	GetEntityRotation(void);
	Vector3D	GetVehicleRotation1(void);
	Vector3D	GetVehicleRotation2(void);
};

#endif