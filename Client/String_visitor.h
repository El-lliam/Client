#pragma once
#include "Visitor.h"
#include <string>

class String_visitor : public Visitor
{
	/*
	La sous-classe du mode visiteur, le mode visiteur permet de découpler le contenu graphique (forme, taille, sommet, longueur d'arète, etc.)
	Pour tout code li?au graphisme, il suffit de changer le visiteur correspondant est TCP_visitor
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