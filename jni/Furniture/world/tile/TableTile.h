#pragma once

#include "FurnitureTiles.h"

class TableTile : public FurnitureTiles {
public:
	TableTile(int, Material const*);
static int _woodId;
static int _stoneId;
	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual bool use(Player*, int, int, int);
	TextureUVCoordinateSet secondary_tex;
};
