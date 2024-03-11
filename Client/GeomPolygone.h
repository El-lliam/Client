#pragma once
#include <vector>
#include "Point.h"
#include "GeomSimple.h"
#include <string>
#include <sstream>
class Visitor;
class GeomPolygone : public GeomSimple
{
public:
	GeomPolygone(vector<int>& v);
	virtual string toString();
	virtual void accept(Visitor* v);
	virtual float surface() { 
		/*Calculer la superficie
		 S = 1/2 * [(x1y2-x2y1)+(x2y3-x3y2)+(x3y1-x1y3)]
		Une figure avec plus de trois sommets a une aire,les trois points ne peuvent pas etre sur la meme ligne
		*/
		if (points.size() < 3)
			return 0;
		float res = 0;
		Point* first = points[0];//Obtenir les coordonnes du premier point
		float x1 = first->getX();
		float y1 = first->getY();
		for (int i = 2; i < points.size(); ++i) {
			float x2 = points[i]->getX();
			float y2 = points[i]->getY();
			float x3 = points[i - 1]->getX();
			float y3 = points[i - 1]->getY();
			res += x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;//Divisez le polygone en plusieurs triangles et calculez respectivement deux fois leur aire
		}
		return res / 2; //diviser par 2
	}
};