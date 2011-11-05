#pragma once

#include "MemoryLeak.h"

//tolua_begin
// emissive blocks
extern char g_BlockLightValue[];
// whether blocks allow spreading
extern char g_BlockSpreadLightFalloff[];
// whether blocks are transparent (light can shine though)
extern bool g_BlockTransparent[];
// one hit break blocks
extern bool g_BlockOneHitDig[];
//tolua_end

//--DO NOT DELETE THIS COMMENT-- //tolua_export

inline bool IsValidBlock( int a_BlockID )	//tolua_export
{											//tolua_export
	if( a_BlockID > -1 &&
		a_BlockID <= 121 && //items to 109 are valid for 1.8.1.. 1.9.5 is up to 121
		//a_BlockID != 29 && allow pistons
		//a_BlockID != 33 && allow pistons
		a_BlockID != 34 &&
		a_BlockID != 36 )
	{
		return true;
	}
	return false;
}											//tolua_export

inline bool isValidItem( int a_ItemID )		//tolua_export
{											//tolua_export
	if( (a_ItemID >= 256 && a_ItemID <= 358)
		|| (a_ItemID == 2256 || a_ItemID == 2257) )
	{
		return true;
	}

	if( a_ItemID == 0 )
		return false;

	return IsValidBlock( a_ItemID );
}											//tolua_export

inline void AddDirection( int & a_X, char & a_Y, int & a_Z, char a_Direction, bool a_bInverse = false ) //tolua_export
{//tolua_export
	if( !a_bInverse )
	{
		switch( a_Direction )
		{
		case 0:
			a_Y--;
			break;
		case 1:
			a_Y++;
			break;
		case 2:
			a_Z--;
			break;
		case 3:
			a_Z++;
			break;
		case 4:
			a_X--;
			break;
		case 5:
			a_X++;
			break;
		};
	}
	else
	{
		switch( a_Direction )	// other way around
		{
		case 0:
			a_Y++;
			break;
		case 1:
			a_Y--;
			break;
		case 2:
			a_Z++;
			break;
		case 3:
			a_Z--;
			break;
		case 4:
			a_X++;
			break;
		case 5:
			a_X--;
			break;
		};
	}
}//tolua_export

#include <math.h>
#define PI				3.14159265358979323846264338327950288419716939937510582097494459072381640628620899862803482534211706798f
#define MIN(a,b) (((a)>(b))?(b):(a))
#define MAX(a,b) (((a)>(b))?(a):(b))
inline void EulerToVector( float a_Pan, float a_Pitch, float & a_X, float & a_Y, float & a_Z )
{
// 	a_X = sinf ( a_Pan / 180 * PI ) * cosf ( a_Pitch / 180 * PI );
// 	a_Y = -sinf ( a_Pitch / 180 * PI );
// 	a_Z = -cosf ( a_Pan / 180 * PI ) * cosf ( a_Pitch / 180 * PI );
a_X = cos(a_Pan / 180 * PI)*cos(a_Pitch / 180 * PI);
a_Y = sin(a_Pan / 180 * PI)*cos(a_Pitch / 180 * PI);
a_Z = sin(a_Pitch / 180 * PI);
}

inline void VectorToEuler( float a_X, float a_Y, float a_Z, float & a_Pan, float & a_Pitch )
{
	if( a_X != 0 )
		a_Pan = atan2( a_Z, a_X ) * 180 / PI - 90;
	else
		a_Pan = 0;
	a_Pitch = atan2(a_Y, sqrtf((a_X * a_X) + (a_Z * a_Z))) * 180 / PI;
}

inline float GetSignf( float a_Val )
{
	return (a_Val < 0.f)?-1.f:1.f;
}

inline float GetSpecialSignf( float a_Val )
{
	return (a_Val <= 0.f)?-1.f:1.f;
}
