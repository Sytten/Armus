/*
============================================================================
 Name : Vector2
 Author : M.A.G.I.E Team
 Modified on: 2015-10-15
 Description : Map the different targets available to our robots depending
			   on is position.
============================================================================
*/

#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>

template <class T>

class Vector2
{
	public:
		Vector2(): x(0), y(0) {}
		Vector2(T p_x, T p_y): x(p_x), y(p_y) {}
		Vector2(Vector2 const& other): x(other.x), y(other.y) {}

		Vector2& operator+=(Vector2 const& other){ x += other.x; y += other.y; return *this;}
		Vector2& operator-=(Vector2 const& other){ x -= other.x; y -= other.y; return *this;}

		T length() const { return sqrt(x*x + y*y);}
		T angle() { T angle = atan2(std::abs(y),std::abs(x)) * 180.0 / 3.1416;
							if(angle < 0.01)
							{
								angle = 0;
								y = 0;
							}
							if(angle > 89.9)
							{
								angle = 90;
								x = 0;
							}

							if(x < 0 && y >= 0)
								angle = 180 - angle;
							else if(x <= 0 && y < 0)
								angle += 180;
							else if(x > 0 && y < 0)
								angle += 270;

						  return angle;  }
		Vector2<T> abs() const { Vector2<T> p_vector(x,y);
						if(p_vector.x < 0)
							p_vector.x *= -1;
						if(p_vector.y < 0)
							p_vector.y *= -1;
						return p_vector; }

		T x;
		T y;
};

template <class T> Vector2<T> operator+(Vector2<T> a, Vector2<T> const& b)
{
	return a += b;
}

template <class T> Vector2<T> operator-(Vector2<T> a, Vector2<T> const& b)
{
	return a -= b;
}

template <class T> bool operator==(Vector2<T> const& a, Vector2<T> const& b)
{
	return (a.x == b.x && a.y == b.y);
}

#endif
