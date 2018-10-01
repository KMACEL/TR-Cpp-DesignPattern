//============================================================================
// İsim        : 01_Singleton
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : 01_Singleton
//============================================================================
#include <iostream>
#include <string>
#include "Mesaj.h"

using namespace std;

int main()
{
  // 1. Kullanış Biçimi
  Mesaj *m1 = Mesaj::getInstance();
  m1->setMesaj("Test");
  m1->mesajYazir();

  // 2. Kullanış Biçimi
  Mesaj::getInstance()->setMesaj("Merhaba");
  Mesaj::getInstance()->mesajYazir();

  return 0;
}
