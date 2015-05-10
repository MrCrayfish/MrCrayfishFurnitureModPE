#pragma once

#include "PlaceableItem.h"
#include "../tile/TileCabinet.h"

class ItemCabinet : public PlaceableItem {
public:
    static int _id;

    ItemCabinet(int, std::string);
};
