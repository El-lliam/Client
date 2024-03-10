#pragma once
#include <vector>
#include "Point.h"
#include "GeomSimple.h"
#include <string>
#include <sstream>
class Visitor;
class GeomLine : public GeomSimple
{
public:
	GeomLine(int x1, int y1, int x2, int y2);
	virtual string toString();
	virtual void accept(Visitor* v);
	virtual float surface() { return 0; }
private:
	Point* p1;
	Point* p2;
};