#pragma once
#ifndef CLIENT
#define CLIENT
#include <winsock2.h>
#include <string>
using namespace std;

class Client
{
	/* ouvre la fen¨ºtre de communication
	* ne peut pas new, Le singleton global obtienne par GetInstance
	*/
private:
	WSADATA wsaData;
	SOCKET sock;
	Client();
	~Client();
	bool connected = false;//Connection est reussir
	static Client* instance;//Marquer la connection 
	void Connect(const char adresseServeur[], const short portServeur);//Connecter 

public:
	void Send(char* msg);//Envoyer des donn¨¦s de type char
	void Send(string& msg);//Envoyer des donn¨¦s de type cha?ne
	void DisConnect();//fermer la connexion
	static Client* GetInstance();//obtenir la connexion actuelle

	/*
	Envoyez des instructions pour enregistrer et lire les graphiques sur le serveur, et les graphiques seront enregistr¨¦ sur le serveur
	*/
	void SaveGraphics();//enregistrer les graphiques
	void LoadGraphics();//load les graphiques
};

#endif
