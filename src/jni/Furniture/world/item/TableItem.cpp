#include "TableItem.h"

int TableItem::_woodId = 460;
int TableItem::_stoneId = 461;

TableItem::TableItem(int id, std::string tex, bool isWood) : PlaceableItem(id, isWood? TableTile::_woodId : TableTile::_stoneId) {
	setNameID(tex);
	setIcon(tex, 0);
}
