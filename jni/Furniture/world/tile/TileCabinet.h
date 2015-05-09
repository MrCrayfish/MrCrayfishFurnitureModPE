#pragma once

#include "FurnitureTiles.h"
#include "../item/ItemCabinet.h"

class TileCabinet : public FurnitureEntityTiles {
public:
	static int _id;
	
	TileCabinet(int, Material const*);

	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual int getResource(int, Random*);
	virtual bool use(Player*, int, int, int);
	
private:
	TextureUVCoordinateSet secondary_tex;
	TextureUVCoordinateSet terciary_tex;
};
