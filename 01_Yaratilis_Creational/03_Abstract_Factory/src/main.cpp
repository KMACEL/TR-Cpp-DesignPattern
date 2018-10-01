//============================================================================
// İsim        : 03_Abstract_Factory
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : 03_Abstract_Factory Pattern
//============================================================================
#include <iostream>
#include "Fabrika.h"
using namespace std;

#define DOLAP 1
//#define MASA 1
int main()
{
#ifdef DOLAP
    Fabrika *fabrika = new DolapOlustur;
#elif MASA
    Fabrika *fabrika = new MasaOlustur;
#endif

    Marangoz *Marangoz;
    Marangoz = fabrika->fabrikaOlustur();
    Marangoz->urunTip();

    return 0;
}
