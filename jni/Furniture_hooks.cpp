#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <substrate.h>

class Tessellator;
#include "MCPE/world/level/tile/Tile.h"
#include "MCPE/world/material/Material.h"
#include "MCPE/client/renderer/tile/TileTessellator.h"
#include "MCPE/client/gui/screens/touch/StartMenuScreen.h"
#include "MCPE/SharedConstants.h"

#include "Furniture/render/tile/FurnitureRenderer.h"
#include "Furniture/world/tile/item/FurnitureTileItems.h"

#include "Furniture/world/tile/TableTile.h"
#include "Furniture/world/tile/ChairTile.h"
#include "Furniture/world/tile/CabinetTile.h"

#include "Furniture/world/item/TableItem.h"
#include "Furniture/world/item/ChairItem.h"
#include "Furniture/world/item/CabinetItem.h"

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
    FurnitureTileItems::tileItemTableWood = new FurnitureTileItems(WoodenTableTile::_id);
    FurnitureTileItems::tileItemTableStone = new FurnitureTileItems(StoneTableTile::_id);
    FurnitureTileItems::tileItemChairWood = new FurnitureTileItems(ChairTile::_woodId);
    FurnitureTileItems::tileItemChairStone = new FurnitureTileItems(ChairTile::_stoneId);

FurnitureTileItems::tileItemCabinet = new FurnitureTileItems(CabinetTile::_id);
}

static void (*_Tile$initTiles)();
static void Tile$initTiles() {
    _Tile$initTiles();

    FurnitureTiles::tileTableWood = new WoodenTableTile(WoodenTableTile::_id);
    FurnitureTiles::tileTableStone = new StoneTableTile(StoneTableTile::_id);
    FurnitureTiles::tileChairWood = new ChairTile(ChairTile::_woodId, &Material::wood);
    FurnitureTiles::tileChairStone = new ChairTile(ChairTile::_stoneId, &Material::stone);
FurnitureTiles::tileCabinet = new CabinetTile(CabinetTile::_id, &Material::wood);

    initTileItems();
}

static void (*_Item$initItems)();
static void Item$initItems() {
    FurnitureItems::itemTableWood = new TableItem(TableItem::_woodId, "itemTableWood", true);
    FurnitureItems::itemTableStone = new TableItem(TableItem::_stoneId, "itemTableStone", false);
    FurnitureItems::itemChairWood = new ChairItem(ChairItem::_woodId, "itemChairWood", true);
    FurnitureItems::itemChairStone = new ChairItem(ChairItem::_stoneId, "itemChairStone", false);
FurnitureItems::itemCabinet = new CabinetItem(CabinetItem::_id, "itemCabinet");
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
}



JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	FurnitureItems::registerTextures();
	
	MSHookFunction((void*) &TileTessellator::tessellateInWorld, (void*) &TileTessellator$tessellateInWorld, (void**) &_TileTessellator$tessellateInWorld);
	MSHookFunction((void*) &Touch::StartMenuScreen::render, (void*) &StartMenuScreen$render, (void**) &_StartMenuScreen$render);
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);
	MSHookFunction((void*) &Tile::initTiles, (void*) &Tile$initTiles, (void**) &_Tile$initTiles);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);


	return JNI_VERSION_1_2;
}
