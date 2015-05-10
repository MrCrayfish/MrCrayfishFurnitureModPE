#pragma once

#include "FillingContainer.h"

class Player;

class Inventory : public FillingContainer {
public:
	// Size : 48
	int selected;
	Player* player;
public:
	Inventory(Player *, bool);
	virtual ~Inventory();
	virtual int getContainerSize();
	virtual bool stillValid(Player *);
	virtual void add(ItemInstance *);
	virtual void doDrop(ItemInstance *, bool);
};
