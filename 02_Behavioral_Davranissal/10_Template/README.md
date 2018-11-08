# Template Method Pattern
**"Template Method Pattern"**  ile bir algoritmanın veya işlemin adımları soyut bir sınıfta tanımlanır ve bu soyut sınıfın alt sınıflarının ilgili adımların gerçekleştirimlerini vermeleri beklenir. Davranışsal bir örüntüdür.

Soyut sınıfın bir metodu algoritmanın adımlarını bir iskelet (kalıp) olarak gerçekleştirir, bunun için tanımlı diğer metotları çağırarak algoritmayı gerçekleştirir. Algoritma adımlarını gerçekleştiren metotlar soyut (abstract) olarak tanımlanır. Bazılarının gerçekleştirimleri de verilebilir. Bu soyut sınıftan türetilen alt sınıflar, soyut metotların gerçekleştirimlerini verirler. Birden fazla gerçekleştirim sınıfı olabilir, böylece algoritma adımlarının (soyut metotlar) farklı farklı gerçekleştirilmeleri mümkün olur. 

## Template Method Pattern Kullanım Adımları

* İlk önce soyut sınıfımızı oluşturuyoruz. Biz sınıfımızın ismini **"AbstractClass"** olarak belirledik. Sınıfımızda **"templateMethod"** ismidne bir method bulunmakta. Bu method, bu sınıftan türetilen sınıfların yapması gereken işlerin şablonlarını oluşturmaktadır. Ardından sınıfımızda **"islem1"**,**"islem2"**,**"tercihliIslem"**,**"sabitIslem"** adında methodlarımız bulunmakta. Bu methodlardan **"islem1"**,**"islem2"** kesinlikle alt sınıflarda tanımlanması gereken methodlar. **"tercihliIslem"** ise tanımlanması gerektiğinde isteğe bağlı method. **"sabitIslem"** ise, tanımlansada farketmeyecek, bütün sınıflarda aynı olacak işlem.


```cpp
class AbstractClass
{
  public:
    void templateMethod()
    {
        islem1();
        islem2();
        sabitIslem();
        tercihliIslem();
    }

    virtual void islem1() = 0;
    virtual void islem2() = 0;
    virtual void tercihliIslem() {}
    void sabitIslem()
    {
        cout << "Bu işlem sabit. Bütün sınıflarda aynı..." << endl;
    }
};
```

* Şimdiki adım olarak **"AbstractClass"** sınıfımızdan türetilen **"Sinif1"** ve **"Sinif2"** isimde sınıflar oluşturuyoruz. Dikkat edilmesi gereken husus, **"templateMethod"** çalıştırılınca sınıflarda tanımlanan **"islem1"**,**"islem2"**,**"tercihliIslem"** methodları çalışacak ama **"sabitIslem"** methodu **"AbstractClass"** sınıfındaki hali ile çalışacak. Bunun sebebi, diğer methodların **"virtual"** olması sebebidir.

```cpp
class Sinif1 : public AbstractClass
{
  public:
    void islem1()
    {
        cout << "Sinif1 - islem1 çalıştı..." << endl;
    }
    void islem2()
    {
        cout << "Sinif1 - islem2 çalıştı..." << endl;
    }
    void tercihliIslem()
    {
        cout << "Sinif1 - tercihliIslem çalıştı..." << endl;
    }
    void sabitIslem()
    {
        cout << "Bu baya sabit Sinif1" << endl;
    }
};

class Sinif2 : public AbstractClass
{
  public:
    void islem1()
    {
        cout << "Sinif2 - islem1 çalıştı..." << endl;
    }
    void islem2()
    {
        cout << "Sinif2 - islem2 çalıştı..." << endl;
    }
    void sabitIslem()
    {
        cout << "Bu baya sabit Sinif2 " << endl;
    }
};
```

* En son kullanım için, **"Sinif1"** ve **"Sinif2"** sınıflarından nesne üretip, **"templateMethod"** methodunu çağırıyoruz.

```cpp
int main()
{
    Sinif1 sinif1;
    Sinif2 sinif2;

    sinif1.templateMethod();

    cout << "-------------------------------" << endl;
    sinif2.templateMethod();

    return 0;
}
```