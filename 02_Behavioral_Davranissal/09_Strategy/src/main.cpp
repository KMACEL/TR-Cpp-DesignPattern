//============================================================================
// İsim        : 09_Strategy
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : Strategy Pattern
//============================================================================
#include <iostream>
using namespace std;

class OgretmenInterface
{
  public:
    virtual void atama(string) const = 0;
};

class OgretmenA : public OgretmenInterface
{
  public:
    void atama(string okul) const override
    {
        cout << "Öğretmen A, " << okul << " okuluna atandı..." << endl;
    }
};

class OgretmenB : public OgretmenInterface
{
  public:
    void atama(string okul) const override
    {
        cout << "Öğretmen B, " << okul << " okuluna atandı..." << endl;
    }
};

class OgretmenC : public OgretmenInterface
{
  public:
    void atama(string okul) const override
    {
        cout << "Öğretmen C, " << okul << " okuluna atandı..." << endl;
    }
};

class Okul
{
  private:
    OgretmenInterface *ogretmenInterface;
    string okulIsmi;

  public:
    Okul(OgretmenInterface *ogretmenInterface, string okulIsmi) : ogretmenInterface(ogretmenInterface), okulIsmi(okulIsmi)
    {
    }

    void setOgretmenDegistir(OgretmenInterface *ogretmenInterface)
    {
        this->ogretmenInterface = ogretmenInterface;
    }

    void atama() const
    {
        ogretmenInterface->atama(okulIsmi);
    }
};

int main()
{
    OgretmenA ogretmenA;
    OgretmenB ogretmenB;
    OgretmenC ogretmenC;

    Okul okul1(&ogretmenA, "Okul-1");
    Okul okul2(&ogretmenB, "Okul-2");
    Okul okul3(&ogretmenC, "Okul-3");

    okul1.atama();
    okul2.atama();
    okul3.atama();

    okul1.setOgretmenDegistir(&ogretmenB);
    okul1.atama();
    okul1.setOgretmenDegistir(&ogretmenC);
    okul1.atama();

    return 0;
}