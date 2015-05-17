#pragma once

#include "PlaceableItem.h"
#include "../tile/OvenTile.h"

class OvenItem: public PlaceableItem {
public:
        Static int _id;

        OvenItem(int);
};
