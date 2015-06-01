#pragma once

#include "../BlockRenderer.h"

class CounterRenderer : public BlockRenderer {
public:
	virtual void render(const TilePos&, FurnitureTile*, TileTessellator*);
};