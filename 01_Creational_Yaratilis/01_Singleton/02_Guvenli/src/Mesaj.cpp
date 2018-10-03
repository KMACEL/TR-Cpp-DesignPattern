#include <iostream>
#include "Mesaj.h"

Mesaj &Mesaj::getInstance()
{
  static Mesaj INSTANCE; // Yok edilmesi garanti
  return INSTANCE;
}

Mesaj::Mesaj()
{
}

Mesaj::~Mesaj()
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
