#include "OvenTile.h"

int OvenTile::_id = 208;

OvenTile::OvenTile(int id, Material const* material) : RotatableTile(id, material) {
	Tile::lightBlock[id] = 0;
	
	setNameId("tileOven");
	setSoundType(Tile::SOUND_METAL);
	tex = getTextureUVCoordinateSet("quartz_block", 0);
	secondary_tex = getTextureUVCoordinateSet("iron_block", 0);
	terciary_tex = getTextureUVCoordinateSet("obsidian", 0);
}

const TextureUVCoordinateSet& OvenTile::getTexture(signed char side, int data) {
	return side == 0 ? tex : (side == 1 ? secondary_tex : terciary_tex);
}

bool OvenTile::use(Player* player, int x, int y, int z) {
	return true;
}

int OvenTile::getResource(int data, Random* rand) {
	return OvenItem::_id;
}