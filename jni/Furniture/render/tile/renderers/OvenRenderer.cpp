#include "OvenRenderer.h"

void OvenRenderer::render(const TilePos& pos, FurnitureTile* tile, TileTessellator* tess) {
	int x = pos.x, y = pos.y, z = pos.z;
	int data = tess->region->getData(x, y, z);
	
	tess->useForcedUV = true;

	tess->tex1(tess->getLightColor(pos));

	tess->forcedUV = tile->getTextureUVCoordinateSet("quartz_block", 1);
	this->setRotatedBounds(tess, data, 0, 0, 0.1, 1, 1, 0.9);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	this->setRotatedBounds(tess, data, 0.9, 1.0, 0.1, 1, 1.2, 0.9);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	
	tess->forcedUV = tile->getTextureUVCoordinateSet("stone", 0);
	this->setRotatedBounds(tess, data, -0.1, 0.1, 0.2, 0, 0.9, 0.8);
	tess->tessellateBlockInWorld(tile, {x, y, z});

	tess->forcedUV = tile->getTextureUVCoordinateSet("obsidian", 0);
	this->setRotatedBounds(tess, data, 0.5, 1.0, 0.2, 0.7, 1.1, 0.4);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	this->setRotatedBounds(tess, data, 0.5, 1.0, 0.6, 0.7, 1.1, 0.8);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	this->setRotatedBounds(tess, data, 0.1, 1.0, 0.2, 0.3, 1.1, 0.4);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	this->setRotatedBounds(tess, data, 0.1, 1.0, 0.6, 0.3, 1.1, 0.8);
	tess->tessellateBlockInWorld(tile, {x, y, z});

	tess->useForcedUV = false;
}
