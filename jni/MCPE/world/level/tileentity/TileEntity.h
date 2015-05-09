#pragma once

#include "TileEntityTypeEnum.h"
#include "../../../nbt/CompoundTag.h"
#include <string>

class TileEntity {
public:
	void onUpdatePacket(CompoundTag *);
	void onNeighborChanged(TileSource &,int,int,int);
	float getShadowRadius(TileSource &);
	~TileEntity();
	void load(CompoundTag *);
	void setRemoved();
	void triggerEvent(int,int);
	void clearCache();
	bool isFinished();
	void getUpdatePacket(); //this returns something
	~TileEntity();
	void tick(TileSource *);
	void save(CompoundTag *);
	void setChanged();
	int distanceToSqr(Vec3 const&);
	bool isRemoved();
	void clearRemoved();
	bool isType(TileEntityType);
	bool isType(TileEntity*,TileEntityType);
	void _destructionWobble(float &,float &,float &);
	void _resetAABB();
	void TileEntity(TileEntityType,TilePos const&,std::string const&);
	void loadStatic(CompoundTag &);
	void setId(TileEntityType,std::string const&);
	static void initTileEntities();
};