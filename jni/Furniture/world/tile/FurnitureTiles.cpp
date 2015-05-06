#include "FurnitureTiles.h"

FurnitureTiles* FurnitureTiles::tileTableWood = NULL;
FurnitureTiles* FurnitureTiles::tileTableStone = NULL;
FurnitureTiles* FurnitureTiles::tileChairWood = NULL;
FurnitureTiles* FurnitureTiles::tileChairStone = NULL;
FurnitureTiles* FurnitureTiles::tileCabinet = NULL;

FurnitureTiles::FurnitureTiles(int id, Material const* material) : Tile(id, material) {
	init();
	category = 1;
}