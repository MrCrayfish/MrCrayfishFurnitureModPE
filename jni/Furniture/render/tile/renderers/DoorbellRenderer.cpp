#include "DoorbellRenderer.h"

void DoorbellRenderer::render(const TilePos& pos, FurnitureTile* tile, TileTessellator* tess) {
	tess->useForcedUV = true;
	int x = pos.x, y = pos.y, z = pos.z;
	int data = tess->region->getData(x, y, z);
	
	int temp = data;
	
	if(data == 11) data = 3;
	if(data == 9) data = 1;
	if(data == 10) data = 2;
	if(data == 8) data = 0;
	
	bool isPressed = temp > 3;
	
	//Base
	tess->forcedUV = tile->getTexture(0, 0);
	this->setRotatedBounds(tess, data, 0.9F, 0.3F, 0.4F, 1.0F, 0.7F, 0.6F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	
	//Button
	tess->forcedUV = tile->getTexture(1, 0);
	this->setRotatedBounds(tess, data, (isPressed)? 0.89F : 0.85F, 0.45F, 0.45F, 0.9F, 0.55F, 0.55F);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	
	tess->useForcedUV = false;
}