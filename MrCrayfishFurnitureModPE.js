/**
  * MrCrayfishâ€™s Furniture Mod PE
  * Copyright (C) 2014 MrCrayfish
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation; either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License along
  * with this program; if not, write to the Free Software Foundation, Inc.,
  * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
  */

var itemDataInfo = [];

var renderChairID = 200;
var renderTableID = 201;
var renderCoffeeTableID = 202;
var renderCabinetID = 203;
var renderCouchID = 204;

var woodenChairID = 243;
var woodenTableID = 242;
var woodenCoffeeTableID = 241;
var stoneChairID = 240;
var stoneTableID = 239;
var stoneCoffeeTableID = 238;
var cabinetID = 237;
var whiteCouchID = 236;
var greenCouchID = 235;
var brownCouchID = 234;
var redCouchID = 233;
var blackCouchID = 232;

var lampID = 231;
var ovenID = 230;
var ovenRangehoodID = 229;
var oakHedgeID = 228;
var spruceHedgeID = 227;
var birchHedgeID = 226;
var jungleHedgeID = 225;
var whiteFenceID = 224;
var tvID = 223;
var computerID = 222;
var printerID = 221;
var stereoID = 220;
var ceilingLightID = 219;
var toiletID = 218;
var basinID = 217;
var wallCabinetID = 216;

/** Textures */

var oak = ["planks", 0];
var spruce = ["planks", 1];
var birch = ["planks", 2];
var jungle = ["planks", 3];

var white = ["wool", 0];
var green = ["wool", 13];
var brown = ["wool", 12];
var red = ["wool", 14];
var black = ["wool", 15];

var cob = ["cobblestone", 0];
var ironb = ["iron_block", 0];

var sides = [
[0, -1, 0],
[0, 1, 0],
[0, 0, -1],
[0, 0, 1],
[-1, 0, 0],
[1, 0, 0]
];

/** Blocks */

Block.defineBlock(woodenChairID, "Wooden Chair", [oak, oak, oak, oak, oak, oak], 0, false, renderChairID);
Block.defineBlock(woodenTableID, "Wooden Table", [oak, oak, oak, oak, oak, oak], 0, false, renderTableID);
Block.defineBlock(woodenCoffeeTableID, "Wooden Coffee Table", [oak, oak, oak, oak, oak, oak], 0, false, renderCoffeeTableID);
Block.defineBlock(stoneChairID, "Stone Chair", [cob, cob, cob, cob, cob, cob], 1, false, renderChairID);
Block.defineBlock(stoneTableID, "Stone Table", [cob, cob, cob, cob, cob, cob], 1, false, renderTableID);
Block.defineBlock(stoneCoffeeTableID, "Stone Coffee Table", [cob, cob, cob, cob, cob, cob], 1, false, renderCoffeeTableID);
Block.defineBlock(cabinetID, "Cabinet", [birch, birch, birch, birch, birch, birch], 0, false, renderCabinetID);
Block.defineBlock(greenCouchID, "Green Couch", [green, green, green, green, green, green], 0, false, renderCouchID);
Block.defineBlock(whiteCouchID, "White Couch", [white, white, white, white, white, white], 0, false, renderCouchID);
Block.defineBlock(brownCouchID, "Brown Couch", [brown, brown, brown, brown, brown, brown], 0, false, renderCouchID);
Block.defineBlock(redCouchID, "Red Couch", [red, red, red, red, red, red], 0, false, renderCouchID);
Block.defineBlock(blackCouchID, "Black Couch", [black, black, black, black, black, black], 0, false, renderCouchID);
/*Block.defineBlock(lampID, "Lamp", [["wool_colored_red", 0]], 0, true, 205);
Block.defineBlock(ovenID, "Oven", [["wool_colored_red", 0]], 0, true, 206);
Block.defineBlock(ovenRangehoodID, "Oven Rangehood", [["wool_colored_red", 0]], 0, true, 207);
Block.defineBlock(oakHedgeID, "Oak Hedge", [["leaves_4", 0]], 0, true, 208);
Block.defineBlock(spruceHedgeID, "Spruce Hedge", [["leaves_5", 0]], 0, true, 208);
Block.defineBlock(birchHedgeID, "Birch Hedge", [["leaves_6", 0]], 0, true, 208);
Block.defineBlock(jungleHedgeID, "Jungle Hedge", [["leaves_7", 0]], 0, true, 208);
Block.defineBlock(whiteFenceID, "White Fence", [["quartz_block_side", 0]], 0, true, 209);
Block.defineBlock(tvID, "TV", [["planks_oak", 0]], 0, true, 210);
Block.defineBlock(computerID, "Computer", [["iron_block", 0]], 0, true, 211);
Block.defineBlock(printerID, "Printer", [["iron_block", 0]], 0, true, 212);
Block.defineBlock(stereoID, "Stereo", [["planks_oak", 0]], 0, true, 213);
Block.defineBlock(ceilingLightID, "Ceiling Light", [["leaves_7", 0]], 0, true, 214);
Block.defineBlock(toiletID, "Toilet", [["quartz_block_side", 0]], 0, true, 215);
Block.defineBlock(basinID, "Basin", [["quartz_block_side", 0]], 0, true, 216);
Block.defineBlock(wallCabinetID, "Wall Cabinet", [["quartz_block_side", 0]], 0, true, 217);

Block.setLightLevel(511, 1.0F);
Block.setLightLevel(513, 1.0F);
Block.setLightLevel(523, 1.0F);*/

