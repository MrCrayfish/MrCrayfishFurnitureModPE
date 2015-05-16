#include "LampTile.h"

int LampTile::_id = 207;

LampTile::LampTile(int id, Material const* material) : FurnitureTile(id, material) {
	tex = getTextureUVCoordinateSet("obsidian", 0);
	secondary_tex = getTextureUVCoordinateSet("wool", 0);
	
	setNameId("tileLamp");
	setSoundType(Tile::SOUND_WOOD);
//	hitbox = AABB({0.375, 0.25, 0}, {0.625, 0.75, 0.1});
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
}

const TextureUVCoordinateSet& LampTile::getTexture(signed char side, int data) {
	return side == 0 ? tex : secondary_tex;
}

int LampTile::getResource(int data, Random* rand) {
	return LampItem::_id;
}
