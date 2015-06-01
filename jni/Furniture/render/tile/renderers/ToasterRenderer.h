#pragma once

#include "../BlockRenderer.h"

class ToasterRenderer : public BlockRenderer {
public:
	virtual void render(const TilePos&, FurnitureTile*, TileTessellator*);
};
