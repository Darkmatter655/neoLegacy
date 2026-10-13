#include "stdafx.h"
#include "KelpTile.h"
#include "Level.h"
#include "Material.h"
#include "IconRegister.h"
#include "Random.h"
#include "Item.h"

KelpTile::KelpTile(int id) : Tile(id, Material::water, false)
{
	setTicking(true);
	icon = nullptr;
	setDestroyTime(0.0f);
	setSoundType(SOUND_GRASS);
	setIconName(L"kelp");
}

int KelpTile::getRenderShape()
{
	return Tile::SHAPE_CROSS_TEXTURE;
}

bool KelpTile::isCubeShaped()
{
	return false;
}

bool KelpTile::isSolidRender(bool isServerLevel)
{
	return false;
}

bool KelpTile::canSurviveHere(Level *level, int x, int y, int z)
{
	if (!level) return false;
	int below = level->getTile(x, y - 1, z);
	// Must be on solid, kelp, or another support under water
	if (below == id) return true;
	if (below == 0) return false;
	Tile *t = Tile::tiles[below];
	if (!t) return false;
	return t->material == Material::stone || t->material == Material::dirt || t->material == Material::sand
		|| t->material == Material::clay || below == Tile::gravel_Id || below == Tile::sand_Id;
}

bool KelpTile::mayPlace(Level *level, int x, int y, int z)
{
	if (!level) return false;
	// Prefer water at this cell (calm or flowing)
	int here = level->getTile(x, y, z);
	if (here != Tile::water_Id && here != Tile::calmWater_Id && here != 0)
		return false;
	return canSurviveHere(level, x, y, z);
}

void KelpTile::tick(Level *level, int x, int y, int z, Random *random)
{
	if (!level || !random) return;
	if (!canSurviveHere(level, x, y, z))
	{
		level->setTile(x, y, z, 0);
		return;
	}
	int data = level->getData(x, y, z);
	if (data < MAX_AGE && random->nextInt(10) == 0)
	{
		int above = level->getTile(x, y + 1, z);
		if (above == Tile::water_Id || above == Tile::calmWater_Id)
		{
			level->setTileAndData(x, y + 1, z, id, 0);
			level->setData(x, y, z, data + 1);
		}
		else if (above == 0)
		{
			// grow into air only if still underwater column context
		}
	}
}

void KelpTile::neighborChanged(Level *level, int x, int y, int z, int type)
{
	if (!canSurviveHere(level, x, y, z))
	{
		level->setTile(x, y, z, 0);
	}
}

int KelpTile::getResource(int data, Random *random, int playerBonusLevel)
{
	// Drop kelp item when item id exists; for now use self id for creative parity
	return id;
}

int KelpTile::getResourceCount(Random *random)
{
	return 1;
}

void KelpTile::registerIcons(IconRegister *iconRegister)
{
	icon = iconRegister->registerIcon(getIconName());
}

Icon *KelpTile::getTexture(int face, int data)
{
	return icon;
}
