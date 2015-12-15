#include "pausestate.h"
#include "sfwdraw.h"
#include "declconst.h"
#include <cstring>

void PauseState::update()
{
	if (sfw::getKey(KEY_ENTER))
		appState = GAME;
	if (sfw::getKey('Q'))
		appState = SPLASH;
}

void PauseState::draw()
{
	sfw::drawTexture(back, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT,0,true,0, 0x88888888);

	unsigned x, y, s;

	s = 32;
	x = WINDOW_WIDTH / 2;
	y = WINDOW_HEIGHT * 3 / 4;
	drawFontCentered(font, "Paused", x, y, 5, 5);

	s = 16;
	x = (WINDOW_WIDTH / 2 - strlen("Enter to Continue")*s) / 2;
	y = WINDOW_HEIGHT * 5 / 8;
	sfw::drawString(font, "Enter to Continue", x, y - 200, 12, 12);
}
