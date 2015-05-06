#pragma once

#include "MCPE/world/level/tile/Tile.h"
#include "MCPE/world/level/TileSource.h"
#include "MCPE/client/renderer/tile/TileTessellator.h"
#include "MCPE/world/level/TilePos.h"

#include "../../world/tile/FurnitureTiles.h"
#include "../../world/tile/WoodenTableTile.h"
#include "../../world/tile/StoneTableTile.h"
#include "../../world/tile/CabinetTile.h"
#include "FurnitureShape.h"


class FurnitureRenderer {
public:
	static void render(TileTessellator*, TileSource*, Tile*, const TilePos&);

	static void renderTable(TileTessellator*, TableTile*, const TilePos&);
	static void renderChair(TileTessellator*, Tile*, const TilePos&);
static void renderCabinet(TileTessellator*, CabinetTile*, const TilePos&);

private:
	static TileSource* region;
};
