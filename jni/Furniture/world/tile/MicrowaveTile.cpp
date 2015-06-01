#include "MicrowaveTile.h"

int MicrowaveTile::_id = 211;

MicrowaveTile::MicrowaveTile(int id, Material const* material) : RotatableTile(id, material) {
	tex = getTextureUVCoordinateSet("quartz_block", 0);
	secondary_tex = getTextureUVCoordinateSet("stone", 0);
	terciary_tex = getTextureUVCoordinateSet("wool", 15);

	setNameId("tileMicrowave");
	setSoundType(Tile::SOUND_WOOD);
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
}

const TextureUVCoordinateSet& MicrowaveTile::getTexture(signed char side, int data) {
	return side == 0 ? tex : side == 1 ? secondary_tex : terciary_tex;
}

bool MicrowaveTile::use(Player* player, int x, int y, int z) {
	int data = player->region.getData(x, y, z);
	int rot = data & 7;
	int hasBread = ((data & 8) >> 3) == 0;

	if(hasBread) {
		//Pickup bread
		return true;
	} else {
		//Put bread
		return true;
	}

	return true;
}

int MicrowaveTile::getResource(int data, Random* rand) {
	return MicrowaveItem::_id;
}
