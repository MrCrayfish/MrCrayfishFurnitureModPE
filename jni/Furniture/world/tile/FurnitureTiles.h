#pragma once

#include "MCPE/world/level/tile/Tile.h"
#include "MCPE/world/material/Material.h"
#include "Furniture/render/tile/FurnitureShape.h"
#include "MCPE/CommonTypes.h"

class FurnitureTiles : public Tile {
public:
	static FurnitureTiles* tileTableWood;
	static FurnitureTiles* tileTableStone;
	static FurnitureTiles* tileChairWood;
	static FurnitureTiles* tileChairStone;
	static FurnitureTiles* tileCabinet;
	
	FurnitureTiles(int, Material const*);
};
