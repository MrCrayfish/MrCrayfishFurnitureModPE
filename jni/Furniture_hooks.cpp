#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <substrate.h>
#include <vector>

#define  LOG_TAG    "FurnitureMod-MCPE" 
#define  ALOG(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

#include "MCPE/world/level/tile/Tile.h"
#include "MCPE/world/level/tile/LiquidTileDynamic.h"
#include "MCPE/world/material/Material.h"
#include "MCPE/world/item/Item.h"
#include "MCPE/client/renderer/tile/TileTessellator.h"
#include "MCPE/locale/I18n.h"
#include "MCPE/world/entity/Motive.h"

/* Renders */
#include "Furniture/render/tile/RenderDispatcher.h"
#include "Furniture/render/tile/renderers/ChairRenderer.h"
#include "Furniture/render/tile/renderers/TableRenderer.h"
#include "Furniture/render/tile/renderers/CoffeeTableRenderer.h"
#include "Furniture/render/tile/renderers/ToiletRenderer.h"
#include "Furniture/render/tile/renderers/CabinetRenderer.h"
#include "Furniture/render/tile/renderers/DoorbellRenderer.h"
#include "Furniture/render/tile/renderers/BinRenderer.h"
#include "Furniture/render/tile/renderers/LampRenderer.h"
#include "Furniture/render/tile/renderers/ChoppingBoardRenderer.h"
#include "Furniture/render/tile/renderers/ToasterRenderer.h"
#include "Furniture/render/tile/renderers/MicrowaveRenderer.h"
#include "Furniture/render/tile/renderers/BarStoolRenderer.h"
#include "Furniture/render/tile/renderers/CounterRenderer.h"
#include "Furniture/render/tile/renderers/CookieJarRenderer.h"
#include "Furniture/render/tile/renderers/OvenRenderer.h"

/* Tiles */
#include "Furniture/world/tile/FurnitureTile.h"
#include "Furniture/world/tile/TableTile.h"
#include "Furniture/world/tile/CoffeeTableTile.h"
#include "Furniture/world/tile/ChairTile.h"
#include "Furniture/world/tile/ToiletTile.h"
#include "Furniture/world/tile/CabinetTile.h"
#include "Furniture/world/tile/KitchenCabinetTile.h"
#include "Furniture/world/tile/DoorbellTile.h"
#include "Furniture/world/tile/BinTile.h"
#include "Furniture/world/tile/LampTile.h"
#include "Furniture/world/tile/ChoppingBoardTile.h"
#include "Furniture/world/tile/ToasterTile.h"
#include "Furniture/world/tile/MicrowaveTile.h"
#include "Furniture/world/tile/BarStoolTile.h"
#include "Furniture/world/tile/CounterTile.h"
#include "Furniture/world/tile/CookieJarTile.h"
#include "Furniture/world/tile/OvenTile.h"

/* Items */
#include "Furniture/world/item/FurnitureItem.h"
#include "Furniture/world/item/TableItem.h"
#include "Furniture/world/item/CoffeeTableItem.h"
#include "Furniture/world/item/ChairItem.h"
#include "Furniture/world/item/ToiletItem.h"
#include "Furniture/world/item/CabinetItem.h"
#include "Furniture/world/item/KitchenCabinetItem.h"
#include "Furniture/world/item/DoorbellItem.h"
#include "Furniture/world/item/BinItem.h"
#include "Furniture/world/item/LampItem.h"
#include "Furniture/world/item/ChoppingBoardItem.h"
#include "Furniture/world/item/ToasterItem.h"
#include "Furniture/world/item/MicrowaveItem.h"
#include "Furniture/world/item/KnifeItem.h"
#include "Furniture/world/item/BarStoolItem.h"
#include "Furniture/world/item/CounterItem.h"
#include "Furniture/world/item/CookieJarItem.h"
#include "Furniture/world/item/OvenItem.h"

#include "Furniture/world/item/material/ItemMaterial.h"
#include "Furniture/world/tile/attributes/FurnitureTileAttributes.h"


void initMod() {
	Motive::initCustomMotives();
}

static void (*_TileTessellator$tessellateInWorld)(TileTessellator*, Tile*, const TilePos&, bool);
static void TileTessellator$tessellateInWorld(TileTessellator* self, Tile* tile, const TilePos& pos, bool b) {
	if(!RenderDispatcher::dispatch(tile->id, pos, tile, self))
		_TileTessellator$tessellateInWorld(self, tile, pos, b);
}

