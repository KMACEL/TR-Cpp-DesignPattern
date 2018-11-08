# Strategy Pattern

**"Strategy Pattern"**, bir sınıfın işlevini çalışma zamanında değiştirmeyi sağlar. **"Strategy Pattern"** algoritmanın, onu kullanan istemcilerden bağımsız olarak değişmesine izin verir.


## Strategy Pattern Kullanım Adımları

* İlk adım olarak soyut bir sınıf tanımlıyoruz. Sınıfımız **"OgretmenInterface"** ismini veriyoruz.

```cpp
class OgretmenInterface
{
  public:
    virtual void atama(string) const = 0;
};
```

* Ardından bu sınıfımızdan somut sınıflar yaratıyoruz. Bunlara **"OgretmenA"**, **"OgretmenB"**, **"OgretmenC"** isimlerini veriyoruz.
```cpp
class OgretmenA : public OgretmenInterface
{
  public:
    void atama(string okul) const override
    {
        cout << "Öğretmen A, " << okul << " okuluna atandı..." << endl;
    }
};

class OgretmenB : public OgretmenInterface
{
  public:
    void atama(string okul) const override
    {
        cout << "Öğretmen B, " << okul << " okuluna atandı..." << endl;
    }
};

class OgretmenC : public OgretmenInterface
{
  public:
    void atama(string okul) const override
    {
        cout << "Öğretmen C, " << okul << " okuluna atandı..." << endl;
    }
};
```

* Ardından **"Okul"** isminde bir sınıf yaratıyoruz. Bu sınıf, içinde **"OgretmenInterface"** nesnesi ve **"okulIsmi"** isminde **"string"** bir değişken bulunmakta. **Constructor** kısmında **"OgretmenInterface"** ve **"okulIsmi"** verilerini alıp, sınıfın başında tanımladığımız değişkenlere atama işlemi gerçekleştiriyoruz. Ardıdan **"setOgretmenDegistir"** fonksiyonumuz bulunmakta. Bu fonksiyon bizim için önemli. Çünkü, çalışma zamanında işlevi değiştiren kısım burada. Bu fonksiyon, sınıfın hangi **"OgretmenInterface"** tanımlı öğretmen ile işlem yapacağını belirliyor. En son olarak **"atama"** fonksiyonu ile, seçtiğimiz okula, seçtiğimiz öğretmeni aktarmış oluyoruz.

```cpp
class Okul
{
  private:
    OgretmenInterface *ogretmenInterface;
    string okulIsmi;

  public:
    Okul(OgretmenInterface *ogretmenInterface, string okulIsmi) : ogretmenInterface(ogretmenInterface), okulIsmi(okulIsmi)
    {
    }

    void setOgretmenDegistir(OgretmenInterface *ogretmenInterface)
    {
        this->ogretmenInterface = ogretmenInterface;
    }

    void atama() const
    {
        ogretmenInterface->atama(okulIsmi);
    }
};
```

* Kullanımına gelecek olursak, **"OgretmenInterface"** soyut sınıfından türettiğimiz **"OgretmenA"**, **"OgretmenB"**, **"OgretmenC"** sınıflarından nesne yaratıyoruz. Ardından **"Okul"** sınıfından nesne yaratıyoruz. Yaratırken **constructor** da hangi öğretmen, hangi okulda bilgilerini veriyoruz. Ve atama işlemini gerçekleştiriyoruz. Son olarak istediğimiz okulda farklı bir öğretmen atamak için **"setOgretmenDegistir"** methodu ile öğretmen değiştirip **"atama"** methodu ile işlemleri gerçekleştiriyoryuz. Bu sayede, çalışma zamanında ilgil sınıfın işleyişini değiştirmiş oluyoruz.

```cpp
int main()
{
    OgretmenA ogretmenA;
    OgretmenB ogretmenB;
    OgretmenC ogretmenC;

    Okul okul1(&ogretmenA, "Okul-1");
    Okul okul2(&ogretmenB, "Okul-2");
    Okul okul3(&ogretmenC, "Okul-3");

    okul1.atama();
    okul2.atama();
    okul3.atama();

    okul1.setOgretmenDegistir(&ogretmenB);
    okul1.atama();
    okul1.setOgretmenDegistir(&ogretmenC);
    okul1.atama();

    return 0;
}
```