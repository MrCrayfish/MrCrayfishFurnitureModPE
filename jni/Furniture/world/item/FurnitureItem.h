#pragma once

#include "MCPE/world/item/Item.h"

class FurnitureItem : public Item {
public:
	static FurnitureItem* itemTableWood;
	static FurnitureItem* itemTableStone;
	static FurnitureItem* itemCoffeeTableWood;
	static FurnitureItem* itemCoffeeTableStone;
	static FurnitureItem* itemChairWood;
	static FurnitureItem* itemChairStone;
	static FurnitureItem* itemToilet;
	static FurnitureItem* itemCabinet;
	static FurnitureItem* itemKitchenCabinet;
	static FurnitureItem* itemDoorbell;
	static FurnitureItem* itemBin;
	static FurnitureItem* itemLamp;
	static FurnitureItem* itemChoppingBoard;
	static FurnitureItem* itemToaster;
	static FurnitureItem* itemMicrowave;
	static FurnitureItem* itemKnife;
	static FurnitureItem* itemBarStool;
	static FurnitureItem* itemCounter;
	static FurnitureItem* itemCookieJar;
	static FurnitureItem* itemOven;
	static FurnitureItem* itemPlate;
     static FurnitureItem* itemTv;
     static FurnitureItem* itemPrinter;
     static FurnitureItem* itemComputer;
	
	FurnitureItem(const std::string&, int);

	static void registerItems();

private:
	static void registerItem(Item* item);
};
