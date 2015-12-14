#pragma once

#include "RotatableBlock.h"
#include "../item/TvItem.h"

class TvBlock : public RotatableBlock {
public:
	static int _id;
	
	TvBlock(int, Material const&);

	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual int getResource(Random&, int, int);
     virtual bool addCollisionShapes(BlockSource&, const BlockPos&, const AABB*, std::vector<AABB, std::allocator<AABB>>&, Entity*);
	
private:
	TextureUVCoordinateSet secondary_tex;

	TextureUVCoordinateSet terciary_tex;
};
