#ifndef MESAJ_H
#define MESAJ_H

#include <iostream>

class Mesaj
{
private:
  static Mesaj *INSTANCE;
  std::string mesaj;

protected:
  Mesaj();

public:
  static Mesaj *getInstance();
  void mesajYazir();
  void setMesaj(std::string);
  std::string getMesaj();
};

#endif
