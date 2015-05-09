#pragma once

#include "ChestTileEntity.h"

class CabinetTileEntity: public ChestTileEntity {
public:
	CabinetTileEntity(TilePos const&);
	bool _canPairWith(TileEntity *,TileSource &);
	int getContainerSize();
	std::string getName();
};