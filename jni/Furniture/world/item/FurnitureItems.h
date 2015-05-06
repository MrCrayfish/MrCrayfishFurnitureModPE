#pragma once

#include "MCPE/world/item/Item.h"
#include "MCPE/client/renderer/texture/TextureAtlas.h"

#include <map>

class FurnitureItems : public Item {
public:
	static FurnitureItems* itemTableWood;
	static FurnitureItems* itemTableStone;
	static FurnitureItems* itemChairWood;
	static FurnitureItems* itemChairStone;
	static FurnitureItems* itemCabinet;

	static TextureAtlas* _atlas;
	
	static std::map<std::string, std::string> textureConverter;

	FurnitureItems(int);
	static void registerTextures();

	int getTextureIndex();

	virtual void setIcon(std::string const&, int);
};