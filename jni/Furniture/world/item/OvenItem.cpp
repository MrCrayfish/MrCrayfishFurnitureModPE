#include "OvenItem.h"

int OvenItem::_id = 468;

OvenItem::OvenItem(int id) : PlaceableItem(id, OvenTile::_id) {
	setNameID("ovenItem");
	setIcon("ovenItem", 0);
}