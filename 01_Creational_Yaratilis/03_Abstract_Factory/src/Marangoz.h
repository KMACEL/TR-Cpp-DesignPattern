#ifndef MARANGOZ_H
#define MARANGOZ_H

#include <iostream>

class Marangoz
{
  public:
    virtual void urunTip() = 0;
};

class Masa : public Marangoz
{
  public:
    void urunTip()
    {
        std::cout << "Masa Yapım Onarım" << std::endl;
    }
};

class Dolap : public Marangoz
{
  public:
    void urunTip()
    {
        std::cout << "Dolap Yapım Onarım" << std::endl;
    }
};

#endif