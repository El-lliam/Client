#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include "Erreur.h"
#include "Client.h"
#include "CmdForServer.h"

#pragma comment(lib, "ws2_32.lib")

Client* Client::instance = NULL;

Client* Client::GetInstance() {
	//Cr¨¦e une nouvelle connexion si la connexion actuelle est NULL
	if (!Client::instance)Client::instance = new Client();
	return Client::instance;
}

Client::Client() {
	int r;
	WSADATA wsaData;

	r = WSAStartup(MAKEWORD(2, 0), &wsaData);//la version

	if (r) throw Erreur("L'initialisation a ¨¦chouer);");

	cout << "On va commencer :" << endl;
	cout << "initialisation effectu¨¦" << endl;

	//---------------------- cr¨¦ation socket -------------------------------------------------

	// IPv4
	int familleAdresses = AF_INET;
	// mode TCP
	int typeSocket = SOCK_STREAM;
	// protocole
	int protocole = IPPROTO_TCP;            

	//cr¨¦r une sock
	this->sock = socket(familleAdresses, typeSocket, protocole);

	if (this->sock == INVALID_SOCKET)//Si la cr¨¦ation ¨¦choue
	{
		ostringstream oss;
		// pour les valeurs renvoyers par WSAGetLastError() : cf. doc  winsock
		oss << "la cr¨¦tion du socket a ¨¦houer: code d'erreur = " << WSAGetLastError() << endl;	
		throw Erreur(oss.str().c_str());
	}

	cout << "socket cr¨¦e" << endl;

	char addr[] = ADDRESS;
	short port = PORT;
	this->Connect(addr, port); //¨¦tablir la connexion au serveu
}

Client::~Client() {
	int r = shutdown(this->sock, SD_BOTH);// on coupe la connexion pour l'envoi et la r¨¦ception

	DisConnect();
	// renvoie une valeur non nulle en cas d'¨¦chec.
	if (r == SOCKET_ERROR)
		throw Erreur("la coupure de connexion a ¨¦chou?");


	r = closesocket(this->sock);  // renvoie une valeur non nulle en cas d'¨¦chec. Le code d'erreur peut ¨ºtre obtenu par un appel WSAGetLastError()
	if (r) throw Erreur("La fermeture du socket a ¨¦chou?");

	WSACleanup();//Met fin l'utilisation de la DLL Winsock 2 (Ws2_32.dll)
	cout << "Arr¨ºter normal du client" << endl;
}

void Client::Send(char* requete) {
	int r;
	int len = strlen(requete);

	//Envoyer les donn¨¦es et la requ¨¨te correspondante et la longueur de la requ¨ºte au serveur
	r = send(this->sock, requete, len, 0);
	char end[] = MSGEND;
	r = send(this->sock, end, 1, 0);
	if (r == SOCKET_ERROR)
		throw Erreur("¨¦chec de l'envoi de la requ¨¨te");
}

void Client::Send(string& requete) {
	int r;
	r = send(this->sock, requete.c_str(), requete.length(), 0);
	char end[] = MSGEND;
	r = send(this->sock, end, 1, 0);
	if (r == SOCKET_ERROR)
		throw Erreur("¨¦chec de l'envoi de la requ¨¨te");
}

void Client::Connect(const char adresseServeur[], short portServeur) {
	int r;
	SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer

	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = inet_addr(adresseServeur);   // inet_addr() convertit de l'ASCII en entier
	sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du r¨¦seau (little-endian ou big-endian)

	//-------------- connexion du client au serveur ---------------------------------------

	r = connect(this->sock, (SOCKADDR*)&sockaddr, sizeof(sockaddr));// renvoie une valeur non nulle en cas d'¨¦chec.
	// Le code d'erreur peut ¨ºtre obtenu par un appel WSAGetLastError()

	if (r == SOCKET_ERROR)
		throw Erreur("La connexion a ¨¦chouer");
	this->connected = true;
}


void Client::DisConnect() {
	if (this->connected) {
		char reques[] = CMD_QUIT;
		this->Send(reques);
		this->connected = false;
	}
}

void Client::SaveGraphics() //enregistrer l'image
{
	char save[] = CMD_SAVE;
	Send(save);
}
void Client::LoadGraphics() //load des images
{
	char load[] = CMD_LOAD;
	Send(load);
}