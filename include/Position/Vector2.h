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

#include <math.h>

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
		T angle() const { return atan2(y,x) * 180.0 / 3.1416; }

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
