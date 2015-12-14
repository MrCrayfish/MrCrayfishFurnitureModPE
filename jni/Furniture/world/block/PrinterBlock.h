#pragma once

#include "FurnitureBlock.h"
#include "../item/PrinterItem.h"

#include "MCPE/world/level/Level.h"
#include "MCPE/world/level/BlockSource.h"

class PrinterBlock: public RotatableBlock {
public:
	static int _id;
	
	PrinterBlock(int, Material const&);
	
	virtual int getResource(Random&, int, int);
	virtual bool use(Player&, const BlockPos&);
};
