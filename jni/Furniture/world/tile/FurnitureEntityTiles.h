#pragma once

#include "MCPE/world/level/tile/EntityTile.h"
#include "MCPE/world/material/Material.h"
#include "Furniture/render/tile/FurnitureShape.h"
#include "MCPE/CommonTypes.h"

class FurnitureEntityTiles : public EntityTile {
public:
	static FurnitureEntityTiles* entityTileCabinet;
	
	FurnitureEntityTiles(int, Material const*);
};