void initRenderers() {
	ALOG("Loading Renders");
	RenderDispatcher::registerRenderer(TableTile::_woodId, new TableRenderer());
	RenderDispatcher::registerRenderer(TableTile::_stoneId, new TableRenderer());
	RenderDispatcher::registerRenderer(CoffeeTableTile::_woodId, new CoffeeTableRenderer());
	RenderDispatcher::registerRenderer(CoffeeTableTile::_stoneId, new CoffeeTableRenderer());
	RenderDispatcher::registerRenderer(ChairTile::_woodId, new ChairRenderer());
	RenderDispatcher::registerRenderer(ChairTile::_stoneId, new ChairRenderer());
	RenderDispatcher::registerRenderer(ToiletTile::_id, new ToiletRenderer());
	RenderDispatcher::registerRenderer(CabinetTile::_id, new CabinetRenderer());
	RenderDispatcher::registerRenderer(KitchenCabinetTile::_id, new CabinetRenderer());
	RenderDispatcher::registerRenderer(DoorbellTile::_id, new DoorbellRenderer());
	RenderDispatcher::registerRenderer(BinTile::_id, new BinRenderer());
	RenderDispatcher::registerRenderer(LampTile::_id, new LampRenderer());
	RenderDispatcher::registerRenderer(ChoppingBoardTile::_id, new ChoppingBoardRenderer());
	RenderDispatcher::registerRenderer(ToasterTile::_id, new ToasterRenderer());
	RenderDispatcher::registerRenderer(MicrowaveTile::_id, new MicrowaveRenderer());
	RenderDispatcher::registerRenderer(BarStoolTile::_id, new BarStoolRenderer());
	RenderDispatcher::registerRenderer(CounterTile::_id, new CounterRenderer());
	RenderDispatcher::registerRenderer(CookieJarTile::_id, new CookieJarRenderer());
	RenderDispatcher::registerRenderer(OvenTile::_id, new OvenRenderer());
	ALOG("Finished Loading Renders");
}

static void (*_Tile$initTiles)();
static void Tile$initTiles() {
	_Tile$initTiles();

	FurnitureTileAttributes woodAttributes(&Material::wood, "planks", "log", Tile::SOUND_WOOD, 1.0F);
	FurnitureTileAttributes stoneAttributes(&Material::stone, "stone", "cobblestone", Tile::SOUND_STONE, 1.5F);

	ALOG("Loading Tiles");
	FurnitureTile::tileTableWood = new TableTile(TableTile::_woodId, "woodTableTile", woodAttributes, TableItem::_woodId);
	FurnitureTile::tileTableStone = new TableTile(TableTile::_stoneId, "stoneTableTile", stoneAttributes, TableItem::_stoneId);
	FurnitureTile::tileCoffeeTableWood = new CoffeeTableTile(CoffeeTableTile::_woodId, "woodCoffeeTableTile", woodAttributes, CoffeeTableItem::_woodId);
	FurnitureTile::tileCoffeeTableStone = new CoffeeTableTile(CoffeeTableTile::_stoneId, "stoneCoffeeTableTile", stoneAttributes, CoffeeTableItem::_stoneId);
	FurnitureTile::tileChairWood = new ChairTile(ChairTile::_woodId, "woodChairTile", woodAttributes, ChairItem::_woodId);
	FurnitureTile::tileChairStone = new ChairTile(ChairTile::_stoneId, "stoneChairTile", stoneAttributes, ChairItem::_stoneId);
	FurnitureTile::tileToilet = new ToiletTile(ToiletTile::_id, &Material::stone);
	FurnitureTile::tileCabinet = new CabinetTile(CabinetTile::_id, &Material::wood);
	FurnitureTile::tileKitchenCabinet = new KitchenCabinetTile(KitchenCabinetTile::_id, &Material::stone);
	FurnitureTile::tileDoorbell = new DoorbellTile(DoorbellTile::_id, &Material::wood);
	FurnitureTile::tileBin = new BinTile(BinTile::_id, &Material::metal); 
	FurnitureTile::tileLamp = new LampTile(LampTile::_id, &Material::stone);
	FurnitureTile::tileChoppingBoard = new ChoppingBoardTile(ChoppingBoardTile::_id, &Material::wood);
	FurnitureTile::tileToaster = new ToasterTile(ToasterTile::_id, &Material::metal); 
	FurnitureTile::tileMicrowave = new MicrowaveTile(MicrowaveTile::_id, &Material::metal);
	FurnitureTile::tileBarStool = new BarStoolTile(BarStoolTile::_id, &Material::stone);
	FurnitureTile::tileCounter = new CounterTile(CounterTile::_id, &Material::stone);
	FurnitureTile::tileCookieJar = new CookieJarTile(CookieJarTile::_id, &Material::glass);
	FurnitureTile::tileOven = new OvenTile(OvenTile::_id, &Material::stone);
	ALOG("Finished Loading Tiles");

	initRenderers();
}

