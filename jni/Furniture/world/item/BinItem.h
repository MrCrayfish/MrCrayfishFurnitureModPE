#pragma once

#include "PlaceableItem.h"
#include "../tile/BinTile.h"

class BinItem: public PlaceableItem {
public:
    static int _id;

    BinItem(int);
};