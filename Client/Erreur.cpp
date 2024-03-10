#define _CRT_SECURE_NO_WARNINGS
using namespace std;

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include "Erreur.h"



//int Erreur::LONGUEURMESSAGE(50);

Erreur::Erreur()
{
	strcpy(this->message, "Erreur !");
}

Erreur::Erreur(const char* messageErreur)
{
	strcpy(this->message, "Erreur : ");
	int l = strlen(messageErreur);
	static int n = LONGUEURMESSAGE - 9;
	if (l <= n) strcat(this->message, messageErreur);
	else
	{
		strncat(this->message, messageErreur, n);
		this->message[LONGUEURMESSAGE] = '\0';
	}
}

Erreur::operator string() const
{
	return string(this->message);
}

ostream& operator << (ostream& os, const Erreur& erreur)
{
	os << (string)erreur;
	return os;
}