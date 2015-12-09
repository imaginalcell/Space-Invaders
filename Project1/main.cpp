#include "vec2.h"
#include "sfwdraw.h"
#include "declconst.h"
#include "gamestate.h"
#include <cassert>

int main()
{
	sfw::initContext(WINDOW_WIDTH,WINDOW_HEIGHT,"SPACEINVADERZIM");

	dfault = sfw::loadTextureMap("./textures/default.jpeg",1,1);

	back = sfw::loadTextureMap("./textures/background.png");
	font = sfw::loadTextureMap("./textures/tonc_font.png", 16, 6);
	mice = sfw::loadTextureMap("./textures/sword.png", 4, 4);

	plyr = sfw::loadTextureMap("./textures/large.ship_.1.png", 1, 1);
	plrM = sfw::loadTextureMap("./textures/defensive_missile.png", 1, 1);

	eOne = sfw::loadTextureMap("./textures/cartoonship_blue.png", 1, 1);
	eTwo = sfw::loadTextureMap("./textures/cartoonship_green.png", 1, 1);
	eMis = sfw::loadTextureMap("./textures/missile.png", 1, 1);
	
	GameState gs;

	while (sfw::stepContext())
	{
		
		gs.update();
		gs.draw();
	}
	sfw::termContext();
	return 0;
	/*//test DistanceFormula
	vec2 a = { 0,0 };
	vec2 b = { 0,0 };

	assert(DistanceFormula(a, b) == 0);

	b = { 1,0 };
	assert(DistanceFormula(a, b) == 1);

	b = {0,-1};
	assert(DistanceFormula(a,b) == 1);

	//test using circles
	a = {0,0};
	float ar = 1;
	b = { 0,0 };
	float br = 1;
	assert(circleOverlap(a, ar, b, br));

	assert((a + b) == b);

	a = { 1,0 };
	b = { 3,0 };
	float s = 3;
	assert(a*s == b);*/
}