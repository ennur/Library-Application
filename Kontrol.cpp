#include "Kontrol.h"
#include <iostream>
#include<iomanip>
#include<Windows.h>
#include<fstream>
#include "Musteri.h"
#include "Urun.h"
#include "Islem.h"
using namespace std;

char DUZCIZGI = 205;
char SOLUSTKOSE = 201;
char SAGUSTKOSE = 187;
char DIKEYCIZGI = 186;
char ASAGIAYRAC = 203;
char SOLALTKOSE = 200;
char SAGALTKOSE = 188;
char YUKARIAYRAC = 202;
char YATAYSAGAAYRAC = 204; 
char YATAYSOLAAYRAC = 185;
enum RENKLER
{
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHTGRAY = 7,
	DARKGRAY = 8,
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,
	WHITE = 15
};
void renkAta(int yazirenk)
{
	int arkaplan = 0;

	int sonRenk;

	sonRenk = (16 * arkaplan) + yazirenk;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), sonRenk);
}
void karakterCikar(char karakter, RENKLER renk)
{
	renkAta(renk);
	cout << karakter;
	renkAta(WHITE);
}


void Kontrol::tavanCiz(int genislik)
{
	cout << SOLUSTKOSE;

	for (int i = 0; i < genislik; i++)
		cout << DUZCIZGI;

	cout << SAGUSTKOSE;

	cout << endl;

}

void Kontrol::zeminCiz(int genislik)
{
	cout << SOLALTKOSE;

	for (int i = 0; i < genislik; i++)
		cout << DUZCIZGI;

	cout << SAGALTKOSE;

	cout << endl;
}
void Kontrol::araCiz(int genislik, string yazi)
{
	cout << DIKEYCIZGI;

	cout << std::left << setw(genislik) << yazi;

	cout << DIKEYCIZGI;
	cout << endl;
}

void Kontrol::ayracCiz(int genislik)
{
	cout << YATAYSAGAAYRAC;

	for (int i = 0; i < genislik; i++)
		cout << DUZCIZGI;

	cout << YATAYSOLAAYRAC;

	cout << endl;
}

void Kontrol::anaMenuCiz()
{    
	Kontrol k1;

	while (true)
	{
		system("cls");
		k1.tavanCiz(20);
		k1.araCiz(20, "Ana Kontrol Paneli");
		ayracCiz(20);

		k1.araCiz(20, "1.Musteri Paneli");
		k1.araCiz(20, "2.Yonetici Paneli");
		k1.araCiz(20, "3.Cikis");
		k1.araCiz(20, " ");
		k1.zeminCiz(20);


		cout << "secim...:";
		int secim;
		cin >> secim;

		if (secim == 1)
		{
			musteriMenuCiz();
		}
		else if (secim == 2)
		{
			yoneticiMenuCiz();
		}
		else
		{
			break;
		}
		system("pause");
	}

}

void Kontrol::musteriMenuCiz()
{
	musteriListele();
	string tcno;

	cout << "tcno..:";
	cin >> tcno;


	tavanCiz(20);
	araCiz(20, "Musteri Paneli");
	ayracCiz(20);

	araCiz(20, "1.Urun Al");
	araCiz(20, "2.Islemleri Listele");
	araCiz(20, "3.Islem Sil");
	araCiz(20, "4.Geri");
	araCiz(20, " ");
	zeminCiz(20);

	cout << "secim...:";
	int secim;
	cin >> secim;

	if (secim == 1)
	{
		urunListele();
		string urunkodu;
		cout << "Urun Kodunu Giriniz..:";
		cin >> urunkodu;
		urunAl(tcno, urunkodu);
	}
	else if (secim == 2)
	{
		islemListele();
	}
	else if (secim == 3)
	{
		islemSil();
	}
}

