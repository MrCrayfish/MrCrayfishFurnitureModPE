#include "OvenTile.h"

int OvenTile::_id = 206;

BinTile::OvenTile(int id, Material const* material) : FurnitureTile(id, material) {
	tex = getTextureUVCoordinateSet("iron_block", 0);
	
	setNameId("tileOven");
	setSoundType(Tile::SOUND_WOOD);
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
}

const TextureUVCoordinateSet& OvenTile::getTexture(signed char side, int data) {
	return tex;
}

int OvenTile::getResource(int data, Random* rand) {
	return OvenItem::_id;
}
