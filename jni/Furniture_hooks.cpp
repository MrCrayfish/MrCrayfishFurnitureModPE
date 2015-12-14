#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <substrate.h>
#include <vector>

#define  LOG_TAG    "FurnitureMod-MCPE" 
#define  ALOG(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

#include "MCPE/world/level/block/Block.h"
#include "MCPE/world/level/block/LiquidBlockDynamic.h"
#include "MCPE/world/material/Material.h"
#include "MCPE/world/item/Item.h"
#include "MCPE/client/renderer/block/BlockTessellator.h"
#include "MCPE/locale/I18n.h"
#include "MCPE/world/entity/Motive.h"

/* Renders */
#include "Furniture/render/block/RenderDispatcher.h"
#include "Furniture/render/block/renderers/ChairRenderer.h"
#include "Furniture/render/block/renderers/TableRenderer.h"
#include "Furniture/render/block/renderers/CoffeeTableRenderer.h"
#include "Furniture/render/block/renderers/ToiletRenderer.h"
#include "Furniture/render/block/renderers/CabinetRenderer.h"
#include "Furniture/render/block/renderers/DoorbellRenderer.h"
#include "Furniture/render/block/renderers/BinRenderer.h"
#include "Furniture/render/block/renderers/LampRenderer.h"
#include "Furniture/render/block/renderers/ChoppingBoardRenderer.h"
#include "Furniture/render/block/renderers/ToasterRenderer.h"
#include "Furniture/render/block/renderers/MicrowaveRenderer.h"
#include "Furniture/render/block/renderers/BarStoolRenderer.h"
#include "Furniture/render/block/renderers/CounterRenderer.h"
#include "Furniture/render/block/renderers/CookieJarRenderer.h"
#include "Furniture/render/block/renderers/OvenRenderer.h"
#include "Furniture/render/block/renderers/PlateRenderer.h"
#include "Furniture/render/block/renderers/TvRenderer.h"
#include "Furniture/render/block/renderers/PrinterRenderer.h"
#include "Furniture/render/block/renderers/ComputerRenderer.h"

/* Blocks */
#include "Furniture/world/block/FurnitureBlock.h"
#include "Furniture/world/block/TableBlock.h"
#include "Furniture/world/block/CoffeeTableBlock.h"
#include "Furniture/world/block/ChairBlock.h"
#include "Furniture/world/block/ToiletBlock.h"
#include "Furniture/world/block/CabinetBlock.h"
#include "Furniture/world/block/KitchenCabinetBlock.h"
#include "Furniture/world/block/DoorbellBlock.h"
#include "Furniture/world/block/BinBlock.h"
#include "Furniture/world/block/LampBlock.h"
#include "Furniture/world/block/ChoppingBoardBlock.h"
#include "Furniture/world/block/ToasterBlock.h"
#include "Furniture/world/block/MicrowaveBlock.h"
#include "Furniture/world/block/BarStoolBlock.h"
#include "Furniture/world/block/CounterBlock.h"
#include "Furniture/world/block/CookieJarBlock.h"
#include "Furniture/world/block/OvenBlock.h"
#include "Furniture/world/block/PlateBlock.h"
#include "Furniture/world/block/TvBlock.h"
#include "Furniture/world/block/PrinterBlock.h"
#include "Furniture/world/block/ComputerBlock.h"

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
#include "Furniture/world/item/PlateItem.h"
#include "Furniture/world/item/TvItem.h"
#include "Furniture/world/item/PrinterItem.h"
#include "Furniture/world/item/ComputerItem.h"

#include "Furniture/world/item/material/ItemMaterial.h"
#include "Furniture/world/block/attributes/FurnitureBlockAttributes.h"

void initMod() {
	Motive::initCustomMotives();
}

static void (*_BlockTessellator$tessellateInWorld)(BlockTessellator*, Block&, const BlockPos&, unsigned char, bool);
static void BlockTessellator$tessellateInWorld(BlockTessellator* self, Block& tile, const BlockPos& pos, unsigned char c, bool b) {
	if(!RenderDispatcher::dispatch(tile.id, pos, tile, self))
		_BlockTessellator$tessellateInWorld(self, tile, pos, c, b);
}

