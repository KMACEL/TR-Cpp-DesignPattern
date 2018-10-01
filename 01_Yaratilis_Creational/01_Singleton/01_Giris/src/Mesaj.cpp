#include <iostream>
#include "Mesaj.h"

Mesaj *Mesaj::INSTANCE = 0;

Mesaj *Mesaj::getInstance()
{
  if (INSTANCE == 0)
  {
    INSTANCE = new Mesaj();
  }
  return INSTANCE;
}

Mesaj::Mesaj()
{
}

void Mesaj::mesajYazir()
{
  std::cout << "Mesajınız : " << getMesaj() << std::endl;
}

void Mesaj::setMesaj(std::string mesaj)
{
  this->mesaj = mesaj;
}

std::string Mesaj::getMesaj()
{
  return this->mesaj;
}