void Kontrol::yoneticiMenuCiz()
{
	Kontrol y1;
	y1.tavanCiz(20);
	y1.araCiz(20, "Yonetici Paneli");

	y1.ayracCiz(20);


	y1.araCiz(20, "1.Musteri Ekle");
	y1.araCiz(20, "2.Musteri Listele");
	y1.araCiz(20, "3.Musteri Sil");
	y1.araCiz(20, "4.Urun Ekle");
	y1.araCiz(20, "5.Urunleri Listele");
	y1.araCiz(20, "6.Urun Sil");
	y1.zeminCiz(20);


	cout << "secim...:";
	int secim;
	cin >> secim;

	if (secim == 1)
	{
		musteriEkle();
	}
	else if (secim == 2)
	{
		musteriListele();
	}
	else if (secim == 3)
	{
		musteriSil();
	}
	else if (secim == 4)
	{
		urunEkle();
	}
	else if (secim == 5)
	{
		urunListele();
	}
	else if (secim == 6)
	{
		urunSil();
	}
}
void Kontrol::musteriEkle()
{  
	
	Musteri m2;
	tavanCiz(50);
	araCiz(50, " ");
	araCiz(50, "EKLENEN MUSTERI");
	araCiz(50, " ");
	
	ayracCiz(50);
	araCiz(50, " ");
	araCiz(50, "Isim........:"+ m2.isimGetir());
	araCiz(50, "Soyisim.....:" + m2.soyisimGetir());
	araCiz(50, "Tcno........:" + m2.tcnoGetir());
	araCiz(50, "Telno.......:" + m2.telnoGetir());
	araCiz(50, "Dogum Tarihi:" + m2.tarihGetir().tarihGetir());
	zeminCiz(50);

	m2.kaydet();
		
	
}
void Kontrol::musteriSil()
{
	musteriListele();
	string tcnoSecilen;
	cout << "tcno..:";
	cin >> tcnoSecilen;

	fstream dosya;
	fstream dosyaKaydet;
	dosya.open("Musteriler.txt", ios::in);
	dosyaKaydet.open("gecici.txt", ios::in | ios::out | ios::app);
	if (dosya.is_open())
	{
		string ad;
		string soyad;
		string tcno;
		string telno;
		int gun;
		int ay;
		int yil;
      while (dosya>>ad>>soyad>>tcno>>telno>>gun>>ay>>yil)
		{
			if (tcno != tcnoSecilen)
			{
				dosyaKaydet << ad << " " << soyad << " " << tcno << " " << telno << " " << gun << " " << ay << " " << yil << endl;

			}
		}
	}

	dosyaKaydet.close();
	dosya.close();

	remove("Musteriler.txt");

	rename("gecici.txt", "Musteriler.txt");

    /****İslemler siliniyor****/

    fstream dosya2;
	fstream dosyaKaydet2;
	dosya2.open("Islemler.txt", ios::in);
	dosyaKaydet2.open("gecici2.txt", ios::in | ios::out | ios::app);

	if (dosya2.is_open())
	{
		string  urunKodu;
		string  islemKodu;
		string  tcno;

		while (dosya2 >> islemKodu >> urunKodu >> tcno)
		{
			if (tcno != tcnoSecilen)
			{
				dosyaKaydet2 << islemKodu << " " << urunKodu << " " << tcno << endl;
			}
		}
	}
	dosyaKaydet2.close();
	dosya2.close();
	remove("Islemler.txt");
	rename("gecici2.txt", "Islemler.txt");


}
void Kontrol::musteriListele()
{
	
	tavanCiz(50);
	araCiz(50, " ");
	araCiz(50, "Musteriler Listesi");
	ayracCiz(50);

	fstream dosya;
	dosya.open("Musteriler.txt",ios::in);

	if (dosya.is_open())
	{
		

		while (dosya.eof()!=true)
		{
			char satir[500];

			dosya.getline(satir, 500);

			araCiz(50, satir);
		}
	}
    zeminCiz(50);
	dosya.close();
}
void Kontrol::urunListele()
{
	tavanCiz(50);
	araCiz(50, " ");
	araCiz(50, "Urunler Listesi");
	ayracCiz(50);

	fstream dosya;
	dosya.open("Urunler.txt", ios::in);

	if (dosya.is_open())
	{
      
		while (dosya.eof() != true)
		{
			char satir[500];

			dosya.getline(satir, 500);

			araCiz(50, satir);
		}
	}
	zeminCiz(50);
	dosya.close();
}
void Kontrol::urunEkle()
{   
	Urun u2;
	
	tavanCiz(50);
	araCiz(50, " ");
	araCiz(50, "EKLENEN URUN");
	araCiz(50, " ");
	
	ayracCiz(50);
	araCiz(50, " ");
	araCiz(50, "Urun adi...:" + u2.urunAdiGetir());
	araCiz(50, "Urun Kodu....:" + u2.urunKoduGetir());
	araCiz(50, "Fiyat........:" + u2.urunFiyatiGetir());
	zeminCiz(50);
	
	u2.kaydet();
}
void Kontrol::urunSil()
{
	urunListele();
	string urunSecilen;
	cout << "Urun Kodu....:";
	cin >> urunSecilen;

	fstream dosya1;
	fstream dosyaKaydet1;
	dosya1.open("Urunler.txt", ios::in);
	dosyaKaydet1.open("gecici1.txt", ios::in | ios::out | ios::app);
	if (dosya1.is_open())
	{
		string urunAdi;
		string  urunKodu;
		string fiyat;

		while (dosya1 >> urunAdi >> urunKodu >> fiyat)
		{
			if (urunKodu != urunSecilen)
			{
                dosyaKaydet1 << urunAdi << " " << urunKodu << " " << fiyat << endl;
            }
		}
	}
    dosyaKaydet1.close();
	dosya1.close();
    remove("Urunler.txt");
    rename("gecici1.txt", "Urunler.txt");

}

