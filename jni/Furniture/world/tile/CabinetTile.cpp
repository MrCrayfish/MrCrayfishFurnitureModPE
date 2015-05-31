#include "CabinetTile.h"

int CabinetTile::_id = 204;

CabinetTile::CabinetTile(int id, Material const* material) : RotatableTile(id, material) {
	Tile::lightBlock[id] = 0;
	
	setNameId("tileCabinet");
	setSoundType(Tile::SOUND_WOOD);
	tex = getTextureUVCoordinateSet("planks", 2);
	secondary_tex = getTextureUVCoordinateSet("planks", 1);
	terciary_tex = getTextureUVCoordinateSet("iron_block", 0);
}

const TextureUVCoordinateSet& CabinetTile::getTexture(signed char side, int data) {
	return side == 0 ? tex : (side == 1 ? secondary_tex : terciary_tex);
}

bool CabinetTile::use(Player* player, int x, int y, int z) {
	return true;
}

int CabinetTile::getResource(int data, Random* rand) {
	return CabinetItem::_id;
}

void CabinetTile::addAABBs(TileSource* region, int x, int y, int z, AABB const* posAABB, std::vector<AABB, std::allocator<AABB>>& pool) {
	addAABB(AABB(0.0F, 0.0F, 0.0F, 1.0F, 1.0F, 1.0F).move(x, y, z), posAABB, pool);
}
