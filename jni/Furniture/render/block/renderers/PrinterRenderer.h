#pragma once

#include "../BlockRenderer.h"

class PrinterRenderer : public BlockRenderer {
public:
	virtual void render(const BlockPos&, FurnitureBlock&, BlockTessellator*);
};
