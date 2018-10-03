//============================================================================
// İsim        : 04_Builder
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : Builder Pattern
//============================================================================
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Bilgisayar
{
  private:
    string anakart;
    string ram;
    string ekranKarti;

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

    void kur() const
    {
        cout << "Bilgisayar Özellikleri - Anakart " << anakart << ", Ram Bellek : " << ram << ", Ekran Kartı : "
             << ekranKarti << " - Kurulum Tamamlandı" << endl;
    }
};

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
};

//----------------------------------------------------------------

class OrtaSegmetBilgisayarBuilder : public BilgisayarBuilder
{
  public:
    virtual ~OrtaSegmetBilgisayarBuilder(){};

    virtual void buildAnakart()
    {
        bilgisayar->setAnakart("Gigabyte");
    }
    virtual void buildRam()
    {
        bilgisayar->setRam("8 GB");
    }
    virtual void buildEkrankarti()
    {
        bilgisayar->setEkranKarti("2 GB AMD");
    }
};

class UstSegmetBilgisayarBuilder : public BilgisayarBuilder
{
  public:
    virtual ~UstSegmetBilgisayarBuilder(){};

    virtual void buildAnakart()
    {
        bilgisayar->setAnakart("Gigabyte");
    }
    virtual void buildRam()
    {
        bilgisayar->setRam("16 GB");
    }
    virtual void buildEkrankarti()
    {
        bilgisayar->setEkranKarti("8 GB NVDIA");
    }
};

//----------------------------------------------------------------
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
    }

    void bilgisayarKur()
    {
        bilgisayarBuilder->getBilgisayar()->kur();
    }
};

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