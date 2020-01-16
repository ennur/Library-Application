#pragma once
#include<string>
using namespace std;

class Urun
{
public:
	Urun();

	void	kaydet();

	string	urunAdiGetir();
	string	urunKoduGetir();
	string	urunFiyatiGetir();

	void	urunAdiAta(string urunAdi);
	void	urunKoduAta(string urunkodu);
	void    urunFiyatiAta(string fiyat);
	
	string 	fiyatUret();
  string	urunKoduUret();
	
private:

	string	m_UrunKodu;
	string	m_UrunAdi;
	string	m_Fiyat;
};
