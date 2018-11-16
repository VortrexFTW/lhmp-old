// (C) LHMP Team 2013-2016; Licensed under Apache 2; See LICENSE;;

#include "CInterpolation.h"
#include "CCore.h"

extern CCore *g_CCore;

CInterpolation::CInterpolation() {
	InterPosition.x = -1985.966675f;
	InterPosition.y = 5.037054f;
	InterPosition.z = 4.284860f;

	InterRotation.x = 0.0f;
	InterRotation.y = 0.0f;

	timestamp = RakNet::TimeMS();
	timeLastMessage = RakNet::TimeMS();
	timeDiff = RakNet::TimeMS();
	interpolationTick = RakNet::TimeMS();

	actualPos = Tools::NullVect();
	previousPos = Tools::NullVect();

	actualRot = Tools::NullVect();
	previousRot = Tools::NullVect();

	entity = nullptr;
}

void CInterpolation::SetUpInterpolation(CEntity *pEntity, Vector3D position)
{
	this->entity = pEntity;
	SetUpInterpolation(position);
}

void CInterpolation::SetUpInterpolation(Vector3D position) {
	/*RakNet::TimeMS difference = (this->timestamp) - (this->timeLastMessage);

	if (difference > 1) {
	this->timeDiff = difference;
	this->timeLastMessage = this->timestamp;
	this->interpolationTick = RakNet::GetTimeMS();

	this->previousPos = this->actualPos;

	// Rounding lessens jittery bouncing
	this->actualPos.x = roundf(position.x * 100) / 100;
	this->actualPos.y = roundf(position.y * 100) / 100;
	this->actualPos.z = roundf(position.z * 100) / 100;
	}*/

	this->timeDiff = (this->timestamp) - (this->timeLastMessage);
	//this->timeDiff = RakNet::GetTimeMS() - this->timeLastMessage;
	if (this->timeDiff <= 0) this->timeDiff = 1;

	this->timeLastMessage = this->timestamp;
	this->interpolationTick = RakNet::GetTimeMS();

	//this->previousPos = this->actualPos;
	this->previousPos = GetEntityPosition();

	// Rounding lessens jittery bouncing
	this->actualPos.x = roundf(position.x * 10000) / 10000;
	this->actualPos.y = roundf(position.y * 10000) / 10000;
	this->actualPos.z = roundf(position.z * 10000) / 10000;
}

void CInterpolation::SetUpInterpolationRot(Vector3D rotation) {
	/*this->timeDiff = (this->timestamp) - (this->timeLastMessage);
	this->timeLastMessage = this->timestamp;
	interpolationTick = RakNet::GetTimeMS();*/

	//this->previousRot = this->actualRot;
	this->previousRot = GetEntityRotation();

	// Rounding lessens jittery bouncing
	this->actualRot.x = roundf(rotation.x * 10000) / 10000;
	this->actualRot.y = roundf(rotation.y * 10000) / 10000;
	this->actualRot.z = roundf(rotation.z * 10000) / 10000;

	this->actualRot = rotation;
}

void CInterpolation::SetUpInterpolationRotVehicle(Vector3D rotation, Vector3D rotation2) {
	/*this->timeDiff = (this->timestamp) - (this->timeLastMessage);
	this->timeLastMessage = this->timestamp;
	this->interpolationTick = RakNet::GetTimeMS();*/

	//this->previousRot = this->actualRot;
	//this->previousRot2 = this->actualRot2;
	this->previousRot = GetVehicleRotation1();
	this->previousRot2 = GetVehicleRotation2();

	// Rounding lessens jittery bouncing
	this->actualRot.x = roundf(rotation.x * 10000) / 10000;
	this->actualRot.y = roundf(rotation.y * 10000) / 10000;
	this->actualRot.z = roundf(rotation.z * 10000) / 10000;

	this->actualRot2.x = roundf(rotation2.x * 10000) / 10000;
	this->actualRot2.y = roundf(rotation2.y * 10000) / 10000;
	this->actualRot2.z = roundf(rotation2.z * 10000) / 10000;

	this->actualRot = rotation;
	this->actualRot2 = rotation2;
}

