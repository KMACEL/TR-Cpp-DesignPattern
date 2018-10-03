#ifndef TREN_H
#define TREN_H

#include <iostream>

class Tren : public Arac
{
  public:
    void aracSesCikar()
    {
        std::cout << "Çuuuf Çuuuuuf" << std::endl;
    }
};
#endif