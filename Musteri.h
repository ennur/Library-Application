#pragma once
#include<string>
#include "Tarih.h"
using namespace std;

class Musteri
{
public:
	Musteri();
	void kaydet();
	string	tcnoGetir();
	string	telnoGetir();
	string	isimGetir();
	string	soyisimGetir();
	Tarih	tarihGetir();

	void isimAta(string isim);
	void telnoAta(string telno);
	void tcnoAta(string tcno);
	void soyisimAta(string soyisim);
	void tarihAta(Tarih tarih);

	string	tcnouret();
	string	telnoUret();
private:
	string mIsim;
	string mSoyisim;
	string mTcno;
	string mTelno;
	Tarih  mDogumTarihi;
};
