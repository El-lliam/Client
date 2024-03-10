#pragma once
#include <sstream>
#include <string>
#include <iostream>
#include <cmath>
#define PI 3.1415926

using namespace std;

class Vector2d
{
public:
	float x, y; /*il n'y a pas de valeur interdite pour x et y */


	explicit Vector2d(float x = 0, float y = 0) :x(x), y(y) {}

	/* ?la place de string on peut mettre n'importe quel type
	permet de faire un "cast" en string */
	operator string () const
	{
		ostringstream os;
		os << "( " << x << ", " << y << ")";
		return os.str();
	}


	const Vector2d operator +(const Vector2d& v) const
	{
		return Vector2d(this->x + v.x, this->y + v.y);
	}
	// v7 = v1.operator + ( v2)

// v5 = v1.operator*(5);

	const Vector2d operator *(const float& a) const
	{
		return Vector2d(this->x * a, this->y * a);
	}

	// v4 = v1.operator-()

	const Vector2d operator-()
	{
		return Vector2d(-x, -y);
	}

	Vector2d Rotate(float radian) {
		float sina = sin(radian);
		float cosa = cos(radian);
		return Vector2d(x * cosa - y * sina, x * sina + y * cosa);
	}

};//Vector2d

inline ostream& operator << (ostream& os, const Vector2d& v)
{
	return os << (string)v; // appelle la méthode : v.operator string
}

//v8 = operator*(2.5,v1);

inline Vector2d operator *(const float& a, const Vector2d& v)
{
	return v * a;
}


