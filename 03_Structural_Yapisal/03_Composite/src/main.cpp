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
    virtual ~Grafik() {}
};

class Elips : public Grafik
{
  public:
    void yazdir() const override
    {
        cout << "Elips \n";
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
    const auto_ptr<Elips> elips1(new Elips());
    const auto_ptr<Elips> elips2(new Elips());
    const auto_ptr<Elips> elips3(new Elips());
    const auto_ptr<Elips> elips4(new Elips());

    // Initialize three composite graphics
    const auto_ptr<CompositeGrafik> graphic1(new CompositeGrafik());
    const auto_ptr<CompositeGrafik> graphic2(new CompositeGrafik());
    const auto_ptr<CompositeGrafik> graphic3(new CompositeGrafik());

    // Composes the graphics
    graphic2->ekle(elips1.get());
    graphic2->ekle(elips2.get());
    graphic2->ekle(elips3.get());

    graphic3->ekle(elips4.get());

    graphic1->ekle(graphic2.get());
    graphic1->ekle(graphic3.get());

    // Prints the complete graphic (four times the string "Ellipse")
    graphic1->yazdir();
    return 0;
}