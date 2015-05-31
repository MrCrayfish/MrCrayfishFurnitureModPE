#include "ChoppingBoardRenderer.h"

void ChoppingBoardRenderer::render(const TilePos& pos, FurnitureTile* tile, TileTessellator* tess) {
	tess->useForcedUV = true;
	int x = pos.x, y = pos.y, z = pos.z;
	int data = tess->region->getData(x, y, z);
	
	if(data == 11) data = 3;
	if(data == 9) data = 1;
	if(data == 10) data = 2;
	if(data == 8) data = 0;
	
	tess->forcedUV = tile->getTexture(0, 0);
	this->setRotatedBounds(tess, data, 0.25F, 0.0F, 0.0625F, 0.8125F, 0.0625F, 0.9375F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	
	tess->forcedUV = tile->getTexture(1, 0);
	this->setRotatedBounds(tess, data, 0.21875F, 0.0F, 0.03125F, 0.84375F, 0.0625F, 0.0625F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	this->setRotatedBounds(tess, data, 0.21875F, 0.0F, 0.9375F, 0.84375F, 0.0625F, 0.96875F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	this->setRotatedBounds(tess, data, 0.8125F, 0.0F, 0.0625F, 0.84375F, 0.0625F, 0.9375F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	this->setRotatedBounds(tess, data, 0.21875F, 0.0F, 0.0625F, 0.25F, 0.0625F, 0.9375F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	
	tess->useForcedUV = false;
}
