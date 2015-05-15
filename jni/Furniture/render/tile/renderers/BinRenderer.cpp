#include "BinRenderer.h"

void BinRenderer::render(const TilePos& pos, FurnitureTile* tile, TileTessellator* tess) {
	tess->useForcedUV = true;
	int x = pos.x, y = pos.y, z = pos.z;

     tess->forcedUV = tile->getTexture(0, 0);
 
     tess->setRenderBounds(0.2, 0.0, 0.2, 0.8, 0.65, 0.8);
	tess->tessellateBlockInWorld(tile, {x, y, z});
    
     tess->setRenderBounds(0.05, 0.65, 0.05, 0.95, 0.8, 0.95);
	tess->tessellateBlockInWorld(tile, {x, y, z});

	tess->forcedUV = tile->getTexture(1, 0);
	tess->setRenderBounds(0.45, 0.9, 0.2, 0.55, 1.0, 0.8);
	tess->tessellateBlockInWorld(tile, {x, y, z});

     tess->setRenderBounds(0.45, 0.8, 0.2, 0.55, 0.9, 0.3);
	tess->tessellateBlockInWorld(tile, {x, y, z});

     tess->setRenderBounds(0.45, 0.8, 0.7, 0.55, 0.9, 0.8);
	tess->tessellateBlockInWorld(tile, {x, y, z});

	tess->useForcedUV = false;
}