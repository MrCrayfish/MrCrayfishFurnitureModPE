#include "PrinterRenderer.h"

void PrinterRenderer::render(const BlockPos& pos, FurnitureBlock& tile, BlockTessellator* tess) {
	tess->useForcedUV = true;
	int x = pos.x, y = pos.y, z = pos.z;
     int data = tess->region->getData({x, y, z}); 
	
	tess->forcedUV = tile.getTextureUVCoordinateSet("iron_block", 0);

	this->setRotatedBounds(tess, data, 0.3F, 0.0F, 0.07F, 0.9F, 0.4F, 0.96F);
	tess->tessellateBlockInWorld(tile, pos);

     tess->forcedUV = tile.getTextureUVCoordinateSet("quartz_block", 0);

	this->setRotatedBounds(tess, data, 0.76F, 0.07F, 0.21F, 1.0F, 0.6F, 0.82F);
	tess->tessellateBlockInWorld(tile, pos);

     this->setRotatedBounds(tess, data, 0.845F, 0.0F, 0.2F, 0.9F, 0.07F, 0.815F);
	tess->tessellateBlockInWorld(tile, pos);

     this->setRotatedBounds(tess, data, 0.845F, 0.0F, 0.2F, 0.9F, 0.07F, 0.815F);
	tess->tessellateBlockInWorld(tile, pos);  

     this->setRotatedBounds(tess, data, 0.0F, 0.07F, 0.23F, 0.9F, 0.14F, 0.72F);
	tess->tessellateBlockInWorld(tile, pos);

     tess->forcedUV = tile.getTextureUVCoordinateSet("stone", 0);

	this->setRotatedBounds(tess, data, 0.85F, 0.07F, 0.25F, 0.9F, 0.7F, 0.725F);
	tess->tessellateBlockInWorld(tile, pos);

	tess->useForcedUV = false;
}