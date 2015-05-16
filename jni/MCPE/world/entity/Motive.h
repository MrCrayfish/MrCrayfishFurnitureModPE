#pragma once
#include <string>
#include <vector>

class Motive {
public:
	static const int MAX_MOTIVE_NAME_LENGTH = 13;

	Motive(std::string, int, int, int, int, bool);

	static std::vector<const Motive*> getAllMotivesAsList();
	static const Motive* getMotiveByName(const std::string&);

	const std::string name;

	const int w, h;
	const int uo, vo;

	const bool isPublic;

	static const Motive* DefaultImage;
	static const Motive Kebab;
	static const Motive Aztec;
	static const Motive Alban;
	static const Motive Aztec2;
	static const Motive Bomb;
	static const Motive Plant;
	static const Motive Wasteland;
	static const Motive Pool;
	static const Motive Courbet;
	static const Motive Sea;
	static const Motive Sunset;
	static const Motive Creebet;
	static const Motive Wanderer;
	static const Motive Graham;
	static const Motive Match;
	static const Motive Bust;
	static const Motive Stage;
	static const Motive Void;
	static const Motive SkullAndRoses;
	static const Motive Fighters;
	static const Motive Pointer;
	static const Motive Pigscene;
	static const Motive BurningSkull;
	static const Motive Skeleton;
	static const Motive DonkeyKong;
	static const Motive Earth;
	static const Motive Wind;
	static const Motive Fire;
	static const Motive Water;

	static Motive* Furniture; // 2 cool 4 const
};
