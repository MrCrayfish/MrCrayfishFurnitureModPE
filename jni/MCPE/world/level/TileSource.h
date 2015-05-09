#pragma once

#include "MCPE/CommonTypes.h"
#include "MCPE/world/level/Level.h"

class TileSource {
public:
	FullTile getTile(int, int, int);
	DataID getData(int, int, int);
	bool setTileAndData(int, int, int, FullTile, int);
};
