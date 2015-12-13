#include "BinItem.h"

int BinItem::_id = 465;

BinItem::BinItem(int id) : PlaceableItem("itemBin", id, BinBlock::_id) {
	setIcon("itembin", 0);
}
