#include "Position/Map.h"

Map::Map()
{
	m_targets.push_back(Target(63.91, 63.91, Pink));
	m_targets.push_back(Target(-63.91, -63.91, Green));
	m_targets.push_back(Target(-63.91, 63.91, Yellow));
	m_targets.push_back(Target(63.91, -63.91, Blue));
	m_targets.push_back(Target(0, 0, Grey));

	m_initialPositions.push_back(StartingPoint(137, 21.3, 180, Yellow, Sumo));
	m_initialPositions.push_back(StartingPoint(137, 51.8, 180, Yellow, Ninja));
	m_initialPositions.push_back(StartingPoint(-25.4, -139.7, 90, Yellow, Sumo));
	m_initialPositions.push_back(StartingPoint(-55.88, -139.7, 90, Yellow, Ninja));

	m_initialPositions.push_back(StartingPoint(25.4, 137, 270, Blue, Sumo));
	m_initialPositions.push_back(StartingPoint(55.88, 137, 270, Blue, Ninja));
	m_initialPositions.push_back(StartingPoint(-139.7, -21.3, 0, Blue, Sumo));
	m_initialPositions.push_back(StartingPoint(-139.7, -51.8, 0, Blue, Ninja));

	m_initialPositions.push_back(StartingPoint(-25.4, 137, 270, Green, Sumo));
	m_initialPositions.push_back(StartingPoint(-55.88, 137, 270, Green, Ninja));
	m_initialPositions.push_back(StartingPoint(139.7, -21.3, 180, Green, Sumo));
	m_initialPositions.push_back(StartingPoint(139.7, -51.8, 180, Green, Ninja));

	m_initialPositions.push_back(StartingPoint(25.4, -137, 90, Pink, Sumo));
	m_initialPositions.push_back(StartingPoint(55.88, -137, 90, Pink, Ninja));
	m_initialPositions.push_back(StartingPoint(-137, 21.3, 0, Pink, Sumo));
	m_initialPositions.push_back(StartingPoint(-137, 51.8, 0, Pink, Ninja));

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

			if(p_startingColor == Pink)
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
