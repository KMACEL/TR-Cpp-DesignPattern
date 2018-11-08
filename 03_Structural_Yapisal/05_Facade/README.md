# Facade Pattern

**"Facade Pattern"** pek çok sınıftan oluşan karmaşık bir sistemin karmaşıklığını saklamak ve istemci daha basit ve kolay kullanılabilir bir arayüz sunmak için kullanılır. Yapısal bir örüntüdür. Basitçe bu örüntü sisteme bir arayüz ekler ve sistemin karmaşıklığını giderir. 

## Facade Pattern Kullanım Adımları

* İlk adım olarak yapılacak işlemleri, operasyonları tanımlıyoruz. Biz projemizde **"Alarm"**, **"Elektrik"**, **"Tv"** işlemleri tanımladık.

```cpp
class Alarm
{
  public:
    void alarmAc()
    {
        cout << "Alarm Açıldı. Eviniz güvende..." << endl;
    }

    void alarmKapat()
    {
        cout << "Alarm Kapatıldı..." << endl;
    }
};

class Elektrik
{
  public:
    void elektrikAc()
    {
        cout << "Elektrik Açık..." << endl;
    }

    void elektrikKapat()
    {
        cout << "Elektrik Kapalı..." << endl;
    }
};

class Tv
{
  public:
    void tvAc()
    {
        cout << "Tv Açık..." << endl;
    }

    void tvKapat()
    {
        cout << "TV Kapalı..." << endl;
    }
};

```

* Ardından **"EvFacade"** isminde bir sınıf oluşturduk. Bu sınıf içinde oluşturduğumuz **"Alarm"**, **"Elektrik"**, **"Tv"** sınıflarından nesneler yarattık. Bu sınıfımızda iki fonksiyonumuz bulunmakta. İlki **"evdenDisariCikinca"** methodu, ilk belirlediğimiz sınıflardan, evden çıkınca yapılacak olan işlemleri tanımlamakta. Diğeri **"eveDonunce"** methodu eve geri dönünce yapıalcak olan işlemleri barındırmaktadır.

```cpp
class EvFacade
{
    Alarm alarm;
    Elektrik elektrik;
    Tv tv;

  public:
    EvFacade() {}

    void evdenDisariCikinca()
    {
        elektrik.elektrikKapat();
        tv.tvKapat();
        alarm.alarmAc();
    }

    void eveDonunce()
    {
        alarm.alarmKapat();
        elektrik.elektrikAc();
        tv.tvAc();
    }
};
```

* Kullanımı da olduktça basittir. İlk olarak **"EvFacade"** sınıfından bir nesne üretiyoruz. Ardından **"evdenDisariCikinca"** yada **"eveDonunce"** methodlarını, isteğimize uygun bir şekilde gerçekleştiriyoruz.

```cpp
int main()
{
    EvFacade evFacade;

    cout << "Evden İşe Gidiliyor ..." << endl;
    evFacade.evdenDisariCikinca();

    cout << "---------------------------------------------" << endl;

    cout << "Eve Giriliyor..." << endl;
    evFacade.eveDonunce();
}

```