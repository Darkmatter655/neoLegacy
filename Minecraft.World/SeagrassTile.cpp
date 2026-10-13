#include "stdafx.h"
#include "SeagrassTile.h"
#include "Level.h"
#include "Material.h"
#include "IconRegister.h"
#include "Random.h"

SeagrassTile::SeagrassTile(int id) : Tile(id, Material::water, false)
{
	icon = nullptr;
	setDestroyTime(0.0f);
	setSoundType(SOUND_GRASS);
	setIconName(L"seagrass");
}

int SeagrassTile::getRenderShape()
{
	return Tile::SHAPE_CROSS_TEXTURE;
}

bool SeagrassTile::isCubeShaped()
{
	return false;
}

bool SeagrassTile::isSolidRender(bool isServerLevel)
{
	return false;
}

bool SeagrassTile::canSurviveHere(Level *level, int x, int y, int z)
{
	if (!level) return false;
	int below = level->getTile(x, y - 1, z);
	if (below == 0) return false;
	Tile *t = Tile::tiles[below];
	if (!t) return false;
	return t->material == Material::dirt || t->material == Material::sand
		|| t->material == Material::clay || below == Tile::gravel_Id
		|| below == Tile::sand_Id || t->material == Material::stone;
}

bool SeagrassTile::mayPlace(Level *level, int x, int y, int z)
{
	if (!level) return false;
	int here = level->getTile(x, y, z);
	if (here != Tile::water_Id && here != Tile::calmWater_Id && here != 0)
		return false;
	return canSurviveHere(level, x, y, z);
}

void SeagrassTile::neighborChanged(Level *level, int x, int y, int z, int type)
{
	if (!canSurviveHere(level, x, y, z))
	{
		level->setTile(x, y, z, 0);
	}
}

int SeagrassTile::getResource(int data, Random *random, int playerBonusLevel)
{
	return id;
}

int SeagrassTile::getResourceCount(Random *random)
{
	return 1;
}

void SeagrassTile::registerIcons(IconRegister *iconRegister)
{
	icon = iconRegister->registerIcon(getIconName());
}

Icon *SeagrassTile::getTexture(int face, int data)
{
	return icon;
}
