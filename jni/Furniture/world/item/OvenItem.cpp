#include "OvenItem.h"

int OvenItem::_id = 511;

OvenItem::OvenItem(int id) : PlaceableItem(id, OvenTile::_id) {
setNameID("ovenItem");
setIcon("apple",0); 
}
