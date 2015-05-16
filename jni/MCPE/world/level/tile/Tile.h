#pragma once

#include <string>
#include <vector>

class Material;
class TileEntity;
class TilePos;
class TileSource;
#include "../../../client/renderer/texture/TextureUVCoordinateSet.h"
class Entity;
class Player;
class Mob;
class Random;
#include "../../phys/AABB.h"
class ItemInstance;
#include "../../../CommonTypes.h"


class Tile {
public:
    class SoundType {
	public:
		float volume;
		float pitch;
		std::string breakSound;
		std::string stepSound;

	
		SoundType() {};
		SoundType(std::string const&, float, float);
	};


	bool replaceable; // 4
	AABB hitbox; // 8
	TextureUVCoordinateSet tex; // 36
	unsigned char id; // 68
	const Tile::SoundType* soundType; // 72
	int renderPass; // 76
	bool canBuildOver; // 80
	int renderType; // 84
	int tileType; // 88
	int tileEntityType; // 92
	float thickness; // 96
	bool canSlide; // 100
	bool canInstaTick; // 101
	float gravity; // 104
	Material* material; // 108
	float friction; // 112
	float destroyTime; // 116
	float explosionResistance; // 120
	int category; // 124
	char fill[8]; // 128
	std::string descriptionId; // 136


	static Tile* tiles[256];
	static bool solid[256];
	static float translucency[256];
	static uint_fast8_t lightBlock[256];

	static const Tile::SoundType SOUND_NORMAL;
	static const Tile::SoundType SOUND_WOOD;
	static const Tile::SoundType SOUND_GRAVEL;
	static const Tile::SoundType SOUND_GRASS;
	static const Tile::SoundType SOUND_STONE;
	static const Tile::SoundType SOUND_METAL;
	static const Tile::SoundType SOUND_GLASS;
	static const Tile::SoundType SOUND_CLOTH;
	static const Tile::SoundType SOUND_SAND;
	static const Tile::SoundType SOUND_SILENT;


	Tile(int, Material const*);
	Tile(int, TextureUVCoordinateSet, Material const*);
	Tile(int, std::string const&, Material const*);

