#include "BedsideCabinetTile.h"

int BedsideCabinetTile::_id = 221;

BedsideCabinetTile::BedsideCabinetTile(int id, Material const* material) : RotatableTile(id, material) {
	Tile::lightBlock[id] = 0;
	
	setNameId("tileBedsideCabinet");
	setSoundType(Tile::SOUND_WOOD);
	tex = getTextureUVCoordinateSet("log", 0);
	secondary_tex = getTextureUVCoordinateSet("planks", 0);
	terciary_tex = getTextureUVCoordinateSet("planks", 1);
}

const TextureUVCoordinateSet& BedsideCabinetTile::getTexture(signed char side, int data) {
	return side == 0 ? tex : (side == 1 ? secondary_tex : terciary_tex);
}

bool BedsideCabinetTile::use(Player* player, int x, int y, int z) {
	return true;
}

int BedsideCabinetTile::getResource(int data, Random* rand) {
	return BedsideCabinetItem::_id;
}

void BedsideCabinetTile::addAABBs(TileSource* region, int x, int y, int z, AABB const* posAABB, std::vector<AABB, std::allocator<AABB>>& pool) {
	addAABB(AABB(0.0F, 0.0F, 0.0F, 1.0F, 1.0F, 1.0F).move(x, y, z), posAABB, pool);
}
