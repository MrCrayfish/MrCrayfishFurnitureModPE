#include "BarStoolTile.h"

int BarStoolTile::_id = 212;

BarStoolTile::BarStoolTile(int id, Material const* material) : FurnitureTile(id, material) {
	tex = getTextureUVCoordinateSet("wool", 0);
	secondary_tex = getTextureUVCoordinateSet("stained_clay", 9);
	terciary_tex = getTextureUVCoordinateSet("quartz_block", 0);
	quartenary_tex = getTextureUVCoordinateSet("stone", 0);

	
	setNameId("tileBarStool");
	setSoundType(Tile::SOUND_WOOD);
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
}

const TextureUVCoordinateSet& BarStoolTile::getTexture(signed char side, int data) {
	return side == 0 ? tex : side == 1 ? secondary_tex : side == 2 ? terciary_tex : quartenary_tex;
}

bool BarStoolTile::use(Player* player, int x, int y, int z) {
	return true;
}

int BarStoolTile::getResource(int data, Random* rand) {
	return BarStoolItem::_id;
}
