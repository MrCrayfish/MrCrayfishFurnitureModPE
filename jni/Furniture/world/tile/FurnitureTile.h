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
	static FurnitureTile* tileBin;
	static FurnitureTile* tileLamp;
	static FurnitureTile* tileChoppingBoard;
	static FurnitureTile* tileToaster;
	static FurnitureTile* tileMicrowave;
	static FurnitureTile* tileBarStool;
	static FurnitureTile* tileCounter;
     static FurnitureTile* tileOven;
	
	FurnitureTile(int, Material const*);
};
