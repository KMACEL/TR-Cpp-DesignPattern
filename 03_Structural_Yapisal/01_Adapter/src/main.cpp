//============================================================================
// İsim        : 01_Adapter
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : Adapter Pattern
//============================================================================
#include <iostream>
using namespace std;

class Daire
{
  public:
    virtual void ciz() = 0;
};

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

class DaireAdapter : public Daire, private StandardDaire //Adapter Class
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

int main()
{
    Daire *c = new DaireAdapter(18);
    c->ciz();

    delete[] c;
}
