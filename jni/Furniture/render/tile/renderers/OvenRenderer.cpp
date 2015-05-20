#include "OvenRenderer.h"

void OvenRenderer::render(const TilePos& pos, FurnitureTile* tile, TileTessellator* tess) {
	tess->useForcedUV = true;
	tess->forcedUV = tile->getTexture(0, 0);
	int x = pos.x, y = pos.y, z = pos.z;
	int data = tess->region->getData(x, y, z);

	//Main Block
	tess->setRenderBounds(0.0F, 0.0F, 0.0F, 1.0F, 0.65F, 0.85F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
        
        //Header
        tess->setRenderBounds(0.0F, 0.65F, 0.0F, 1.0F, 0.9F, 0.1F);
        tess->tessellateBlockInWorld(tile, {x, y, z});

        //Door
        tess->forcedUV = tile->getTexture(1, 0);
        tess->setRenderBounds(0.1F, 0.1F, 0.85F, 0.9F, 0.50F, 0.95F);
        tess->tessellateBlockInWorld(tile, {x, y, z});

	tess->useForcedUV = false;
}
