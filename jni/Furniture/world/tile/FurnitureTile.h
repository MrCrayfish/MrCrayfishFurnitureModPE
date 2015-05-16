#pragma once

#include "MCPE/world/item/TileItem.h"
#include "MCPE/world/level/tile/Tile.h"
#include "MCPE/world/level/TileSource.h"

#include "../../util/CollisionHelper.h"

class FurnitureTile : public Tile {
public:
	static FurnitureTile* tileTableWood;
	static FurnitureTile* tileTableStone;
	static FurnitureTile* tileChairWood;
	static FurnitureTile* tileChairStone;
	static FurnitureTile* tileToilet;
	static FurnitureTile* tileCabinet;
	static FurnitureTile* tileDoorbell;
	
	FurnitureTile(int, Material const*);
};
