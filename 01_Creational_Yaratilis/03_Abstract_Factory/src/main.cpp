//============================================================================
// İsim        : 03_Abstract_Factory
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : 03_Abstract_Factory Pattern
//============================================================================
#include <iostream>
using namespace std;

#define DOLAP 1
//#define MASA 1

class Marangoz
{
  public:
    virtual void urunTip() = 0;
};

class Masa : public Marangoz
{
  public:
    void urunTip() override
    {
        std::cout << "Masa Yapım Onarım" << std::endl;
    }
};

class Dolap : public Marangoz
{
  public:
    void urunTip() override
    {
        std::cout << "Dolap Yapım Onarım" << std::endl;
    }
};

class Fabrika
{
  public:
    virtual Marangoz *fabrikaOlustur() = 0;
};

class DolapOlustur : public Fabrika
{
  public:
    Marangoz *fabrikaOlustur() override
    {
        return new Dolap;
    }
};

class MasaOlustur : public Fabrika
{
  public:
    Marangoz *fabrikaOlustur() override
    {
        return new Masa;
    }
};

int main()
{
#ifdef DOLAP
    Fabrika *fabrika = new DolapOlustur;
#elif MASA
    Fabrika *fabrika = new MasaOlustur;
#endif

    Marangoz *marangoz = fabrika->fabrikaOlustur();
    marangoz->urunTip();

    delete[] fabrika;
    delete[] marangoz;
    return 0;
}
