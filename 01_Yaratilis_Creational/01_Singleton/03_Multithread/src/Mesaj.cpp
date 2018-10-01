#include <iostream>
#include <mutex>
#include "Mesaj.h"

Mesaj *Mesaj::INSTANCE = 0;
std::mutex mtx;

Mesaj *Mesaj::getInstance()
{
  if (INSTANCE == 0) // Eğer çift kontrollü olursa daha güvenli olduğu gözlemlenmiştir http://www.drdobbs.com/cpp/c-and-the-perils-of-double-checked-locki/184405726
  {
    mtx.lock();
    if (INSTANCE == 0)
    {
      INSTANCE = new Mesaj();
    }
    mtx.unlock();
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
