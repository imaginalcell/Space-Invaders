#include "splashstate.h"
#include "sfwdraw.h"
#include "declconst.h"
#include <cstring>

void SplashState::update()
{
	if (sfw::getKey(KEY_ENTER))
		appState = PLAY;
	if (sfw::getKey(KEY_ESCAPE))
		appState = QUIT;
}

void SplashState::draw()
{
	sfw::drawTexture(back, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT);

		unsigned x, y, s;
		
		s = 32;
		x = (WINDOW_WIDTH) / 2;
		y = WINDOW_HEIGHT * 3 / 4;
		drawFontCentered(font, TITLE, x, y, s, s);

		s = 20;
		y = WINDOW_HEIGHT * 5 / 8;
		drawFontCentered(font, "Enter to Start", x, y, s, s);
		drawFontCentered(font, "Escape to Quit", x, y-20, s, s);

		s = 18;
		y = WINDOW_HEIGHT * 8 / 16;
		drawFontCentered(font, "Triston Vaskey", x, y, s, s);
		drawFontCentered(font, "triston.vaskey@students.aie.edu.au", x, y - 19, 16, 16, ORANGE);
}
