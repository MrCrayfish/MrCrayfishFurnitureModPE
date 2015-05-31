#pragma once

#include "PlaceableItem.h"
#include "../tile/ChoppingBoardTile.h"

class ChoppingBoardItem : public PlaceableItem {
public:
    static int _id;

    ChoppingBoardItem(int);
};