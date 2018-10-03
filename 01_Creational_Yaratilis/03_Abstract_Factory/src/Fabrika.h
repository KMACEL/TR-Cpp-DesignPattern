#ifndef FABRIKA_H
#define FABRIKA_H

#include "Marangoz.h"

class Fabrika
{
  public:
    virtual Marangoz *fabrikaOlustur() = 0;
};

class DolapOlustur : public Fabrika
{
  public:
    Marangoz *fabrikaOlustur()
    {
        return new Dolap;
    }
};

class MasaOlustur : public Fabrika
{
  public:
    Marangoz *fabrikaOlustur()
    {
        return new Masa;
    }
};

#endif