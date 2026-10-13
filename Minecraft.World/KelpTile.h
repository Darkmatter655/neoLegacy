#pragma once
#include "Tile.h"

// 1.13 kelp — grows upward in water
class KelpTile : public Tile
{
public:
	static const int MAX_AGE = 25;

	KelpTile(int id);

	virtual int getRenderShape() override;
	virtual bool isCubeShaped() override;
	virtual bool isSolidRender(bool isServerLevel = false) override;
	virtual bool mayPlace(Level *level, int x, int y, int z) override;
	virtual void tick(Level *level, int x, int y, int z, Random *random) override;
	virtual void neighborChanged(Level *level, int x, int y, int z, int type) override;
	virtual int getResource(int data, Random *random, int playerBonusLevel) override;
	virtual int getResourceCount(Random *random) override;
	virtual void registerIcons(IconRegister *iconRegister) override;
	virtual Icon *getTexture(int face, int data) override;

private:
	Icon *icon;
	bool canSurviveHere(Level *level, int x, int y, int z);
};
