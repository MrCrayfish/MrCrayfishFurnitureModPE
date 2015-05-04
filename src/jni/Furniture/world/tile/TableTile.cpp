#include "TableTile.h"

int TableTile::_woodId = 200;
int TableTile::_stoneId = 201;

TableTile::TableTile(int id, Material const* material) : FurnitureTiles(id, material) {
	tex = getTextureUVCoordinateSet("planks", 0);
	stone_tex = getTextureUVCoordinateSet("stone", 0);

	(isWood())? setNameId("tileTableWood") : setNameId("tileTableStone");
	(isWood())? setSoundType(Tile::SOUND_WOOD) : setSoundType(Tile::SOUND_STONE);
	renderType = FurnitureShape::TABLE;
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
}

bool TableTile::isWood() {
	return material == &Material::wood;
}

const TextureUVCoordinateSet& TableTile::getTexture(signed char side, int data) {
	return (isWood())? tex : stone_tex;
}

bool TableTile::use(Player* player, int x, int y, int z) {
	return false;
}

int TableTile::getResource(int data, Random* rand) {
	if(isWood()) return TableItem::_woodId;
	else return TableItem::_stoneId;
	return 0;
}
