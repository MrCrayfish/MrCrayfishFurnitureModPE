#include "TileTessellator.h"

void TileTessellator::setRenderBounds(float x0, float y0, float z0, float x1, float y1, float z1) {
	this->bounds = AABB({x0, y0, z0}, {x1, y1, z1});
}