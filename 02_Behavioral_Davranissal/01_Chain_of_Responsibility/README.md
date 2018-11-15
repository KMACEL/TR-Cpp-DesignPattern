# Chain of Responsibility Pattern

**"Chain of Responsibility Pattern"**, Türkçe anlamı **"Sorumluluk Zinciri"dir**. Bu pattern, bir talebin göndericisini alıcısına, birden fazla nesneyi isteği yerine getirme şansı vererek birleştirmekten kaçınmak niyetindedir. Alıcı nesneleri zincirler ve istekleri bir nesne ele geçirene kadar zincir boyunca geçirir.

## Chain of Responsibility Pattern Kullanım Adımları

* İlk önce **"TrafikKurallari"** isminde bir sınıf oluşturuyoruz. Bu sınıf, içinde kendi tipinde bir nesne bulundurmakta. Bu nesne üzerinden işlemler gerçekleşecek. Bu sınıf oluşturulnca yani **"constructor"**da, oluşturduğumuz nesneye **"NULL"** değerini atıyoruz. Ardından sanal bir **"deconstructor"** oluşturuyoruz. Bu oluşturduğumuz sınıfı silme işleminde kullanılmaktadır. Bu işlemden sonra **sorgula** isminde bir method oluşturuyoruz. Bu method, alt sınıfta hıza göre işlemler yapacak. **"setKuralDegistir"** methodu ise, başta belirtilen kuralları değiştirmeye yaramaktadır.

```cpp
class TrafikKurallari
{
protected:
  TrafikKurallari *trafikKurallari;

public:
  TrafikKurallari()
  {
    trafikKurallari = NULL;
  }

  virtual ~TrafikKurallari() {}

  virtual void sorgula(int value) = 0;

  void setKuralDegistir(TrafikKurallari *yolTipi)
  {
    trafikKurallari = yolTipi;
  }
};
```

* Şimdi ise oluşturduğumuz **"TrafikKurallari"** sınıfında miras alan **"Yol"** sınıfını oluşturuyoruz. İlk önce sorgularda kullanılacak olan parametreleri alıyoruz. Bunlar **"hizLimiti"** ve **"yolTipi"**. Her yol tipine göre hız limiti farklıdır. Bu sınıfın **"constructor"** methodunda yola ait tipi ve limiti alıyoruz. Burada **"sorgula"** isimde, **"TrafikKurallari"** sınıfından gelen bir method bulunmakta. Bu method, yapılan hıza göre, **"Yol"** sınıfı oluşurken belirlediği limitlere ile karşılaştırmasını sağlar. Karşılaştırma sonucuna görede ekrana belirli bilgiler verir.  

```cpp
class Yol : public TrafikKurallari
{
private:
  int hizLimiti;
  string yolTipi;

public:
  Yol(string yolTipi, int hizLimiti)
  {
    this->hizLimiti = hizLimiti;
    this->yolTipi = yolTipi;
  }

  ~Yol() {}

  void sorgula(int yapilanHiz) override
  {
    if (yapilanHiz < hizLimiti)
    {
      cout << "--------------------------------------------------" << endl;
      cout << "Yol Tipi : " << yolTipi << endl
           << "Hız Limiti : " << hizLimiti << endl
           << "Yapılan Hız : " << yapilanHiz << endl
           << "Sonuç : Ceza Almadınız." << endl;
    }
    else if (trafikKurallari != NULL)
    {
      trafikKurallari->sorgula(yapilanHiz);
    }
    else
    {
      cout << "--------------------------------------------------" << endl;
      cout << "Dikkat !!! Hız Limit Aşımı" << endl
           << "Yol Tipi : " << yolTipi << endl
           << "Yapılan Hız " << yapilanHiz << endl
           << "Bu Yolda Limit : " << hizLimiti << endl
           << "Lütfen Limitte Kalınız." << endl;
    }
  }
};
```

* Bu sistematiği kullanmak için, **"TrafikKurallari"** tipinde ve **"Yol"** sınıfından nesneler oluşturmamız gerekmektedir. Ardından hız sorgulamaları gerçekleşecektir. Eğer **"setKuralDegistir"** methodu kullanılırsa, **"()"** içinde belirtilen, daha önceden tanımlanmış olan yol bilgilerine göre, yol tipi ve hızına göre işlem gerçekleşecektir.

```cpp
int main()
{
  TrafikKurallari *ulke1 = new Yol("Tek Şerit", 100);
  TrafikKurallari *ulke2 = new Yol("Çift Şerit", 120);
  TrafikKurallari *ulke3 = new Yol("Otoban", 150);

  ulke1->sorgula(80);
  ulke1->sorgula(115);

  ulke1->setKuralDegistir(ulke2);
  ulke1->sorgula(90);
  ulke1->sorgula(115);

  ulke2->sorgula(85);
  ulke2->sorgula(130);
  ulke2->setKuralDegistir(ulke3);
  ulke2->sorgula(140);

  delete ulke1;
  delete ulke2;
  delete ulke3;

  return 0;
}
```