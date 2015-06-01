#include "ToasterTile.h"

int ToasterTile::_id = 209;

ToasterTile::ToasterTile(int id, Material const* material) : RotatableTile(id, material) {
	tex = getTextureUVCoordinateSet("iron_block", 0);
	secondary_tex = getTextureUVCoordinateSet("wool", 15);
	terciary_tex = getTextureUVCoordinateSet("stone", 0);
	
	setNameId("tileToaster");
	setSoundType(Tile::SOUND_WOOD);
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
}

const TextureUVCoordinateSet& ToasterTile::getTexture(signed char side, int data) {
	return side == 0 ? tex : side == 1 ? secondary_tex : terciary_tex;
}

bool ToasterTile::use(Player* player, int x, int y, int z) {
	int data = player->region.getData(x, y, z);
	int rot = data & 7;
	int hasBread = ((data & 8) >> 3) == 0;

	if(hasBread) {
		//Pickup bread
		return true;
	} else { //Ah whatever, get carried item not now
		//Put bread
		return true;
	}

	return true;
}

int ToasterTile::getResource(int data, Random* rand) {
	return ToasterItem::_id;
}