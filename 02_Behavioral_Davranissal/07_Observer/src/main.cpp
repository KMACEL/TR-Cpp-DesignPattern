//============================================================================
// İsim        : 07_Observer
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : Observer Pattern
//============================================================================
#include <iostream>
#include <list>
using namespace std;

// Abstract Observer
class ObserverInterface
{
  public:
    virtual void guncelle(float nem, float sicaklik, float basinc) = 0;
};

// Abstract Interface for Displays
class DurumGostericiInterface
{
  public:
    virtual void goster() = 0;
};

// The Abstract Subjectu
class HavaDurumuVerisiInterface
{
  public:
    virtual void kayitOb(ObserverInterface *ob) = 0;
    virtual void silOb(ObserverInterface *ob) = 0;
    virtual void bildiriOb() = 0;
};

// The Concrete Subject
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
    void YeniSensorVerisi(float nem, float sicaklik, float basinc)
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

// A Concrete Observer
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

// A Concrete Observer
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

    void goster()
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

    void guncelle(float nem, float sicaklik, float basinc)
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

int main()
{

    HavaDurumuVerileri *havaVerisi = new HavaDurumuVerileri;
    MevcutDurumGosterici *mevcutDurumGosterici = new MevcutDurumGosterici(*havaVerisi);
    HavaIstatistik *havaIstatistik = new HavaIstatistik(*havaVerisi);

    havaVerisi->YeniSensorVerisi(10.2, 28.2, 1001);
    havaVerisi->YeniSensorVerisi(12, 30.12, 1003);
    havaVerisi->YeniSensorVerisi(10.2, 26, 806);
    havaVerisi->YeniSensorVerisi(10.3, 35.9, 900);

    havaVerisi->silOb(mevcutDurumGosterici);

    havaVerisi->YeniSensorVerisi(100, 40, 1900);

    delete[] havaIstatistik; 
    delete[] mevcutDurumGosterici;
    delete havaVerisi;

    return 0;
}