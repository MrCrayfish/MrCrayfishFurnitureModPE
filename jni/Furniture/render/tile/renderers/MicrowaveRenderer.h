#pragma once

#include "../BlockRenderer.h"

class MicrowaveRenderer : public BlockRenderer {
public:
	virtual void render(const TilePos&, FurnitureTile*, TileTessellator*);
};