/** Dummy Blocks */

Block.defineBlock(100, "DummyBlock1", [cob, cob, cob, cob, cob, cob], 0, false, 0);
Block.defineBlock(101, "DummyBlock2", [oak, oak, oak, oak, oak, oak], 0, false, 0);
Block.defineBlock(102, "DummyBlock3", [spruce, spruce, spruce, spruce, spruce, spruce], 0, false, 0);
Block.defineBlock(103, "DummyBlock4", [ironb, ironb, ironb, ironb, ironb, ironb], 0, false, 0);

/** Furniture Register */

function itemData(itemId, blockId)
{
	this.itemId = itemId;
	this.blockId = blockId;
}

function registerFurniture(itemId, itemName, itemTexture, blockId)
{
	ModPE.setItem(itemId, itemTexture, 5, itemName, 0);
	itemDataInfo.push(new itemData(itemId, blockId));
}

registerFurniture(511, "Wooden Chair", "record_11", woodenChairID);
registerFurniture(510, "Wooden Table", "record_blocks", woodenTableID);
registerFurniture(509, "Wooden Coffee Table", "record_13", woodenCoffeeTableID);
registerFurniture(508, "Stone Chair", "record_cat", stoneChairID);
registerFurniture(507, "Stone Table", "record_far", stoneTableID);
registerFurniture(506, "Stone Coffee Table", "record_chirp", stoneCoffeeTableID);
registerFurniture(505, "Cabinet", "record_mall", cabinetID);
registerFurniture(504, "White Couch", "record_mellohi", whiteCouchID);
registerFurniture(503, "Green Couch", "record_stal", greenCouchID);
registerFurniture(502, "Brown Couch", "record_strad", brownCouchID);
registerFurniture(501, "Red Couch", "record_wait", redCouchID);
registerFurniture(500, "Black Couch", "record_ward", blackCouchID);

//ModPE.addCraftRecipe(1000, 1, 0, 280);
Item.addCraftRecipe(509, 1, 0, [3, 1, 0]);
Item.addCraftRecipe(510, 1, 0, [3, 1, 0]);
Item.addCraftRecipe(511, 1, 0, [3, 1, 0]); 
Item.addCraftRecipe(508, 1, 0, [3, 1, 0]);
Item.addCraftRecipe(507, 1, 0, [3, 1, 0]);
Item.addCraftRecipe(506, 1, 0, [3, 1, 0]); 
Item.addCraftRecipe(505, 1, 0, [3, 1, 0]); 
Item.addCraftRecipe(504, 1, 0, [3, 1, 0]); 
Item.addCraftRecipe(503, 1, 0, [3, 1, 0]); 
Item.addCraftRecipe(502, 1, 0, [3, 1, 0]); 
Item.addCraftRecipe(501, 1, 0, [3, 1, 0]); 
Item.addCraftRecipe(500, 1, 0, [3, 1, 0]); 

