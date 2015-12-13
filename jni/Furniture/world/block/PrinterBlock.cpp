#include "PrinterBlock.h"

int PrinterBlock::_id = 231;

PrinterBlock::PrinterBlock(int id, Material const& material) : RotatableBlock("blockPrinter", id, material) {
	tex = getTextureUVCoordinateSet("quartz_block", 0);
	
	setSoundType(Block::SOUND_ANVIL);
	setSolid(false);
}

bool PrinterBlock::use(Player& player, const BlockPos& pos) {
	return true;
}

int PrinterBlock::getResource(Random& rand, int data, int idk) {
	return PrinterItem::_id;
}
