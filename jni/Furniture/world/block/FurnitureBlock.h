#pragma once

#include <android/log.h>
#define  LOG_TAG    "FurnitureMod-MCPE" 
#define  ALOG(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

#include "MCPE/world/item/BlockItem.h"
#include "MCPE/world/level/block/Block.h"
#include "MCPE/world/level/BlockSource.h"

#include "../../util/CollisionHelper.h"

class FurnitureBlock : public Block {
public:
	static FurnitureBlock* blockTableWood;
	static FurnitureBlock* blockTableStone;
	static FurnitureBlock* blockCoffeeTableWood;
	static FurnitureBlock* blockCoffeeTableStone;
	static FurnitureBlock* blockChairWood;
	static FurnitureBlock* blockChairStone;
	static FurnitureBlock* blockToilet;
	static FurnitureBlock* blockCabinet;
	static FurnitureBlock* blockKitchenCabinet;
	static FurnitureBlock* blockDoorbell;
	static FurnitureBlock* blockBin;
	static FurnitureBlock* blockLamp;
	static FurnitureBlock* blockChoppingBoard;
	static FurnitureBlock* blockToaster;
	static FurnitureBlock* blockMicrowave;
	static FurnitureBlock* blockBarStool;
	static FurnitureBlock* blockCounter;
	static FurnitureBlock* blockCookieJar;
	static FurnitureBlock* blockOven;
	static FurnitureBlock* blockPlate;
     static FurnitureBlock* blockTv;
     static FurnitureBlock* blockPrinter;
     static FurnitureBlock* blockComputer;
	
	FurnitureBlock(const std::string&, int, Material const&);

	static void registerBlocks();

private:
	static void registerBlock(Block*);
};
