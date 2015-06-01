#pragma once

#include "PlaceableItem.h"
#include "../tile/MicrowaveTile.h"

class MicrowaveItem : public PlaceableItem {
public:
    static int _id;

    MicrowaveItem(int);
};