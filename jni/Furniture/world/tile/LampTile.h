#pragma once

#include "FurnitureTile.h"
#include "../item/LampItem.h"

class LampTile: public FurnitureTile {
public:
	static int _id;
	
	LampTile(int, Material const*);

	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual int getResource(int, Random*);
	
private:
	TextureUVCoordinateSet secondary_tex;
};
