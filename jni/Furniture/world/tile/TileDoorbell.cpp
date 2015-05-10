#include "TileDoorbell.h"
#include "../../../MCPE/world/level/Level.h"

int TileDoorbell::_id = 205;

TileDoorbell::TileDoorbell(int id, Material const* material) : FurnitureTiles(id, material) {
	tex = getTextureUVCoordinateSet("log", 0);
	secondary_tex = getTextureUVCoordinateSet("iron_block", 0);
	
	setNameId("tileDoorbell");
	setSoundType(Tile::SOUND_WOOD);
	renderType = FurnitureShape::DOORBELL;
	hitbox = AABB({0.375, 0.25, 0}, {0.625, 0.75, 0.1});
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
}

const TextureUVCoordinateSet& TileDoorbell::getTexture(signed char side, int data) {
	return side == 0 ? tex : secondary_tex;
}

bool TileDoorbell::use(Player* player, int x, int y, int z) {
	Level::level->playSound(x, y, z, "fire.fire", 100, 100);
	return true;
}

int TileDoorbell::getResource(int data, Random* rand) {
	return ItemDoorbell::_id;
}

int TileDoorbell::getResourceCount(Random* rand) {
	return 1;
}
