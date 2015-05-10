#pragma once

#include "FurnitureTiles.h"
#include "../item/ChairItem.h"

class TileChair : public FurnitureTiles {
public:
	static int _woodId;
	static int _stoneId;

	TileChair(int, Material const*);

	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual int getResource(int, Random*);
	virtual int getResourceCount(Random*);
	virtual bool use(Player*, int, int, int);

	bool isWood();

private:
	TextureUVCoordinateSet secondary_tex;
};
