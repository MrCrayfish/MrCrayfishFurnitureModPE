#include "ToasterItem.h"

int ToasterItem::_id = 469;

ToasterItem::ToasterItem(int id) : PlaceableItem(id, ToasterTile::_id) {
	setNameID("toasterItem");
	setIcon("toasterItem", 0);
}
