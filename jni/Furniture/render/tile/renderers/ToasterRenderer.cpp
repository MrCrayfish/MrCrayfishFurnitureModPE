#include "ToasterRenderer.h"

void ToasterRenderer::render(const TilePos& pos, FurnitureTile* tile, TileTessellator* tess) {
	tess->useForcedUV = true;
	int x = pos.x, y = pos.y, z = pos.z;
	int data = tess->region->getData(x, y, z);

	if(data == 11) data = 3;
	if(data == 9) data = 1;
	if(data == 10) data = 2;
	if(data == 8) data = 0;

	tess->forcedUV = tile->getTexture(0, 0);
	this->setRotatedBounds(tess, data, 0.34375F, 0.0F, 0.21875F, 0.40625F, 0.4F, 0.78125F);
    tess->tessellateBlockInWorld(tile, {x, y, z});
    this->setRotatedBounds(tess, data, 0.59375F, 0.0F, 0.21875F, 0.65625F, 0.4F, 0.78125F);
    tess->tessellateBlockInWorld(tile, {x, y, z});
    this->setRotatedBounds(tess, data, 0.46875F, 0.0F, 0.28125F, 0.53125F, 0.4F, 0.71875F);
    tess->tessellateBlockInWorld(tile, {x, y, z});
    this->setRotatedBounds(tess, data, 0.40625F, 0.0F, 0.21875F, 0.59375F, 0.4F, 0.28125F);
    tess->tessellateBlockInWorld(tile, {x, y, z});
    this->setRotatedBounds(tess, data, 0.40625F, 0.0F, 0.71875F, 0.59375F, 0.4F, 0.78125F);
    tess->tessellateBlockInWorld(tile, {x, y, z});

    tess->forcedUV = tile->getTexture(1, 0);
    this->setRotatedBounds(tess, data, 0.3125F, 0.0F, 0.1875F, 0.6875F, 0.0625F, 0.8125F);
    tess->tessellateBlockInWorld(tile, {x, y, z});

    tess->forcedUV = tile->getTexture(2, 0);
    this->setRotatedBounds(tess, data, 0.4375F, 0.25F, 0.15625F, 0.5625F, 0.3F, 0.21875F);
    tess->tessellateBlockInWorld(tile, {x, y, z});

	tess->useForcedUV = false;
}
