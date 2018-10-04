//============================================================================
// İsim        : 01_Chain_of_Responsibility
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : Chain of Responsibility
//============================================================================
#include <iostream>

using namespace std;

class Handler
{
protected:
  Handler *next;

public:
  Handler()
  {
    next = NULL;
  }

  virtual ~Handler() {}

  virtual void sorgula(int value) = 0;

  void setHandlerGecis(Handler *nextInLine)
  {
    next = nextInLine;
  }
};

class SpecialHandler : public Handler
{
private:
  int myLimit;
  int myId;

public:
  SpecialHandler(int limit, int id)
  {
    myLimit = limit;
    myId = id;
  }

  ~SpecialHandler() {}

  void sorgula(int value) override
  {
    if (value < myLimit)
    {
      cout << "Handler ID : " << myId << ", Handler Limiti : " << myLimit << " Girdiğiniz değer : " << value << ". Değer uygun." << endl;
    }
    else if (next != NULL)
    {
      next->sorgula(value);
    }
    else
    {
      cout << "Limit aşımı : (" << myId << "), Girdiğiniz değer " << value << ". Lütfen " << myLimit << " limitinde kalınız." << endl;
    }
  }

};

int main()
{
  Handler *h1 = new SpecialHandler(10, 1);
  Handler *h2 = new SpecialHandler(20, 2);
  Handler *h3 = new SpecialHandler(30, 3);

  h1->sorgula(9);
  h1->sorgula(11);

  h1->setHandlerGecis(h2);
  h1->sorgula(18);
  h1->sorgula(40);

  h2->sorgula(19);
  h2->sorgula(25);
  h2->setHandlerGecis(h3);
  h2->sorgula(25);

  delete h1;
  delete h2;
  delete h3;

  return 0;
}