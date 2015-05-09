#include "CabinetTileEntity.h"

CabinetTileEntity::CabinetTileEntity(TilePos const& pos): ChestTileEntity(pos) {

}

bool CabinetTileEntity::_canPairWith(TileEntity *,TileSource &) {
	return false;
}

int CabinetTileEntity::getContainerSize() {
	return 15;
}

std::string CabinetTileEntity::getName() {
	return "Cabinet";
}