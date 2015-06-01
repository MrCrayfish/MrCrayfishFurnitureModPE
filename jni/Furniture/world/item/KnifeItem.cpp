#include "KnifeItem.h"

int KnifeItem::_id = 472;

KnifeItem::KnifeItem(int id) : FurnitureItem(id) {
	setNameID("knifeItem");
	setIcon("knifeItem", 0);
}