static void (*_Item$initItems)();
static void Item$initItems() {
	ALOG("Loading Items");
	FurnitureItem::itemTableWood = new TableItem(TableItem::_woodId, "woodTableItem", ItemMaterial::WOOD, TableTile::_woodId);
	FurnitureItem::itemTableStone = new TableItem(TableItem::_stoneId, "stoneTableItem", ItemMaterial::STONE, TableTile::_stoneId);
	FurnitureItem::itemCoffeeTableWood = new CoffeeTableItem(CoffeeTableItem::_woodId, "woodCoffeeTableItem", ItemMaterial::WOOD, CoffeeTableTile::_woodId);
	FurnitureItem::itemCoffeeTableStone = new CoffeeTableItem(CoffeeTableItem::_stoneId, "stoneCoffeeTableItem", ItemMaterial::STONE, CoffeeTableTile::_stoneId);
	FurnitureItem::itemChairWood = new ChairItem(ChairItem::_woodId, "woodChairItem", ItemMaterial::WOOD, ChairTile::_woodId);
	FurnitureItem::itemChairStone = new ChairItem(ChairItem::_stoneId, "stoneChairItem", ItemMaterial::STONE, ChairTile::_stoneId);
	FurnitureItem::itemToilet = new ToiletItem(ToiletItem::_id);
	FurnitureItem::itemCabinet = new CabinetItem(CabinetItem::_id);
	FurnitureItem::itemKitchenCabinet = new KitchenCabinetItem(KitchenCabinetItem::_id);
	FurnitureItem::itemDoorbell = new DoorbellItem(DoorbellItem::_id);
	FurnitureItem::itemBin = new BinItem(BinItem::_id);
	FurnitureItem::itemLamp = new LampItem(LampItem::_id);
	FurnitureItem::itemChoppingBoard = new ChoppingBoardItem(ChoppingBoardItem::_id);
	FurnitureItem::itemToaster = new ToasterItem(ToasterItem::_id);
	FurnitureItem::itemMicrowave = new MicrowaveItem(MicrowaveItem::_id);
	FurnitureItem::itemKnife = new KnifeItem(KnifeItem::_id);
	FurnitureItem::itemBarStool = new BarStoolItem(BarStoolItem::_id);
	FurnitureItem::itemCounter = new CounterItem(CounterItem::_id);
	FurnitureItem::itemCookieJar = new CookieJarItem(CookieJarItem::_id);
	FurnitureItem::itemOven = new OvenItem(OvenItem::_id);
	ALOG("Finished Loading Items");

	_Item$initItems();
}

static void (*_Item$initCreativeItems)();
static void Item$initCreativeItems() {
	_Item$initCreativeItems();

	ALOG("Adding Creative Items");
	Item::addCreativeItem(FurnitureItem::itemTableWood, 0);
	Item::addCreativeItem(FurnitureItem::itemTableStone, 0);
	Item::addCreativeItem(FurnitureItem::itemCoffeeTableWood, 0);
	Item::addCreativeItem(FurnitureItem::itemCoffeeTableStone, 0);
	Item::addCreativeItem(FurnitureItem::itemChairWood, 0);
	Item::addCreativeItem(FurnitureItem::itemChairStone, 0);
	Item::addCreativeItem(FurnitureItem::itemToilet, 0);
	Item::addCreativeItem(FurnitureItem::itemCabinet, 0);
	Item::addCreativeItem(FurnitureItem::itemKitchenCabinet, 0);
	Item::addCreativeItem(FurnitureItem::itemDoorbell, 0);
	Item::addCreativeItem(FurnitureItem::itemBin, 0);
	Item::addCreativeItem(FurnitureItem::itemLamp, 0);
	Item::addCreativeItem(FurnitureItem::itemChoppingBoard, 0);
	Item::addCreativeItem(FurnitureItem::itemToaster, 0);
	Item::addCreativeItem(FurnitureItem::itemMicrowave, 0);
	Item::addCreativeItem(FurnitureItem::itemKnife, 0);
	Item::addCreativeItem(FurnitureItem::itemBarStool, 0);
	Item::addCreativeItem(FurnitureItem::itemCounter, 0);
	Item::addCreativeItem(FurnitureItem::itemCookieJar, 0);
	Item::addCreativeItem(FurnitureItem::itemOven, 0);
	ALOG("Finished Adding Creative Items");
}

