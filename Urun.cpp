#include "Urun.h"
#include <string>
#include <fstream>
using namespace std;
string urunListesi[] = { "Ekran_karti","Ses_Karti","Islemci","Klavye","Fare","Monitor","Ram","Sabit_Disk","Hoparlor","SSD_Disk","Notebook","Kasa","Flash_Disk","Tablet","Cep_Telefonu","Kulaklik","Yazici","Scanner","Optik_Okuyucu","Tv_Karti" };


Urun::Urun()
{
	int urunIndex = rand() % 20;
	m_UrunAdi = urunListesi[urunIndex];

	m_UrunKodu = urunKoduUret();
	m_Fiyat = fiyatUret();

}

void Urun::kaydet()
{
	std::fstream kayit;
	kayit.open("Urunler.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	if (kayit.is_open() == true)
	 {
		kayit << urunAdiGetir() << " " << urunKoduGetir() << " " << urunFiyatiGetir() << endl;

	 }
  kayit.close();
}

string Urun::urunAdiGetir()
{
	return m_UrunAdi;
}

string Urun::urunKoduGetir()
{
	return m_UrunKodu;
}

string Urun::urunFiyatiGetir()
{
	return m_Fiyat;
}

void Urun::urunAdiAta(string urunAdi)
{ 
	m_UrunAdi = urunAdi;
}

void Urun::urunKoduAta(string urunkodu)
{
	m_UrunKodu = urunkodu;
}
void Urun::urunFiyatiAta(string fiyat)
{ 
	m_Fiyat = fiyat;
}

string Urun::fiyatUret()
{   
	for (int i = 0; i < 3; i++)
	{
        m_Fiyat += '1' + rand() % 9;
	}
	return m_Fiyat;
}

string Urun::urunKoduUret()
{   
	for (int i = 0; i < 4; i++)
	{
		m_UrunKodu += '1' + rand() % 9;
	}
	return m_UrunKodu;

}
