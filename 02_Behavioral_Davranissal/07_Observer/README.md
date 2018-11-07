# Observer Pattern

Uygulamada bir yer ya da birçok yer, bir sistem olayı veya bir uygulama durumu değişikliği hakkında bilgi sahibi olmamız gerekir. Sistem olaylarını dinlemeye ve ilgili taraflara bildirimde bulunmanın standart bir yoluna, standart bir şekilde abone olmak durumunda kullanılmaktadır. 

Yani **"Observer Pattern"**, nesneler arasında bağımlılık tanımlar, böylece bir nesne değiştiğinde, tüm bağımlıları otomatik olarak bildirilir ve güncellenir.

## Observer Pattern Kullanım Adımları
Bu örneğimizde hava durumu gösterici yapıyoruz. Projemizde, nem, sıcaklık ve basıç verilerini bir ekranda gösteren, yeni veriler geldikçe de gerekli yerleri güncelleyen yapıyı inceleyeceğiz

* İlk önce bir soyut sınıf tanımlıyoruz. Bizim sınıfımızın ismini **"ObserverInterface"** olarak belirledik. Bu sınıf, içinde **"guncelle"** adında bir soyut method bulundurmakta. Bu fonksiyon, nem, sıcaklık ve basınç verilerini almakta.

```cpp
class ObserverInterface
{
  public:
    virtual void guncelle(float nem, float sicaklik, float basinc) = 0;
};
```

* Yapılan değişikliği göstermeye yarayan soyut bir sınıf tanımlıyoruz.

```cpp
class DurumGostericiInterface
{
  public:
    virtual void goster() = 0;
};
```

* Gelen hava durumlarını kontrol etmeye yaran, **"HavaDurumuVerisiInterface"** isminde soyut bir sınıf tanımlıyoruz.

```cpp
class HavaDurumuVerisiInterface
{
  public:
    virtual void kayitOb(ObserverInterface *ob) = 0;
    virtual void silOb(ObserverInterface *ob) = 0;
    virtual void bildiriOb() = 0;
};
```

* Hava durumu verilerini alan **"HavaDurumuVerileri"** ismindeki sınıfımızı tanımlıyoruz. Bu sınıf  **"HavaDurumuVerisiInterface"** soyut sınıfını miras olarak alan somut bir sınıftır.

```cpp
class HavaDurumuVerileri : public HavaDurumuVerisiInterface
{
  private:
    float nem;
    float sicaklik;
    float basinc;
    list<ObserverInterface *> observeInterfacesListe;

  protected:
    void bildiriOb() override
    {
        for (list<ObserverInterface *>::iterator it = observeInterfacesListe.begin(); it != observeInterfacesListe.end(); it++)
        {
            (*it)->guncelle(nem, sicaklik, basinc);
            (dynamic_cast<DurumGostericiInterface *>(*it))->goster();
        }
    }

  public:
    void yeniSensorVerisi(float nem, float sicaklik, float basinc)
    {
        this->nem = nem;
        this->sicaklik = sicaklik;
        this->basinc = basinc;
        bildiriOb();
    }

    void kayitOb(ObserverInterface *ob) override
    {
        observeInterfacesListe.push_back(ob);
    }

    void silOb(ObserverInterface *ob) override
    {
        observeInterfacesListe.remove(ob);
    }
};
```

* Gelen yeni verileri gösteren, **"MevcutDurumGosterici"** ismindeki sınıfımızı oluşturuyoruz. Bu sınıf, **"ObserverInterface"** ve **"DurumGostericiInterface"** sınıflarından miras almatka.

```cpp
class MevcutDurumGosterici : public ObserverInterface, public DurumGostericiInterface
{
  private:
    float nem;
    float sicaklik;
    float basinc;
    HavaDurumuVerileri &veri;

  public:
    MevcutDurumGosterici(HavaDurumuVerileri &veri) : veri(veri)
    {
        veri.kayitOb(this);
    }
    void goster() override
    {
        cout << "_____Hava Durum_____" << endl;
        cout << "Nem      : " << nem << endl;
        cout << "Sıcaklık : " << sicaklik << endl;
        cout << "Basınç   : " << basinc << endl;
        cout << "_______________________________" << endl;
    }

    void guncelle(float nem, float sicaklik, float basinc) override
    {
        this->nem = nem;
        this->sicaklik = sicaklik;
        this->basinc = basinc;
    }
};
```

* Gelen verilerin istatiğini tutan bir sınıf daha oluşturuyoruz. Bu sınıfta, **"ObserverInterface"** ve **"DurumGostericiInterface"** sınıflarından miras almatka.

