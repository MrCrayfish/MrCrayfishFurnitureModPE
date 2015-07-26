#pragma once

#include "../BlockRenderer.h"

class BedsideCabinetRenderer : public BlockRenderer {
public:
	virtual void render(const TilePos&, FurnitureTile*, TileTessellator*);
};
