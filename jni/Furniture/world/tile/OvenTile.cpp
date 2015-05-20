#include "OvenTile.h"

int OvenTile::_id = 33;

OvenTile::OvenTile(int id, Material const* material) : RotatableTile(id, material) {
	Tile::lightBlock[id] = 0;
	
	setNameId("tileOven");
	setSoundType(Tile::SOUND_STONE);
	tex = getTextureUVCoordinateSet("quartz_block", 1);
	secondary_tex = getTextureUVCoordinateSet("stone", 0);
	terciary_tex = getTextureUVCoordinateSet("obsidian", 0);
}

const TextureUVCoordinateSet& OvenTile::getTexture(signed char side, int data) {
	return side == 0 ? tex : (side == 1 ? secondary_tex : terciary_tex);
}

bool OvenTile::use(Player* player, int x, int y, int z) {
	return false;
}

int OvenTile::getResource(int data, Random* rand) {
	return CabinetItem::_id;
}

void OvenTile::addAABBs(TileSource* region, int x, int y, int z, AABB const* posAABB, std::vector<AABB, std::allocator<AABB>>& pool) {
	addAABB(AABB(0.1F, 0.0F, 0.0F, 0.9F, 1.0F, 1.0F).move(x, y, z), posAABB, pool);
	addAABB(AABB(0.1F, 1.0F, 0.0F, 0.9F, 1.2F, 0.1F).move(x, y, z), posAABB, pool);
        addAABB(AABB(0.2F, 0.1F, 1.0F, 0.8F, 0.9F, 1.1F).move(x, y, z), posAABB, pool);
}