```cpp
class HavaIstatistik : public ObserverInterface, public DurumGostericiInterface
{
  private:
    float enYuksekSicaklik;
    float enDusukSicaklik;
    float ortalamaSicaklik;

    float enYuksekNem;
    float enDusukNem;
    float ortalamaNem;

    float enYuksekBasinc;
    float enDusukBasinc;
    float ortalamaBasinc;

    int gelenVeriSayisi;
    HavaDurumuVerileri &havaDurumuVerileri;

  public:
    HavaIstatistik(HavaDurumuVerileri &gelenHavaDurumuVerileri) : havaDurumuVerileri(gelenHavaDurumuVerileri)
    {
        this->enYuksekSicaklik = -1000;
        this->enDusukSicaklik = 1000;
        this->ortalamaSicaklik = 0;

        this->enYuksekNem = -1000;
        this->enDusukNem = 1000;
        this->ortalamaNem = 0;

        this->enYuksekBasinc = -1000;
        this->enDusukBasinc = 1000;
        this->ortalamaBasinc = 0;

        this->gelenVeriSayisi = 0;

        havaDurumuVerileri.kayitOb(this);
    }

    void goster() override
    {
        cout << "________İstatistikler_________" << endl;
        cout << "En Düşük Sıcaklık  : " << enDusukSicaklik << endl;
        cout << "En Yüksek Sıcaklık : " << enYuksekSicaklik << endl;
        cout << "Ortalama Sıcaklık  : " << ortalamaSicaklik << endl;
        cout << "-------------------------------" << endl;
        cout << "En Düşük Nem       : " << enDusukNem << endl;
        cout << "En Yüksek Nem      : " << enYuksekNem << endl;
        cout << "Ortalama Nem       : " << ortalamaNem << endl;
        cout << "-------------------------------" << endl;
        cout << "En Düşük Basınç    : " << enDusukBasinc << endl;
        cout << "En Yüksek Basınç   : " << enYuksekBasinc << endl;
        cout << "Ortalama Basınç    : " << ortalamaBasinc << endl;
        cout << "_______________________________" << endl
             << endl;
    }

    void guncelle(float nem, float sicaklik, float basinc) override
    {
        ++gelenVeriSayisi;

        if (sicaklik > enYuksekSicaklik)
        {
            enYuksekSicaklik = sicaklik;
        }
        if (sicaklik < enDusukSicaklik)
        {
            enDusukSicaklik = sicaklik;
        }
        ortalamaSicaklik = (ortalamaSicaklik * (gelenVeriSayisi - 1) + sicaklik) / gelenVeriSayisi;

        if (nem > enYuksekNem)
        {
            enYuksekNem = nem;
        }
        if (nem < enDusukNem)
        {
            enDusukNem = nem;
        }
        ortalamaNem = (ortalamaNem * (gelenVeriSayisi - 1) + nem) / gelenVeriSayisi;

        if (basinc > enYuksekBasinc)
        {
            enYuksekBasinc = basinc;
        }
        if (basinc < enDusukBasinc)
        {
            enDusukBasinc = basinc;
        }
        ortalamaBasinc = (ortalamaBasinc * (gelenVeriSayisi - 1) + basinc) / gelenVeriSayisi;
    }
};
```

* Kullanım için, ilk olarak **"HavaDurumuVerileri"** nesnesi oluşturuyoruz. Bu nesne, **"yeniSensorVerisi"** methodu yardımı ile, sistemimize veri girişi sağlamaya yaramaktadır. Ardından göstericiler için **"MevcutDurumGosterici"** ve **"HavaIstatistik"** nesneleri oluşturup, işleyecekleri **"HavaDurumuVerileri"** nesnesini atıyoruz. Ardından veri girişi gerçekleştiriyoruz. Eğer hayıtı silmek istersek, yani dinleyeni silmek istersek, yani **"MevcutDurumGosterici"** ve **"HavaIstatistik"** sınıflarından birini devre dışı bırakmak istersek **"silOb"** yardımı ile bağlılığını kaldırıyoruz.

```cpp
int main()
{

    HavaDurumuVerileri *havaVerisi = new HavaDurumuVerileri;

    MevcutDurumGosterici *mevcutDurumGosterici = new MevcutDurumGosterici(*havaVerisi);
    HavaIstatistik *havaIstatistik = new HavaIstatistik(*havaVerisi);

    havaVerisi->yeniSensorVerisi(10.2, 28.2, 1001);
    havaVerisi->yeniSensorVerisi(12, 30.12, 1003);
    havaVerisi->yeniSensorVerisi(10.2, 26, 806);
    havaVerisi->yeniSensorVerisi(10.3, 35.9, 900);

    havaVerisi->silOb(mevcutDurumGosterici);

    havaVerisi->yeniSensorVerisi(100, 40, 1900);

    delete[] havaIstatistik; 
    delete[] mevcutDurumGosterici;
    delete havaVerisi;

    return 0;
}
```