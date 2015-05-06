#pragma once

#include "PlaceableItem.h"
#include "../tile/CabinetTile.h"

class CabinetItem : public PlaceableItem {
public:
    static int _id;

    CabinetItem(int, std::string);
};