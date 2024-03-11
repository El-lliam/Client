#pragma once
#include "Visitor.h"
#include <string>

class String_visitor : public Visitor
{
	/*
	La sous-classe du mode visiteur, le mode visiteur permet de decoupler le contenu graphique (forme, taille, sommet, longueur d'arete, etc.)
	Pour tout code liee au graphisme, il suffit de changer le visiteur correspondant est TCP_visitor
	*/
public:
	virtual void visit(GeomCircle* geom);
	virtual void visit(GeomCompos* geom);
	virtual void visit(GeomPolygone* geom);
	virtual void visit(GeomLine* geom);
	string getString();
private:
	string result;

};