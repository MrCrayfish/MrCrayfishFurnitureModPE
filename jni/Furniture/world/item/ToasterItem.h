#pragma once

#include "PlaceableItem.h"
#include "../tile/ToasterTile.h"

class ToasterItem : public PlaceableItem {
public:
    static int _id;

    ToasterItem(int);
};