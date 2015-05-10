#include "FurnitureItems.h"

FurnitureItems* FurnitureItems::itemTableWood = NULL;
FurnitureItems* FurnitureItems::itemTableStone = NULL;
FurnitureItems* FurnitureItems::itemChairWood = NULL;
FurnitureItems* FurnitureItems::itemChairStone = NULL;
FurnitureItems* FurnitureItems::itemCabinet = NULL;
FurnitureItems* FurnitureItems::itemDoorbell = NULL;

TextureAtlas* FurnitureItems::_atlas = NULL;

std::map<std::string, std::string> FurnitureItems::textureConverter;


FurnitureItems::FurnitureItems(int id) : Item(id - 256) {
	atlas = "furnitureitems.png";
	creativeCategory = 2;
}

void FurnitureItems::setIcon(std::string const& name, int index) {
	Item::setIcon(textureConverter[name], index);
}

int FurnitureItems::getTextureIndex() {
    return 0;
}

// TODO: omg get rid of this texture implementation :(
void FurnitureItems::registerTextures() {
	textureConverter["itemTableWood"] = "apple";
	textureConverter["itemTableStone"] = "apple_golden";
    textureConverter["itemChairWood"] = "arrow";
    textureConverter["itemChairStone"] = "axe";
	textureConverter["itemCabinet"] = "axe"; //omg its the same as stone chair
	textureConverter["itemBedsideCabinet"] = "axe";
	textureConverter["itemDoorbell"] = "axe";
}
