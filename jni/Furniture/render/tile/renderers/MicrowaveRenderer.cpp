#include "MicrowaveRenderer.h"

void MicrowaveRenderer::render(const TilePos& pos, FurnitureTile* tile, TileTessellator* tess) {
	tess->useForcedUV = true;
	int x = pos.x, y = pos.y, z = pos.z;
	int data = tess->region->getData(x, y, z);

	if(data == 11) data = 3;
	if(data == 9) data = 1;
	if(data == 10) data = 2;
	if(data == 8) data = 0;

	bool hasItem = data > 3;

	tess->forcedUV = tile->getTexture(0, 0);
	this->setRotatedBounds(tess, data, 0.25F, 0.0F, 0.0625F, 0.8125F, 0.5F, 0.125F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	this->setRotatedBounds(tess, data, 0.25F, 0.0F, 0.125F, 0.8125F, 0.0625F, 0.75F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	this->setRotatedBounds(tess, data, 0.25F, 0.4375F, 0.125F, 0.8125F, 0.5F, 0.75F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	this->setRotatedBounds(tess, data, 0.25F, 0.0F, 0.75F, 0.8125F, 0.5F, 0.9375F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	this->setRotatedBounds(tess, data, 0.75F, 0.0F, 0.125F, 0.8125F, 0.5F, 0.75F);
	tess->tessellateBlockInWorld(tile, {x, y, z});

	tess->forcedUV = tile->getTexture(0, 0);
	this->setRotatedBounds(tess, data, 0.1875F, 0.0625F, 0.125F, 0.25F, 0.125F, 0.6875F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	this->setRotatedBounds(tess, data, 0.1875F, 0.375F, 0.125F, 0.25F, 0.4375F, 0.6875F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	this->setRotatedBounds(tess, data, 0.1875F, 0.125F, 0.125F, 0.25F, 0.375F, 0.1875F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	this->setRotatedBounds(tess, data, 0.1875F, 0.125F, 0.625F, 0.25F, 0.375F, 0.6875F);
	tess->tessellateBlockInWorld(tile, {x, y, z});

	tess->forcedUV = tile->getTexture(2, 0);
	this->setRotatedBounds(tess, data, 0.1875F, 0.0F, 0.0625F, 0.25F, 0.0625F, 0.75F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	this->setRotatedBounds(tess, data, 0.1875F, 0.4375F, 0.0625F, 0.25F, 0.5F, 0.75F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	this->setRotatedBounds(tess, data, 0.1875F, 0.0625F, 0.0625F, 0.25F, 0.4375F, 0.125F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	this->setRotatedBounds(tess, data, 0.1875F, 0.0625F, 0.6875F, 0.25F, 0.4375F, 0.75F);
	tess->tessellateBlockInWorld(tile, {x, y, z});

	tess->forcedUV = tile->getTexture(1, 0);
	this->setRotatedBounds(tess, data, 0.1875F, 0.0F, 0.78125F, 0.25F, 0.5F, 0.9375F);
	tess->tessellateBlockInWorld(tile, {x, y, z});

	if (hasItem) {
	  //render an item. (How?)
	}

	tess->forcedUV = tile->getTexture(1, 0);
	this->setRotatedBounds(tess, data, 0.265625F, 0.0625F, 0.1875F, 0.625F, 0.125F, 0.640625F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	
	tess->useForcedUV = false;
}