/*
============================================================================
 Name : Angle
 Author : M.A.G.I.E Team
 Modified on: 2015-10-15
 Description : Compute the angle between two vectors.
============================================================================
*/

#ifndef ANGLE_H_
#define ANGLE_H_

#include "Position/Vector2.h"
#include <math.h>

float rotationAngle(Vector2<float> const& p_1, Vector2<float> const& p_2);
float rotationAngle(float const& p_angle1, float const& p_angle2);

#endif /* ANGLE_H_ */
