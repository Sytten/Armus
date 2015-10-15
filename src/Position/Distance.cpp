#include "Position/Distance.h"

float sqrtDistance(Vector2<float> p_1, Vector2<float> p_2)
{
	double xSqr = double(p_1.x - p_2.x) * (p_1.x - p_2.x);
	double ySqr = double(p_1.y - p_2.y) * (p_1.y - p_2.y);

	return (float)sqrt(xSqr + ySqr);
}

Vector2<float> vectorToCartesian(float p_distance, float p_angle)
{
	Vector2<float> coordinates;
		coordinates.x = cos(p_angle) * p_distance;
		coordinates.y = sin(p_angle) * p_distance;

	return coordinates;
}

bool near(Vector2<float> p_1, Vector2<float> p_2)
{
	if(sqrtDistance(p_1, p_2) < 4)
		return true;
	else
		return false;
}

