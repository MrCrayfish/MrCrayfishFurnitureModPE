#pragma once

#include "RotatableTile.h"
#include "../item/BedsideCabinetItem.h"

class BedsideCabinetTile : public RotatableTile {
public:
	static int _id;
	
	BedsideCabinetTile(int, Material const*);

	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual int getResource(int, Random*);
	virtual void addAABBs(TileSource* region, int x, int y, int z, AABB const* posAABB, std::vector<AABB, std::allocator<AABB>>& pool);
	virtual bool use(Player*, int, int, int);
	
private:
	TextureUVCoordinateSet secondary_tex;
	TextureUVCoordinateSet terciary_tex;
};
