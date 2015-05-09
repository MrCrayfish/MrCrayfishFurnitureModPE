#pragma once

#include "Tile.h"

class EntityTile: public Tile {
	void newTileEntity(TilePos const&);
	~EntityTile();
	~EntityTile();
	EntityTile(int,Material const*);
	EntityTile(int,std::string const&,Material const*);
	void triggerEvent(TileSource *,int,int,int,int,int);
	void neighborChanged(TileSource *,int,int,int,int,int,int);
}