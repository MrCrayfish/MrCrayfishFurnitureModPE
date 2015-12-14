#pragma once

#include "PlaceableItem.h"
#include "../block/ComputerBlock.h"

class ComputerItem: public PlaceableItem {
public:
	static int _id;

	ComputerItem(int);
};