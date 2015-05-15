#pragma once

#include "FurnitureTile.h"
#include "../item/BinItem.h"

class BinTile : public FurnitureTile {
public:
	static int _id;
	
	BinTile(int, Material const*);

	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual int getResource(int, Random*);
	
private:
	TextureUVCoordinateSet secondary_tex;
};
