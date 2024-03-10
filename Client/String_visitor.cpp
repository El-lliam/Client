#include "String_visitor.h"
#include "CmdForServer.h"
void String_visitor::visit(GeomCircle* geom) {
	stringstream ss;
	ss << CMD_CIRCLE << " " << geom->toString();
	result = result + ss.str();
}

void String_visitor::visit(GeomCompos* geom) {
	geom->accept(this);
}

void String_visitor::visit(GeomPolygone* geom) {
	stringstream ss;
	ss << CMD_POLYGONE << " " << geom->toString();
	result = result + ss.str();
}
void String_visitor::visit(GeomLine* geom) {
	stringstream ss;
	ss << CMD_LINE << " " << geom->toString();
	result = result + ss.str();
}
string String_visitor::getString() {
	return result;
}