/** Handles Furniture Placing */

function useItem(x, y, z, itemId, blockId, side)
{
     var dir = sides[side];
	var player = getPlayerEnt();
	var rotation  = getRealData();
	
	for (var i = 0; i < itemDataInfo.length; i++)
	{
		var data = itemDataInfo[i];
		if(data.itemId == itemId)
		{
               Player.swingArm();

               // Does not work, requires BlockLauncher bug fix
               blockPlaceSound(data.blockId, x + dir[0], y + dir[1], x + dir[2]);
			Level.setTile(x + dir[0], y + dir[1], z + dir[2], data.blockId, rotation);
			break;
		}
	}
}

function getRealData() {
        switch(Player.getDataFromYaw() & 3) {
            case 0:
                return 2;
                break;
            case 1:
                return 5;
                break;
            case 2:
                return 3;
                break;
            case 3:
                return 4;
                break;
        }
}

/** Render Handler */

function renderBlockHook(blockId, x, y, z)
{
	switch(Block.getRenderType(blockId))
	{
	case renderChairID:
		renderChair(blockId, x, y, z);
		break;
	case renderTableID:
		renderTable(blockId, x, y, z);
		break;
	case renderCoffeeTableID:
		renderCoffeeTable(blockId, x, y, z);
		break;
	case renderCabinetID:
		renderCabinet(blockId, x, y, z);
		break;
	case renderCouchID:
		renderCouch(blockId, x, y, z);
		break;
	}
}

/** Rotation Helper */

function renderComponent(block, x, y, z, metadata, var1, minY, var2, var3, maxY, var4)
{
	switch (metadata) 
	{
	case 1:
		var var_temp_1 = var1;
		var1 = 1.0 - var3;
		var var_temp_2 = var2;
		var2 = 1.0 - var4;
		var3 = 1.0 - var_temp_1;
		var4 = 1.0 - var_temp_2;
		break;
	case 2:
		var var_temp_3 = var1;
		var1 = var2;
		var2 = 1.0 - var3;
		var3 = var4;
		var4 = 1.0 - var_temp_3;
		break;
	case 0:
		var var_temp_4 = var1;
		var1 = 1.0 - var4;
		var var_temp_5 = var2;
		var2 = var_temp_4;
		var var_temp_6 = var3;
		var3 = 1.0 - var_temp_5;
		var4 = var_temp_6;
		break;
	}
	Block.setShape(block, var1, minY, var2, var3, maxY, var4);
	BlockRenderer.renderBlock(block, x, y, z);
}

/** Block Renders */

function renderChair(blockId, x, y, z)
{
	var metadata = Level.getData(x, y, z);
	var block = 101;
	if(blockId == stoneChairID) {
		block = 100;
	}

	renderComponent(block, x, y, z, metadata, 0.1, 0.0, 0.1, 0.2, 0.5, 0.2);
	renderComponent(block, x, y, z, metadata, 0.8, 0.0, 0.8, 0.9, 0.5, 0.9);
	renderComponent(block, x, y, z, metadata, 0.8, 0.0, 0.1, 0.9, 0.5, 0.2);
	renderComponent(block, x, y, z, metadata, 0.1, 0.0, 0.8, 0.2, 0.5, 0.9);
	renderComponent(block, x, y, z, metadata, 0.1, 0.5, 0.1, 0.9, 0.6, 0.9);
	renderComponent(block, x, y, z, metadata, 0.8, 0.6, 0.1, 0.9, 1.2, 0.9);
}

