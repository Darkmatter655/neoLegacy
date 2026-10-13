#include "stdafx.h"
#include "CoralTile.h"
#include "Item.h"
#include "IconRegister.h"

const wstring CoralTile::TEXTURE_NAMES[] = {
	L"tube",
	L"brain",
	L"bubble",
	L"fire",
	L"horn"
};

const unsigned int CoralTile::CORAL_NAMES[TYPE_COUNT] = {
	IDS_TILE_CORAL_TUBE,
	IDS_TILE_CORAL_BRAIN,
	IDS_TILE_CORAL_BUBBLE,
	IDS_TILE_CORAL_FIRE,
	IDS_TILE_CORAL_HORN
};

const unsigned int CoralTile::CORAL_USE_DESCS[TYPE_COUNT] = {
	IDS_DESC_CORAL_TUBE,
	IDS_DESC_CORAL_BRAIN,
	IDS_DESC_CORAL_BUBBLE,
	IDS_DESC_CORAL_FIRE,
	IDS_DESC_CORAL_HORN
};

CoralTile::CoralTile(int id) : Tile(id, Material::coral)
{
	setBaseItemTypeAndMaterial(Item::eBaseItemType_structblock, Item::eMaterial_stone);
	icons = nullptr;
}

Icon *CoralTile::getTexture(int face, int data)
{
	if (data < 0 || data >= TYPE_COUNT) data = 0;
	return icons[data];
}

int CoralTile::getSpawnResourcesAuxValue(int data)
{
	return data;
}

unsigned int CoralTile::getDescriptionId(int iData)
{
	if (iData < 0 || iData >= TYPE_COUNT) iData = 0;
	return CoralTile::CORAL_NAMES[iData];
}

unsigned int CoralTile::getUseDescriptionId(int iData)
{
	if (iData < 0 || iData >= TYPE_COUNT) iData = 0;
	return CoralTile::CORAL_USE_DESCS[iData];
}

void CoralTile::registerIcons(IconRegister *iconRegister)
{
	icons = new Icon*[TYPE_COUNT];
	for (int i = 0; i < TYPE_COUNT; i++)
	{
		wstring name = getIconName();
		if (!TEXTURE_NAMES[i].empty()) name += L"_" + TEXTURE_NAMES[i];
		icons[i] = iconRegister->registerIcon(name);
	}
}
