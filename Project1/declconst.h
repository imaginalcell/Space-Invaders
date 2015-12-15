#pragma once

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 600

#define BOUNDS_TOP WINDOW_HEIGHT -60
#define BOUNDS_BOTTOM 60
#define BOUNDS_LEFT 80
#define BOUNDS_RIGHT WINDOW_WIDTH -80

#define TITLE "SPACEINVADERZIM"

class GameState;
//declaration
extern unsigned back;
extern unsigned font;
extern unsigned mice;
extern unsigned plyr;
extern unsigned plrM;
extern unsigned eTwo;
extern unsigned eMis;
extern unsigned dfault;

enum STATE {SPLASH, PLAY, GAME, PAUSE, VICTORY, QUIT };
extern STATE appState;

void drawFontCentered(unsigned sprite, const char* text, unsigned x, unsigned y, unsigned w, unsigned h, unsigned color = 0xffffffff);