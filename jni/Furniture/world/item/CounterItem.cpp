#include "CounterItem.h"

int CounterItem::_id = 474;

CounterItem::CounterItem(int id) : PlaceableItem(id, CounterTile::_id) {
	setNameID("counterItem");
	setIcon("counterItem", 0);
}
