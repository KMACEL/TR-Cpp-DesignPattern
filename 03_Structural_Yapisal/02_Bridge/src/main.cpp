//============================================================================
// İsim        : 02_Bridge
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : Bridge Pattern
//============================================================================
#include <iostream>

using namespace std;

/* Implementor*/
class CizimAPISablon
{
  public:
    virtual void cemberCiz(double x, double y, double yaricap) = 0;
    virtual ~CizimAPISablon() {}
};

/* Concrete ImplementorA*/
class CizimAPI1 : public CizimAPISablon
{
  public:
    void cemberCiz(double x, double y, double yaricap) override
    {
        cout << "CizimAPI1 Verileri x:  " << x << " y :" << y << " yarı çap : " << yaricap << endl;
    }
};

/* Concrete ImplementorB*/
class CizimAPI2 : public CizimAPISablon
{
  public:
    void cemberCiz(double x, double y, double yaricap) override
    {
        cout << "CizimAPI2 Verileri x:  " << x << " y :" << y << " yarı çap : " << yaricap << endl;
    }
};

/* Abstraction*/
class Sekil
{
  public:
    virtual ~Sekil() {}
    virtual void ciz() = 0;
    virtual void yuzdeOlarakBoyutlandir(double boyutlandir) = 0;
};

/* Refined Abstraction*/
class CircleShape : public Sekil
{
  private:
    double m_x, m_y, yaricap;
    CizimAPISablon *cizimAPI;

  public:
    CircleShape(double x, double y, double yaricap, CizimAPISablon *cizimAPI) : m_x(x), m_y(y), yaricap(yaricap), cizimAPI(cizimAPI)
    {
    }
    void ciz()
    {
        cizimAPI->cemberCiz(m_x, m_y, yaricap);
    }
    void yuzdeOlarakBoyutlandir(double boyutlandir)
    {
        yaricap *= boyutlandir;
    }
};

int main()
{
    CircleShape circle1(1, 2, 3, new CizimAPI1());
    CircleShape circle2(5, 7, 11, new CizimAPI2());
    circle1.yuzdeOlarakBoyutlandir(2.5);
    circle2.yuzdeOlarakBoyutlandir(2.5);
    circle1.ciz();
    circle2.ciz();
    return 0;
}
