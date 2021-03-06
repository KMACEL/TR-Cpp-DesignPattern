//============================================================================
// İsim        : 11_Visitor
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : Visitor Pattern
//============================================================================
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Tekerlek;
class Motor;
class Govde;
class Araba;

// Araba Birleşenleri Soyut Sınıf
class ArabaBirlesenleriVisitor
{
  public:
    virtual void visit(Tekerlek &tekerlek) const = 0;
    virtual void visit(Motor &motor) const = 0;
    virtual void visit(Govde &govde) const = 0;
    virtual void visitAraba(Araba &car) const = 0;
};

// ArabaBirlesenleri Yapım
class ArabaBirlesenleri
{
  public:
    virtual void onayla(const ArabaBirlesenleriVisitor &visitor) = 0;
};

class Tekerlek : public ArabaBirlesenleri
{
  private:
    string isim;

  public:
    explicit Tekerlek(const string &isim) : isim(isim)
    {
    }

    const string &getIsim() const
    {
        return isim;
    }

    void onayla(const ArabaBirlesenleriVisitor &visitor) override
    {
        visitor.visit(*this);
    }
};

class Motor : public ArabaBirlesenleri
{
  public:
    void onayla(const ArabaBirlesenleriVisitor &visitor) override
    {
        visitor.visit(*this);
    }
};

class Govde : public ArabaBirlesenleri
{
  public:
    void onayla(const ArabaBirlesenleriVisitor &visitor) override
    {
        visitor.visit(*this);
    }
};

class Araba
{
  private:
    vector<ArabaBirlesenleri *> arabaBirlesenleri;

  public:
    vector<ArabaBirlesenleri *> &getBirlesen()
    {
        return arabaBirlesenleri;
    }

    Araba()
    {
        arabaBirlesenleri.push_back(new Tekerlek("Ön Sol"));
        arabaBirlesenleri.push_back(new Tekerlek("Ön Sağ"));
        arabaBirlesenleri.push_back(new Tekerlek("Arka SOl"));
        arabaBirlesenleri.push_back(new Tekerlek("Arka Sağ"));
        arabaBirlesenleri.push_back(new Govde());
        arabaBirlesenleri.push_back(new Motor());
    }
    ~Araba()
    {
        for (vector<ArabaBirlesenleri *>::iterator it = arabaBirlesenleri.begin(); it != arabaBirlesenleri.end(); ++it)
        {
            delete *it;
        }
    }
};


class ArabaBirlesemleriYazdirVisitor : public ArabaBirlesenleriVisitor
{
  public:
    void visit(Tekerlek &tekerlek) const override
    {
        cout << "Visiting " << tekerlek.getIsim() << " tekerlek" << endl;
    }
    void visit(Motor &motor) const override
    {
        cout << "Visiting motor" << endl;
    }
    void visit(Govde &govde) const override
    {
        cout << "Visiting govde" << endl;
    }
    void visitAraba(Araba &araba) const override
    {

        cout << "Visiting araba" << endl;

        vector<ArabaBirlesenleri *> &arabaElemanlari = araba.getBirlesen();
        for (vector<ArabaBirlesenleri *>::iterator it = arabaElemanlari.begin(); it != arabaElemanlari.end(); ++it)
        {
            (*it)->onayla(*this); 
        }
        cout << "Visited araba" << endl;
    }
};

class ArabaBirlesemleriYapVisitor : public ArabaBirlesenleriVisitor
{
  public:
    void visit(Tekerlek &tekerlek) const override
    {
        cout << "Tekerlek takılıyor : " << tekerlek.getIsim() << " tekerlek" << endl;
    }
    void visit(Motor &motor) const override
    {
        cout << "Motor Monteleniyor" << endl;
    }
    void visit(Govde &govde) const override
    {
        cout << "Gövde taşınıyor" << endl;
    }
    void visitAraba(Araba &araba) const override
    {
        cout << endl
             << "Arabaya başlanıyor" << endl;

        vector<ArabaBirlesenleri *> &arabaEleman = araba.getBirlesen();
        for (vector<ArabaBirlesenleri *>::iterator it = arabaEleman.begin(); it != arabaEleman.end(); ++it)
        {
            (*it)->onayla(*this);
        }
        cout << "Araba yapımı bitti." << endl;
    }
};

int main()
{
    Araba araba;
    ArabaBirlesemleriYazdirVisitor arabaBirlesemleriYazdirVisitor;
    ArabaBirlesemleriYapVisitor arabaBirlesemleriYapVisitor;

    arabaBirlesemleriYazdirVisitor.visitAraba(araba);
    arabaBirlesemleriYapVisitor.visitAraba(araba);

    return 0;
}
