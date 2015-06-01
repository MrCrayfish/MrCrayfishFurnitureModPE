#pragma once

#include "PlaceableItem.h"
#include "../tile/BarStoolTile.h"

class BarStoolItem : public PlaceableItem {
public:
    static int _id;

    BarStoolItem(int);
};
