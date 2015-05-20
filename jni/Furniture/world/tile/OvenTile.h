#pragma once

#include "FurnitureTile.h"
#include "../item/OvenItem.h"

class OvenTile : public FurnitureTile {
public:
	static int _id;
	
	OvenTile(int, Material const*);

	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual int getResource(int, Random*);
        virtual bool use(Player*, int, int, int);
	
private:
        TextureUVCoordinateSet secondary_tex;
};
