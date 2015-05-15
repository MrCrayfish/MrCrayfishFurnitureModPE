#pragma once

#include "../BlockRenderer.h"

class BinRenderer: public BlockRenderer {
public:
	virtual void render(const TilePos&, FurnitureTile*, TileTessellator*);
};
