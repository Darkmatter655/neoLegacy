#pragma once
#include "Tile.h"

class ChunkRebuildData;
class CoralTile : public Tile
{
	friend class ChunkRebuildData;
public:
	static const int TYPE_TUBE = 0;
	static const int TYPE_BRAIN = 1;
	static const int TYPE_BUBBLE = 2;
	static const int TYPE_FIRE = 3;
	static const int TYPE_HORN = 4;
	static const int TYPE_COUNT = 5;

	static const wstring TEXTURE_NAMES[];
	static const unsigned int CORAL_NAMES[TYPE_COUNT];
	static const unsigned int CORAL_USE_DESCS[TYPE_COUNT];

private:
	Icon **icons;

public:
	CoralTile(int id);

	virtual Icon *getTexture(int face, int data);
	virtual unsigned int getDescriptionId(int iData = -1);
	virtual unsigned int getUseDescriptionId(int iData = -1);
	virtual int getSpawnResourcesAuxValue(int data);
	void registerIcons(IconRegister *iconRegister);
};
