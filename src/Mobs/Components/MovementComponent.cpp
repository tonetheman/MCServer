#include "Globals.h"
#include "MovementComponent.h"
#include "../Monster.h"

#include "../../World.h"

cMovementComponent::cMovementComponent(cMonster * a_Entity) : m_Self(a_Entity){}


int cMovementComponent::FindFirstNonAirBlockPosition(double a_PosX, double a_PosZ)
{
	int PosY = (int)floor(m_Self->GetPosY());
	PosY = Clamp(PosY, 0, cChunkDef::Height);

	if (!cBlockInfo::IsSolid(m_Self->GetWorld()->GetBlock((int)floor(a_PosX), PosY, (int)floor(a_PosZ))))
	{
		while (!cBlockInfo::IsSolid(m_Self->GetWorld()->GetBlock((int)floor(a_PosX), PosY, (int)floor(a_PosZ))) && (PosY > 0))
		{
			PosY--;
		}

		return PosY + 1;
	}
	else
	{
		while (cBlockInfo::IsSolid(m_Self->GetWorld()->GetBlock((int)floor(a_PosX), PosY, (int)floor(a_PosZ))) && (PosY < cChunkDef::Height))
		{
			PosY++;
		}

		return PosY;
	}
}