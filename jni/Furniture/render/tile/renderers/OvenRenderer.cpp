#include "OvenRenderer.h"

void OvenRenderer::render(const TilePos& pos, FurnitureTile* tile, TileTessellator* tess) {
	int x = pos.x, y = pos.y, z = pos.z;
	int data = tess->region->getData(x, y, z);
	
	tess->useForcedUV = true;

	tess->tex1(tess->getLightColor(pos));

	tess->forcedUV = tile->getTextureUVCoordinateSet("quartz_block", 1);
	this->setRotatedBounds(tess, data, 0.1, 0.0, 0.0, 0.9, 1.0, 1.0);
	tess->tessellateBlockInWorld(tile, {x, y, z});
        this->setRotatedBounds(tess, data, 0.1, 1.0, 0.0, 0.9, 1.2, 0.1);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	
	tess->forcedUV = tile->getTextureUVCoordinateSet("stone", 0);
	this->setRotatedBounds(tess, data, 0.8, 0.1, 1.0, 0.8, 0.9, 1.1);
	tess->tessellateBlockInWorld(tile, {x, y, z});

//	tess->forcedUV = tile->getTextureUVCoordinateSet("obsidian", 0);
//	this->setRotatedBounds(tess, data, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0);
//	tess->tessellateBlockInWorld(tile, {x, y, z});

	tess->useForcedUV = false;
}
