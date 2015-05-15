#include "BinItem.h"

int BinItem::_id = 466;

BinItem::BinItem(int id) : PlaceableItem(id, BinTile::_id) {
	setNameID("binItem");
	setIcon("binItem", 0);
}