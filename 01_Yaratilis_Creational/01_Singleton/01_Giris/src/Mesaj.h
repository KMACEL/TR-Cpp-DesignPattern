#ifndef MESAJ_H
#define MESAJ_H

#include <iostream>

class Mesaj
{
private:
  static Mesaj *INSTANCE;
  std::string mesaj;

protected:
  // Constructor Methodumuz
  Mesaj();

public:
  // Mesaj sınıfımızı kullanmak için oluşturduğumuz public türündeki method
  static Mesaj *getInstance();
  // mesaj değişkenine veri atamamıza yardımcı olan method
  void setMesaj(std::string);
  // mesaj değişkeninden veri almaya yarayan method
  std::string getMesaj();
  // mesaj değişken içeriğini yazmaya yarayan method
  void mesajYazir();
};

#endif
