#include "Position/Angle.h"

float rotationAngle(Vector2<float> const& p_1, Vector2<float> const& p_2)
{
	float dot = p_1.x*p_2.x + p_1.y*p_2.y;
	float det = p_1.x*p_2.y - p_1.y*p_2.x;

	return atan2(det, dot) * 180.0 / 3.1416;
}

float rotationAngle(float const& p_angle1, float const& p_angle2)
{
	return p_angle1-p_angle2;
}
