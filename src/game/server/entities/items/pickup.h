/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_SERVER_ENTITIES_PICKUP_H
#define GAME_SERVER_ENTITIES_PICKUP_H

#include <game/server/entity.h>

const int PickupPhysSize = 14;

class CPickup : public CEntity
{
public:
	CPickup(CGameWorld *pGameWorld, int Type, vec2 Pos, int SubType);

	virtual void Reset();
	virtual void Tick();
	virtual void TickPaused();
	virtual void Snap(int SnappingClient);
	virtual void StartFarm(int ClientID);
	virtual void Picking(int Time);
	virtual void MaterFarm(int ClientID, int MaterialID);
	int m_SpawnTick;

private:
	int m_Type;
	int m_SubType;
	int m_Drop;

	vec2 m_MoveDirection;
};

#endif
