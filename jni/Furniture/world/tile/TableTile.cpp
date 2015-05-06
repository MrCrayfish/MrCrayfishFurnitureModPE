#include "TableTile.h"

int TableTile::_woodId = 200;
int TableTile::_stoneId = 201;

TableTile::TableTile(int id, Material const* material) : FurnitureTiles(id, material) {
	renderType = FurnitureShape::TABLE;
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
}

const TextureUVCoordinateSet& TableTile::getTexture(signed char side, int data) {
	return (side == 0)? tex : secondary_tex;
}

bool TableTile::use(Player* player, int x, int y, int z) {
	return false;
}
