# Decorator Pattern
**"Decorator Pattern"**, bir nesneye dinamik olarak ek davranış veya sorumluluklar eklemesine yardımcı olur. Dekoratörler, genişletme işlevselliği için alt sınıflamaya esnek bir alternatif sunar. Buna “Wrapper” denir. Uygulamanız bir çeşit filtreleme yapıyorsa, Dekoratör iş için göz önünde bulundurulması gereken iyi bir model olabilir.

## Decorator Pattern Kullanım Adımları

* İlk adım olarak soyut bir sınıf oluşturuyoruz. Bizim sınıfımızın ismi **"Araba"** olarak belirledik. 

```cpp
class Araba 
{
protected:
  string aciklama;

public:
  Araba()
  {
    aciklama = "Bilinmeyen Araba";
  }

  virtual string getAciklama()
  {
    return aciklama;
  }

  virtual double getFiyat() = 0;
};
```

* Bir sonraki adım **Dekaratör** sınıfımızı oluşturmak. Bu sınıf ismi **"SecenekDecorator"** olarak belirledik ve **"Araba"** sınıfından miras alacak şekilde hazırladık. Bu sınıf, bir arabaya özelliklik ekleme için oluşturulmuş soyut bir sınıftır.

```cpp
class SecenekDecorator : public Araba
{
public:
  virtual string getAciklama() = 0;
};
```

* Artık oluşturduğumuz soyut sınıfları somutlaştırma vakti. İlk olarak **"Araba"** sınıfından türeyen bir **"ArabaModel1"** adında sınıf oluşturuyoruz. Bu sınıf ana hattımızı, ürünümüzü belirtiyor. 

```cpp
class ArabaModel1 : public Araba
{
public:
  ArabaModel1()
  {
    aciklama = "Fiat Egea";
  }

  virtual double getFiyat() override
  {
    return 56000.23;
  }
};
```

* Ardından **"SecenekDecorator"** sınıfından türetilen özellikleri oluşturuyoruz. İstediğimiz kadar özellik böylece **"SecenekDecorator"** sınıfı sayesinde ana hattımıza ekleyebilecek durumda olacağız. Biz proje kapsamında aracımıza **"Navigasyon"**, **"SesSistemi"**, **"OtomatikVites"** özelliklerini ekledik. 

```cpp
class Navigasyon : public SecenekDecorator
{
  Araba *araba;

public:
  Navigasyon(Araba *araba)
  {
    this->araba = araba;
  }
  string getAciklama() override
  {
    return araba->getAciklama() + ", Navigasyon";
  }

  double getFiyat() override
  {
    return 300.56 + araba->getFiyat();
  }
  ~Navigasyon()
  {
    cout << "~Navigasyon()\n";
    delete araba;
  }
};

class SesSistemi : public SecenekDecorator
{
  Araba *araba;

public:
  SesSistemi(Araba *araba)
  {
    this->araba = araba;
  }
  string getAciklama() override
  {
    return araba->getAciklama() + ", Süper ses sistemi";
  }

  double getFiyat() override
  {
    return 250.60 + araba->getFiyat();
  }
  ~SesSistemi()
  {
    cout << "~SesSistemi()\n";
    delete araba;
  }
};

class OtomatikVites : public SecenekDecorator
{
  Araba *araba;

public:
  OtomatikVites(Araba *araba)
  {
    this->araba = araba;
  }
  string getAciklama() override
  {
    return araba->getAciklama() + ", Otomatik Vites";
  }

  double getFiyat() override
  {
    return 5450.25 + araba->getFiyat();
  }
  ~OtomatikVites()
  {
    cout << "~OtomatikVites()\n";
    delete araba;
  }
```

* Bu özellikleri kullanmak için ise ilk önce boş bir araba yaratıyoruz. Bunu **"Araba"** sınıfın türünde **"ArabaModel1"** sınıfından bir nesne yaratarak gerçekleştiriyoruz. Ardından oluşturduğumuz boş sınıfa özlelik eklemek için **"araba = new <SECTIGINIZ_OZELLIK>(araba);"** kalıbı ile, özelliklerinizi dahil ediyoruz. Böylece bir önceki sınıfta değişiklikler yapmadan yeni özellikler eklemesini gerçekleştiriyoruz.

```cpp
int main()
{
  Araba *araba = new ArabaModel1();
  cout << "Araba Modeli " << araba->getAciklama() << " fiyatı " << araba->getFiyat() << "₺\n";

  // Arabaya özellik ekliyoruz
  araba = new Navigasyon(araba);
  cout << araba->getAciklama() << " özelliği fiyatı " << araba->getFiyat() << "₺\n";

  araba = new SesSistemi(araba);
  cout << araba->getAciklama() << " özelliği fiyatı " << araba->getFiyat() << "₺\n";

  araba = new OtomatikVites(araba);
  cout << araba->getAciklama() << " özelliği fiyatı " << araba->getFiyat() << "₺\n";

  cout << "----------------------------------------------" << endl;

  delete araba;

  return 0;
}
```