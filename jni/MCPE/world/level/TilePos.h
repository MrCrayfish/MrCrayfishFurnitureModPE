#pragma once

class TilePos {
public:
	int x;
	int y;
	int z;
public:
	TilePos(const ChunkPos &, int);
	TilePos(const Vec3 &);
	TilePos(float, float, float);
};