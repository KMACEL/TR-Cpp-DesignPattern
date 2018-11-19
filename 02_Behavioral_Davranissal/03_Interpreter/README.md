# Interpreter Pattern

**"Interpreter Pattern"**, özellikle dil işleme gibi durumlarda oldukça tercih edilen bir türdür. 

## Interpreter Pattern Kullanım Adımları

Biz örneğimizde, girilen bir **"ROMA Rakamının"** karşılığını veren programı yazacağız.

* İlk adım olarak **"RomaRakamInterpreter"** isminde bir sınıf oluşturuyoryuz. Bu sınıfta **"private"** erişim hakkında ve **"RomaRakamInterpreter"** türünde  **"binler"**, **"yuzler"**, **"onlar"**, **"birler"** isminde nesneler oluşturuyoruz. Ardından **"protected"** türünde geri **"char"** tipinde değer döndüren **"bir"**, **"dort"**, **"bes"**, **"dokuz"** ve int tipinde **"carpan"** isminde methodlar tanımlıyoruz. Bu methodlar, romen rakamlarında etkileşime giren rakamlardır. Çarpanda, hangi basamak olduğunu belli eder. Dikkat edilmesi gereken husus, bu methodlar **"virtual"** yani soyuttur. Ardından  **"public"** erişim hakkında bazı işlemlerimiz bulunmakta. İlk olarak Constructorlar tanımlıyoruz ardından **"interpret"** tanımlıyoruz. En son bunların anlatımını gerçekleştireceğiz. Sonra, geri değer döndürmeyen ve sanal olan bir **"interpret"** methodu daha tanımlıyoruz.  Bu fonsiyon bizim için çok önemli çünkü bütün hesapalama burada gerçekleşmektedir. Dikkat ederseniz, **"virtual"** olarak tanımlanmış. Bu sayede, alt sınıflardan gelen verinin,  değer ve basamağına göre işlem yapmakta.

```cpp
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
```

* Şimdiki adım olarak oluşturduğumuz **"RomaRakamInterpreter"** sınıfından miras alan **"Binler"**, **"Yuzler"**, **"Onlar"**, **"Birler"** sınıflarını oluşturuyoruz. bu sınıflar hemen hemen aynıdır, farkları ise, ilgili basamakta döndürülen işaret. Mesela **"Binler"** sınıfında **"bir()"** methodu geriye **"M"** döndürürken, **Onlar"** sınıfı **"bir()"** methodu geriye **"X"** değeri döndürmektedir.  

```cpp
class Binler : public RomaRakamInterpreter
{
public:
  Binler(int) : RomaRakamInterpreter(1) {}

protected:
  char bir() override
  {
    return 'M';
  }
  char *dort() override
  {
    return "";
  }
  char bes() override
  {
    return '\0';
  }
  char *dokuz() override
  {
    return "";
  }
  int carpan() override
  {
    return 1000;
  }
};

class Yuzler : public RomaRakamInterpreter
{
public:
  Yuzler(int) : RomaRakamInterpreter(1) {}

protected:
  char bir() override
  {
    return 'C';
  }
  char *dort() override
  {
    return "CD";
  }
  char bes() override
  {
    return 'D';
  }
  char *dokuz() override
  {
    return "CM";
  }
  int carpan() override
  {
    return 100;
  }
};

class Onlar : public RomaRakamInterpreter
{
public:
  Onlar(int) : RomaRakamInterpreter(1) {}

protected:
  char bir() override
  {
    return 'X';
  }
  char *dort() override
  {
    return "XL";
  }
  char bes() override
  {
    return 'L';
  }
  char *dokuz() override
  {
    return "XC";
  }
  int carpan() override
  {
    return 10;
  }
};

class Birler : public RomaRakamInterpreter
{
public:
  Birler(int) : RomaRakamInterpreter(1) {}

protected:
  char bir() override
  {
    return 'I';
  }
  char *dort() override
  {
    return "IV";
  }
  char bes() override
  {
    return 'V';
  }
  char *dokuz() override
  {
    return "IX";
  }
  int carpan() override
  {
    return 1;
  }
};
```

* **"RomaRakamInterpreter"** constructorda değişkenlere atama gerçekleştiriyoruz. Ardından **"interpret"** methodunun tanımlamasını gerçekleştiriyoruz. Bu method, kullanıcıdan aldığı değeri, constructorda oluşturduğu sınıflara tek tek gönderip işlenmesini sağlıyor.

```cpp
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
```

* Kullanım için ise, **"RomaRakamInterpreter"** sınıfından bir nesne oluşturuyoruz. Ardından, **"interpreter.interpret(input) "** kodu ile, biz durdurana kadar dönüştürme işlemine devam ediyor. 

```cpp
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
```