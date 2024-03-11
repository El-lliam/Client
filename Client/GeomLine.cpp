#include "GeomLine.h"
#include "Visitor.h"
void GeomLine::accept(Visitor* v) {
	v->visit(this);
}

GeomLine::GeomLine(int x1, int y1, int x2, int y2) {
	p1 = new Point(x1, y1);
	p2 = new Point(x2, y2);
	points.push_back(p1);
	points.push_back(p2);
};

string GeomLine::toString() {
	stringstream ss;
	ss << p1->toString() << " " << p2->toString() << " " << GeomSimple::toString() << endl;
	return ss.str();
}
