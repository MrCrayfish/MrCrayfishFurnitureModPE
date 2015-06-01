#include "MicrowaveItem.h"

int MicrowaveItem::_id = 471;

MicrowaveItem::MicrowaveItem(int id) : PlaceableItem(id, MicrowaveTile::_id) {
	setNameID("microwaveItem");
	setIcon("microwaveItem", 0);
}
