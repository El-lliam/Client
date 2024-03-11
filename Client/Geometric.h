#pragma once
#include "Point.h"
using namespace std;
class Visitor;
class Geometric
{
	/* La classe parente de tous les graphiques est une classe abstraite.
	Les sous-classes sont GeomSimple pour les graphiques simples et GeomCompos pour les graphiques composites
	*/
public:
	virtual ~Geometric() {};
	virtual void accept(Visitor* v) = 0;//Graphiques combinee, qui sont un pointeur/une liste/un tableau, utilise pour stocker une serie de graphiques
	virtual void moveBy(Vector2d& v) = 0;//traduction graphique
	virtual void rotateBy(Point* pivot, float radian) = 0;//rotation graphique
	virtual void zoomBy(Point* pivot, float factor) = 0;//Agrandissement ou reduction 
	virtual float surface() = 0;
	virtual string toString() = 0;
	virtual void setColor(int rr, int gg, int bb) = 0;
};