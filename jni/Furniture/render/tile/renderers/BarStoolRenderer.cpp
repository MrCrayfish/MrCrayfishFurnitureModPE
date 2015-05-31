#include "BarStoolRenderer.h"

void BarStoolRenderer::render(const TilePos& pos, FurnitureTile* tile, TileTessellator* tess) {
	tess->useForcedUV = true;
	int x = pos.x, y = pos.y, z = pos.z;
	int data = tess->region->getData(x, y, z);
	
	tess->forcedUV = tile->getTexture(0, data); //wool
    tess->setRenderBounds(0.21875D, 0.75D, 0.21875D, 0.78125D, 0.78125D, 0.78125D);
    tess->tessellateBlockInWorld(tile, {x, y, z});

    tess->forcedUV = tile->getTexture(1, 0); //stained clay
    tess->setRenderBounds(0.1875D, 0.5625D, 0.1875D, 0.8125D, 0.75D, 0.8125D);
    tess->tessellateBlockInWorld(tile, {x, y, z});

    tess->forcedUV = tile->getTexture(2, data); //quartz
    tess->setRenderBounds(0.25D, 0.0D, 0.25D, 0.375D, 0.5625D, 0.375D);
    tess->tessellateBlockInWorld(tile, {x, y, z});
    tess->setRenderBounds(0.625D, 0.0D, 0.25D, 0.75D, 0.5625D, 0.375D);
    tess->tessellateBlockInWorld(tile, {x, y, z});
    tess->setRenderBounds(0.25D, 0.0D, 0.625D, 0.375D, 0.5625D, 0.75D);
    tess->tessellateBlockInWorld(tile, {x, y, z});
    tess->setRenderBounds(0.625D, 0.0D, 0.625D, 0.75D, 0.5625D, 0.75D);
    tess->tessellateBlockInWorld(tile, {x, y, z});

    tess->forcedUV = tile->getTexture(3, data); //stone
    tess->setRenderBounds(0.28125D, 0.25D, 0.375D, 0.34375D, 0.3125D, 0.625D);
    tess->tessellateBlockInWorld(tile, {x, y, z});
    tess->setRenderBounds(0.65625D, 0.25D, 0.375D, 0.71875D, 0.3125D, 0.625D);
    tess->tessellateBlockInWorld(tile, {x, y, z});
    tess->setRenderBounds(0.375D, 0.25D, 0.65625D, 0.625D, 0.3125D, 0.71875D);
    tess->tessellateBlockInWorld(tile, {x, y, z});
    tess->setRenderBounds(0.375D, 0.25D, 0.28125D, 0.625D, 0.3125D, 0.34375D);
    tess->tessellateBlockInWorld(tile, {x, y, z});
	
	tess->useForcedUV = false;
}
