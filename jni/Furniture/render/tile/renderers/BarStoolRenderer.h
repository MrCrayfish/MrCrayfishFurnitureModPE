#pragma once

#include "../BlockRenderer.h"

class BarStoolRenderer : public BlockRenderer {
public:
	virtual void render(const TilePos&, FurnitureTile*, TileTessellator*);
};