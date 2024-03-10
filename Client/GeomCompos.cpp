#include "GeomCompos.h"
#include "Visitor.h"
GeomCompos::~GeomCompos() {
	for (Geometric* g : geoms) {
		delete g;
	}
};
void GeomCompos::accept(Visitor* v) {//Envoyer un graphique au serveur

	for (Geometric* g : geoms) {
		g->accept(v);
	}
}

void GeomCompos::add(Geometric* g) {//ajouter une nouvelle forme
	geoms.push_back(g);
}

void GeomCompos::moveBy(Vector2d& v) {//traduire
	for (Geometric* g : geoms) {
		g->moveBy(v);
	}
}
void GeomCompos::rotateBy(Point* pivot, float radian) {//Faire tourner
	for (Geometric* g : geoms) {
		g->rotateBy(pivot, radian);
	}
}
void GeomCompos::zoomBy(Point* pivot, float factor) {//zoomer ou dézoomer
	for (Geometric* g : geoms) {
		g->zoomBy(pivot, factor);
	}
}

float GeomCompos::surface() {//Calculer la surface de tous les graphiques
	float res = 0;
	for (Geometric* g : geoms) {
		res += g->surface();
	}
	return res;
}

string GeomCompos::toString() {
	stringstream ss;
	for (Geometric* g : geoms) {
		ss << g->toString();
	}
	return ss.str();
}

void GeomCompos::setColor(int rr, int gg, int bb) {
	for (Geometric* g : geoms) {
		g->setColor(rr, gg, bb);
	}
}