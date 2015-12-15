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
		{
			sprite = plrM;
		}
		else
		{
			sprite = eMis;
		}
		vel.y = speed;
	}
	void onUpdate()
	{
		lifespan -= sfw::getDeltaTime();
		radius -= sfw::getDeltaTime() * 4;
		if (lifespan < 0) active = false;
	}
};