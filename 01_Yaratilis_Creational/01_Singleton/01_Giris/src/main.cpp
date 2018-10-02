//============================================================================
// İsim        : 01_Singleton
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : Singleton Giriş Örneği
//============================================================================
#include <iostream>
#include <string>
#include "Mesaj.h" // Hazırladığımız sınıfı ekliyoruz

using namespace std;

int main()
{
  // 1. Kullanış Biçimi : Bir "Mesaj" sınıfından "m1" adında nesne yaratıp,
  // Mesaj sınıfının "Instance"sini içeri aktrıyoruz
  Mesaj *m1 = Mesaj::getInstance();
  m1->setMesaj("Test");
  m1->mesajYazir();

  // 2. Kullanış Biçimi : Hiç bir nesne yaratmadan direk kullanabiliyoruz.
  Mesaj::getInstance()->setMesaj("Merhaba");
  Mesaj::getInstance()->mesajYazir();

  // Burada da gösterilmek istenen, tekrar bir nesne yaratılmasına rağmen ve 
  // setMesaj() fonksiyonunu kullanmamamıza rağmen, bir önceki hali oluyor.
  Mesaj *m2 = Mesaj::getInstance();
  m2->mesajYazir();

  return 0;
}
