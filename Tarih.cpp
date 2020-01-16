#include <iostream>
#include "Tarih.h"
#include<string>
#include <stdlib.h>
using  namespace std;

string Tarih::tarihGetir()
{  
	
	string donus = "";

	donus = std::to_string(tarih_gun) +"/"+ std::to_string(tarih_ay) +"/"+ std::to_string(tarih_yil);

	return donus;
}

int Tarih::gunGetir()
{
	return tarih_gun;
}

int Tarih::ayGetir()
{
	return tarih_ay;
}

int Tarih::yilGetir()
{
	return tarih_yil;
}


Tarih::Tarih()
{
	
		tarih_gun = 1 + rand() % 30;
		tarih_ay = 1 + rand() % 12;
		tarih_yil = 1940 + rand() % 65;
}






