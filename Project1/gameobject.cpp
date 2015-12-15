#include "gameobject.h"
#include "sfwdraw.h"

GameState *GameObject::gs;

void GameObject::update()
{
	if (!active) return;
	pos = integrate(pos, vel, sfw::getDeltaTime());

	onUpdate();
}

void GameObject::draw()
{
	if (!active) return;
	sfw::drawTexture(sprite, pos.x, pos.y, radius + 2, radius + 2, 0, true, 0, color);
	sfw::drawCircle(pos.x,pos.y,radius);
	onDraw();
}

void collides(GameObject &a, GameObject &b)
{
	if (a.active && b.active)
		if (circleOverlap(a.pos, a.radius,
			b.pos, b.radius))
		{
			a.onCollision(b);
			b.onCollision(a);
		}
}