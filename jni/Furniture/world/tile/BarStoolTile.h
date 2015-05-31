#pragma once

#include "FurnitureTile.h"
#include "../item/BarStoolItem.h"

#include "MCPE/world/level/Level.h"
#include "MCPE/world/level/TileSource.h"
#include "../../util/CollisionHelper.h"

class BarStoolTile : public FurnitureTile {
public:
	static int _id;
	
	BarStoolTile(int, Material const*);

	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual int getResource(int, Random*);
	virtual bool use(Player*, int, int, int);

private:
	TextureUVCoordinateSet secondary_tex;
	TextureUVCoordinateSet terciary_tex;
	TextureUVCoordinateSet quartenary_tex;
};
