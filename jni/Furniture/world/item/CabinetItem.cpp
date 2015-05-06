#include "CabinetItem.h"

int CabinetItem::_id = 464;

CabinetItem::CabinetItem(int id, std::string tex) : PlaceableItem(id, CabinetTile::_id) {
	setNameID(tex);
	setIcon(tex, 1);
}