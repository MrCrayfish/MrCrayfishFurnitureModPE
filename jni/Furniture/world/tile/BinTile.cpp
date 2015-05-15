#include "BinTile.h"
#include "../../../MCPE/world/level/Level.h"

int BinTile::_id = 206;

BinTile::BinTile(int id, Material const* material) : FurnitureTile(id, material) {
	tex = getTextureUVCoordinateSet("iron_block", 0);
	secondary_tex = getTextureUVCoordinateSet("stone", 0);
	
	setNameId("tileBin");
	setSoundType(Tile::SOUND_WOOD);
//	hitbox = AABB({0.375, 0.25, 0}, {0.625, 0.75, 0.1});
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
}

const TextureUVCoordinateSet& BinTile::getTexture(signed char side, int data) {
	return side == 0 ? tex : secondary_tex;
}

int BinTile::getResource(int data, Random* rand) {
	return BinItem::_id;
}
