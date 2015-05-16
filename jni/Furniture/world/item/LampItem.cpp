#include "LampItem.h"

int LampItem::_id = 467;

LampItem::LampItem(int id) : PlaceableItem(id, LampTile::_id) {
	setNameID("lampItem");
	setIcon("lampItem", 0);
}