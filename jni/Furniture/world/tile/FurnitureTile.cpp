#include "FurnitureTile.h"

FurnitureTile* FurnitureTile::tileTableWood = NULL;
FurnitureTile* FurnitureTile::tileTableStone = NULL;
FurnitureTile* FurnitureTile::tileChairWood = NULL;
FurnitureTile* FurnitureTile::tileChairStone = NULL;
FurnitureTile* FurnitureTile::tileToilet = NULL;
FurnitureTile* FurnitureTile::tileCabinet = NULL;
FurnitureTile* FurnitureTile::tileDoorbell = NULL;
FurnitureTile* FurnitureTile::tileBin = NULL;
FurnitureTile* FurnitureTile::tileLamp = NULL;

FurnitureTile::FurnitureTile(int id, Material const* material) : Tile(id, material) {
	init();
	category = 1;

	new TileItem(id - 256);
}
