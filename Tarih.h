#pragma once

using namespace std;

class Tarih
{
public:
	 string tarihGetir();
	 int gunGetir();
	 int ayGetir();
	 int yilGetir();

	 Tarih();

private:
	int tarih_gun;
	int tarih_ay;
	int tarih_yil;

};


