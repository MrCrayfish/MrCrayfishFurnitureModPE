#include "ChairTile.h"

int ChairTile::_woodId = 202;
int ChairTile::_stoneId = 203;

ChairTile::ChairTile(int id, Material const* material) : FurnitureTiles(id, material) {
	tex = getTextureUVCoordinateSet("planks", 0);
	stone_tex = getTextureUVCoordinateSet("stone", 0);

	(isWood())? setNameId("tileChairWood") : setNameId("tileChairStone");
	(isWood())? setSoundType(Tile::SOUND_WOOD) : setSoundType(Tile::SOUND_STONE);
	renderType = FurnitureShape::CHAIR;
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
}

bool ChairTile::isWood() {
	return material == &Material::wood;
}

const TextureUVCoordinateSet& ChairTile::getTexture(signed char side, int data) {
	return (isWood())? tex : stone_tex;
}

bool ChairTile::use(Player* player, int x, int y, int z) {
	return false;
}

int ChairTile::getResource(int data, Random* rand) {
	if(isWood()) return ChairItem::_woodId;
	else return ChairItem::_stoneId;
}