function renderTable(blockId, x, y, z)
{
	var forward = (getTile(x + 1, y, z) == woodenTableID) | (getTile(x + 1, y, z) == stoneTableID);
	var back = (getTile(x - 1, y, z) == woodenTableID) | (getTile(x - 1, y, z) == stoneTableID);
	var left = (getTile(x, y, z - 1) == woodenTableID) | (getTile(x, y, z - 1) == stoneTableID);
	var right = (getTile(x, y, z + 1) == woodenTableID) | (getTile(x, y, z + 1) == stoneTableID);

	var block = 101;
	if(blockId == stoneTableID) {
		block = 100;
	}
	
	if (forward && right && !left && !back) {
		renderComponent(block, x, y, z, 3, 0.175, 0.0, 0.175, 0.425, 0.9, 0.425);
	}
	if (forward && !right && left && !back) {
		renderComponent(block, x, y, z, 3, 0.175, 0.0, 0.575, 0.425, 0.9, 0.825);
	}
	if (!forward && right && !left && back) {
		renderComponent(block, x, y, z, 3, 0.575, 0.0, 0.175, 0.825, 0.9, 0.425);		
	}
	if (!forward && !right && left && back) {
		renderComponent(block, x, y, z, 3, 0.575, 0.0, 0.575, 0.825, 0.9, 0.825);
	}
	if (forward && !right && !left && !back) {
		renderComponent(block, x, y, z, 3, 0.175, 0.0, 0.375, 0.425, 0.9, 0.625);
	}
	if (!forward && right && !left && !back) {
		renderComponent(block, x, y, z, 3, 0.375, 0.0, 0.175, 0.625, 0.9, 0.425);
	}
	if (!forward && !right && left && !back) {
		renderComponent(block, x, y, z, 3, 0.375, 0.0, 0.575, 0.625, 0.9, 0.825);
	}
	if (!forward && !right && !left && back) {
		renderComponent(block, x, y, z, 3, 0.575, 0.0, 0.375, 0.825, 0.9, 0.625);
	}
	if (!forward && !right && !left && !back) {
		renderComponent(block, x, y, z, 3, 0.375, 0.0, 0.375, 0.625, 0.9, 0.625);
	}
	
	renderComponent(block, x, y, z, 3, 0.0, 0.9, 0.0, 1.0, 1.0, 1.0);
}

function renderCoffeeTable(blockId, x, y, z)
{
	var forward = (getTile(x + 1, y, z) == woodenCoffeeTableID) | (getTile(x + 1, y, z) == stoneCoffeeTableID);
	var back = (getTile(x - 1, y, z) == woodenCoffeeTableID) | (getTile(x - 1, y, z) == stoneCoffeeTableID);
	var left = (getTile(x, y, z - 1) == woodenCoffeeTableID) | (getTile(x, y, z - 1) == stoneCoffeeTableID);
	var right = (getTile(x, y, z + 1) == woodenCoffeeTableID) | (getTile(x, y, z + 1) == stoneCoffeeTableID);
	
	var block = blockId;
	
	renderComponent(block, x, y, z, 3, 0.0, 0.4, 0.0, 1.0, 0.5, 1.0);
	
	if (!back) {
		if (!left) {
			renderComponent(block, x, y, z, 3, 0.0, 0.0, 0.0, 0.1, 0.4, 0.1);
		}
		if (!right) {
			renderComponent(block, x, y, z, 3, 0.0, 0.0, 0.9, 0.1, 0.4, 1.0);
		}
	}
	if (!forward) {
		if (!left) {
			renderComponent(block, x, y, z, 3, 0.9, 0.0, 0.0, 1.0, 0.4, 0.1);
		}
		if (!right) {
			renderComponent(block, x, y, z, 3, 0.9, 0.0, 0.9, 1.0, 0.4, 1.0);
		}
	}
	if (!left) {
		if (!forward) {
			renderComponent(block, x, y, z, 3, 0.9, 0.0, 0.0, 1.0, 0.4, 0.1);
		}
		if (!back) {
			renderComponent(block, x, y, z, 3, 0.0, 0.0, 0.0, 0.1, 0.4, 0.1);
		}
	}
	if (!right) {
		if (!forward) {
			renderComponent(block, x, y, z, 3, 0.9, 0.0, 0.9, 1.0, 0.4, 1.0);
		}
		if (!back) {
			renderComponent(block, x, y, z, 3, 0.0, 0.0, 0.9, 0.1, 0.4, 1.0);
		}
	}
}

