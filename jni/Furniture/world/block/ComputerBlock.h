#pragma once

#include "RotatableBlock.h"
#include "../item/ComputerItem.h"

class ComputerBlock : public RotatableBlock {
public:
	static int _id;
	
	ComputerBlock(int, Material const&);

	virtual int getResource(Random&, int, int);
	
private:
	TextureUVCoordinateSet secondary_tex;
};