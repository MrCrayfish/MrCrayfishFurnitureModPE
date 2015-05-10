#pragma once

#include "FurnitureTiles.h"
#include "../item/ItemDoorbell.h"

class TileDoorbell : public FurnitureTiles {
public:
	static int _id;
	
	TileDoorbell(int, Material const*);

	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual int getResource(int, Random*);
	virtual int getResourceCount(Random*);
	virtual bool use(Player*, int, int, int);
	
private:
	TextureUVCoordinateSet secondary_tex;
};
