#pragma once

#include "PlaceableItem.h"
#include "../block/PrinterBlock.h"

class PrinterItem: public PlaceableItem {
public:
    static int _id;
	
    PrinterItem(int);
};