Vector3D CInterpolation::Interpolate() {
	RakNet::TimeMS actualTime = RakNet::GetTimeMS();
	RakNet::TimeMS tickDiff = (actualTime - this->interpolationTick);

	float t = (float)tickDiff / (float)this->timeDiff;
	float distance = Tools::GetDistanceBetween3DPoints(this->previousPos, this->actualPos);
	float treshold = 7.5;

	// If pos is somehow incorrect, block black screen bug
	if (this->actualPos.x != this->actualPos.x) return (this->InterPosition);

	if (distance < treshold) {
		this->InterPosition.x = Lerp(this->previousPos.x, this->actualPos.x, t);
		this->InterPosition.y = Lerp(this->previousPos.y, this->actualPos.y, t);
		this->InterPosition.z = Lerp(this->previousPos.z, this->actualPos.z, t);
	}
	else {
		this->InterPosition = this->actualPos;
	}

	return (this->InterPosition);
}

Vector3D CInterpolation::InterpolateRot() {
	RakNet::TimeMS actualTime = RakNet::GetTimeMS();
	RakNet::TimeMS tickDiff = (actualTime - this->interpolationTick);

	float t = (float)tickDiff / (float)this->timeDiff;

	this->InterRotation.x = Lerp(this->previousRot.x, this->actualRot.x, t);
	this->InterRotation.y = Lerp(this->previousRot.y, this->actualRot.y, t);
	this->InterRotation.z = Lerp(this->previousRot.z, this->actualRot.z, t);

	return (this->InterRotation);
}

Vector3D CInterpolation::InterpolateRotVehicle() {
	RakNet::TimeMS actualTime = RakNet::GetTimeMS();
	RakNet::TimeMS tickDiff = (actualTime - this->interpolationTick);

	float t = (float)tickDiff / (float)this->timeDiff;

	this->InterRotation.x = Lerp(this->previousRot.x, this->actualRot.x, t);
	this->InterRotation.y = Lerp(this->previousRot.y, this->actualRot.y, t);
	this->InterRotation.z = Lerp(this->previousRot.z, this->actualRot.z, t);

	return (this->InterRotation);
}

Vector3D CInterpolation::InterpolateRotVehicle2() {
	RakNet::TimeMS actualTime = RakNet::GetTimeMS();
	RakNet::TimeMS tickDiff = (actualTime - this->interpolationTick);

	float t = (float)tickDiff / (float)this->timeDiff;

	this->InterRotation2.x = Lerp(this->previousRot2.x, this->actualRot2.x, t);
	this->InterRotation2.y = Lerp(this->previousRot2.y, this->actualRot2.y, t);
	this->InterRotation2.z = Lerp(this->previousRot2.z, this->actualRot2.z, t);

	return (this->InterRotation2);
}

Vector3D CInterpolation::GetPosition() {
	return this->InterPosition;
}

void CInterpolation::SetTimestamp(RakNet::TimeMS time) {
	this->timestamp = time;
}

void CInterpolation::SetPosition(Vector3D pos) {
	this->InterPosition = pos;
}

float CInterpolation::Lerp(float v0, float v1, float t) {
	if (t > 1) t = 1;

	return (1 - t) * v0 + t * v1;
}

void CInterpolation::SetEntity(CEntity *pEntity)
{
	entity = pEntity;
}

CEntity* CInterpolation::GetEntity(void)
{
	return this->entity;
}

Vector3D CInterpolation::GetEntityPosition(void)
{
	if (!entity) return Tools::NullVect();
	DWORD uiEntity = this->entity->GetEntity();
	if (!uiEntity) return Tools::NullVect();
	OBJECT *pEntityObject = (OBJECT*)uiEntity;
	return pEntityObject->position;
}

Vector3D CInterpolation::GetEntityRotation(void)
{
	if (!entity) return Tools::NullVect();
	DWORD uiEntity = this->entity->GetEntity();
	if (!uiEntity) return Tools::NullVect();
	OBJECT *pEntityObject = (OBJECT*)uiEntity;
	return pEntityObject->rotation;
}

Vector3D CInterpolation::GetVehicleRotation1(void)
{
	if (!entity) return Tools::NullVect();
	DWORD uiEntity = this->entity->GetEntity();
	if (!uiEntity) return Tools::NullVect();
	_VEHICLE *pGameVehicle = (_VEHICLE*)uiEntity;
	return pGameVehicle->rotation;
}

Vector3D CInterpolation::GetVehicleRotation2(void)
{
	if (!entity) return Tools::NullVect();
	DWORD uiEntity = this->entity->GetEntity();
	if (!uiEntity) return Tools::NullVect();
	_VEHICLE *pGameVehicle = (_VEHICLE*)uiEntity;
	return pGameVehicle->rotationSecond;
}