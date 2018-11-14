//============================================================================
// İsim        : 08_State
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : State Pattern
//============================================================================
#include <iostream>
using namespace std;

class Makine
{
  private:
    class Durum *durum;

  public:
    Makine();
    void setDurum(Durum *durum);
    void ac();
    void kapat();
};

class Durum
{
  public:
    virtual void ac(Makine *makine)
    {
        cout << "   şu anda açık\n";
    }
    virtual void kapat(Makine *makine)
    {
        cout << "  şu anda kapalı\n";
    }
};

class AC : public Durum
{
  public:
    AC()
    {
        cout << "   AC constructor. ";
    }

    ~AC()
    {
        cout << "  AC de-constructor\n";
    }

    void kapat(Makine *m);
};

class KAPAT : public Durum
{
  public:
    KAPAT()
    {
        cout << "   KAPAT constructor. ";
    }
    ~KAPAT()
    {
        cout << "   KAPAT de-constructor\n";
    }
    void ac(Makine *makine);
};

Makine::Makine()
{
    durum = new KAPAT();
    cout << '\n';
}

void Makine::setDurum(Durum *durum)
{
    this->durum = durum;
}

void Makine::ac()
{
    durum->ac(this);
}

void Makine::kapat()
{
    durum->kapat(this);
}

void AC::kapat(Makine *m)
{
    cout << "   AC konumundan KAPAT konumuna geçildi";
    m->setDurum(new KAPAT());
    delete this;
}

void KAPAT::ac(Makine *makine)
{
    cout << "   KAPAT konumundan AC konumuna geçildi";
    makine->setDurum(new AC());
    delete this;
}

int main()
{
    void (Makine::*ptrs[])() = {&Makine::kapat, &Makine::ac};
    Makine fsm;
    int num;
    while (1)
    {
        cout << "Durum Giriniz : 0 - 1: ";
        cin >> num;
        (fsm.*ptrs[num])();
    }
}