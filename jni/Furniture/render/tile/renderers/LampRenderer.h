#pragma once

#include "../BlockRenderer.h"

class LampRenderer: public BlockRenderer {
public:
	virtual void render(const TilePos&, FurnitureTile*, TileTessellator*);
};
