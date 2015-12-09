#include "Enemy.h"
#include "gamestate.h"
#include <iostream>

void Enemy::onCollision(GameObject & o)
{
}

void Enemy::onUpdate()
{
	trailDelay += sfw::getDeltaTime();
	if (trailDelay > trailRate)
	{
		trailDelay = 0;
		gs->s
	}
}

void Enemy::onInactive()
{
}
