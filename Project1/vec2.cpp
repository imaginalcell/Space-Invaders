#include "vec2.h"
#include <cmath>
#include <ctime>

//0 = start
//.5 = midpoint
//1 = end
float lerp(float start, float end, float alpha)
{
	return start+alpha*(end - start);
}

float randRange(float min, float max)
{
	float alpha = rand() / (RAND_MAX*1.f);

	return min + alpha*(max - min);
}

bool circleOverlap(vec2 p1, float r1, vec2 p2, float r2)
{
	float d = DistanceFormula(p1, p2);
	float r = r1 + r2;
	return d < r;
}

float DistanceFormula(vec2 a, vec2 b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;

	//sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))
	return sqrt(dx*dx + dy*dy);
}

vec2 operator+(vec2 a, vec2 b)
{
	vec2 retval;
	retval.x = a.x + b.x;
	retval.y = a.y + b.y;
	return retval;
}
vec2 operator-(vec2 a, vec2 b)
{
	vec2 retval;
	retval.x = a.x - b.x;
	retval.y = a.y - b.y;
	return retval;
}

vec2 operator/(vec2 a, float b)
{
	vec2 retval;
	retval.x = a.x / b;
	retval.y = a.y / b;
	return retval;
}
vec2 operator*(vec2 a, float b)
{
	vec2 retval;
	retval.x = a.x * b;
	retval.y = a.y * b;
	return retval;
}

bool operator==(vec2 a, vec2 b)
{
	return a.x == b.x && a.y == b.y;
}

vec2 integrate(vec2 pos, vec2 vel, float dt)
{
	return pos + vel*dt;
}