#ifndef ARAC_H
#define ARAC_H

enum AracTipi
{
    Tren_T,
    Araba_T,
    Ucak_T
};

class Arac
{
  public:
    virtual void aracSesCikar() = 0;
    static Arac *create(AracTipi tip);
};
#endif