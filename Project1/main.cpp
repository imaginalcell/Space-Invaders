#include "vec2.h"
#include "sfwdraw.h"
#include "declconst.h"
#include "gamestate.h"
#include "splashstate.h"
#include "pausestate.h"
#include "victorystate.h"
#include <cassert>

STATE appState = SPLASH;

// definition
unsigned back;
unsigned font;
unsigned mice;
unsigned plyr;
unsigned plrM;
unsigned eTwo;
unsigned eMis;
unsigned dfault;

int main()
{
	sfw::initContext(WINDOW_WIDTH,WINDOW_HEIGHT,TITLE);

	// initialization
	dfault = sfw::loadTextureMap("./textures/default.jpg",1,1);

	back = sfw::loadTextureMap("./textures/background.png");
	font = sfw::loadTextureMap("./textures/fontmap.png", 16, 16);
	mice = sfw::loadTextureMap("./textures/sword.png", 4, 4);

	plyr = sfw::loadTextureMap("./textures/large.ship_.1.png", 1, 1);
	plrM = sfw::loadTextureMap("./textures/defensive_missile.png", 1, 1);

	eTwo = sfw::loadTextureMap("./textures/cartoonship_green.png", 1, 1);
	eMis = sfw::loadTextureMap("./textures/missile.png", 1, 1);
	
	GameState    gs;
	SplashState  ss;
	PauseState   ps;
	VictoryState vs;

	while (sfw::stepContext() && !sfw::getKey(KEY_ESCAPE))
	{
		switch (appState)
		{
		case SPLASH:
			ss.update();
			ss.draw();
			break;
		case PLAY:
			gs.reset();
			appState = GAME;
		case GAME:
			gs.update();
			gs.draw();
			break;
		case PAUSE:
			gs.draw();
			ps.update();
			ps.draw();
			break;
		case VICTORY:
			gs.update();
			gs.draw();
			vs.update();
			vs.draw();
		}
	}
	sfw::termContext();
	return 0;
}
void drawFontCentered(unsigned sprite, const char* text, unsigned x, unsigned y, unsigned w, unsigned h, unsigned color)
{
	x -= strlen(text) * w / 2;
	sfw::drawString(font, text, x, y, w, h, 0, 0, color);
}