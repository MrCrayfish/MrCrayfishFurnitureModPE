#include "ComputerItem.h"

int ComputerItem::_id = 476;

ComputerItem::ComputerItem(int id) : PlaceableItem("itemComputer", id, ComputerBlock::_id) {
	setIcon("itemcomputer", 0);
}
