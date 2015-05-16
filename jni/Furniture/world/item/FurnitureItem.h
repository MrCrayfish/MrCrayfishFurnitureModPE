#pragma once

#include "MCPE/world/item/Item.h"

class FurnitureItem : public Item {
public:
	static FurnitureItem* itemTableWood;
	static FurnitureItem* itemTableStone;
	static FurnitureItem* itemChairWood;
	static FurnitureItem* itemChairStone;
	static FurnitureItem* itemToilet;
	static FurnitureItem* itemCabinet;
	static FurnitureItem* itemDoorbell;

	FurnitureItem(int);
};