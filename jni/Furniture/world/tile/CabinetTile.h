#pragma once

#include "FurnitureTiles.h"
#include "../item/CabinetItem.h"

class CabinetTile : public FurnitureTiles {
public:
	static int _id;
	
	CabinetTile(int, Material const*);

	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual int getResource(int, Random*);
	virtual bool use(Player*, int, int, int);
};