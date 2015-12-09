#pragma once
#include "gameobject.h"

class Player : public GameObject
{
public:
	float delay, rof;
	int health;

	Player(float x,float y) 
			:GameObject(x,y,35)
	{
		speed = 175;
	}

	void onUpdate();
	void onCollision(GameObject &o);
	void onInactive();
};