# Adapter Pattern

**"Adapter Pattern"**, bir sınıfın arayüzünü istemcinin beklediği başka bir arayüze dönüştürür. Böylece istemci bu farklı sınıfla çalışabilir, aksi takdirde bilmediği bir arayüze sahip sınıfı kullanamaz. 

## Adapter Pattern Kullanım Adımları

* İlk önce soyut bir sınıf oluşturuyoruz. Sınıfımıza **"Daire"** ismini verdik. Bu sınıfın **"ciz"** adında bir methodu bulunmakta.

```cpp
class Daire
{
  public:
    virtual void ciz() = 0;
};
```

* Ardından **"StandardDaire"** isminde bir sınıf oluşturuyoruz. Bu sınıf, daire bilgilerini almaktadır.

```cpp
class StandardDaire
{
  private:
    double yariCap;

  public:
    StandardDaire(double yariCap)
    {
        this->yariCap = yariCap;
        cout << "StandardDaire:  Yarat. Yarı Çapı = " << yariCap << endl;
    }
    void cizim()
    {
        cout << "StandardDaire:  Yarı Çapı. " << yariCap << endl;
    }
};
```

* Ardından **"DaireAdapter"** isminde bir sınıf oluşturuyoruz. Bu sınıf, **"Daire"** ve **"StandardDaire"** sınıfından miras almakta. Bu dairenin içinde constructor olarak dairenin çap bilgisini almakta. Bu bilgiyi, **"StandardDaire"** sınıfına göndermekte. Ardından **"ciz"** methodu ile, **"cizim"** sınıfını çalıştırmakta.

```cpp
class DaireAdapter : public Daire, private StandardDaire 
{
  public:
    DaireAdapter(double cap)
        : StandardDaire(cap / 2)
    {
        cout << "DaireAdapter: Yarat. Çapı = " << cap << endl;
    }
    virtual void ciz() override
    {
        cout << "DaireAdapter: Çiz." << endl;
        cizim();
    }
};
```

* Kullanım için **"Daire"** türünde, bir nesne yaratıyoruz. Nesneyi, **"DaireAdapter"** sınıfından oluşturuyoruz. Oluştururken constructora dairenin çap bilgisini veriyoruz. En son olarak **"ciz"** methodu ile dairemizi çiziyoruz.

```cpp
int main()
{
    Daire *c = new DaireAdapter(18);
    c->ciz();
    
    delete[] c;
}
```