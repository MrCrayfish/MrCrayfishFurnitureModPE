#pragma once

#include "TileEntity.h"

class ChestTileEntity: public TileEntity {
public:
	int getContainerSize();
	ItemInstance getItem(int);
	void onUpdatePacket(CompoundTag *);
	int getMaxStackSize();
	void triggerEvent(int,int);
	std::string getName();
	void startOpen(Player &);
	~ChestTileEntity();
	~ChestTileEntity();
	void stopOpen(Player &);
	void setItem(int,ItemInstance *);
	ChestTileEntity(TilePos const&);
	int getModelOffsetX();
	void _getCenter(float &,float &,float &);
	bool _canOpenThis(Player &);
	bool canOpen(Player &);
	bool _canPairWith(TileEntity *,TileSource &);
	void pairWith(ChestTileEntity*,bool);
	void onNeighborChanged(TileSource &,int,int,int);
	void _unpair();
	void unpair();
	void openBy(Player &);
	void load(CompoundTag *);
	void _saveClientSideState(CompoundTag &)
	void save(CompoundTag *);
	void getUpdatePacket();
	void clearCache();
	void tick(TileSource *);
	void setRemoved();
};