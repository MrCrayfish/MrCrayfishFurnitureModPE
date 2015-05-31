#include "CounterTile.h"

int CounterTile::_id = 213;

CounterTile::CounterTile(int id, Material const* material) : RotatableTile(id, material) {
	tex = getTextureUVCoordinateSet("quartz_block", 0);
	secondary_tex = getTextureUVCoordinateSet("stained_clay", 9);

	setNameId("tileCounter");
	setSoundType(Tile::SOUND_WOOD);
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
}

const TextureUVCoordinateSet& CounterTile::getTexture(signed char side, int data) {
	return side == 0 ? tex : secondary_tex;
}

int CounterTile::getResource(int data, Random* rand) {
	return CounterItem::_id;
}
