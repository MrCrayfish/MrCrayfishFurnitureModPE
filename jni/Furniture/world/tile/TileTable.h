#pragma once

#include "FurnitureTiles.h"
#include "../item/TableItem.h"

class TileTable : public FurnitureTiles {
public:
	static int _woodId;
	static int _stoneId;
	
	TileTable(int, Material const*);

	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual int getResource(int, Random*);
	virtual bool use(Player*, int, int, int);
	
	bool isWood();
private:
	TextureUVCoordinateSet secondary_tex;
};
