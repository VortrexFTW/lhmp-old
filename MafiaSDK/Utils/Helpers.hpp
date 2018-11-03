#ifndef _SHAREDUTILS_DEFINES_H_
#define _SHAREDUTILS_DEFINES_H_

// Macros
#define SAFE_RELEASE(p)               { if(p) { (p)->Release(); (p)=NULL; } }
#define SAFE_DELETE(p)                { if(p) { delete (p); (p)=NULL; } }
#define PADDING(prefix, name, size)	  BYTE prefix##_##name##[size]

#ifdef WIN32
#define PATH_SEPERATOR "\\"
#else
#define PATH_SEPERATOR "/"
#endif

// Constants
#define C_MISSION_CLASS 0x063788C
#define LS3D_Alloc 0x1008D510

struct Vector3D
{
	float x, y, z;

	Vector3D(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f) {
		x = _x;
		y = _y;
		z = _z;
	}

	void SetVals(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f) {
		x = _x;
		y = _y;
		z = _z;
	}

	Vector3D Lerp(const Vector3D & newVal, float timeDiff) const {
		return Vector3D(x + timeDiff * (newVal.x - x), y + timeDiff * (newVal.y - y), z + timeDiff * (newVal.z - z));
	}

	float Distance(const Vector3D & pos2,const float compareDistance)
	{
		float cONc = ((x - pos2.x)*(x - pos2.x)) + ((y - pos2.y)*(y - pos2.y)) + ((z - pos2.z)*(z - pos2.z));
		float compareSEC = compareDistance*compareDistance;
		if (cONc == compareSEC)
			return 0;
		else if (cONc < compareSEC)
			return 1;
		return 2;
	}

	bool IsNull() const {

		return x == 0.0f && y == 0.0f && z == 0.0f;
	}
};
struct Vector4D
{
	float x, y, z, w;
};

class S_GameItem
{
public:
	int		weaponId;
	int		ammoLoaded;
	int		ammoHidden;
	int		_unk;
};

class G_Inventory
{
public:
	S_GameItem items[8];
};


#endif