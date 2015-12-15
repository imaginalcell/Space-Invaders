#pragma once
#include "sfwdraw.h"
#include "pausestate.h"
#include "basestate.h"


class VictoryState : public BaseState
{
public:
	unsigned color, baseColor;
	VictoryState()
		:color(CYAN), baseColor(color - 0xff)
	{

	}

	void update();
	void draw();
};