static std::string (*_I18n$get)(std::string const&, std::vector<std::string, std::allocator<std::string>> const&);
static std::string I18n$get(std::string const& key, std::vector<std::string, std::allocator<std::string>> const& a) {
	if(key == "item.woodTableItem.name") return "Wooden Table";
	if(key == "item.stoneTableItem.name") return "Stone Table";
	if(key == "item.woodCoffeeTableItem.name") return "Wooden Coffee Table";
	if(key == "item.stoneCoffeeTableItem.name") return "Stone Coffee Table";
	if(key == "item.woodChairItem.name") return "Wooden Chair";
	if(key == "item.stoneChairItem.name") return "Stone Chair";
	if(key == "item.toiletItem.name") return "Toilet";
	if(key == "item.bathItem.name") return "Bath";
	if(key == "item.showerItem.name") return "Shower";
	if(key == "item.showerHeadItem.name") return "Shower Head";
	if(key == "item.cabinetItem.name") return "Cabinet";
	if(key == "item.doorbellItem.name") return "Doorbell";
	if(key == "item.bedsideCabinetItem.name") return "Bedside Cabinet";
	if(key == "item.tvItem.name") return "TV";
	if(key == "item.fridgeItem.name") return "Fridge";
	if(key == "item.ovenItem.name") return "Oven";
	if(key == "item.blenderItem.name") return "Blender";
	if(key == "item.choppingBoardItem.name") return "Chopping Board";
	if(key == "item.toasterItem.name") return "Toaster";
	if(key == "item.microwaveItem.name") return "Microwave";
	if(key == "item.counterItem.name") return "Counter";
	if(key == "item.sinkCounterItem.name") return "Counter (Sink)";
	if(key == "item.lampItem.name") return "Lamp";
	if(key == "item.binItem.name") return "Bin";
	if(key == "item.barStoolItem.name") return "Bar Stool";
	if(key == "item.dishwasherItem.name") return "Dishwasher";
	if(key == "item.basinItem.name") return "Basin";
	if(key == "item.cupItem.name") return "Cup";
	if(key == "item.knifeItem.name") return "Knife";
	if(key == "item.cookieJarItem.name") return "Cookie Jar";
	if(key == "item.ovenItem.name") return "Oven";
	
	return _I18n$get(key, a);
}

static bool (*_LiquidTileDynamic$_isWaterBlocking)(LiquidTileDynamic*, TileSource*, const TilePos&);
static bool LiquidTileDynamic$_isWaterBlocking(LiquidTileDynamic* self, TileSource* region, const TilePos& pos) {
	Tile* tile = region->getTilePtr(pos.x, pos.y, pos.z);
	if(tile == FurnitureTile::tileTableWood ||
     	tile == FurnitureTile::tileTableStone ||
		tile == FurnitureTile::tileCoffeeTableWood ||
     	tile == FurnitureTile::tileCoffeeTableStone ||
		tile == FurnitureTile::tileChairWood ||
		tile == FurnitureTile::tileChairStone ||
		tile == FurnitureTile::tileToilet ||
		tile == FurnitureTile::tileCabinet ||
		tile == FurnitureTile::tileDoorbell ||
		tile == FurnitureTile::tileBin ||
		tile == FurnitureTile::tileLamp ||
		tile == FurnitureTile::tileChoppingBoard ||
		tile == FurnitureTile::tileToaster ||
		tile == FurnitureTile::tileMicrowave ||
		tile == FurnitureTile::tileCookieJar ||
		tile == FurnitureTile::tileOven ||
		tile == FurnitureTile::tileCounter)
			return true;
	
	return _LiquidTileDynamic$_isWaterBlocking(self, region, pos);
}

static std::vector<const Motive*> (*_Motive$getAllMotivesAsList)();
static std::vector<const Motive*> Motive$getAllMotivesAsList() {
	std::vector<const Motive*> retval = _Motive$getAllMotivesAsList();
	retval.push_back(Motive::Furniture);
	return retval;
}


JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	initMod();

	MSHookFunction((void*) &TileTessellator::tessellateInWorld, (void*) &TileTessellator$tessellateInWorld, (void**) &_TileTessellator$tessellateInWorld);
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);
	MSHookFunction((void*) &Tile::initTiles, (void*) &Tile$initTiles, (void**) &_Tile$initTiles);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &I18n::get, (void*) &I18n$get, (void**) &_I18n$get);
	MSHookFunction((void*) &LiquidTileDynamic::_isWaterBlocking, (void*) &LiquidTileDynamic$_isWaterBlocking, (void**) &_LiquidTileDynamic$_isWaterBlocking);
	MSHookFunction((void*) &Motive::getAllMotivesAsList, (void*) &Motive$getAllMotivesAsList, (void**) &_Motive$getAllMotivesAsList);

	return JNI_VERSION_1_2;
}
