#include "OvenTile.h"

int OvenTile::_id = 28;

OvenTile::OvenTile(int id, Material const* material) : FurnitureTile(id, material) {
	tex = getTextureUVCoordinateSet("iron_block", 0);
        secondary_tex = getTextureUVCoordinateSet("stone", 0);
	
	setNameId("tileOven");
	setSoundType(Tile::SOUND_STONE);
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
}

const TextureUVCoordinateSet& OvenTile::getTexture(signed char side, int data) {
	return side == 0 ? tex : secondary_tex;
}

bool OvenTile::use(Player* player, int x, int y, int z) {
	return false;
}

int OvenTile::getResource(int data, Random* rand) {
	return OvenItem::_id;
}