function renderCabinet(blockId, x, y, z)
{
	var metadata = Level.getData(x, y, z);
	
	renderComponent(102, x, y, z, metadata, -0.0625, 0.0625, 0.0625, 0.5, 0.9375, 0.9375);
	
	renderComponent(103, x, y, z, metadata, -0.1, 0.375, 0.125, 0.0, 0.75, 0.1875);
	renderComponent(103, x, y, z, metadata, -0.1, 0.6875, 0.1875, 0.0, 0.75, 0.25);
	renderComponent(103, x, y, z, metadata, -0.1, 0.375, 0.1875, 0.0, 0.4375, 0.25);
		
	renderComponent(cabinetID, x, y, z, 3, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0);
}

var UP = 0;
var DOWN = 1;
var LEFT = 2;
var RIGHT = 3;

function renderCouch(blockId, x, y, z)
{
	var metadata = Level.getData(x, y, z);
	
	if(isCouch(x, y, z, metadata, DOWN))
	{
		if(getRotation(x, y, z, metadata, DOWN) == RIGHT)
		{
			renderComponent(blockId, x, y, z, metadata, 0.0, 0.6, 0.0, 0.75, 1.2, 0.25);
		}
		else if(getRotation(x, y, z, metadata, DOWN) == LEFT)
		{
			renderComponent(blockId, x, y, z, metadata, 0.0, 0.6, 0.75, 0.75, 1.2, 1.0);
		}
		else
		{
			if(isAirBlock(x, y, z, metadata, LEFT))
			{
				renderComponent(blockId, x, y, z, metadata, -0.001, 0.5, -0.2, 1.001, 0.9, 0.05);
			}
			if(isAirBlock(x, y, z, metadata, RIGHT))
			{
				renderComponent(blockId, x, y, z, metadata, -0.001, 0.5, 0.95, 1.001, 0.9, 1.2);
			}
		}
	}
	else
	{
		if(isAirBlock(x, y, z, metadata, LEFT))
		{
			renderComponent(blockId, x, y, z, metadata, -0.001, 0.5, -0.2, 1.001, 0.9, 0.05);
		}
		if(isAirBlock(x, y, z, metadata, RIGHT))
		{
			renderComponent(blockId, x, y, z, metadata, -0.001, 0.5, 0.95, 1.001, 0.9, 1.2);
		}
	}
	
	renderComponent(blockId, x, y, z, metadata, 0.75, 0.6, 0.0, 1, 1.2, 1);
	renderComponent(blockId, x, y, z, metadata, 0.0, 0.0, 0.0, 1, 0.6, 1);
}

function isCouch(x, y, z, metadata, rotation) 
{
	var block = 0;

	switch (rotation) {
	case UP:
		if (metadata == 3)
			block = getTile(x + 1, y, z);
		if (metadata == 1)
			block = getTile(x - 1, y, z);
		if (metadata == 2)
			block = getTile(x, y, z - 1);
		if (metadata == 0)
			block = getTile(x, y, z + 1);
		break;
	case DOWN:
		if (metadata == 3)
			block = getTile(x - 1, y, z);
		if (metadata == 1)
			block = getTile(x + 1, y, z);
		if (metadata == 2)
			block = getTile(x, y, z + 1);
		if (metadata == 0)
			block = getTile(x, y, z - 1);
		break;
	case LEFT:
		if (metadata == 2)
			block = getTile(x - 1, y, z);
		if (metadata == 0)
			block = getTile(x + 1, y, z);
		if (metadata == 3)
			block = getTile(x, y, z - 1);
		if (metadata == 1)
			block = getTile(x, y, z + 1);
		break;
	case RIGHT:
		if (metadata == 2)
			block = getTile(x + 1, y, z);
		if (metadata == 0)
				block = getTile(x - 1, y, z);
		if (metadata == 3)
			block = getTile(x, y, z + 1);
		if (metadata == 1)
			block = getTile(x, y, z - 1);
		break;
	}
	
	if(block == whiteCouchID | block == greenCouchID | block == brownCouchID | block == redCouchID | block == blackCouchID)
	{
		return true;
	}
	return false;
}

