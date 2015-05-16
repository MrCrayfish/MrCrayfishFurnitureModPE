#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <substrate.h>
#include <vector>

#include "MCPE/world/level/tile/Tile.h"
#include "MCPE/world/level/tile/LiquidTileDynamic.h"
#include "MCPE/world/material/Material.h"
#include "MCPE/world/item/Item.h"
#include "MCPE/client/renderer/tile/TileTessellator.h"
#include "MCPE/locale/I18n.h"
#include "MCPE/world/entity/Motive.h"

#include "Furniture/render/tile/RenderDispatcher.h"
#include "Furniture/render/tile/renderers/ChairRenderer.h"
#include "Furniture/render/tile/renderers/TableRenderer.h"
#include "Furniture/render/tile/renderers/ToiletRenderer.h"
#include "Furniture/render/tile/renderers/CabinetRenderer.h"
#include "Furniture/render/tile/renderers/DoorbellRenderer.h"
#include "Furniture/render/tile/renderers/BinRenderer.h"
#include "Furniture/render/tile/renderers/LampRenderer.h"
#include "Furniture/world/tile/FurnitureTile.h"
#include "Furniture/world/tile/TableTile.h"
#include "Furniture/world/tile/ChairTile.h"
#include "Furniture/world/tile/ToiletTile.h"
#include "Furniture/world/tile/CabinetTile.h"
#include "Furniture/world/tile/DoorbellTile.h"
#include "Furniture/world/tile/BinTile.h"
#include "Furniture/world/tile/LampTile.h"
#include "Furniture/world/item/FurnitureItem.h"
#include "Furniture/world/item/TableItem.h"
#include "Furniture/world/item/ChairItem.h"
#include "Furniture/world/item/ToiletItem.h"
#include "Furniture/world/item/CabinetItem.h"
#include "Furniture/world/item/DoorbellItem.h"
#include "Furniture/world/item/BinItem.h"
#include "Furniture/world/item/LampItem.h"
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
	RenderDispatcher::registerRenderer(TableTile::_woodId, new TableRenderer());
	RenderDispatcher::registerRenderer(TableTile::_stoneId, new TableRenderer());
	RenderDispatcher::registerRenderer(ChairTile::_woodId, new ChairRenderer());
	RenderDispatcher::registerRenderer(ChairTile::_stoneId, new ChairRenderer());
	RenderDispatcher::registerRenderer(ToiletTile::_id, new ToiletRenderer());
	RenderDispatcher::registerRenderer(CabinetTile::_id, new CabinetRenderer());
	RenderDispatcher::registerRenderer(DoorbellTile::_id, new DoorbellRenderer());
        RenderDispatcher::registerRenderer(BinRenderer::_id, new BinRenderer());
        RenderDispatcher::registerRenderer(LampRenderer::_id, new LampRenderer());
}

static void (*_Tile$initTiles)();
static void Tile$initTiles() {
	_Tile$initTiles();

	FurnitureTileAttributes woodAttributes(&Material::wood, "planks", "log", Tile::SOUND_WOOD, 1.0F);
	FurnitureTileAttributes stoneAttributes(&Material::stone, "stone", "cobblestone", Tile::SOUND_STONE, 1.5F);

	FurnitureTile::tileTableWood = new TableTile(TableTile::_woodId, "woodTableTile", woodAttributes, TableItem::_woodId);
	FurnitureTile::tileTableStone = new TableTile(TableTile::_stoneId, "stoneTableTile", stoneAttributes, TableItem::_stoneId);
	FurnitureTile::tileChairWood = new ChairTile(ChairTile::_woodId, "woodChairTile", woodAttributes, ChairItem::_woodId);
	FurnitureTile::tileChairStone = new ChairTile(ChairTile::_stoneId, "stoneChairTile", stoneAttributes, ChairItem::_stoneId);
	FurnitureTile::tileToilet = new ToiletTile(ToiletTile::_id, &Material::stone);
	FurnitureTile::tileCabinet = new CabinetTile(CabinetTile::_id, &Material::wood);
	FurnitureTile::tileDoorbell = new DoorbellTile(DoorbellTile::_id, &Material::wood);
        FurnitureTile::tileBin = new BinTile(BinTile::_id, &Material::metal);
        FurnitureTile::tileLamp = new LampTile(LampTile::_id, &Material::stone);
    
	initRenderers();
}

static void (*_Item$initItems)();
static void Item$initItems() {
	FurnitureItem::itemTableWood = new TableItem(TableItem::_woodId, "woodTableItem", ItemMaterial::WOOD, TableTile::_woodId);
	FurnitureItem::itemTableStone = new TableItem(TableItem::_stoneId, "stoneTableItem", ItemMaterial::STONE, TableTile::_stoneId);
	FurnitureItem::itemChairWood = new ChairItem(ChairItem::_woodId, "woodChairItem", ItemMaterial::WOOD, ChairTile::_woodId);
	FurnitureItem::itemChairStone = new ChairItem(ChairItem::_stoneId, "stoneChairItem", ItemMaterial::STONE, ChairTile::_stoneId);
	FurnitureItem::itemToilet = new ToiletItem(ToiletItem::_id);
	FurnitureItem::itemCabinet = new CabinetItem(CabinetItem::_id);
	FurnitureItem::itemDoorbell = new DoorbellItem(DoorbellItem::_id);
        FurnitureItem::itemBin = new BinItem(LampItem::_id);
        FurnitureItem::itemLamp = new LampItem(LampItem::_id);

	_Item$initItems();
}

static void (*_Item$initCreativeItems)();
static void Item$initCreativeItems() {
	_Item$initCreativeItems();

	Item::addCreativeItem(FurnitureItem::itemTableWood, 0);
	Item::addCreativeItem(FurnitureItem::itemTableStone, 0);
	Item::addCreativeItem(FurnitureItem::itemChairWood, 0);
	Item::addCreativeItem(FurnitureItem::itemChairStone, 0);
	Item::addCreativeItem(FurnitureItem::itemToilet, 0);
	Item::addCreativeItem(FurnitureItem::itemCabinet, 0);
	Item::addCreativeItem(FurnitureItem::itemDoorbell, 0);
        Item::addCreativeItem(FurnitureItem::itemBin, 0);
        Item::addCreativeItem(FurnitureItem::itemLamp, 0);
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
	if(key == "item.lampItem.name") return "Lamp";
        if(key == "item.binItem.name") return "Bin";
	
	return _I18n$get(key, a);
}

static bool (*_LiquidTileDynamic$_isWaterBlocking)(LiquidTileDynamic*, TileSource*, const TilePos&);
static bool LiquidTileDynamic$_isWaterBlocking(LiquidTileDynamic* self, TileSource* region, const TilePos& pos) {
	Tile* tile = region->getTilePtr(pos.x, pos.y, pos.z);
	if(tile == FurnitureTile::tileTableWood ||
     	tile == FurnitureTile::tileTableStone ||
		tile == FurnitureTile::tileChairWood ||
		tile == FurnitureTile::tileChairStone ||
		tile == FurnitureTile::tileToilet ||
		tile == FurnitureTile::tileCabinet ||
		tile == FurnitureTile::tileDoorbell ||
             tile == FurnitureTile::tileBin ||
             tile == FurnitureTile::tileLamp)
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
