#pragma once
#include "basestate.h"

class PauseState : public BaseState
{
public:
	unsigned transparentComp;
	unsigned colorComp;

	void update();
	void draw();
};