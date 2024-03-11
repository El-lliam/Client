#include "GeomCircle.h"
#include "Visitor.h"
void GeomCircle::accept(Visitor* v) {
	v->visit(this);
}

GeomCircle::GeomCircle(int x, int y, int r) {//Composent un cercle
	this->center = new Point(x, y);
	points.push_back(this->center);//Ajouter le centre de ce cercle a la collection de sommets de graphiques simples
	radius = r;
};

string GeomCircle::toString() {
	stringstream ss;
	ss << center->toString() << " " << radius << " " << GeomSimple::toString() << endl;
	return ss.str();
}
