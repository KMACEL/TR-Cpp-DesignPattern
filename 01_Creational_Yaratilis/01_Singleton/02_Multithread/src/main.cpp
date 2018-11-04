//============================================================================
// İsim        : 02_Multithread
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : Multithread Singleton Kullanımı
//============================================================================
#include <iostream>
#include <string>
#include <mutex>

using namespace std;

mutex mtx;

class Mesaj
{
private:
  // INSTANCE değişkenini tanımlıyoruz
  static Mesaj *INSTANCE;
  string mesaj;

protected:
  // Constructor Methodumuz
  Mesaj()
  {
  }

  // c++ 11 ile gelen, constructor kopyalanmasını engellenyen yapı
  Mesaj(const Mesaj &) = delete;

  // Atama operatörü "=" derleyici tarafından
  // otomatik üretebilinen bir operatördür.
  // Bu da singleton için işlevini kaybetmeye sebep olabilir.
  // Bunuda tanımlamamız karşılaşılacak problemleri azaltır.
  Mesaj &operator=(const Mesaj &) = delete;

  // Güvenlik olarak Destructor özel yapmaktır. Bu önlem,
  // Singleton nesnesinin  istem dışı olarak silmesini engeller.
  ~Mesaj();

public:
  static Mesaj *getInstance()
  {
    // Eğer çift kontrollü olursa daha güvenli olduğu gözlemlenmiştir http://www.drdobbs.com/cpp/c-and-the-perils-of-double-checked-locki/184405726
    if (INSTANCE == 0)
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

  void mesajYazir()
  {
    cout << "Mesajınız : " << getMesaj() << endl;
  }

  void setMesaj(string mesaj)
  {
    this->mesaj = mesaj;
  }

  string getMesaj()
  {
    return this->mesaj;
  }
};

// INSTANCE değerine ilk atama, sıfırlama işlemi yapan kısım
Mesaj *Mesaj::INSTANCE = 0;

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
