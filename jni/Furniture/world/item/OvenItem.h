#pragma once

#include "PlaceableItem.h"
#include "../tile/OvenTile.h"

class OvenItem: public PlaceableItem {
public:
        static int _id;

        OvenItem(int);
};
