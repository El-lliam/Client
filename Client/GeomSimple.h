#pragma once
#include <vector>
#include "Point.h"
#include "Geometric.h"
#include <string>

using namespace std;
class Visitor;
class GeomSimple : public Geometric
{
	/* Les graphiques simples, par opposition aux graphiques hybrides GeomCompos, les graphiques simples sont de vrais graphiques, tels que des cercles, des triangles, des polygones, des lignes, etc.
	* Ils h�ritent tous de cette classe, les op�rations de move, de rotate et de zoom agissent directement sur tous ses sommets
	*/
public:
	virtual ~GeomSimple()
	{
		for (Point* p : points) {
			delete p;
		}
	};
	virtual string toString() {
		stringstream ss;
		ss << r << " " << g << " " << b;
		return ss.str();
	};
	virtual void accept(Visitor* v) = 0;
	virtual void moveBy(Vector2d& v) //Pour traduire le graphique, il vous suffit de traduire tous les points du graphique
	{
		for (Point* p : points) {
			p->moveBy(v);
		}
	}
	virtual void rotateBy(Point* pivot, float radian) //faire pivoter tous les points
	{
		for (Point* p : points) {
			p->rotateBy(pivot, radian);
		}
	}
	virtual void zoomBy(Point* pivot, float factor)//Zoom avant ou arri�re pour tous les points
	{
		for (Point* p : points) {
			p->zoomBy(pivot, factor);
		}
	}

	virtual void addPoint(Point* p)//Ajouter un sommet suppl�mentaire au polygone
	{
		points.push_back(p);
	}

	virtual float surface() = 0;


	virtual void setColor(int rr, int gg, int bb) {	//Utilisez la m�thode de r�glage des couleurs RGB pour d�finir la couleur initiale du graphique.
		r = rr;
		g = gg;
		b = bb;
	}

protected:
	vector<Point*> points; //L'ensemble des sommets des graphiques simples, le sommet d'un cercle est le centre du cercle, la ligne est les deux extr�mit�s, etc.
	int r = 0;
	int g = 0;
	int b = 0;
};