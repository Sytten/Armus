/*
============================================================================
 Name : Distance
 Author : M.A.G.I.E Team
 Modified on: 2015-10-15
 Description : Simple function to compute distances between points.
============================================================================
*/

#ifndef DISTANCE_H_
#define DISTANCE_H_

#include <math.h>
#include "Position/Vector2.h"

float sqrtDistance(Vector2<float> p_1, Vector2<float> p_2);

Vector2<float> vectorToCartesian(float p_distance, float p_angle);

bool near(Vector2<float> p_1, Vector2<float> p_2);


#endif /* DISTANCE_H_ */
