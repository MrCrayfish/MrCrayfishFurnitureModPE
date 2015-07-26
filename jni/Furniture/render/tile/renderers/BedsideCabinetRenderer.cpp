#include "BedsideCabinetRenderer.h"

void BedsideCabinetRenderer::render(const TilePos& pos, FurnitureTile* tile, TileTessellator* tess) {
	tess->useForcedUV = true;
	tess->forcedUV = tile->getTexture(0, 0);
	int x = pos.x, y = pos.y, z = pos.z;
	int data = tess->region->getData(x, y, z);

	/*Top and bottom*/
	tess->setRenderBounds(0.0F, 0.0F, 0.0F, 1.0F, 0.1F, 1.0F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	tess->setRenderBounds(0.0F, 0.9F, 0.0F, 1.0F, 1.0F, 1.0F);
	tess->tessellateBlockInWorld(tile, {x, y, z});

	/*Center & Handles*/
	tess->forcedUV = tile->getTexture(1, 0);
	this->setRotatedBounds(tess, data, 0.055F, 0.1F, 0.05F, 0.945F, 0.9F, 0.945F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	this->setRotatedBounds(tess, data, -0.05, 0.675, 0.35, 0.0, 0.75, 0.625);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	this->setRotatedBounds(tess, data, -0.05F, 0.25F, 0.35F, 0.0F, 0.325F, 0.625F);
	tess->tessellateBlockInWorld(tile, {x, y, z});

	/*Drawers*/
	tess->forcedUV = tile->getTexture(2, 0);
	this->setRotatedBounds(tess, data, 0.0F, 0.15F, 0.125F, 0.1F, 0.425F, 0.875F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	this->setRotatedBounds(tess, data, 0.0F, 0.55F, 0.125F, 0.1F, 0.85F, 0.875F);
	tess->tessellateBlockInWorld(tile, {x, y, z});

	tess->useForcedUV = false;
}
