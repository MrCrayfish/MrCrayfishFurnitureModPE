#include "BedsideCabinetItem.h"

int BedsideCabinetItem::_id = 477;

BedsideCabinetItem::BedsideCabinetItem(int id) : PlaceableItem(id, BedsideCabinetTile::_id) {
	setNameID("bedsideCabinetItem");
	setIcon("bedsideCabinetItem", 0);
}
