#include "OvenTile.h"

int OvenTile::_id = 28;

OvenTile::OvenTile(int id, Material const* material) : RotatableTile(id, material) {
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;

	setNameId("tileOven");
	setSoundType(Tile::SOUND_STONE);
	setDestroyTime(1.0F);
	tex = getTextureUVCoordinateSet("quartz_block", 0);
}

void OvenTile::addAABBs(TileSource* region, int x, int y, int z, AABB const* posAABB, std::vector<AABB, std::allocator<AABB>>& pool) {
	addAABB(AABB(0, 0, 0.1, 1, 1, 0.9).move(x, y, z), posAABB, pool);
	addAABB(CollisionHelper::getRotatedCollisionBox(region->getData(x, y, z), 0.9, 1.0, 0.1, 1, 1.2, 0.9).move(x, y, z), posAABB, pool);
	addAABB(CollisionHelper::getRotatedCollisionBox(region->getData(x, y, z), -0.1, 0.1, 0.2, 0, 0.9, 0.8).move(x, y, z), posAABB, pool);
	addAABB(CollisionHelper::getRotatedCollisionBox(region->getData(x, y, z), 0.5, 1.0, 0.2, 0.7, 1.1, 0.4).move(x, y, z), posAABB, pool);
	addAABB(CollisionHelper::getRotatedCollisionBox(region->getData(x, y, z), 0.5, 1.0, 0.6, 0.7, 1.1, 0.8).move(x, y, z), posAABB, pool);
	addAABB(CollisionHelper::getRotatedCollisionBox(region->getData(x, y, z), 0.1, 1.0, 0.2, 0.3, 1.1, 0.4).move(x, y, z), posAABB, pool);
	addAABB(CollisionHelper::getRotatedCollisionBox(region->getData(x, y, z), 0.1, 1.0, 0.6, 0.3, 1.1, 0.8).move(x, y, z), posAABB, pool);
}
bool OvenTile::use(Player* player, int x, int y, int z) {
	return true;
}

int OvenTile::getResource(int data, Random* rand) {
	return OvenItem::_id;
}
