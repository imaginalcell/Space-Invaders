#pragma once

#include "vec2.h"
#include "declconst.h"
#include "sfwdraw.h"

class GameObject
{
public:
	static GameState *gs;

	vec2 pos, vel;
	float radius;
	unsigned sprite;
	unsigned color;
	float speed;
	bool active;

	GameObject(float x, float y, float radius)
		:pos({x,y}), speed(0),color(WHITE),
		vel({0,0}),radius(radius),active(true),sprite(dfault)
	{ }

	void draw();
	void update();

	void setInactive()
	{
		if (!active)return;
		active = false;
		onInactive();
	}

	virtual void onInactive() {}
	virtual void onUpdate() {}
	virtual void onDraw() {}
	virtual void onCollision(GameObject &o) {}
};
void collides(GameObject &a, GameObject &b);