#include "declconst.h"
#include "Player.h"
#include "sfwdraw.h"
#include "gamestate.h"

void Player::onUpdate()
{
	vel = { 0,0 };
	
	
	delay += sfw::getDeltaTime();
	if (sfw::getKey(' ') && delay > rof)
	{
		delay = 0;
		gs->spawnBullet(pos.x, pos.y, 300);
	}
	if (sfw::getKey('A'))
	{
		vel.x = -speed;
	}
	if (sfw::getKey('D'))
	{
		vel.x = speed;
	}
//Collision with wall
	if (pos.x - radius < BOUNDS_LEFT)
	{
		pos.x = BOUNDS_LEFT + radius;
	}
	if (pos.x + radius > BOUNDS_RIGHT)
	{
		pos.x = BOUNDS_RIGHT - radius;
	}
}

void Player::onCollision(GameObject & o)
{
	if (o.vel.y < 0)
	{
 		health--;
		o.active = false;
		radius += .77;
		switch (health)
		{
		case 2: ; break;
		case 1: ; break;
		case 0: active = false; break;
		}
	}
}

void Player::onInactive()
{
	gs->spawnParticle(pos.x, pos.y, 0, 600, .2f, RED);
	gs->spawnParticle(pos.x, pos.y, 3, 15, .4f, YELLOW);
	gs->spawnParticle(pos.x, pos.y, 12, 0, .3f, MAGENTA);
	gs->spawnParticle(pos.x, pos.y, 15, 24, .6f, GREEN);
}
