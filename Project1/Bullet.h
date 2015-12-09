#pragma once
#include "gameobject.h"
#include <cmath>

class Bullet : public GameObject
{
public:
	float lifespan;

	Bullet(float x, float y, float a_speed)
		:GameObject(x, y, 10), lifespan(3.0f)
	{
		speed = a_speed;
		if (speed > 0)
			color = CYAN;
		else color = WHITE;
		vel.y = speed;
	}
	void onUpdate()
	{
		lifespan -= sfw::getDeltaTime();
		if (lifespan < 0) active = false;
	}
};