#include "TileChair.h"

int TileChair::_woodId = 202;
int TileChair::_stoneId = 203;

TileChair::TileChair(int id, Material const* material) : FurnitureTiles(id, material) {
	renderType = FurnitureShape::CHAIR;
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;

	(isWood())? setNameId("tileChairWood") : setNameId("tileChairStone");
	(isWood())? setSoundType(Tile::SOUND_WOOD) : setSoundType(Tile::SOUND_STONE);
	(isWood())? setDestroyTime(1.0F) : setDestroyTime(1.5F);
	tex = (isWood())? getTextureUVCoordinateSet("planks", 0) : getTextureUVCoordinateSet("cobblestone", 0);
	secondary_tex = (isWood())? getTextureUVCoordinateSet("log", 0) : getTextureUVCoordinateSet("stone", 0);
}

bool TileChair::isWood() {
	return material == &Material::wood;
}

const TextureUVCoordinateSet& TileChair::getTexture(signed char side, int data) {
	return (side == 0)? tex : secondary_tex;
}

bool TileChair::use(Player* player, int x, int y, int z) {
	//make it sittable
	return true;
}

int TileChair::getResource(int data, Random* rand) {
	if(isWood())
		return ChairItem::_woodId;
	else 
		return ChairItem::_stoneId;
}

int TileChair::getResourceCount(Random* rand) {
	return 1;
}