	virtual ~Tile(); // 2
	virtual void onFertilized(TileSource*, int, int, int); // 4
	virtual AABB const& getShape(TileSource*, int, int, int, AABB&, bool); // 5
	virtual AABB const& getShape(unsigned char, AABB&, bool); // 6
	virtual bool isObstructingChests(TileSource*, int, int, int); // 7
	virtual bool shouldRenderFace(TileSource*, int, int, int, signed char, AABB const&) const; // 8
	virtual TextureUVCoordinateSet const& getTexture(signed char); // 9
	virtual TextureUVCoordinateSet const& getTexture(signed char, int); // 10
	virtual TextureUVCoordinateSet const& getTexture(TileSource*, int, int, int, signed char); // 11
	virtual void getTessellatedUVs(); // 12
	virtual void getCarriedTexture(signed char, int); // 13
	virtual AABB* getAABB(TileSource*, int, int, int, AABB&, int, bool, int); // 14
	virtual void addAABBs(TileSource*, int, int, int, AABB const*, std::vector<AABB, std::allocator<AABB>>&); // 15
	virtual bool isPathfindable(TileSource*, int, int, int); // 17
	virtual bool mayPick(); // 18
	virtual bool mayPick(int, bool); // 19
	virtual bool mayPlace(TileSource*, int, int, int, signed char); // 20
	virtual bool mayPlace(TileSource*, int, int, int); // 21
	virtual int getTickDelay(); // 22
	virtual void tick(TileSource*, int, int, int, Random*); // 23
	virtual void animateTick(TileSource*, int, int, int, Random*); // 24
	virtual void destroy(TileSource*, int, int, int, int); // 25
	virtual void playerWillDestroy(Player*, int, int, int, int); // 26
	virtual void neighborChanged(TileSource*, int, int, int, int, int, int); // 27
	virtual void onPlace(TileSource*, int, int, int); // 28
	virtual void onRemove(TileSource*, int, int, int); // 29
	virtual void getSecondPart(TileSource&, TilePos const&, TilePos&); // 30
	virtual void onGraphicsModeChanged(bool, bool); // 31
	virtual int getResource(int, Random*); // 32
	virtual int getResourceCount(Random*); // 33
	virtual void getDestroyProgress(Player*); // 34
	virtual void spawnResources(TileSource*, int, int, int, int, float); // 35
	virtual void spawnBurnResources(TileSource*, float, float, float); // 36
	virtual float getExplosionResistance(Entity*); // 37
	virtual void clip(TileSource*, int, int, int, Vec3 const&, Vec3 const&, bool, int); // 38
	virtual void wasExploded(TileSource*, int, int, int); // 39
	virtual bool use(Player*, int, int, int); // 40
	virtual void stepOn(Entity*, int, int, int); // 41
	virtual void fallOn(TileSource*, int, int, int, Entity*, float); // 42
	virtual int getPlacementDataValue(Mob*, int, int, int, signed char, float, float, float, int); // 43
	virtual void prepareRender(TileSource*, int, int, int); // 44
	virtual void attack(Player*, int, int, int); // 45
	virtual void handleEntityInside(TileSource*, int, int, int, Entity*, Vec3&); // 46
	virtual int getColor(int); // 47
	virtual int getColor(TileSource*, int, int, int); // 48
	virtual bool isSignalSource(); // 49
	virtual bool getSignal(TileSource*, int, int, int); // 50
	virtual int getSignal(TileSource*, int, int, int, int); // 51
	virtual int getDirectSignal(TileSource*, int, int, int, int); // 52
	virtual bool entityInside(TileSource*, int, int, int, Entity*); // 53
	virtual void playerDestroy(Player*, int, int, int, int); // 54
	virtual bool canSurvive(TileSource*, int, int, int); // 55
	virtual Tile* setNameId(std::string const&); // 60
	virtual std::string getName(ItemInstance const*) const; // 56
	virtual void triggerEvent(TileSource*, int, int, int, int, int); // 61
	virtual TextureUVCoordinateSet getTextureNum(int); // 62
	virtual void getMobToSpawn(TileSource&, TilePos const&) const; // 63
	virtual int getIconYOffset() const; // 64
	virtual void setShape(float, float, float, float, float, float); // 65
	virtual Tile* setSoundType(Tile::SoundType const&); // 66
	virtual Tile* setLightBlock(Brightness); // 67
	virtual Tile* setLightEmission(float); // 68
	virtual Tile* setExplodeable(float); // 69
	virtual Tile* setDestroyTime(float); // 70
	virtual void setTicking(bool); // 71
	virtual void getSpawnResourcesAuxValue(int); // 72
	virtual Tile* init(); // 73

