#include "ItemCabinet.h"

int ItemCabinet::_id = 464;

ItemCabinet::ItemCabinet(int id, std::string tex) : PlaceableItem(id, TileCabinet::_id) {
	setNameID(tex);
	setIcon(tex, 1);
}
