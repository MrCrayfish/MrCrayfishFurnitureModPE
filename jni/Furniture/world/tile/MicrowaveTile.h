#pragma once

#include "RotatableTile.h"
#include "../item/MicrowaveItem.h"

#include "MCPE/world/level/Level.h"
#include "MCPE/world/level/TileSource.h"
#include "../../util/CollisionHelper.h"

class MicrowaveTile : public RotatableTile {
public:
	static int _id;
	
	MicrowaveTile(int, Material const*);

	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual int getResource(int, Random*);
	virtual bool use(Player*, int, int, int);

private:
	TextureUVCoordinateSet secondary_tex;
	TextureUVCoordinateSet terciary_tex;
};
