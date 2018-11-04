//============================================================================
// İsim        : 02_Factory
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : 02_Factory Pattern
//============================================================================
#include <iostream>

using namespace std;

enum AracTipi
{
    Tren_T,
    Araba_T,
    Ucak_T
};

// Abstract sınıf
class Arac
{
  public:
    virtual void aracSesCikar() = 0;
    static Arac *create(AracTipi);
};

class Ucak : public Arac
{
  public:
    void aracSesCikar() override
    {
        cout << "Vuuuuuuuuuuh Vuuuuuuh" << endl;
    }
};

class Tren : public Arac
{
  public:
    void aracSesCikar() override
    {
        cout << "Çuuuf Çuuuuuf" << endl;
    }
};

class Araba : public Arac
{
  public:
    void aracSesCikar() override
    {
        cout << "Vııın Vııın" << endl;
    }
};

Arac *Arac::create(AracTipi tip)
{
    if (tip == Tren_T)
    {
        return new Tren();
    }
    else if (tip == Araba_T)
    {
        return new Araba();
    }
    else if (tip == Ucak_T)
    {
        return new Ucak();
    }
    else
    {
        return NULL;
    }
}

int main()
{
    AracTipi tip = Ucak_T;
    Arac *aracPtr = Arac::create(tip);
    aracPtr->aracSesCikar();

    delete[] aracPtr;
    return 0;
}
