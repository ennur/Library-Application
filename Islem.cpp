#include "Islem.h"
#include "Urun.h"
#include "Musteri.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

Islem::Islem()
{
	 
	mIslemKodu = islemKoduUret();

}

string Islem::urunKoduGetir()
{
	
	return mUrunKodu;
}

string Islem::tcNoGetir()
{   
	return mMusteriTcNo;

}

string Islem::islemKoduGetir()
{
	return mIslemKodu ;
}


void Islem::kaydet()
{ 
	std::fstream kayit;
	kayit.open("Islemler.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	if (kayit.is_open() == true)
	{
		kayit << islemKoduGetir() << " " << urunKoduGetir() << " " << tcNoGetir() << endl;

	}
	kayit.close();
}

string Islem::islemKoduUret()
{   
	for (int i = 0; i < 4; i++)
	{
		mIslemKodu += '1' + rand() % 9;
	}
	return mIslemKodu;
}

void Islem::tcAta(string tc)
{
	mMusteriTcNo = tc;
}

void Islem::urunKoduAta(string urun)
{
	mUrunKodu = urun;
}
