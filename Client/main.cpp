#include <winsock2.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include "Erreur.h"
#include "Client.h"
#include "TCP_visitor.h"
#include <vector>
#include "CmdForServer.h"
#include <fstream>
#include <iostream>
#include "String_visitor.h"
using namespace std;

void save(GeomCompos* G, const char* name) {
	ofstream outfile;
	outfile.open(name);
	String_visitor st;
	st.visit(G);
	outfile << st.getString();
	outfile.close();
}

void load(GeomCompos* G, const char* name) {
	ifstream infile;
	infile.open(name);
	string line;

	while (getline(infile, line))
	{
		stringstream ss;
		ss << line;
		int type;
		ss >> type;
		vector<int> p;
		int x, y, x1, y1, r;
		int cr, cg, cb;
		GeomCircle* res1;
		GeomPolygone* res2;
		GeomLine* res3;
		switch (type)
		{
		case ID_CIRCLE:
			ss >> x >> y >> r >> cr >> cg >> cb;
			res1 = new GeomCircle(x, y, r);
			res1->setColor(cr, cg, cb);
			G->add(res1);
			break;
		case ID_POLYGONE:
			while (!ss.eof())
			{
				int var;
				ss >> var;
				p.push_back(var);
			}
			cb = p.back();
			p.pop_back();
			cg = p.back();
			p.pop_back();
			cr = p.back();
			p.pop_back();
			res2 = new GeomPolygone(p);
			res2->setColor(cr, cg, cb);
			G->add(res2);
			break;
		case ID_LINE:

			ss >> x >> y >> x1 >> y1 >> cr >> cg >> cb;
			res3 = new GeomLine(x, y, x1, y1);
			res3->setColor(cr, cg, cb);
			G->add(res3);
			break;
		default:
			break;
		}
	}
	infile.close();
}

int main()
{
	try
	{
		GeomCompos g;


		GeomCircle* c = new GeomCircle(200, 200, 100); //Créer un cercle avec un milieu de 200 200 et un rayon de 100
		c->setColor(0, 125, 200); //définir la valeur RGB
		g.add(c); //Mettre dans le graphique global

		GeomLine* line = new GeomLine(0, 0, 400, 200); //Créer un segment de ligne du point final 0 0 au point final 400 400
		line->setColor(200, 125, 200); //définir la valeur RGB
		g.add(line); //Mettre dans le graphique global

		vector<int> points = { 50,50, 75,25, 100,50, 100,100 ,50,100 };// L'ensemble des sommets d'un polygone x1 y1 x2 y2  …
		GeomPolygone* pl = new GeomPolygone(points); //Créer un polygone à partir de cette collection
		pl->setColor(0, 0, 200); //définir la valeur RGB
		g.add(pl); //Mettre dans le graphique global

		Vector2d move = Vector2d(25, 50); //traduire ce vecteur
		g.moveBy(move); //Traduire tous les graphiques en vecteur de move

		Point pivot = Point(75, 75);//centre de rotation
		g.rotateBy(&pivot, 0.3);//Faites pivoter 1 radian autour du pivot, notez que les radians ne sont pas des angles

		g.zoomBy(&pivot, 0.5);//Centré sur le pivot, le graphique devient 0,5 fois la taille d'origine
		cout << "surface is:" << g.surface() << endl;
		g.setColor(0, 255, 0);//Tous les graphiques deviennent rouges
		save(&g, "saved_data.txt");//enregistrer tous les graphiques dans un fichier

		//load(&g, "saved_data.txt");//Lire le graphique enregistré en g

		//visitor
		TCP_visitor tcpv;
		g.accept(&tcpv);
		Client::GetInstance()->DisConnect();
	}
	catch (Erreur erreur)
	{
		cerr << erreur << endl;
	}



	return 0;

}