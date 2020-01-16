#include "Musteri.h"
#include <string>
#include <fstream>
using namespace  std;

string isimlerListesi[] = { "Ahmet","Osman","Ali","Mehmet","Veli","Sarp","Emrah","Eser","Erbil","Oguz","Can","Murat","Sinan","Mert","Mete","Sait","Ervah","Cihat","Orhan","Fatih","Ahu","Binnur","Bilge","Candan","Cahide","Demet","Deste","Gizem","Ece","Elanur","Fatma","Fidan","Gamze","Hale","Hilal","Irmak","Jale","Kader","Kamile","Lale" };
string soyisimlerListesi[] = { "KANDEMIR","ORHON","VURAL","YAVUZ","UZ","ERDEM","DEDE","UYANIK","ASLAN","ERKURAN","ER","DAL","KARAKUM","YILMAZ","TAHTACI","KAYA","ERGE","ONUK","TOPAL","BEDER" };

Musteri::Musteri()
{
	int isimIndex = rand() % 40;
	int soyisimIndex = rand() % 20;

	mIsim = isimlerListesi[isimIndex];
	mSoyisim = soyisimlerListesi[soyisimIndex];

	mTcno = tcnouret();
	mTelno = telnoUret();
}
void Musteri::kaydet()
{
	std::fstream kayit;

	kayit.open("Musteriler.txt", std::fstream::in | std::fstream::out | std::fstream::app);

	if (kayit.is_open() == true)
	{
		kayit << isimGetir() << " " << soyisimGetir() << " " << " " << tcnoGetir() << " " << telnoGetir() << " " << tarihGetir().gunGetir() << " /" << tarihGetir().ayGetir() << " /" << tarihGetir().yilGetir() << endl;
	}


	kayit.close();


}
string	Musteri::tcnoGetir()
{
	return mTcno;
}
string	Musteri::telnoGetir()
{
	return mTelno;
}
string	Musteri::isimGetir()
{
	return mIsim;
}

std::string	Musteri::soyisimGetir()
{
	return mSoyisim;
}
Tarih	Musteri::tarihGetir()
{
	return mDogumTarihi;
}

void Musteri::isimAta(std::string isim)
{
	mIsim = isim;
}
void Musteri::telnoAta(string telno)
{
	mTelno = telno;
}
void Musteri::tcnoAta(string tcno)
{
	mTcno = tcno;
}
void Musteri::soyisimAta(string soyisim)
{
	mSoyisim = soyisim;
}
void Musteri::tarihAta(Tarih tarih)
{
	mDogumTarihi = tarih;
}

string	Musteri::tcnouret()
{
	string tcno = "";

	for (int i = 0; i < 4; i++)
	{
		tcno += '1' + rand() % 9;
	}
	return tcno;
}

std::string	Musteri::telnoUret()
{
	std::string telno = "";
	for (int i = 0; i < 10; i++)
	{
		telno += '0' + rand() % 10;
	}
	return telno;
}
