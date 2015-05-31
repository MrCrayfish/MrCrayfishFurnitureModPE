#pragma once

#include "PlaceableItem.h"
#include "../tile/CounterTile.h"

class CounterItem : public PlaceableItem {
public:
    static int _id;

    CounterItem(int);
};
