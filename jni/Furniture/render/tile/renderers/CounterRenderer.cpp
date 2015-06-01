#include "CounterRenderer.h"

void CounterRenderer::render(const TilePos& pos, FurnitureTile* tile, TileTessellator* tess) {
	tess->useForcedUV = true;
	int x = pos.x, y = pos.y, z = pos.z;
	TileSource* ts = tess->region;
	int data = ts->getData(x, y, z);

	if(data == 11) data = 3;
	if(data == 9) data = 1;
	if(data == 10) data = 2;
	if(data == 8) data = 0;

	Tile* forwardId = tess->region->getTilePtr(x + 1, y, z);
	Tile* backId = tess->region->getTilePtr(x - 1, y, z);
	Tile* leftId = tess->region->getTilePtr(x, y, z - 1);
	Tile* rightId = tess->region->getTilePtr(x, y, z + 1);
	bool forward = forwardId == tile;
	bool back = backId == tile;
	bool left = leftId == tile;
	bool right = rightId == tile;
	
	tess->forcedUV = tile->getTexture(0, data);

    if (left)
    {
      if (data == 2)
      {
        this->setRotatedBounds(tess, data, 0.0F, 0.0F, 0.125F, 1.0F, 0.875F, 1.0F);
        tess->tessellateBlockInWorld(tile, {x, y, z});
      }
      else if (data == 3)
      {
        this->setRotatedBounds(tess, data, 0.0F, 0.0F, 0.0F, 1.0F, 0.875F, 0.875F);
        tess->tessellateBlockInWorld(tile, {x, y, z});
      }
    }
    if (right)
    {
      if (data == 2 && (!forward))
      {
        this->setRotatedBounds(tess, data, 0.125F, 0.0F, 0.125F, 1.0F, 0.875F, 1.0F);
        tess->tessellateBlockInWorld(tile, {x, y, z});
      }
      else if ((data == 3) && (!back))
      {
        this->setRotatedBounds(tess, data, 0.125F, 0.0F, 0.0F, 1.0F, 0.875F, 0.875F);
        tess->tessellateBlockInWorld(tile, {x, y, z});
      }
      else
      {
        this->setRotatedBounds(tess, data, 0.125F, 0.0F, 0.0F, 1.0F, 0.875F, 1.0F);
        tess->tessellateBlockInWorld(tile, {x, y, z});
      }
    }
    else
    {
      this->setRotatedBounds(tess, data, 0.125F, 0.0F, 0.0F, 1.0F, 0.875F, 1.0F);
      tess->tessellateBlockInWorld(tile, {x, y, z});
    }

    tess->forcedUV = tile->getTexture(1, 0);
    this->setRotatedBounds(tess, data, 0.0F, 0.875F, 0.0F, 1.0F, 1.0F, 1.0F);
    tess->tessellateBlockInWorld(tile, {x, y, z});
	
	tess->useForcedUV = false;
}
