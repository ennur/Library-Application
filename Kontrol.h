#pragma once

#include<string>
using namespace std;
class Kontrol
{
public:

	void tavanCiz(int genislik);

	void zeminCiz(int genislik);

	void araCiz(int genislik, string yazi);

	void ayracCiz(int genislik);

	
	void anaMenuCiz();
  void musteriMenuCiz();
  void yoneticiMenuCiz();
	
	void musteriListele();
	void musteriEkle();
	void musteriSil();

	void islemSil();
	void islemListele();
	void urunAl(string tcno,string urunkodu);

  void urunListele();
	void urunEkle();
	void urunSil();
};
