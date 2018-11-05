# Builder Pattern
**"Builder Pattern"**, karmaşık bir nesnenin yapısını temsilinden ayırmak için kullanılır. Böylece aynı oluşturma işlemi ile farklı nesneler oluşturabilmektedir. Bu patterni, karmaşık bir obje oluşturmak istendiğinde fakat karmaşık bir kurucu üyeye veya argümanlara ihtiyaç duymak istemediğimizde kullanmaktayız.

## Builder Pattern Kullanım Adımları

* İlk olarak ana sınıfımızı oluşturuyoruz. Ana sınıfımız **"Bilgisayar"** ismindedir. İçeriğinde bilgisayar donanımı değişkenleri ve bunlar ile iletişim methodları barındırmakta. En son olarak, verilen parçları **"kur()"** methodu ile ekrana yazdırmakta.

```cpp
class Bilgisayar
{
  private:
    string anakart;
    string ram;
    string ekranKarti;
    string segment;

  public:
    void setAnakart(const string &anakart)
    {
        this->anakart = anakart;
    }
    void setRam(const string &ram)
    {
        this->ram = ram;
    }
    void setEkranKarti(const string &ekranKarti)
    {
        this->ekranKarti = ekranKarti;
    }

    void setSegment(const string &segment)
    {
        this->segment = segment;
    }

    void kur() const
    {
        cout << segment << " Bilgisayar Özellikleri - Anakart " << anakart << ", Ram Bellek : " << ram << ", Ekran Kartı : "
             << ekranKarti << " - Kurulum Tamamlandı" << endl;
    }
};
```

* Ardından ana sınıfımızın **"Builder"**ını oluşturuyoruz. Bu sınıf içinde **"Bilgisayar"** türünde değişken bulunmakta. **"unique_ptr"** kullanmamızın nedeni, **pointer** ile çalıştığımızda ve **"new"** ile yeni sınıflar oluşturduğumuzda, **"RAM"** bellekte yer kaplamaktadır. Bunları işlemlerimiz bitince silmemiz gerekmektedir. **"unique_ptr"** bu işlemi bizim için, efektif bir biçimde yerine getirmektedir. Bu sınıfta **"getBilgisayar"** methodu bulunmaktadır. Bu method, geriye oluşturduğumuz **"Bilgisayar"** nesnesini döndürür. **"yeniBilgisayarOlustur"** methodu ise, **"Bilgisayar"** türünden bir sınıf oluşturup, **"bilgisayar"** değişkenine atar. Bu sınıf soyut bir sınıftır. **"buildAnakart"**, **"buildRam"**, **"buildEkrankarti"**, **"buildSegment"** methodları bulunmaktadır.

```cpp
class BilgisayarBuilder
{
  protected:
    unique_ptr<Bilgisayar> bilgisayar;

  public:
    virtual ~BilgisayarBuilder(){};

    Bilgisayar *getBilgisayar()
    {
        return bilgisayar.release();
    }
    void yeniBilgisayarOlustur()
    {
        bilgisayar = make_unique<Bilgisayar>();
    }
    virtual void buildAnakart() = 0;
    virtual void buildRam() = 0;
    virtual void buildEkrankarti() = 0;
    virtual void buildSegment() = 0;
};
```

* **BilgisayarBuilder** dan türetilen, spesifik alt sınıfları oluşturuyoruz. Bu sınıfların amacı, **"BilgisayarBuilder"** da bulunan ve istenen **"buildAnakart"**, **"buildRam"**, **"buildEkrankarti"**, **"buildSegment"** methodlarını anlamlandırmak. Verileri atamak.

```cpp
class OrtaSegmetBilgisayarBuilder : public BilgisayarBuilder
{
  public:
    virtual ~OrtaSegmetBilgisayarBuilder(){};

    void buildAnakart() override
    {
        bilgisayar->setAnakart("Asus");
    }

    void buildRam() override
    {
        bilgisayar->setRam("8 GB");
    }

    void buildEkrankarti() override
    {
        bilgisayar->setEkranKarti("2 GB AMD");
    }

    void buildSegment() override
    {
        bilgisayar->setSegment("Orta Segmet");
    }
};

class UstSegmetBilgisayarBuilder : public BilgisayarBuilder
{
  public:
    virtual ~UstSegmetBilgisayarBuilder(){};

    void buildAnakart() override
    {
        bilgisayar->setAnakart("Gigabyte");
    }

    void buildRam() override
    {
        bilgisayar->setRam("16 GB");
    }

    void buildEkrankarti() override
    {
        bilgisayar->setEkranKarti("8 GB NVDIA");
    }

    void buildSegment() override
    {
        bilgisayar->setSegment("Üst Segmet");
    }
};
```

* En son olarak **"Build"** işlemini yapacak olan sınıfımızı oluşturuyoruz. bu sınıfımızda **"BilgisayarBuilder"** sınıfından bir nesnemiz bulunmakta. **"bilgisayarSec"** isminde bir methodumuz bulunmakta. Bu method, kullanıcıdan **"BilgisayarBuilder"** türünde değişken almakta. Fonksiyonda aldığı veriyi, sınıf içinde oluşturduğu **"bilgisayarBuilder"** nesnesine atamakta. **"bilgisayarKur"** methodu ilede, **"Bilgisayar"** sınıfındaki  **"kur"** methodunu çalıştırmaktadır.

```cpp
class Build
{
  private:
    BilgisayarBuilder *bilgisayarBuilder;

  public:
    void bilgisayarSec(BilgisayarBuilder *pb)
    {
        bilgisayarBuilder = pb;
        bilgisayarBuilder->yeniBilgisayarOlustur();
        bilgisayarBuilder->buildAnakart();
        bilgisayarBuilder->buildEkrankarti();
        bilgisayarBuilder->buildRam();
        bilgisayarBuilder->buildSegment();
    }

    void bilgisayarKur()
    {
        bilgisayarBuilder->getBilgisayar()->kur();
    }
};
```

* Kullanım için ilk önce **"Build"** nesnesi oluşturuyoruz. Ardınan **Builder** dan türetilen, spesifik alt sınıflardan nesneler oluşturuyoruz. **"build.bilgisayarSec"** methodu ile **Builder** dan türetilen nesneyi atıyoruz. En son olarka kur methodunu çalıştıryoruz.

```cpp
int main()
{
    Build build;
    OrtaSegmetBilgisayarBuilder ortaSegment;
    UstSegmetBilgisayarBuilder ustSegment;

    build.bilgisayarSec(&ortaSegment);
    build.bilgisayarKur();

    build.bilgisayarSec(&ustSegment);
    build.bilgisayarKur();
}
```