void initRenderers() {
	ALOG("Loading Renders");
	RenderDispatcher::registerRenderer(TableBlock::_woodId, new TableRenderer());
	RenderDispatcher::registerRenderer(TableBlock::_stoneId, new TableRenderer());
	RenderDispatcher::registerRenderer(CoffeeTableBlock::_woodId, new CoffeeTableRenderer());
	RenderDispatcher::registerRenderer(CoffeeTableBlock::_stoneId, new CoffeeTableRenderer());
	RenderDispatcher::registerRenderer(ChairBlock::_woodId, new ChairRenderer());
	RenderDispatcher::registerRenderer(ChairBlock::_stoneId, new ChairRenderer());
	RenderDispatcher::registerRenderer(ToiletBlock::_id, new ToiletRenderer());
	RenderDispatcher::registerRenderer(CabinetBlock::_id, new CabinetRenderer());
	RenderDispatcher::registerRenderer(KitchenCabinetBlock::_id, new CabinetRenderer());
	RenderDispatcher::registerRenderer(DoorbellBlock::_id, new DoorbellRenderer());
	RenderDispatcher::registerRenderer(BinBlock::_id, new BinRenderer());
	RenderDispatcher::registerRenderer(LampBlock::_id, new LampRenderer());
	RenderDispatcher::registerRenderer(ChoppingBoardBlock::_id, new ChoppingBoardRenderer());
	RenderDispatcher::registerRenderer(ToasterBlock::_id, new ToasterRenderer());
	RenderDispatcher::registerRenderer(MicrowaveBlock::_id, new MicrowaveRenderer());
	RenderDispatcher::registerRenderer(BarStoolBlock::_id, new BarStoolRenderer());
	RenderDispatcher::registerRenderer(CounterBlock::_id, new CounterRenderer());
	RenderDispatcher::registerRenderer(CookieJarBlock::_id, new CookieJarRenderer());
	RenderDispatcher::registerRenderer(OvenBlock::_id, new OvenRenderer());
	RenderDispatcher::registerRenderer(PlateBlock::_id, new PlateRenderer());
     RenderDispatcher::registerRenderer(TvBlock::_id, new TvRenderer());
     RenderDispatcher::registerRenderer(PrinterBlock::_id, new PrinterRenderer());
     RenderDispatcher::registerRenderer(ComputerBlock::_id, new ComputerRenderer());
	ALOG("Finished Loading Renders");
}

static void (*_Block$initBlocks)();
static void Block$initBlocks() {
	_Block$initBlocks();
	
	FurnitureBlockAttributes woodAttributes(Material::getMaterial(MaterialType::WOOD), "planks", "log", Block::SOUND_WOOD, 1.0F);
	FurnitureBlockAttributes stoneAttributes(Material::getMaterial(MaterialType::STONE), "stone", "cobblestone", Block::SOUND_STONE, 1.5F);
	
	ALOG("Loading Block");
	FurnitureBlock::blockTableWood = new TableBlock(TableBlock::_woodId, "woodTableBlock", woodAttributes, TableBlock::_woodId);
	ALOG("Loaded first block");
	FurnitureBlock::blockTableStone = new TableBlock(TableBlock::_stoneId, "stoneTableBlock", stoneAttributes, TableItem::_stoneId);
	FurnitureBlock::blockCoffeeTableWood = new CoffeeTableBlock(CoffeeTableBlock::_woodId, "woodCoffeeTableBlock", woodAttributes, CoffeeTableItem::_woodId);
	FurnitureBlock::blockCoffeeTableStone = new CoffeeTableBlock(CoffeeTableBlock::_stoneId, "stoneCoffeeTableBlock", stoneAttributes, CoffeeTableItem::_stoneId);
	FurnitureBlock::blockChairWood = new ChairBlock(ChairBlock::_woodId, "woodChairBlock", woodAttributes, ChairItem::_woodId);
	FurnitureBlock::blockChairStone = new ChairBlock(ChairBlock::_stoneId, "stoneChairBlock", stoneAttributes, ChairItem::_stoneId);
	FurnitureBlock::blockToilet = new ToiletBlock(ToiletBlock::_id, Material::getMaterial(MaterialType::STONE));
	FurnitureBlock::blockCabinet = new CabinetBlock(CabinetBlock::_id, Material::getMaterial(MaterialType::WOOD));
	FurnitureBlock::blockKitchenCabinet = new KitchenCabinetBlock(KitchenCabinetBlock::_id, Material::getMaterial(MaterialType::STONE));
	FurnitureBlock::blockDoorbell = new DoorbellBlock(DoorbellBlock::_id, Material::getMaterial(MaterialType::WOOD));
	FurnitureBlock::blockBin = new BinBlock(BinBlock::_id, Material::getMaterial(MaterialType::IRON)); 
	FurnitureBlock::blockLamp = new LampBlock(LampBlock::_id, Material::getMaterial(MaterialType::STONE));
	FurnitureBlock::blockChoppingBoard = new ChoppingBoardBlock(ChoppingBoardBlock::_id, Material::getMaterial(MaterialType::WOOD));
	FurnitureBlock::blockToaster = new ToasterBlock(ToasterBlock::_id, Material::getMaterial(MaterialType::IRON)); 
	FurnitureBlock::blockMicrowave = new MicrowaveBlock(MicrowaveBlock::_id, Material::getMaterial(MaterialType::IRON));
	FurnitureBlock::blockBarStool = new BarStoolBlock(BarStoolBlock::_id, Material::getMaterial(MaterialType::STONE));
	FurnitureBlock::blockCounter = new CounterBlock(CounterBlock::_id, Material::getMaterial(MaterialType::STONE));
	FurnitureBlock::blockCookieJar = new CounterBlock(CookieJarBlock::_id, Material::getMaterial(MaterialType::DECORATION));
	FurnitureBlock::blockOven = new OvenBlock(OvenBlock::_id, Material::getMaterial(MaterialType::STONE));
	FurnitureBlock::blockPlate = new PlateBlock(PlateBlock::_id, Material::getMaterial(MaterialType::DECORATION));
     FurnitureBlock::blockTv = new TvBlock(TvBlock::_id, Material::getMaterial(MaterialType::STONE));
     FurnitureBlock::blockPrinter = new PrinterBlock(PrinterBlock::_id, Material::getMaterial(MaterialType::STONE));
     FurnitureBlock::blockComputer = new ComputerBlock(ComputerBlock::_id, Material::getMaterial(MaterialType::STONE));
	ALOG("Finished Loading Blocks");

	FurnitureBlock::registerBlocks();
	
	initRenderers();
}

