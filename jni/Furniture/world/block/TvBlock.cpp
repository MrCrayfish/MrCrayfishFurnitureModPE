#include "TvBlock.h"

int TvBlock::_id = 230;

TvBlock::TvBlock(int id, Material const& material) : RotatableBlock("blockTv", id, material) {
	tex = getTextureUVCoordinateSet("log", 0);
	secondary_tex = getTextureUVCoordinateSet("planks", 0);

	terciary_tex = getTextureUVCoordinateSet("wool", 15);
	
	setSoundType(Block::SOUND_WOOD);
	setSolid(false);
}

bool TvBlock::addCollisionShapes(BlockSource& region, const BlockPos& pos, const AABB* posAABB, std::vector<AABB, std::allocator<AABB>>& pool, Entity* entity) {
	addAABB(AABB(0.0F, 0.0F, 0.0F, 1.0F, 1.0F, 1.0F).move(pos.x, pos.y, pos.z), posAABB, pool);
	return true;
}

const TextureUVCoordinateSet& TvBlock::getTexture(signed char side, int data) {
	return side == 0 ? tex : side == 1 ? secondary_tex : terciary_tex;
}

int TvBlock::getResource(Random& rand, int data, int idk) {
	return TvItem::_id;
}
