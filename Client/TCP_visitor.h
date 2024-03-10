#pragma once
#include "Visitor.h"

class TCP_visitor : public Visitor
{
	/*
	La sous-classe du mode visiteur, le mode visiteur permet de d�coupler le contenu graphique (forme, taille, sommet, longueur d'ar�te, etc.)
	Pour tout code li?au graphisme, il suffit de changer le visiteur correspondant est TCP_visitor
	*/
public:
	virtual void visit(GeomCircle* geom);
	virtual void visit(GeomCompos* geom);
	virtual void visit(GeomPolygone* geom);
	virtual void visit(GeomLine* geom);
	void sendTcpReqest(const char* cmd, GeomSimple* geom);
};
