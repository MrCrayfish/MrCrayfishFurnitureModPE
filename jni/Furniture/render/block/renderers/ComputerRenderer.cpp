#include "ComputerRenderer.h"

void ComputerRenderer::render(const BlockPos& pos, FurnitureBlock& tile, BlockTessellator* tess) {
     tess->useForcedUV = true;
	int x = pos.x, y = pos.y, z = pos.z;
     int data = tess->region->getData({x, y, z}); 	

     tess->forcedUV = tile.getTextureUVCoordinateSet("iron_block", 0);

     this->setRotatedBounds(tess, data, 0.3F, 0.0F, 0.14F, 0.94F, 0.3F, 0.825F);
     tess->tessellateBlockInWorld(tile, pos);

     tess->forcedUV = tile.getTextureUVCoordinateSet("gravel", 0);

     this->setRotatedBounds(tess, data, 0.07F, 0.0F, 0.07F, 0.24F, 0.07F, 0.94F);
     tess->tessellateBlockInWorld(tile, pos);

     tess->forcedUV = tile.getTextureUVCoordinateSet("door", 12);

     this->setRotatedBounds(tess, data, 0.28F, 0.4F, 0.14F, 0.4F, 0.47F, 0.84F);
     tess->tessellateBlockInWorld(tile, pos);

     this->setRotatedBounds(tess, data, 0.28F, 0.94F, 0.14F, 0.4F, 1.0F, 0.84F);
     tess->tessellateBlockInWorld(tile, pos);

     this->setRotatedBounds(tess, data, 0.28F, 0.48F, 0.14F, 0.4F, 0.94F, 0.23F);
     tess->tessellateBlockInWorld(tile, pos);

     this->setRotatedBounds(tess, data, 0.28F, 0.48F, 0.715F, 0.4F, 0.94F, 0.84F);
     tess->tessellateBlockInWorld(tile, pos);

     tess->forcedUV = tile.getTextureUVCoordinateSet("quartz_block", 0);

     this->setRotatedBounds(tess, data, 0.4F, 0.47F, 0.23F, 0.825F, 0.94F, 0.715F);
     tess->tessellateBlockInWorld(tile, pos);

     tess->forcedUV = tile.getTextureUVCoordinateSet("wool", 7);

     this->setRotatedBounds(tess, data, 0.3F, 0.47F, 0.23F, 0.4F, 0.94F, 0.715F);
     tess->tessellateBlockInWorld(tile, pos);

     tess->forcedUV = tile.getTextureUVCoordinateSet("stone", 0);

     this->setRotatedBounds(tess, data, 0.4F, 0.3F, 0.4F, 0.6F, 0.47F, 0.6F);
     tess->tessellateBlockInWorld(tile, pos);
     
     this->setRotatedBounds(tess, data, 0.35F, 0.3F, 0.35F, 0.65F, 0.35F, 0.65F);
     tess->tessellateBlockInWorld(tile, pos);
     
     tess->useForcedUV = false;
}
