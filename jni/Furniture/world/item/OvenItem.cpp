#include "OvenItem.h"

int OvenItem::_id = 33;

OvenItem::OvenItem(int id) : PlaceableItem(id, OvenTile::_id) {
setNameId("ovenItem");
setIcon("apple",0); 
}
