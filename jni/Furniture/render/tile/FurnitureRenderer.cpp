#include "FurnitureRenderer.h"

TileSource* FurnitureRenderer::region;

void FurnitureRenderer::render(TileTessellator* tess, TileSource* region, Tile* tile, const TilePos& pos) {
	FurnitureRenderer::region = region;

	switch(tile->renderType) {
	case FurnitureShape::TABLE:
		renderTable(tess, (TileTable*)tile, pos);
		break;
	case FurnitureShape::CHAIR:
		renderChair(tess, (TileChair*)tile, pos);
		break;
	case FurnitureShape::CABINET:
		renderCabinet(tess, (TileCabinet*)tile, pos);
		break;
	case FurnitureShape::DOORBELL:
		renderDoorbell(tess, (TileDoorbell*)tile, pos);
	default:
		tess->tessellateBlockInWorld(tile, pos);
	}
}

void FurnitureRenderer::renderTable(TileTessellator* tess, TileTable* tile, const TilePos& pos) {
    int x = pos.x, y = pos.y, z = pos.z;

    int forwardId = region->getTile(x + 1, y, z).id;
    int backId = region->getTile(x - 1, y, z).id;
    int leftId = region->getTile(x, y, z - 1).id;
    int rightId = region->getTile(x, y, z + 1).id;
    bool forward = forwardId == TileTable::_woodId || forwardId == TileTable::_stoneId;
    bool back = backId == TileTable::_woodId || backId == TileTable::_stoneId;
    bool left = leftId == TileTable::_woodId || leftId == TileTable::_stoneId;
    bool right = rightId == TileTable::_woodId || rightId == TileTable::_stoneId;
		
	tess->useForcedUV = true;
	
	tess->forcedUV = tile->getTexture(0,0);

	if(forward && right && !left && !back) {
		tess->setRenderBounds(0.175, 0.0, 0.175, 0.425, 0.9, 0.425);
		tess->tessellateBlockInWorld(tile, pos);
	}
	if(forward && !right && left && !back) {
		tess->setRenderBounds(0.175, 0.0, 0.575, 0.425, 0.9, 0.825);
		tess->tessellateBlockInWorld(tile, pos);
	}
	if(!forward && right && !left && back) {
		tess->setRenderBounds(0.575, 0.0, 0.175, 0.825, 0.9, 0.425);
		tess->tessellateBlockInWorld(tile, pos);
	}
	if(!forward && !right && left && back) {
		tess->setRenderBounds(0.575, 0.0, 0.575, 0.825, 0.9, 0.825);
		tess->tessellateBlockInWorld(tile, pos);
	}
	if(forward && !right && !left && !back) {
		tess->setRenderBounds(0.175, 0.0, 0.375, 0.425, 0.9, 0.625);
		tess->tessellateBlockInWorld(tile, pos);
	}
	if(!forward && right && !left && !back) {
		tess->setRenderBounds(0.375, 0.0, 0.175, 0.625, 0.9, 0.425);
		tess->tessellateBlockInWorld(tile, pos);
	}	
	if(!forward && !right && left && !back) {
		tess->setRenderBounds(0.375, 0.0, 0.575, 0.625, 0.9, 0.825);
		tess->tessellateBlockInWorld(tile, pos);
	}
	if(!forward && !right && !left && back) {
		tess->setRenderBounds(0.575, 0.0, 0.375, 0.825, 0.9, 0.625);	
		tess->tessellateBlockInWorld(tile, pos);
	}
	if(!forward && !right && !left && !back) {
		tess->setRenderBounds(0.375, 0.0, 0.375, 0.625, 0.9, 0.625);
		tess->tessellateBlockInWorld(tile, pos);
	}

    //tess->forcedUV = tile->getTexture(1,0);

	tess->setRenderBounds(0.0, 0.9, 0.0, 1.0, 1.0, 1.0);
	tess->tessellateBlockInWorld(tile, pos);

	tess->useForcedUV = false;
}

void FurnitureRenderer::renderChair(TileTessellator* tess, TileChair* tile, const TilePos& pos) {
    int x = pos.x, y = pos.y, z = pos.z;
	int data = region->getData(x, y, z);

    tess->useForcedUV = true;
	tess->forcedUV = tile->getTexture(0,0);

	// Legs
	tess->setRenderBounds(0.1, 0.0, 0.1, 0.2, 0.5, 0.2);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	tess->setRenderBounds(0.8, 0.0, 0.8, 0.9, 0.5, 0.9);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	tess->setRenderBounds(0.8, 0.0, 0.1, 0.9, 0.5, 0.2);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	tess->setRenderBounds(0.1, 0.0, 0.8, 0.2, 0.5, 0.9);
	tess->tessellateBlockInWorld(tile, {x, y, z});

	// Back Rest
	// TODO: Make a RenderHelper to auto rotate block bounds
	tess->setRenderBounds(0.8, 0.6, 0.1, 0.9, 1.2, 0.9);
	tess->tessellateBlockInWorld(tile, {x, y, z});

	//tess->forcedUV = tile->getTexture(1,0);

	// Base
	tess->setRenderBounds(0.1, 0.5, 0.1, 0.9, 0.6, 0.9);
	tess->tessellateBlockInWorld(tile, {x, y, z});

	tess->useForcedUV = false;
}

void FurnitureRenderer::renderCabinet(TileTessellator* tess, TileCabinet* tile, const TilePos& pos) {
	tess->useForcedUV = true;
	tess->forcedUV = tile->getTexture(0, 0);
	int x = pos.x, y = pos.y, z = pos.z;
	tess->setRenderBounds(0, 0, 0, 1, 1, 1);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	tess->forcedUV = tile->getTexture(1, 0);
	tess->setRenderBounds(0.0625, 0.0625, 1, 0.9375, 0.9375, 1.05);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	tess->forcedUV = tile->getTexture(2, 0);
	tess->setRenderBounds(0.125, 0.375, 1.05, 0.1875, 0.75, 1.1);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	tess->setRenderBounds(0.1875, 0.375, 1.05, 0.25, 0.4375, 1.1);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	
	tess->setRenderBounds(0.1875, 0.6875, 1.05, 0.25, 0.75, 1.1);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	
	tess->useForcedUV = false;
}

void FurnitureRenderer::renderDoorbell(TileTessellator* tess, TileDoorbell* tile, const TilePos& pos) {
	tess->useForcedUV = true;
	int x = pos.x, y = pos.y, z = pos.z;
	tess->forcedUV = tile->getTexture(0, 0);
	tess->setRenderBounds(0.375, 0.25, 0, 0.625, 0.75, 0.1);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	tess->forcedUV = tile->getTexture(1, 0);
	tess->setRenderBounds(0.4375, 0.4375, 0.1, 0.5625, 0.5625, 0.15);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	tess->useForcedUV = false;
}
