#ifndef ARABA_H
#define ARABA_H

#include <iostream>

class Araba : public Arac
{
  public:
    void aracSesCikar()
    {
        std::cout << "Vııın Vııın" << std::endl;
    }
};
#endif