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
	static FurnitureItem* itemBin;
	static FurnitureItem* itemLamp;
	static FurnitureItem* itemChoppingBoard;
	static FurnitureItem* itemToaster;
	static FurnitureItem* itemMicrowave;
	static FurnitureItem* itemKnife;
	static FurnitureItem* itemBarStool;
	static FurnitureItem* itemCounter;
     static FurnitureItem* itemOven;
	
	FurnitureItem(int);
};
