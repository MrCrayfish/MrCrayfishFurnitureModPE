#pragma once

#include "RotatableTile.h"
#include "../item/OvenItem.h"

class OvenTile : public RotatableTile {
public:
	static int _id;

	OvenTile(int, Material const*);

	virtual int getResource(int, Random*);
	virtual bool use(Player*, int, int, int);
	virtual void addAABBs(TileSource*, int, int, int, AABB const*, std::vector<AABB, std::allocator<AABB>>&);
};
