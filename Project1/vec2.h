#pragma once

struct vec2 {float x, y;};

bool circleOverlap(vec2 p1, float r1, vec2 p2, float r2);
float DistanceFormula(vec2 a, vec2 b);

vec2 operator+(vec2 a, vec2 b);
vec2 operator-(vec2 a, vec2 b);

vec2 operator/(vec2 a, float b);
vec2 operator*(vec2 a, float b);

bool operator==(vec2 a, vec2 b);

vec2 integrate(vec2 pos, vec2 vel,float dt );

float randRange(float min, float max);

float lerp(float start, float end, float alpha);