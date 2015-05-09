#include "TileCabinet.h"

int TileCabinet::_id = 204;

TileCabinet::TileCabinet(int id, Material const* material) : FurnitureEntityTiles(id, material) {
	tex = getTextureUVCoordinateSet("planks", 2);
	secondary_tex = getTextureUVCoordinateSet("planks", 1);
	terciary_tex = getTextureUVCoordinateSet("iron_block", 0);
	
	setNameId("tileCabinet");
	setSoundType(Tile::SOUND_WOOD);
	renderType = FurnitureShape::CABINET;
	tileEntityType = tileEntityType::CABINET;
	//Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
}

const TextureUVCoordinateSet& TileCabinet::getTexture(signed char side, int data) {
	return side == 0 ? tex : (side == 1 ? secondary_tex : terciary_tex);
}

bool TileCabinet::use(Player* player, int x, int y, int z) {
	return false;
}

int TileCabinet::getResource(int data, Random* rand) {
	return ItemCabinet::_id;
}