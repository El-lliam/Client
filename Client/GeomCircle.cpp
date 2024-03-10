#include "GeomCircle.h"
#include "Visitor.h"
void GeomCircle::accept(Visitor* v) {//La fonction visite permet d'accéder aux données de base du graphisme, les coordonnées du centre du cercle, le rayon, etc.
	v->visit(this);
}

GeomCircle::GeomCircle(int x, int y, int r) {//Les éléments de base qui composent un cercle
	this->center = new Point(x, y);
	points.push_back(this->center);//Ajouter le centre de ce cercle ?la collection de sommets de graphiques simples
	radius = r;
};

string GeomCircle::toString() {
	stringstream ss;
	ss << center->toString() << " " << radius << " " << GeomSimple::toString() << endl;
	return ss.str();
}
