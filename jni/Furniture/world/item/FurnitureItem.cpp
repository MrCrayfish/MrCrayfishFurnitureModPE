#include "FurnitureItem.h"

FurnitureItem* FurnitureItem::itemTableWood = NULL;
FurnitureItem* FurnitureItem::itemTableStone = NULL;
FurnitureItem* FurnitureItem::itemChairWood = NULL;
FurnitureItem* FurnitureItem::itemChairStone = NULL;
FurnitureItem* FurnitureItem::itemToilet = NULL;
FurnitureItem* FurnitureItem::itemCabinet = NULL;
FurnitureItem* FurnitureItem::itemDoorbell = NULL;

FurnitureItem::FurnitureItem(int id) : Item(id - 256) {
	creativeCategory = 4;
}
