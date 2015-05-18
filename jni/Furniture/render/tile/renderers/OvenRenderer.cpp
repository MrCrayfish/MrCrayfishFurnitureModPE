#include "OvenRenderer.h"

void OvenRenderer::render(const TilePos& pos, FurnitureTile* tile, TileTessellator* tess) {
	tess->useForcedUV = true;
	tess->forcedUV = tile->getTexture(0, 0);
	int x = pos.x, y = pos.y, z = pos.z;
	int data = tess->region->getData(x, y, z);

	//Block
	tess->setRenderBounds(0.0F, 0.0F, 0.0F, 1.0F, 1.0F, 1.0F);
	tess->tessellateBlockInWorld(tile, {x, y, z});

	tess->useForcedUV = false;
}
