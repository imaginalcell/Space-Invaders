#pragma once
#include "sfwdraw.h"
#include "declconst.h"
#include "basestate.h"

class SplashState : public BaseState
{
public:
	unsigned color, baseColor;
	SplashState()
		:color(ORANGE), baseColor(color - 0xff)
	{

	}

	void update();
	void draw();
};