void Kontrol::islemSil()
{
	islemListele();
	string islemSecilen;
	cout << "Islem Kodu....:";
	cin >> islemSecilen;

	fstream dosya2;
	fstream dosyaKaydet2;
	dosya2.open("Islemler.txt", ios::in);
	dosyaKaydet2.open("gecici2.txt", ios::in | ios::out | ios::app);
	
	if (dosya2.is_open())
	{
		string  urunKodu;
		string  islemKodu;
		string  tcno;

		while (dosya2 >> islemKodu >> urunKodu >> tcno)
		{
			if (islemKodu != islemSecilen)
			{
				dosyaKaydet2 << islemKodu << " " << urunKodu << " " << tcno << endl;
			}
		}
	}
	dosyaKaydet2.close();
	dosya2.close();
	remove("Islemler.txt");
	rename("gecici2.txt", "Islemler.txt");
}

void Kontrol::islemListele()
{

	tavanCiz(50);
	araCiz(50, " ");
	araCiz(50, "Islemler Listesi");
	ayracCiz(50);

	fstream dosya;
	dosya.open("Islemler.txt", ios::in);

	if (dosya.is_open())
	{

        while (dosya.eof() != true)
		{
			char satir[500];

			dosya.getline(satir, 500);

			araCiz(50, satir);
		}
	}
	zeminCiz(50);
	dosya.close();

}

void Kontrol::urunAl(string tcno, string urunkodu)
{
	
	Islem i2;
	i2.tcAta(tcno);
	i2.urunKoduAta(urunkodu);
	tavanCiz(50);
	araCiz(50, " ");
	araCiz(50, "EKLENEN ISLEM");
	araCiz(50, " ");

	ayracCiz(50);
	araCiz(50, " ");
	araCiz(50, "Islem Kodu....:" + i2.islemKoduGetir());
	araCiz(50, "Urun Kodu.....:" + i2.urunKoduGetir());
	araCiz(50, "Tcno........:" + i2.tcNoGetir());
	
	zeminCiz(50);

	i2.kaydet();

}


