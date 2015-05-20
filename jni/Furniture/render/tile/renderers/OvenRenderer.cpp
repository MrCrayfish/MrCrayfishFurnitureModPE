#include "OvenRenderer.h"

void OvenRenderer::render(const TilePos& pos, FurnitureTile* tile, TileTessellator* tess) {
	tess->useForcedUV = true;
	tess->forcedUV = tile->getTexture(0, 0);
	int x = pos.x, y = pos.y, z = pos.z;
	int data = tess->region->getData(x, y, z);

	//Main Block
	tess->setRenderBounds(0.1F, 0.0F, 0.0F, 0.9F, 1.0F, 1.0F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
        
        //Header
        tess->setRenderBounds(0.1F, 1.0F, 0.0F, 0.9F, 1.2F, 0.1F);
        tess->tessellateBlockInWorld(tile, {x, y, z});        

        //Door
        tess->forcedUV = tile->getTexture(1, 0);
        tess->setRenderBounds(0.2F, 0.1F, 1.0F, 0.8F, 0.9F, 1.1F);
        tess->tessellateBlockInWorld(tile, {x, y, z});

        //Stoves
        tess->forcedUV = tile->getTexture(2, 0);
        tess->setRenderBounds(0.1F, 0.0F, 0.0F, 0.9F, 1.0F, 1.0F);
        tess->tessellateBlockInWorld(tile, {x, y, z});
        tess->setRenderBounds(0.1F, 0.0F, 0.0F, 0.9F, 1.0F, 1.0F);
        tess->tessellateBlockInWorld(tile, {x, y, z});
        tess->setRenderBounds(0.1F, 0.0F, 0.0F, 0.9F, 1.0F, 1.0F);
        tess->tessellateBlockInWorld(tile, {x, y, z});
        tess->setRenderBounds(0.1F, 0.0F, 0.0F, 0.9F, 1.0F, 1.0F);
        tess->tessellateBlockInWorld(tile, {x, y, z});

	tess->useForcedUV = false;
}
