#pragma once

#include "../BlockRenderer.h"

class ComputerRenderer: public BlockRenderer {
public:
	virtual void render(const BlockPos&, FurnitureBlock&, BlockTessellator*);
};