	void addAABB(const AABB&, const AABB*, std::vector<AABB, std::allocator<AABB>>&);
	void popResource(TileSource*, int, int, int, ItemInstance const&);
	TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string&, int);
	Tile* setCategory(int);
	static void initTiles();


	static Tile* rock;
	static Tile* grass;
	static Tile* dirt;
	static Tile* podzol;
	static Tile* stoneBrick;
	static Tile* wood;
	static Tile* sapling;
	static Tile* unbreakable;
	static Tile* water;
	static Tile* calmWater;
	static Tile* lava;
	static Tile* calmLava;
	static Tile* sand;
	static Tile* gravel;
	static Tile* goldOre;
	static Tile* ironOre;
	static Tile* coalOre;
	static Tile* log;
	static Tile* leaves;
	static Tile* sponge;
	static Tile* web;
	static Tile* glass;
	static Tile* thinGlass;
	static Tile* lapisOre;
	static Tile* lapisBlock;
	static Tile* dispenser;
	static Tile* sandStone;
	static Tile* musicBlock;
	static Tile* bed;
	static Tile* unused_27;
	static Tile* unused_28;
	static Tile* unused_29;
	static Tile* unused_30;
	static Tile* tallgrass;
	static Tile* unused_32;
	static Tile* unused_33;
	static Tile* unused_34;
	static Tile* unused_36;
	static Tile* cloth;
	static Tile* yellowFlower;
	static Tile* redFlower;
	static Tile* brownMushroom;
	static Tile* redMushroom;
	static Tile* goldBlock;
	static Tile* ironBlock;
	static Tile* stoneSlab;
	static Tile* stoneSlabHalf;
	static Tile* redBrick;
	static Tile* tnt;
	static Tile* bookshelf;
	static Tile* mossStone;
	static Tile* obsidian;
	static Tile* torch;
	static Tile* fire;
	static Tile* mobSpawner;
	static Tile* stairs_wood;
	static Tile* chest;
	static Tile* redStoneDust;
	static Tile* diamondOre;
	static Tile* diamondBlock;
	static Tile* workBench;
	static Tile* stonecutterBench;
	static Tile* crops;
	static Tile* farmland;
	static Tile* furnace;
	static Tile* furnace_lit;
	static Tile* sign;
	static Tile* door_wood;
	static Tile* ladder;
	static Tile* rail;
	static Tile* goldenRail;
	static Tile* stairs_stone;
	static Tile* wallSign;
	static Tile* lever;
	static Tile* pressurePlate_stone;
	static Tile* door_iron;
	static Tile* pressurePlate_wood;
	static Tile* redStoneOre;
	static Tile* redStoneOre_lit;
	static Tile* notGate_off;
	static Tile* notGate_on;
	static Tile* button;
	static Tile* buttonWood;
	static Tile* topSnow;
	static Tile* ice;
	static Tile* snow;
	static Tile* cactus;
	static Tile* clay;
	static Tile* reeds;
	static Tile* recordPlayer;
	static Tile* fence;
	static Tile* stairs_brick;
	static Tile* fenceGateOak;
	static Tile* fenceGateSpruce;
	static Tile* fenceGateBirch;
	static Tile* fenceGateJungle;
	static Tile* fenceGateBigOak;
	static Tile* fenceGateAcacia;
	static Tile* pumpkin;
	static Tile* hellRock;
	static Tile* hellSand;
	static Tile* lightGem;
	static Tile* portalTile;
	static Tile* litPumpkin;
	static Tile* cake;
	static Tile* diode_off;
	static Tile* diode_on;
	static Tile* trapdoor;
	static Tile* monsterStoneEgg;
	static Tile* stoneBrickSmooth;
	static Tile* melon;
	static Tile* pumpkinStem;
	static Tile* melonStem;
	static Tile* netherReactor;
	static Tile* glowingObsidian;
	static Tile* woodSlab;
	static Tile* woodSlabHalf;
	static Tile* activatorRail;
	static Tile* cobbleWall;
	static Tile* carrots;
	static Tile* potatoes;
	static Tile* beetroot;
	static Tile* woodStairsDark;
	static Tile* woodStairsBirch;
	static Tile* woodStairsJungle;
	static Tile* woodStairsAcacia;
	static Tile* woodStairsBigOak;
	static Tile* hayBlock;
	static Tile* coalBlock;
	static Tile* woolCarpet;
	static Tile* deadBush;
	static Tile* leaves2;
	static Tile* log2;
	static Tile* stairs_stoneBrickSmooth;
	static Tile* netherBrick;
	static Tile* netherrack;
	static Tile* ironFence;
	static Tile* netherFence;
	static Tile* stairs_netherBricks;
	static Tile* stairs_sandStone;
	static Tile* quartzBlock;
	static Tile* stairs_quartz;
	static Tile* endPortalFrame;
	static Tile* mycelium;
	static Tile* brownMushroomBlock;
	static Tile* redMushroomBlock;
	static Tile* stainedClay;
	static Tile* hardenedClay;
	static Tile* vine;
	static Tile* packedIce;
	static Tile* cocoa;
	static Tile* doublePlant;
	static Tile* endStone;
	static Tile* waterlily;
	static Tile* emeraldOre;
	static Tile* emeraldBlock;
	static Tile* offlamp;
	static Tile* onlamp;
	static Tile* redstoneBlock;
	static Tile* invisible_bedrock;
	static Tile* info_updateGame1;
	static Tile* info_updateGame2;
	static Tile* info_reserved6;
};
