#pragma once

#include "PlaceableItem.h"
#include "../tile/LampTile.h"

class LampItem: public PlaceableItem {
public:
    static int _id;

    LampItem(int);
};