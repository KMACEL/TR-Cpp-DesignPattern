#ifndef MESAJ_H
#define MESAJ_H

#include <iostream>

class Mesaj
{
private:
  std::string mesaj;

private:
  Mesaj();

  // Güvenlik için tanımlamalar
  Mesaj(const Mesaj &) = delete; // c++ 11 ile gelen, constructor kopyalanmasını engellenyen yapı
  //Mesaj(const Mesaj &);

  // Atama operatörü "=" derleyici tarafından
  // otomatik üretebilinen bir operatördür.
  // Bu da singleton için işlevini kaybetmeye sebep olabilir.
  // Bunuda tanımlamamız karşılaşılacak problemleri azaltır.
  Mesaj &operator=(const Mesaj &) = delete;

  // Güvenlik olarak Destructor özel yapmaktır. Bu önlem,
  // Singleton nesnesinin  istem dışı olarak silmesini engeller.
  ~Mesaj();

public:
  static Mesaj &getInstance(); // Pointer yerine Referans döndürülmesi, güvenlik için daha iyidir
  void mesajYazir();
  void setMesaj(std::string);
  std::string getMesaj();
};

#endif