static void (*_Item$initItems)();
static void Item$initItems() {
	ALOG("Loading Items");
	FurnitureItem::itemTableWood = new TableItem(TableItem::_woodId, "itemtablewood", ItemMaterial::WOOD, TableBlock::_woodId);
	FurnitureItem::itemTableStone = new TableItem(TableItem::_stoneId, "itemtablestone", ItemMaterial::STONE, TableBlock::_stoneId);
	FurnitureItem::itemCoffeeTableWood = new CoffeeTableItem(CoffeeTableItem::_woodId, "itemcoffeetablewood", ItemMaterial::WOOD, CoffeeTableBlock::_woodId);
	FurnitureItem::itemCoffeeTableStone = new CoffeeTableItem(CoffeeTableItem::_stoneId, "itemcoffeetablestone", ItemMaterial::STONE, CoffeeTableBlock::_stoneId);
	FurnitureItem::itemChairWood = new ChairItem(ChairItem::_woodId, "itemchairwood", ItemMaterial::WOOD, ChairBlock::_woodId);
	FurnitureItem::itemChairStone = new ChairItem(ChairItem::_stoneId, "itemchairstone", ItemMaterial::STONE, ChairBlock::_stoneId);
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
	FurnitureItem::itemPlate = new PlateItem(PlateItem::_id);
     FurnitureItem::itemTv = new TvItem(TvItem::_id);
     FurnitureItem::itemPrinter = new PrinterItem(PrinterItem::_id);
     FurnitureItem::itemComputer = new ComputerItem(ComputerItem::_id);
	ALOG("Finished Loading Items");

	FurnitureItem::registerItems();
	
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
	Item::addCreativeItem(FurnitureItem::itemPlate, 0);
     Item::addCreativeItem(FurnitureItem::itemOven, 0);
     Item::addCreativeItem(FurnitureItem::itemPrinter, 0);
     Item::addCreativeItem(FurnitureItem::itemComputer, 0);
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
	if(key == "item.plateItem.name") return "Plate";
	
	return _I18n$get(key, a);
}

static bool (*_LiquidBlockDynamic$_isWaterBlocking)(LiquidBlockDynamic*, BlockSource&, const BlockPos&);
static bool LiquidBlockDynamic$_isWaterBlocking(LiquidBlockDynamic* self, BlockSource& region, const BlockPos& pos) {
	Block* tile = region.getBlock(pos);
	return (tile == FurnitureBlock::blockTableWood ||
     	tile == FurnitureBlock::blockTableStone ||
		tile == FurnitureBlock::blockCoffeeTableWood ||
     	tile == FurnitureBlock::blockCoffeeTableStone ||
		tile == FurnitureBlock::blockChairWood ||
		tile == FurnitureBlock::blockChairStone ||
		tile == FurnitureBlock::blockToilet ||
		tile == FurnitureBlock::blockCabinet ||
		tile == FurnitureBlock::blockDoorbell ||
		tile == FurnitureBlock::blockBin ||
		tile == FurnitureBlock::blockLamp ||
		tile == FurnitureBlock::blockChoppingBoard ||
		tile == FurnitureBlock::blockToaster ||
		tile == FurnitureBlock::blockMicrowave ||
		tile == FurnitureBlock::blockCookieJar ||
		tile == FurnitureBlock::blockOven ||
		tile == FurnitureBlock::blockCounter ||
		tile == FurnitureBlock::blockPlate)?
			true :
			_LiquidBlockDynamic$_isWaterBlocking(self, region, pos);
}

static std::vector<const Motive*> (*_Motive$getAllMotivesAsList)();
static std::vector<const Motive*> Motive$getAllMotivesAsList() {
	std::vector<const Motive*> retval = _Motive$getAllMotivesAsList();
	retval.push_back(Motive::Furniture);
	return retval;
}


JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	initMod();
	
	MSHookFunction((void*) &BlockTessellator::tessellateInWorld, (void*) &BlockTessellator$tessellateInWorld, (void**) &_BlockTessellator$tessellateInWorld);
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);
	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &I18n::get, (void*) &I18n$get, (void**) &_I18n$get);
	MSHookFunction((void*) &LiquidBlockDynamic::_isWaterBlocking, (void*) &LiquidBlockDynamic$_isWaterBlocking, (void**) &_LiquidBlockDynamic$_isWaterBlocking);
	MSHookFunction((void*) &Motive::getAllMotivesAsList, (void*) &Motive$getAllMotivesAsList, (void**) &_Motive$getAllMotivesAsList);

	return JNI_VERSION_1_2;
}
