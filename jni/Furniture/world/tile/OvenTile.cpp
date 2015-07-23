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
	addAABB(AABB(0.0F, 0.0F, 0.1F, 1.0F, 1.0F, 0.9F).move(x, y, z), posAABB, pool);
     addAABB(CollisionHelper::getRotatedCollisionBox(region->getData(x, y, z), 0.9F, 1.0F, 0.1F, 1.0F, 1.2F, 0.9F).move(x, y, z), posAABB, pool);
     addAABB(CollisionHelper::getRotatedCollisionBox(region->getData(x, y, z), -0.1F, 0.1F, 0.2F, 0.0F, 0.9F, 0.8F).move(x, y, z), posAABB, pool);
     addAABB(CollisionHelper::getRotatedCollisionBox(region->getData(x, y, z), 0.5F, 1.0F, 0.2F, 0.7F, 1.1F, 0.4F).move(x, y, z), posAABB, pool);
     addAABB(CollisionHelper::getRotatedCollisionBox(region->getData(x, y, z), 0.5F, 1.0F, 0.2F, 0.7F, 1.1F, 0.4F).move(x, y, z), posAABB, pool);
     addAABB(CollisionHelper::getRotatedCollisionBox(region->getData(x, y, z), 0.1F, 1.0F, 0.2F, 0.3F, 1.1F, 0.4F).move(x, y, z), posAABB, pool);
     addAABB(CollisionHelper::getRotatedCollisionBox(region->getData(x, y, z), 0.1F, 1.0F, 0.6F, 0.3F, 1.1F, 0.8F).move(x, y, z), posAABB, pool);
}

bool OvenTile::use(Player* player, int x, int y, int z) {
	return true;
}

int OvenTile::getResource(int data, Random* rand) {
	return OvenItem::_id;
}
