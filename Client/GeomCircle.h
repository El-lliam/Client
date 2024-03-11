#pragma once
#include <vector>
#include "Point.h"
#include "GeomSimple.h"
#include <string>
#include <sstream>
class Visitor;
class GeomCircle : public GeomSimple
{
	/* Un cercle dans des graphiques simples, comprenant 
		un centre 
		un rayon
	*/
public:
	GeomCircle(int x, int y, int r);
	virtual string toString();
	virtual void accept(Visitor* v);
	virtual float surface() { return 3.14 * radius * radius; }//Calculer la superficie
	virtual void zoomBy(Point* pivot, float factor)
	{
		GeomSimple::zoomBy(pivot, factor);
		radius *= factor;
	}
private:
	Point* center;
	int radius;
};


