#pragma once
#include "GeomCompos.h"
#include "GeomCircle.h"
#include "GeomPolygone.h"
#include "GeomLine.h"
	class Visitor
{
	/* Classe mère du mode visiteur, le mode visiteur permet de découpler le contenu graphique (forme, taille, sommet, longueur des côtés, etc.)
	Pour tout code lié au graphisme, il suffit de changer le visiteur correspondant.
	seul visiteur tcp est TCP_visitor
	*/
public:
	virtual void visit(GeomCircle* geom) = 0;
	virtual void visit(GeomCompos* geom) = 0;
	virtual void visit(GeomPolygone* geom) = 0;
	virtual void visit(GeomLine* geom) = 0;
};
