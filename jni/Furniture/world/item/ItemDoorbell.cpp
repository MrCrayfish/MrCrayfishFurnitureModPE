#include "ItemDoorbell.h"

int ItemDoorbell::_id = 465;

ItemDoorbell::ItemDoorbell(int id, std::string tex) : PlaceableItem(id, TileDoorbell::_id) {
	setNameID(tex);
	setIcon(tex, 3);
}
