#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <substrate.h>

class Tessellator;
#include "MCPE/world/level/Level.h"
#include "MCPE/world/level/tile/Tile.h"
#include "MCPE/world/material/Material.h"
#include "MCPE/client/renderer/tile/TileTessellator.h"
#include "MCPE/client/gui/screens/touch/StartMenuScreen.h"
#include "MCPE/SharedConstants.h"

#include "Furniture/render/tile/FurnitureRenderer.h"
#include "Furniture/world/tile/item/FurnitureTileItems.h"

#include "Furniture/world/tile/TileTable.h"
#include "Furniture/world/tile/TileChair.h"
#include "Furniture/world/tile/TileCabinet.h"
#include "Furniture/world/tile/TileDoorbell.h"

#include "Furniture/world/item/TableItem.h"
#include "Furniture/world/item/ChairItem.h"
#include "Furniture/world/item/ItemCabinet.h"
#include "Furniture/world/item/ItemDoorbell.h"

#include "MCPE/language/I18n.h"

#define LOG_TAG "furniturepe"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

static void (*_TileTessellator$tessellateInWorld)(TileTessellator*, Tile*, const TilePos&, bool);
static void TileTessellator$tessellateInWorld(TileTessellator* self, Tile* tile, const TilePos& pos, bool sth) {
    if(tile->renderType >= 100) FurnitureRenderer::render(self, self->region, tile, pos);
    _TileTessellator$tessellateInWorld(self, tile, pos, sth);
}

static void (*_StartMenuScreen$render)(Touch::StartMenuScreen*, int, int, float);
static void StartMenuScreen$render(Touch::StartMenuScreen* self, int x, int y, float scale) {
    _StartMenuScreen$render(self, x, y, scale);
    self->_screenRenderer.drawString(self->_minecraftClient->_font, "MrCrayfish's Furniture Mod", 1, 1, Color::WHITE);
}

void initTileItems() {
    FurnitureTileItems::tileItemTableWood = new FurnitureTileItems(TileTable::_woodId);
    FurnitureTileItems::tileItemTableStone = new FurnitureTileItems(TileTable::_stoneId);
    FurnitureTileItems::tileItemChairWood = new FurnitureTileItems(TileChair::_woodId);
    FurnitureTileItems::tileItemChairStone = new FurnitureTileItems(TileChair::_stoneId);
    FurnitureTileItems::tileItemCabinet = new FurnitureTileItems(TileCabinet::_id);
    FurnitureTileItems::tileItemDoorbell = new FurnitureTileItems(TileDoorbell::_id);
}

static void (*_Tile$initTiles)();
static void Tile$initTiles() {
    _Tile$initTiles();

    FurnitureTiles::tileTableWood = new TileTable(TileTable::_woodId, &Material::wood);
    FurnitureTiles::tileTableStone = new TileTable(TileTable::_stoneId, &Material::stone);
    FurnitureTiles::tileChairWood = new TileChair(TileChair::_woodId, &Material::wood);
    FurnitureTiles::tileChairStone = new TileChair(TileChair::_stoneId, &Material::stone);
    FurnitureTiles::tileDoorbell = new TileDoorbell(TileDoorbell::_id, &Material::wood);
	FurnitureEntityTiles::entityTileCabinet = new TileCabinet(TileCabinet::_id, &Material::wood);
    initTileItems();
}

static void (*_Item$initItems)();
static void Item$initItems() {
    FurnitureItems::itemTableWood = new TableItem(TableItem::_woodId, "itemTableWood", true);
    FurnitureItems::itemTableStone = new TableItem(TableItem::_stoneId, "itemTableStone", false);
    FurnitureItems::itemChairWood = new ChairItem(ChairItem::_woodId, "itemChairWood", true);
    FurnitureItems::itemChairStone = new ChairItem(ChairItem::_stoneId, "itemChairStone", false);
    FurnitureItems::itemCabinet = new ItemCabinet(ItemCabinet::_id, "itemCabinet");
    FurnitureItems::itemDoorbell = new ItemDoorbell(ItemDoorbell::_id, "itemDoorbell");
	
    _Item$initItems();
}

static void (*_Item$initCreativeItems)();
static void Item$initCreativeItems() {
    _Item$initCreativeItems();

    Item::addCreativeItem(FurnitureItems::itemTableWood, 0);
    Item::addCreativeItem(FurnitureItems::itemTableStone, 0);
    Item::addCreativeItem(FurnitureItems::itemChairWood, 0);
    Item::addCreativeItem(FurnitureItems::itemChairStone, 0);
	Item::addCreativeItem(FurnitureItems::itemCabinet, 0);
	Item::addCreativeItem(FurnitureItems::itemDoorbell, 0);
}

static std::string (*_I18n$get)(std::string const&, std::vector<std::string,std::allocator<std::string>> const&);

static std::string I18n$get(std::string const& key, std::vector<std::string,std::allocator<std::string>> const& a) {
	if(key == "item.itemTableWood.name") return "Wooden Table";
	if(key == "item.itemTableStone.name") return "Stone Table";
	if(key == "item.itemChairWood.name") return "Wooden Chair";
	if(key == "item.itemChairStone.name") return "Stone Chair";
	if(key == "item.itemCabinet.name") return "Cabinet";
	if(key == "item.itemDoorbell.name") return "Doorbell";
	if(key == "item.itemBedsideCabinet.name") return "Bedside Cabinet";

	return _I18n$get(key, a);
}

static TileEntity* (*_TileEntityFactory$createTileEntity)(TileEntityType, const TilePos&);
static TileEntity* TileEntityFactory$createTileEntity(TileEntityType type, const TilePos& pos) {
	if(type == TileEntityType::CABINET) return new CabinetTileEntity(pos);
	
	return _TileEntityFactory$createTileEntity(type, pos);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	FurnitureItems::registerTextures();

	void* tileEntityFactory$createTileEntity = dlsym(RTLD_DEFAULT, "_ZN17TileEntityFactory16createTileEntityE14TileEntityTypeRK7TilePos");
	
	MSHookFunction((void*) &TileTessellator::tessellateInWorld, (void*) &TileTessellator$tessellateInWorld, (void**) &_TileTessellator$tessellateInWorld);
	MSHookFunction((void*) &Touch::StartMenuScreen::render, (void*) &StartMenuScreen$render, (void**) &_StartMenuScreen$render);
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);
	MSHookFunction((void*) &Tile::initTiles, (void*) &Tile$initTiles, (void**) &_Tile$initTiles);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &I18n::get, (void*) &I18n$get, (void**) &_I18n$get);
	MSHookFunction((void*)&TileEntity::initTileEntities, (void*)&TileEntity$initTileEntities, (void**)&_TileEntity$initEntities);
    MSHookFunction(tileEntityFactory$createTileEntity, (void*)&TileEntityFactory$createTileEntity, (void**)&_TileEntityFactory$createTileEntity);

	return JNI_VERSION_1_2;
}
