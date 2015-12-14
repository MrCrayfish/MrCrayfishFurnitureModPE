#include "PrinterItem.h"

int PrinterItem::_id = 491;

PrinterItem::PrinterItem(int id) : PlaceableItem("itemPrinter", id, PrinterBlock::_id) {
	setIcon("itemprinter", 0);
}
