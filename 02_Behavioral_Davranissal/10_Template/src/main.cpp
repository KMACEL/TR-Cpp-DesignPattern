//============================================================================
// İsim        : 10_Template
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : Template Pattern
//============================================================================
#include <iostream>

using namespace std;

class AbstractClass
{
  public:
    void templateMethod()
    {
        islem1();
        islem2();
        sabitIslem();
        tercihliIslem();
    }

    virtual void islem1() = 0;
    virtual void islem2() = 0;
    virtual void tercihliIslem() {}
    void sabitIslem()
    {
        cout << "Bu işlem sabit. Bütün sınıflarda aynı..." << endl;
    }
};

class Sinif1 : public AbstractClass
{
  public:
    void islem1()
    {
        cout << "Sinif1 - islem1 çalıştı..." << endl;
    }
    void islem2()
    {
        cout << "Sinif1 - islem2 çalıştı..." << endl;
    }
    void tercihliIslem()
    {
        cout << "Sinif1 - tercihliIslem çalıştı..." << endl;
    }
    void sabitIslem()
    {
        cout << "Bu baya sabit Sinif1" << endl;
    }
};

class Sinif2 : public AbstractClass
{
  public:
    void islem1()
    {
        cout << "Sinif2 - islem1 çalıştı..." << endl;
    }
    void islem2()
    {
        cout << "Sinif2 - islem2 çalıştı..." << endl;
    }
    void sabitIslem()
    {
        cout << "Bu baya sabit Sinif2 " << endl;
    }
};

int main()
{
    Sinif1 sinif1;
    Sinif2 sinif2;

    sinif1.templateMethod();

    cout << "-------------------------------" << endl;
    sinif2.templateMethod();

    return 0;
}
