//============================================================================
// İsim        : 01_Chain_of_Responsibility
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : Chain of Responsibility
//============================================================================
#include <iostream>
#include <string>

using namespace std;

class TrafikKurallari
{
protected:
  TrafikKurallari *trafikKurallari;

public:
  TrafikKurallari()
  {
    trafikKurallari = NULL;
  }

  virtual ~TrafikKurallari() {}

  virtual void sorgula(int value) = 0;

  void setKuralDegistir(TrafikKurallari *yolTipi)
  {
    trafikKurallari = yolTipi;
  }
};

class Yol : public TrafikKurallari
{
private:
  int hizLimiti;
  string yolTipi;

public:
  Yol(string yolTipi, int hizLimiti)
  {
    this->hizLimiti = hizLimiti;
    this->yolTipi = yolTipi;
  }

  ~Yol() {}

  void sorgula(int yapilanHiz) override
  {
    if (yapilanHiz < hizLimiti)
    {
      cout << "--------------------------------------------------" << endl;
      cout << "Yol Tipi : " << yolTipi << endl
           << "Hız Limiti : " << hizLimiti << endl
           << "Yapılan Hız : " << yapilanHiz << endl
           << "Sonuç : Ceza Almadınız." << endl;
    }
    else if (trafikKurallari != NULL)
    {
      trafikKurallari->sorgula(yapilanHiz);
    }
    else
    {
      cout << "--------------------------------------------------" << endl;
      cout << "Dikkat !!! Hız Limit Aşımı" << endl
           << "Yol Tipi : " << yolTipi << endl
           << "Yapılan Hız " << yapilanHiz << endl
           << "Bu Yolda Limit : " << hizLimiti << endl
           << "Lütfen Limitte Kalınız." << endl;
    }
  }
};

int main()
{
  TrafikKurallari *ulke1 = new Yol("Tek Şerit", 100);
  TrafikKurallari *ulke2 = new Yol("Çift Şerit", 120);
  TrafikKurallari *ulke3 = new Yol("Otoban", 150);

  ulke1->sorgula(80);
  ulke1->sorgula(115);

  ulke1->setKuralDegistir(ulke2);
  ulke1->sorgula(90);
  ulke1->sorgula(115);

  ulke2->sorgula(85);
  ulke2->sorgula(130);
  ulke2->setKuralDegistir(ulke3);
  ulke2->sorgula(140);

  delete ulke1;
  delete ulke2;
  delete ulke3;

  return 0;
}