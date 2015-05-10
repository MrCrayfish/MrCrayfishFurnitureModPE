#pragma once
#include <string>

class ItemInstance;
class Player;

class Container {
public:
	//void **vtable;	// 0

public:
	virtual ~Container();
	virtual ItemInstance *getItem(int);
	virtual void setItem(int, ItemInstance *);
	virtual void removeItem(int, int);
	virtual std::string getName();
	virtual int getContainerSize();
	virtual int getMaxStackSize();
	virtual bool stillValid(Player *);
	virtual void startOpen();
	virtual void stopOpen();
	virtual int getSlotCopies();
};
