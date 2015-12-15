#include "victorystate.h"
#include "declconst.h"
#include <cstring>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>

void VictoryState::update()
{
	if (sfw::getKey('R'))
		appState = SPLASH;
}

void VictoryState::draw()
{
	sfw::drawTexture(back, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT,0,true,0,0x88888888);

	unsigned x, y, s;

	s = 24;
	x = (WINDOW_WIDTH) / 2;
	y = (WINDOW_HEIGHT) / 2;
	drawFontCentered(font, "You Have Been Slain", x, y + 30, s, s, ORANGE);

	s = 18;
	y = WINDOW_HEIGHT * 5 / 8;
	drawFontCentered(font, "R to Menu", x, y, s, s, color);

	std::fstream fin("scores.dat", std::ios_base::in);
	std::vector<unsigned> scores;
	
	while (!fin.eof())
	{
		unsigned t;
		fin >> t;
		scores.push_back(t);
	}
	scores.pop_back();
	fin.close();

	y = WINDOW_HEIGHT / 2;
	s = 32 + sin(sfw::getDeltaTime() * 6) * 4;
	sfw::drawString(font, std::to_string(scores[scores.size()-1]).c_str(),
		x, y, s, s,ORANGE);

	s = 18;
	y = WINDOW_HEIGHT / 2 - scores.size() * s;
	for (int i = scores.size() - 2; i >= 0 && scores.size()-i < 12; --i)
	{
		sfw::drawString(font, std::to_string(scores[i]).c_str(), 
														  x, y + 18*i, s, s);
	}
}
