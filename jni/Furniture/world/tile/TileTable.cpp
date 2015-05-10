#include "TileTable.h"

int TileTable::_woodId = 200;
int TileTable::_stoneId = 201;

TileTable::TileTable(int id, Material const* material) : FurnitureTiles(id, material) {
	renderType = FurnitureShape::TABLE;
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;

	(isWood())? setNameId("tileWoodTable") : setNameId("tileStoneTable");
	(isWood())? setSoundType(Tile::SOUND_WOOD) : setSoundType(Tile::SOUND_STONE);
	(isWood())? setDestroyTime(1.0F) : setDestroyTime(1.5F);
	tex = (isWood())? getTextureUVCoordinateSet("planks", 0) : getTextureUVCoordinateSet("cobblestone", 0);
	secondary_tex = (isWood())? getTextureUVCoordinateSet("log", 0) : getTextureUVCoordinateSet("stone", 0);
}

bool TileTable::isWood() {
	return material == &Material::wood;
}

const TextureUVCoordinateSet& TileTable::getTexture(signed char side, int data) {
	return (side == 0)? tex : secondary_tex;
}

bool TileTable::use(Player* player, int x, int y, int z) {
	return false;
}

int TileTable::getResource(int data, Random* rand) {
	if(isWood())
		return TableItem::_woodId;
	else 
		return TableItem::_stoneId;
}

int TileTable::getResourceCount(Random* rand) {
	return 1;
}
