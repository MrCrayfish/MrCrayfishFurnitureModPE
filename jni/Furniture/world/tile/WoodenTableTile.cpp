#include "WoodenTableTile.h"

int WoodenTableTile::_id = 200;

WoodenTableTile::WoodenTableTile(int id) : TableTile(id, &Material::wood) {
    tex = getTextureUVCoordinateSet("planks", 0);
    secondary_tex = getTextureUVCoordinateSet("log", 0);
    
    setNameId("tileWoodTable");
    setSoundType(Tile::SOUND_WOOD);
    setDestroyTime(1.0F);
}
