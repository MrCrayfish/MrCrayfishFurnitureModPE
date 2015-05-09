#pragma once

#include "PlaceableItem.h"
#include "../tile/TileDoorbell.h"

class ItemDoorbell : public PlaceableItem {
public:
    static int _id;

    ItemDoorbell(int, std::string);
};
