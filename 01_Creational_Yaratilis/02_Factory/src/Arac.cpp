#include <iostream>
#include "Arac.h"
#include "Tren.h"
#include "Araba.h"
#include "Ucak.h"

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
