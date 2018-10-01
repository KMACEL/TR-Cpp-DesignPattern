//============================================================================
// İsim        : 02_Factory
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : 02_Factory Pattern
//============================================================================
#include <iostream>
#include "Arac.h"

using namespace std;

int main()
{
    AracTipi tip = Ucak_T;
    Arac *aracPtr = Arac::create(tip);
    aracPtr->aracSesCikar();

    return 0;
}
