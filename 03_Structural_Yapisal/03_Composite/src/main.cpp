//============================================================================
// İsim        : 03_Composite
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : Composite Pattern
//============================================================================
#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;

class Grafik
{
  public:
    virtual void yazdir() const = 0;
};

class Elips : public Grafik
{
  public:
    void yazdir() const override
    {
        cout << "Elips \n";
    }
};

class Kare : public Grafik
{
  public:
    void yazdir() const override
    {
        cout << "Kare \n";
    }
};

class Ucgen : public Grafik
{
  public:
    void yazdir() const override
    {
        cout << "Üçgen \n";
    }
};

class CompositeGrafik : public Grafik
{
  private:
    vector<Grafik *> grafikListesi;

  public:
    void yazdir() const override
    {
        for (Grafik *grafik : grafikListesi)
        {
            grafik->yazdir();
        }
    }

    void ekle(Grafik *grafik)
    {
        grafikListesi.push_back(grafik);
    }
};

int main()
{
    // Initialize four ellipses
    const unique_ptr<Elips> elips1(new Elips());
    const unique_ptr<Elips> elips2(new Elips());
    const unique_ptr<Kare> kare(new Kare());
    const unique_ptr<Ucgen> ucgen(new Ucgen());

    // Initialize three composite graphics
    const unique_ptr<CompositeGrafik> graphic1(new CompositeGrafik());
    const unique_ptr<CompositeGrafik> graphic2(new CompositeGrafik());
    const unique_ptr<CompositeGrafik> graphic3(new CompositeGrafik());

    // Composes the graphics
    graphic2->ekle(elips1.get());
    graphic2->ekle(elips2.get());
    graphic2->ekle(ucgen.get());

    graphic3->ekle(kare.get());

    graphic1->ekle(graphic2.get());
    graphic1->ekle(graphic3.get());

    // Prints the complete graphic (four times the string "Ellipse")
    graphic1->yazdir();
    return 0;
}