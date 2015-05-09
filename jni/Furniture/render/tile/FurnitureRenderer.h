#pragma once

#include "MCPE/world/level/tile/Tile.h"
#include "MCPE/world/level/TileSource.h"
#include "MCPE/client/renderer/tile/TileTessellator.h"
#include "MCPE/world/level/TilePos.h"

#include "../../world/tile/FurnitureTiles.h"
#include "../../world/tile/TileTable.h"
#include "../../world/tile/TileChair.h"
#include "../../world/tile/TileCabinet.h"
#include "../../world/tile/TileDoorbell.h"
#include "FurnitureShape.h"


class FurnitureRenderer {
public:
	static void render(TileTessellator*, TileSource*, Tile*, const TilePos&);

	static void renderTable(TileTessellator*, TileTable*, const TilePos&);
	static void renderChair(TileTessellator*, TileChair*, const TilePos&);
	static void renderCabinet(TileTessellator*, TileCabinet*, const TilePos&);
	static void renderDoorbell(TileTessellator*, TileDoorbell*, const TilePos&);
	
private:
	static TileSource* region;
};
