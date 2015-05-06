#include "CabinetTile.h"

int CabinetTile::_id = 204;

CabinetTile::CabinetTile(int id, Material const* material) : FurnitureTiles(id, material) {
	tex = getTextureUVCoordinateSet("planks", 2);
	
	setNameId("tileCabinet");
	setSoundType(Tile::SOUND_WOOD);
	renderType = FurnitureShape::CABINET;
	//Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
}

const TextureUVCoordinateSet& CabinetTile::getTexture(signed char side, int data) {
	return tex;
}

bool CabinetTile::use(Player* player, int x, int y, int z) {
	return false;
}

int CabinetTile::getResource(int data, Random* rand) {
	return CabinetItem::_id;
}
