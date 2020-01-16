#pragma once  
#include <string>

using namespace std;
class Islem
{
public:
	Islem();

	string	urunKoduGetir();

	string	tcNoGetir();

	string	islemKoduGetir();

	void	kaydet();

	string islemKoduUret();
	void tcAta(string tc);
	void urunKoduAta(string urun);
private:
	string  mIslemKodu;
	string	mUrunKodu;
	string  mMusteriTcNo;

};
