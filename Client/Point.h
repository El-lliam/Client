#pragma once
#include <string>
#include <sstream>
#include "Vector2d.h"
using namespace std;
class Point
{
private:
	int x = 0;
	int y = 0;
	Vector2d vectorTo(Point* other) {//Calculer le vecteur, le point de d¨¦part est (0, 0)
		return Vector2d(other->x - x, other->y - y);
	}
public:
	Point(int xx, int yy) {
		x = xx;
		y = yy;
	};
	int getX() { return x; };
	int getY() { return y; };
	int setX(int newx) { x = newx; };
	int setY(int newy) { y = newy; };
	string toString()
	{
		stringstream ss;
		ss << x << " " << y;
		return ss.str();
	};


	void moveBy(Vector2d& v) {//traduction ponctuelle
		x += v.x;
		y += v.y;
	}

	void rotateBy(Point* pivot, float radian) {//La rotation du point, radian est radians
		Vector2d v = pivot->vectorTo(this).Rotate(radian);//Faire pivoter le vecteur form?par le pivot et le point courant
		x = pivot->x + v.x;
		y = pivot->y + v.y;
	}

	void zoomBy(Point* pivot, float factor) {
		Vector2d v = pivot->vectorTo(this) * factor;//Zoom avant/arri¨¨re sur le vecteur form?par le pivot et le point courant
		x = pivot->x + v.x;//Le rôle des deux fonctions ci-dessus est de compléter la rotation des graphiques
		y = pivot->y + v.y;//Si tous les points d'un graphique ont subi des changements correspondants, alors le graphique entier a subi des changements correspondants
	}
};