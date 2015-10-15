#include "Position/Map.h"

Map::Map()
{
	m_targets.push_back(Target(121.92, 0, Purple));
	m_targets.push_back(Target(-121.92, 0, Green));
	m_targets.push_back(Target(0, 121.92, Yellow));
	m_targets.push_back(Target(0, -121.92, Blue));
	m_targets.push_back(Target(0, 0, Grey));
}

std::vector<Target> Map::raceTargets(Color p_startingColor, bool p_goingLeft, Behavior p_behavior)
{
	std::vector<Target> targets;

	if(p_behavior == Ninja)
	{
		Vector2<float> position = initialPosition(p_startingColor, p_goingLeft, p_behavior);
		float angle = initialAngle(p_startingColor, p_goingLeft, p_behavior);
		Target closestTarget;
		float closestDistance = 1000;

		for(int i = 0; i < m_targets.size(); ++i)
		{
			if(m_targets[i].color == p_startingColor)
				targets.push_back(m_targets[i]);
		}

		for(int i = 0; i < m_targets.size(); ++i)
		{
			if(sqrtDistance(position, m_targets[i].position) < closestDistance)
			{
				closestDistance = sqrtDistance(position, m_targets[i].position);
				closestTarget = m_targets[i];
			}
		}
		targets.push_back(closestTarget);

		closestTarget.position = position + vectorToCartesian(91.44, angle);
		closestTarget.color = Other;
		targets.push_back(closestTarget);
	}
	else
	{
		for(int i = 0; i < m_targets.size(); ++i)
		{
			if(m_targets[i].color == Grey)
				targets.push_back(m_targets[i]);
		}
	}

	return targets;
}

Vector2<float> Map::initialPosition(Color p_startingColor, bool p_goingLeft, Behavior p_behavior)
{
	for(int i = 0; i < m_initialPositions.size(); ++i)
	{
		if(m_initialPositions[i].color == p_startingColor && m_initialPositions[i].behavior == p_behavior)
		{
			if(p_startingColor == Blue)
			{
				if(!p_goingLeft && m_initialPositions[i].position.x < 0)
					return m_initialPositions[i].position;
				else if (p_goingLeft && m_initialPositions[i].position.x > 0)
					return m_initialPositions[i].position;
			}

			if(p_startingColor == Green)
			{
				if(!p_goingLeft && m_initialPositions[i].position.y > 0)
					return m_initialPositions[i].position;
				else if (p_goingLeft && m_initialPositions[i].position.y < 0)
					return m_initialPositions[i].position;
			}

			if(p_startingColor == Yellow)
			{
				if(!p_goingLeft && m_initialPositions[i].position.x > 0)
					return m_initialPositions[i].position;
				else if (p_goingLeft && m_initialPositions[i].position.x < 0)
					return m_initialPositions[i].position;
			}

			if(p_startingColor == Purple)
			{
				if(!p_goingLeft && m_initialPositions[i].position.y < 0)
					return m_initialPositions[i].position;
				else if (p_goingLeft && m_initialPositions[i].position.y > 0)
					return m_initialPositions[i].position;
			}
		}
	}
}

float Map::initialAngle(Color p_startingColor, bool p_goingLeft, Behavior p_behavior)
{
	Vector2<float> position = initialPosition(p_startingColor, p_goingLeft, p_behavior);

	for(int i = 0; i < m_initialPositions.size(); ++i)
	{
		if(m_initialPositions[i].position == position)
			return m_initialPositions[i].angle;
	}
}
