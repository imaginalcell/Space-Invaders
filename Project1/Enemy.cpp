#include "Enemy.h"
#include "gamestate.h"
#include <iostream>

void Enemy::onCollision(GameObject & o)
{
	if (o.vel.y > 0)
	{
		setInactive();
		o.setInactive();
		gs->score++;
	}
}

void Enemy::onUpdate()
{
	trailDelay += sfw::getDeltaTime();
	if (trailDelay > trailRate)
	{
		trailDelay = 0;
		gs->spawnParticle(pos.x +randRange(-1.f,1.f), pos.y + radius, 3, 0, 1, RED);
	}
	delay += sfw::getDeltaTime();
	if (delay > rof)
	{
		delay = randRange(-.5f, .5f);
		gs->spawnBullet(pos.x, pos.y - radius, -300);
	}
	if (pos.y < BOUNDS_BOTTOM)
		active = false;
}

void Enemy::onInactive()
{
	gs->spawnParticle(pos.x, pos.y, 0, 100, .1f, RED);
	gs->spawnParticle(pos.x, pos.y, 3, 15, .4f, YELLOW);
	gs->spawnParticle(pos.x, pos.y, 12, 0, .3f, MAGENTA);
}
