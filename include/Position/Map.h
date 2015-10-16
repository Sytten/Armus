/*
============================================================================
 Name : Map
 Author : M.A.G.I.E Team
 Modified on: 2015-10-16
 Description : Map the different targets available to our robots depending
			   on is position and inform him about its initial location.
============================================================================
*/

#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Position/Vector2.h"
#include "Position/Distance.h"
#include "Behavior.h"
#include "Sensors/Color.h"

struct Target
{
	Target():position(0, 0),color(Grey){}
	Target(float p_x, float p_y, Color p_color):position(p_x, p_y),color(p_color){}

	Vector2<float> position;
	Color color;
};

class Map
{
	private:
		struct StartingPoint
		{
			StartingPoint(float p_x, float p_y, float p_angle, Color p_color):position(p_x, p_y),angle(p_angle), color(p_color){}
			Vector2<float> position;
			float angle;
			Color color;
			Behavior behavior;
		};

	public:
		Map();
		std::vector<Target> raceTargets(Color p_startingColor, bool p_goingLeft, Behavior p_behavior);
		Vector2<float> initialPosition(Color p_startingColor, bool p_goingLeft, Behavior p_behavior);
		float initialAngle(Color p_startingColor, bool p_goingLeft, Behavior p_behavior);

	private:
		std::vector<Target> m_targets;
		std::vector<StartingPoint> m_initialPositions;
};

#endif
