# Factory Method Pattern
Bu pattern kullanmım amacı, siz projenizde bir takım standartlar oluşturmak isteyebilirsiniz. Yapacağınız sınıfları, sadece istediğiniz yötemler ile kontrol etmek isteyebilirsiniz. Bunun için **Factory Method Pattern** gayet kullanışlıdır.

**Factory Pattern**, bir var olan şablona uygun olarak nesneler yaratmaktadır. **Factory  Method Pattern**, nesneler oluşturmak için bir arabirim tanımlar. Fakat işlevi kullanıcı belirler. Örneğin bir plastik baskı fabrikası düşünün. Baskı malzemesi aynıdır. Fakat sonunda çıkan ürün, kalıba göre farklılılar gösterir.

## Factory Method Pattern Kullanım Adımları

* İlk adım olarak **soyut** bir üst sınıf oluşurulur.

```cpp
class Arac
{
  public:
    virtual void aracSesCikar() = 0;
    static Arac *create(AracTipi);
};
```
* Ardından o sınıftan miras alacak diğer sınıflarımızı tanımlıyoruz.

```cpp
class Ucak : public Arac
{
  public:
    void aracSesCikar() override
    {
        cout << "Vuuuuuuuuuuh Vuuuuuuh" << endl;
    }
};

class Tren : public Arac
{
  public:
    void aracSesCikar() override
    {
        cout << "Çuuuf Çuuuuuf" << endl;
    }
};

class Araba : public Arac
{
  public:
    void aracSesCikar() override
    {
        cout << "Vııın Vııın" << endl;
    }
};
```
* **enum**, kullanım aşamalarımız sabit ve kullanışlı olması amacı ile yazılmıştır.

```cpp
enum AracTipi
{
    Tren_T,
    Araba_T,
    Ucak_T
};

```

* Soyut sınıfımızda olan **"create"** methodumuzu tanımlıyoruz. 

```cpp
Arac *Arac::create(AracTipi tip)
{
    if (tip == Tren_T)
    {
        return new Tren();
    }
    else if (tip == Araba_T)
    {
        return new Araba();
    }
    else if (tip == Ucak_T)
    {
        return new Ucak();
    }
    else
    {
        return NULL;
    }
}
```

* Kullanım için,

```cpp
int main()
{
    AracTipi tip = Ucak_T;
    Arac *aracPtr = Arac::create(tip);
    aracPtr->aracSesCikar();

    return 0;
}
```