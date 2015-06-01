#include "BarStoolItem.h"

int BarStoolItem::_id = 473;

BarStoolItem::BarStoolItem(int id) : PlaceableItem(id, BarStoolTile::_id) {
	setNameID("barStoolItem");
	setIcon("barStoolItem", 0);
}