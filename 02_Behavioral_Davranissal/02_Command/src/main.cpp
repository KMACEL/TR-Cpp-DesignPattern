//============================================================================
// İsim        : 02_Command
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : Command Pattern
//============================================================================
#include <iostream>

using namespace std;

class Komut
{
public:
  virtual void calistir() = 0;
};

class Isik
{
public:
  Isik() {}

  void ac()
  {
    cout << "Işık Açıldı..." << endl;
  }

  void kapat()
  {
    cout << "Işık Kapandı..." << endl;
  }
};

class AcKomut : public Komut
{
private:
  Isik &isik;

public:
  AcKomut(Isik &isik) : isik(isik)
  {
  }

  virtual void calistir() override
  {
    isik.ac();
  }
};


class KapatKomut : public Komut
{
private:
  Isik &isik;

public:
  KapatKomut(Isik &isik) : isik(isik)
  {
  }
  virtual void calistir() override
  {
    isik.kapat();
  }
};

class Degistir
{
  private:
  Komut &acKomut;
  Komut &kapatKomut;

public:
  Degistir(Komut &acKomut, Komut &kapatKomut)
      : acKomut(acKomut), kapatKomut(kapatKomut)
  {
  }

  void ac()
  {
    acKomut.calistir();
  }

  void kapat()
  {
    kapatKomut.calistir();
  }
};

int main()
{
  Isik lamba;
  AcKomut degistirAc(lamba);
  KapatKomut degistirKapat(lamba);

  Degistir s(degistirAc, degistirKapat);
  s.ac();
  s.kapat();
}