#include "Position/Map.h"

Map::Map()
{
	m_targets.push_back(Target(121.92, 0, Purple));
	m_targets.push_back(Target(-121.92, 0, Green));
	m_targets.push_back(Target(0, 121.92, Yellow));
	m_targets.push_back(Target(0, -121.92, Blue));
	m_targets.push_back(Target(0, 0, Grey));
}

std::vector<Target> Map::raceTargets(Color p_startingColor, bool p_is_left, Behavior p_behavior)
{
	std::vector<Target> targets;

	if(p_behavior == Ninja)
	{
		Vector2<float> position = initialPosition(p_startingColor, p_is_left, p_behavior);
		float angle = initialAngle(p_startingColor, p_is_left, p_behavior);
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

Vector2<float> Map::initialPosition(Color p_startingColor, bool p_is_left, Behavior p_behavior)
{

}

float Map::initialAngle(Color p_startingColor, bool p_is_left, Behavior p_behavior)
{

}
