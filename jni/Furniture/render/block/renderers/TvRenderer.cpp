#include "TvRenderer.h"

void TvRenderer::render(const BlockPos& pos, FurnitureBlock& tile, BlockTessellator* tess) {
	int x = pos.x, y = pos.y, z = pos.z;
	int data = tess->region->getData({x, y, z});
	
	tess->useForcedUV = true;

	tess->forcedUV = tile.getTextureUVCoordinateSet("log", 0);

	this->setRotatedBounds(tess, data, 0.1F, 0.0F, 0.1F, 0.6F, 0.1F, 0.9F);
     tess->tessellateBlockInWorld(tile, pos);

     this->setRotatedBounds(tess, data, 0.1F, 0.7F, 0.1F, 0.6F, 0.8F, 0.9F);
     tess->tessellateBlockInWorld(tile, pos);

     this->setRotatedBounds(tess, data, 0.1F, 0.1F, 0.1F, 0.6F, 0.7F, 0.2F);
     tess->tessellateBlockInWorld(tile, pos);

     this->setRotatedBounds(tess, data, 0.1F, 0.1F, 0.8F, 0.6F, 0.7F, 0.9F);
     tess->tessellateBlockInWorld(tile, pos);

     tess->forcedUV = tile.getTextureUVCoordinateSet("wool", 7);

     this->setRotatedBounds(tess, data, 0.2F, 0.1F, 0.2F, 0.5F, 0.7F, 0.8F);
     tess->tessellateBlockInWorld(tile, pos);

     tess->forcedUV = tile.getTextureUVCoordinateSet("planks", 0);

	this->setRotatedBounds(tess, data, 0.5F, 0.07F, 0.2F, 0.9F, 0.7F, 0.8F);
     tess->tessellateBlockInWorld(tile, pos);

	tess->useForcedUV = false;
}