function isAirBlock(x, y, z, metadata, rotation) 
{
	switch (rotation) 
	{
	case UP:
		if (metadata == 3)
			return getTile(x + 1, y, z) == 0;
		if (metadata == 1)
			return getTile(x - 1, y, z) == 0;
		if (metadata == 2)
			return getTile(x, y, z - 1) == 0;
		if (metadata == 0)
			return getTile(x, y, z + 1) == 0;
	case DOWN:
		if (metadata == 3)
			return getTile(x - 1, y, z) == 0;
		if (metadata == 1)
			return getTile(x + 1, y, z) == 0;
		if (metadata == 2)
			return getTile(x, y, z + 1) == 0;
		if (metadata == 0)
			return getTile(x, y, z - 1) == 0;
	case LEFT:
		if (metadata == 2)
			return getTile(x - 1, y, z) == 0;
		if (metadata == 0)
			return getTile(x + 1, y, z) == 0;
		if (metadata == 3)
			return getTile(x, y, z - 1) == 0;
		if (metadata == 1)
			return getTile(x, y, z + 1) == 0;
	case RIGHT:
		if (metadata == 2)
			return getTile(x + 1, y, z) == 0;
		if (metadata == 0)
			return getTile(x - 1, y, z) == 0;
		if (metadata == 3)
			return getTile(x, y, z + 1) == 0;
		if (metadata == 1)
			return getTile(x, y, z - 1) == 0;
	}
	return false;
}

function getRotation(x, y, z, metadata, rotation) 
{
	var blockMetadata = getMetadata(x, y, z, metadata, rotation);
	if (metadata == 3) {
		if (blockMetadata == 3)
			return DOWN;
		if (blockMetadata == 1)
			return UP;
		if (blockMetadata == 2)
			return RIGHT;
		if (blockMetadata == 0)
			return LEFT;
	}
	if (metadata == 1) {
		if (blockMetadata == 3)
			return UP;
		if (blockMetadata == 1)
			return DOWN;
		if (blockMetadata == 2)
			return LEFT;
		if (blockMetadata == 0)
			return RIGHT;
	}
	if (metadata == 2) {
		if (blockMetadata == 3)
			return LEFT;
		if (blockMetadata == 1)
			return RIGHT;
		if (blockMetadata == 2)
			return DOWN;
		if (blockMetadata == 0)
			return UP;
	}
	if (metadata == 0) {
		if (blockMetadata == 3)
			return RIGHT;
		if (blockMetadata == 1)
			return LEFT;
		if (blockMetadata == 2)
			return UP;
		if (blockMetadata == 0)
			return DOWN;
	}
	return 0;
}

function getMetadata(x, y, z, metadata, rotation) 
{
	switch (rotation) 
	{
	case UP:
		if (metadata == 3)
			return Level.getData(x + 1, y, z);
		if (metadata == 1)
			return Level.getData(x - 1, y, z);
		if (metadata == 2)
			return Level.getData(x, y, z - 1);
		if (metadata == 0)
			return Level.getData(x, y, z + 1);
	case DOWN:
		if (metadata == 3)
			return Level.getData(x - 1, y, z);
		if (metadata == 1)
			return Level.getData(x + 1, y, z);
		if (metadata == 2)
			return Level.getData(x, y, z + 1);
		if (metadata == 0)
			return Level.getData(x, y, z - 1);
	case LEFT:
		if (metadata == 2)
			return Level.getData(x - 1, y, z);
		if (metadata == 0)
			return Level.getData(x + 1, y, z);
		if (metadata == 3)
			return Level.getData(x, y, z - 1);
		if (metadata == 1)
			return Level.getData(x, y, z + 1);
	case RIGHT:
		if (metadata == 2)
			return Level.getData(x + 1, y, z);
		if (metadata == 0)
			return Level.getData(x - 1, y, z);
		if (metadata == 3)
			return Level.getData(x, y, z + 1);
		if (metadata == 1)
			return Level.getData(x, y, z - 1);
	}
	return 0;
}

function blockPlaceSound(block, x, y, z) {
    if(block == 237 || block == 241 || block == 242 || block == 243) Level.playSound(x, y, z, "step.wood", 1, 1);
    if(block == 240 || block == 239 || block == 238) Level.playSound(x, y, z, "step.stone", 1, 1);
    if(block == 232 || block == 233 || block == 234 || block == 235 || block == 236) Level.playSound(x, y, z, "step.wool", 1, 1);
}
