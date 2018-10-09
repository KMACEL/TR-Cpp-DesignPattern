//============================================================================
// İsim        : 03_Interpreter
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : Interpreter Pattern
//============================================================================
#include <iostream>
#include <cstring>

using namespace std;

class RomaRakamInterpreter
{
private:
  RomaRakamInterpreter *binler;
  RomaRakamInterpreter *yuzler;
  RomaRakamInterpreter *onlar;
  RomaRakamInterpreter *birler;

protected:
  virtual char bir() {}
  virtual char *dort() {}
  virtual char bes() {}
  virtual char *dokuz() {}
  virtual int carpan() {}

public:
  RomaRakamInterpreter();
  RomaRakamInterpreter(int) {}
  int interpret(char *);
  
  virtual void interpret(char *input, int &total)
  {
    int index;
    index = 0;
    if (!strncmp(input, dokuz(), 2))
    {
      total += 9 * carpan();
      index += 2;
    }
    else if (!strncmp(input, dort(), 2))
    {
      total += 4 * carpan();
      index += 2;
    }
    else
    {
      if (input[0] == bes())
      {
        total += 5 * carpan();
        index = 1;
      }
      else
        index = 0;
      for (int end = index + 3; index < end; index++)
        if (input[index] == bir())
          total += 1 * carpan();
        else
          break;
    }
    strcpy(input, &(input[index]));
  }
};

class Binler : public RomaRakamInterpreter
{
public:
  Binler(int) : RomaRakamInterpreter(1) {}

protected:
  char bir()
  {
    return 'M';
  }
  char *dort()
  {
    return "";
  }
  char bes()
  {
    return '\0';
  }
  char *dokuz()
  {
    return "";
  }
  int carpan()
  {
    return 1000;
  }
};

class Yuzler : public RomaRakamInterpreter
{
public:
  Yuzler(int) : RomaRakamInterpreter(1) {}

protected:
  char bir()
  {
    return 'C';
  }
  char *dort()
  {
    return "CD";
  }
  char bes()
  {
    return 'D';
  }
  char *dokuz()
  {
    return "CM";
  }
  int carpan()
  {
    return 100;
  }
};

class Onlar : public RomaRakamInterpreter
{
public:
  Onlar(int) : RomaRakamInterpreter(1) {}

protected:
  char bir()
  {
    return 'X';
  }
  char *dort()
  {
    return "XL";
  }
  char bes()
  {
    return 'L';
  }
  char *dokuz()
  {
    return "XC";
  }
  int carpan()
  {
    return 10;
  }
};

class Birler : public RomaRakamInterpreter
{
public:
  Birler(int) : RomaRakamInterpreter(1) {}

protected:
  char bir()
  {
    return 'I';
  }
  char *dort()
  {
    return "IV";
  }
  char bes()
  {
    return 'V';
  }
  char *dokuz()
  {
    return "IX";
  }
  int carpan()
  {
    return 1;
  }
};

RomaRakamInterpreter::RomaRakamInterpreter()
{
  binler = new Binler(1);
  yuzler = new Yuzler(1);
  onlar = new Onlar(1);
  birler = new Birler(1);
}

int RomaRakamInterpreter::interpret(char *input)
{
  int total;
  total = 0;
  binler->interpret(input, total);
  yuzler->interpret(input, total);
  onlar->interpret(input, total);
  birler->interpret(input, total);

  if (strcmp(input, ""))
  {
    return 0;
  }

  return total;
}

int main()
{
  RomaRakamInterpreter interpreter;
  char input[20];
  cout << "Roma rakamı giriniz : ";
  while (cin >> input)
  {
    cout << "Latin Karşılığı : " << interpreter.interpret(input) << endl;
    cout << "Roma rakamı giriniz : ";
  }
}