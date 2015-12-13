#include "ComputerBlock.h"

int ComputerBlock::_id = 232;

ComputerBlock::ComputerBlock(int id, Material const& material) : RotatableBlock("blockComputer", id, material) {
	tex = getTextureUVCoordinateSet("iron_block", 0);
	secondary_tex = getTextureUVCoordinateSet("stone", 0);
	
	setSoundType(Block::SOUND_WOOD);
	setSolid(false);
}

int ComputerBlock::getResource(Random& rand, int data, int idk) {
	return ComputerItem::_id;
}
