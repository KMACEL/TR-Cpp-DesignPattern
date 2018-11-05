# Abstract Factory Pattern
**Abstract Factory Pattern**, ortak bir sınıf türünden türetilecek, farklı nesnelerin oluşturulmasında kullanılmaktadır. **Abstract Factory** düzeni, genel bir deseni takip eden nesneler oluşturmamıza izin veren bir çerçeve sunmaktadır. Bu pattern, somut sınıflarını doğrudan belirtmeden, ilgili veya bağımlı nesnelerin ailelerinin oluşturulmasını sağlar.


## Abstract Factory Pattern Kullanım Adımları

* İlk önce, soyut bir sınıf oluşturuyoruz. Bu sınıf, bizim ürünlerimizi kapsayacak.

```cpp
class Marangoz
{
  public:
    virtual void urunTip() = 0;
};

```

* Ardından oluşturduğumuz soyut sınıftan somut sınıflar oluşturuyoruz.

```cpp
class Masa : public Marangoz
{
  public:
    void urunTip() override
    {
        std::cout << "Masa Yapım Onarım" << std::endl;
    }
};

class Dolap : public Marangoz
{
  public:
    void urunTip() override
    {
        std::cout << "Dolap Yapım Onarım" << std::endl;
    }
};
```

* Ardından **Abstract Factory** oluşturuyoruz. Bu sınıf içinde, daha önce oluşturulan soyut sınıf türünden veri geri döndüren method bulunmakta.

```cpp
class Fabrika
{
  public:
    virtual Marangoz *fabrikaOlustur() = 0;
};
```

* Şimdiki adım ise işe özgü somut sınıflar üretmekte.

```cpp
class DolapOlustur : public Fabrika
{
  public:
    Marangoz *fabrikaOlustur() override
    {
        return new Dolap;
    }
};

class MasaOlustur : public Fabrika
{
  public:
    Marangoz *fabrikaOlustur() override
    {
        return new Masa;
    }
};
```

* Kullanım olarak ilk önce fabrika türümüzü belirlilyoruz. Ardından yapıalcak iş tanımlayıp, fabrikamıza atama gerçekleştiriyoruz.

```cpp
int main()
{
    Fabrika *fabrika = new DolapOlustur;
    Marangoz *marangoz = fabrika->fabrikaOlustur();
    marangoz->urunTip();

    return 0;
}
```