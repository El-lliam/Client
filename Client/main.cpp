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

		GeomLine* line = new GeomLine(100, 100, 300, 100);
		line->setColor(96, 96, 96);
		g.add(line);

		vector<int> points = { 100,100, 100,196, 244,196 ,244,100,};
		GeomPolygone* polygone = new GeomPolygone(points);
		polygone->setColor(178,102,255);
		g.add(polygone);

		GeomCircle* c = new GeomCircle(222, 148, 20);
		c->setColor(0, 204, 0);
		g.add(c);

		Vector2d move = Vector2d(25, 50);
		g.moveBy(move);

		Point pivot = Point(75, 75);
		g.rotateBy(&pivot, 0.4);

		g.zoomBy(&pivot, 0.9);

		cout << "La surface est :" << g.surface() << endl;

		g.setColor(51,153,255);

		save(&g, "saved_data.txt");
		//load(&g, "saved_data.txt");

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