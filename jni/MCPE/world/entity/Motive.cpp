#include "Motive.h"

Motive* Motive::Furniture;

void Motive::initCustomMotives() {
	Motive::Furniture = new Motive("furniture", 32, 32, 224, 224, true);
}