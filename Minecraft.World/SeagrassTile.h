#pragma once
#include "Tile.h"

// 1.13 seagrass — short underwater plant
class SeagrassTile : public Tile
{
public:
	static const int TYPE_DEFAULT = 0;
	static const int TYPE_TALL_BOTTOM = 1;
	static const int TYPE_TALL_TOP = 2;

	SeagrassTile(int id);

	virtual int getRenderShape() override;
	virtual bool isCubeShaped() override;
	virtual bool isSolidRender(bool isServerLevel = false) override;
	virtual bool mayPlace(Level *level, int x, int y, int z) override;
	virtual void neighborChanged(Level *level, int x, int y, int z, int type) override;
	virtual int getResource(int data, Random *random, int playerBonusLevel) override;
	virtual int getResourceCount(Random *random) override;
	virtual void registerIcons(IconRegister *iconRegister) override;
	virtual Icon *getTexture(int face, int data) override;

private:
	Icon *icon;
	bool canSurviveHere(Level *level, int x, int y, int z);
};
