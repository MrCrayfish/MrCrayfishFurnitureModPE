#include "OvenRenderer.h"

void OvenRenderer::render(const TilePos& pos, FurnitureTile* tile, TileTessellator* tess) {
	tess->useForcedUV = true;
	int x = pos.x, y = pos.y, z = pos.z;

     tess->forcedUV = tile->getTexture(0, 0);

     tess->setRenderBounds(0.1, 0.0, 0.0, 1.0, 0.9, 1.0);
     tess->tessellateBlockInWorld(tile, {x, y, z});

     tess->setRenderBounds(0.0, 0.0, 0.0, 0.1, 1.1, 1.0);
     tess->tessellateBlockInWorld(tile, {x, y, z});
    
     tess->forcedUV = tile->getTexture(1, 0);

     tess->setRenderBounds(1.0, 0.25, 0.15, 1.1, 0.75, 0.85);
     tess->tessellateBlockInWorld(tile, {x, y, z});

     tess->forcedUV = tile->getTexture(2, 0);
  
     tess->setRenderBounds(0.6, 0.9, 0.6, 0.8, 1.0, 0.8);
     tess->tessellateBlockInWorld(tile, {x, y, z});

     tess->setRenderBounds(0.2, 0.9, 0.6, 0.4, 1.0, 0.8);
     tess->tessellateBlockInWorld(tile, {x, y, z});

     tess->setRenderBounds(0.2, 0.9, 0.2, 0.4, 1.0, 0.4);
     tess->tessellateBlockInWorld(tile, {x, y, z});
     
     tess->setRenderBounds(0.6, 0.9, 0.2, 0.8, 1.0, 0.4);
     tess->tessellateBlockInWorld(tile, {x, y, z});

	tess->useForcedUV = false;
}