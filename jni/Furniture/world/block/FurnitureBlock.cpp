#include "FurnitureBlock.h"

FurnitureBlock* FurnitureBlock::blockTableWood = NULL;
FurnitureBlock* FurnitureBlock::blockTableStone = NULL;
FurnitureBlock* FurnitureBlock::blockCoffeeTableWood = NULL;
FurnitureBlock* FurnitureBlock::blockCoffeeTableStone = NULL;
FurnitureBlock* FurnitureBlock::blockChairWood = NULL;
FurnitureBlock* FurnitureBlock::blockChairStone = NULL;
FurnitureBlock* FurnitureBlock::blockToilet = NULL;
FurnitureBlock* FurnitureBlock::blockCabinet = NULL;
FurnitureBlock* FurnitureBlock::blockKitchenCabinet = NULL;
FurnitureBlock* FurnitureBlock::blockDoorbell = NULL;
FurnitureBlock* FurnitureBlock::blockBin = NULL;
FurnitureBlock* FurnitureBlock::blockLamp = NULL;
FurnitureBlock* FurnitureBlock::blockChoppingBoard = NULL;
FurnitureBlock* FurnitureBlock::blockToaster = NULL;
FurnitureBlock* FurnitureBlock::blockMicrowave = NULL;
FurnitureBlock* FurnitureBlock::blockBarStool = NULL;
FurnitureBlock* FurnitureBlock::blockCounter = NULL;
FurnitureBlock* FurnitureBlock::blockCookieJar = NULL;
FurnitureBlock* FurnitureBlock::blockOven = NULL;
FurnitureBlock* FurnitureBlock::blockPlate = NULL;
FurnitureBlock* FurnitureBlock::blockTv = NULL;
FurnitureBlock* FurnitureBlock::blockPrinter = NULL;
FurnitureBlock* FurnitureBlock::blockComputer = NULL;

FurnitureBlock::FurnitureBlock(const std::string& name, int id, Material const& material) : Block(name, id, material) {
	ALOG("Loaded FurnitureBlock");
	creativeCategory = 3;
}

void FurnitureBlock::registerBlocks() {
	ALOG("Registering Blocks");
	registerBlock(blockTableWood);
	registerBlock(blockTableStone);
	registerBlock(blockCoffeeTableWood);
	registerBlock(blockCoffeeTableStone);
	registerBlock(blockChairWood);
	registerBlock(blockChairStone);
	registerBlock(blockToilet);
	registerBlock(blockCabinet);
	registerBlock(blockKitchenCabinet);
	registerBlock(blockDoorbell);
	registerBlock(blockBin);
	registerBlock(blockLamp);
	registerBlock(blockChoppingBoard);
	registerBlock(blockToaster);
	registerBlock(blockMicrowave);
	registerBlock(blockBarStool);
	registerBlock(blockCounter);
	registerBlock(blockCookieJar);
	registerBlock(blockOven);
	registerBlock(blockPlate);
     registerBlock(blockTv);
     registerBlock(blockPrinter); 
     registerBlock(blockComputer);
	ALOG("Finished Registering Blocks");
}

void FurnitureBlock::registerBlock(Block* block) {
	ALOG("Init");
	block->init();
	ALOG("Adding block to list");
	Block::mBlocks[block->id] = block;
	ALOG("Adding block item!");
	Item::mItems[block->id] = new BlockItem(block->getDescriptionId(), block->id - 256);
}
