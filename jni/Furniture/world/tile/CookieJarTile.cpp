#include "CookieJarTile.h"

int CookieJarTile::_id = 33;

CookieJarTile::CookieJarTile(int id, Material const* material) : FurnitureTile(id, material) {
        init();
	setNameId("tileCookieJar");
	setSoundType(Tile::SOUND_GLASS);
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
	renderPass = Tile::glass->renderPass;
}

int CookieJarTile::getResource(int data, Random* rand) {
	return CookieJarItem::_id;
}
