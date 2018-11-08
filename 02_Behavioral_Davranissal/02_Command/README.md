# Command Pattern

**"Command Pattern"** bir isteği bir nesne olarak kapsüllemek için kullanılır. Böylece istemcileri farklı isteklere, sıraya veya kayıt isteklerine göre parametrelendirmenize ve geri alınamayan işlemleri desteklemenize izin verir.

## Command Pattern Kullanım Adımları

* İlk olarak soyut bir sınıf oluşturuyoruz. Bu sınıfa **"Komut"** ismini verdik. Bu sınıfın  **"calistir"** isminde bir methodu bulunmakta.

```cpp
class Komut
{
public:
  virtual void calistir() = 0;
};
```

* Ardından işlem görecek sınıfımızı hazırlıyoruz. Bu sınıf ismine **"Isik"** ismini verdik. Bu sınıf, ışığı açma ve kapama işlemi gerçekleştiriyor.

```cpp
class Isik
{
public:
  Isik() {}

  void ac()
  {
    cout << "Işık Açıldı..." << endl;
  }

  void kapat()
  {
    cout << "Işık Kapandı..." << endl;
  }
};
```

* Sonraki adım olarak, **Komut"** sınıfından komutlar üretiyoruz. Projemizde **"AcKomut"** ve **"KapatKomut"** olarak 2 komut bulunmakta.

```cpp
class AcKomut : public Komut
{
private:
  Isik &isik;

public:
  AcKomut(Isik &isik) : isik(isik)
  {
  }

  virtual void calistir()
  {
    isik.ac();
  }
};


class KapatKomut : public Komut
{
private:
  Isik &isik;

public:
  KapatKomut(Isik &isik) : isik(isik)
  {
  }
  virtual void calistir() override
  {
    isik.kapat();
  }
};
```

* Son adım olarak **"Degistir"** sınıfını tanımlıyoruz. Bu sınıf, bir ışığın açma ve kapatma durumlarını kontrol etmektedir.

```cpp
class Degistir
{
  private:
  Komut &acKomut;
  Komut &kapatKomut;

public:
  Degistir(Komut &acKomut, Komut &kapatKomut)
      : acKomut(acKomut), kapatKomut(kapatKomut)
  {
  }

  void ac()
  {
    acKomut.calistir();
  }

  void kapat()
  {
    kapatKomut.calistir();
  }
};
```

* Şimdi yazdığımız sınıfların kontrolünü yapalım. ilk olarak **"Isik"** sınıfından bir nesne üretiyoruz. Ardından **"Komut"** sınıfından türetilen, **"AcKomut"** ve **"KapatKomut"** sınıflarıdnan nesneler üretiyoruz.   **"Isik"** sınıfından ürettiğimiz nesneleride komutlara veriyoruz.  En sonra **"Degistir"** sınıfından nesne üret,yoruz ve komut nesnelerinide parametre olarak veriyoruz. Artık kolay bir şekilde komutumuzu kullanabiliriz. **"ac"**, **"kapat"** fonksiyonları sayesinde, ışık açma - kapatma işlemlerini gerçekleştiriyoruz.

```cpp
int main()
{
  Isik lamba;
  AcKomut degistirAc(lamba);
  KapatKomut degistirKapat(lamba);

  Degistir s(degistirAc, degistirKapat);
  s.ac();
  s.kapat();
}
```