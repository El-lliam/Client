#include "TCP_visitor.h"
#include "Client.h"
#include "CmdForServer.h"
void TCP_visitor::visit(GeomCircle* geom) {
	sendTcpReqest(CMD_CIRCLE, geom); //Envoyer des données circulaires au serveur
}

void TCP_visitor::visit(GeomCompos* geom) {
	geom->accept(this);//Parce qu'il s'agit d'une combinaison de graphiques, composée de plusieurs graphiques, utilisez donc la fonction d'acceptation pour vous souvenir
}

void TCP_visitor::visit(GeomPolygone* geom) {
	sendTcpReqest(CMD_POLYGONE, geom);//Envoyer les données de polygone au serveur
}
void TCP_visitor::visit(GeomLine* geom) {
	sendTcpReqest(CMD_LINE, geom);//Envoyer les données du segment de ligne au serveur
}
void TCP_visitor::sendTcpReqest(const char* cmd, GeomSimple* geom) {//Affichez les mots que le graphique est créé et envoyez-le au serveur.
	stringstream ss;
	ss << cmd << " " << geom->toString();
	string request = ss.str();
	Client::GetInstance()->Send(request);
}