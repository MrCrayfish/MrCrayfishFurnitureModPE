#pragma once

#include "PlaceabeItem.h"
#include "./tile/OvenTile.h"

class OvenItem: public PlaceableItem {
Public:
        static int _id;

        OvenItem(int);
};
