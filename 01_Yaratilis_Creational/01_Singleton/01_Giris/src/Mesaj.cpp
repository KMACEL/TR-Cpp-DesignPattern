#include <iostream>
#include "Mesaj.h" 

// INSTANCE değişkenine başlangıç değeri atıyoruz
Mesaj *Mesaj::INSTANCE = 0;

// Mesaj sınıfımızı kullanmak için oluşturduğumuz public türtedi method
Mesaj *Mesaj::getInstance()
{
  // Eğer INSTANCE değeri 0 ise yani hiç bu sınıf çağırılmamışsa,
  // sınıfı oluşturuyoruz.
  if (INSTANCE == 0)
  {
    INSTANCE = new Mesaj();
  }
  // Eğer bu sınıf daha öncd oluşturulmuşsa, yani çağırılmışsa geriye 
  // var olan "INSTANCE"yi döndürüyoruz 
  return INSTANCE;
}

// Constructor Methodumuz 
Mesaj::Mesaj()
{
}

// mesaj değişkenine veri atamamıza yardımcı olan method
void Mesaj::setMesaj(std::string mesaj)
{
  this->mesaj = mesaj;
}

// mesaj değişkeninden veri almaya yarayan method 
std::string Mesaj::getMesaj()
{
  return this->mesaj;
}

// mesaj değişken içeriğini yazmaya yarayan method
void Mesaj::mesajYazir()
{
  std::cout << "Mesajınız : " << getMesaj() << std::endl;
}
