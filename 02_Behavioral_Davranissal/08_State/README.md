# State Pattern

**"State Pattern"**, bir nesnenin iç durumu değiştiğinde davranışını da değiştirmesini sağlar. Bu durumda nesne, çalışma zamanında sınıfını değiştiriyormuş gibi davranır. Yani duruma göre farklı işlevleri yerine getirir. 

## State Pattern Kullanım Adımları

* İlk olarak **"Makine"** isminde bir sınıf oluşturuyoruz. Bu sınıf, işlem görecek ana sınıfımız. Bu sınıf içinde dikkat ederseniz **"class Durum *durum;"** diye bir tanımlama bulunmakta. Aslında asıl **"Durum"** sınıfı, daha sonra tanımlanacak. Eğer sınıfın yukarısında tanımlamazsak, içinde kullanacağımız zaman başına **"class"** ifadesini getirmek gerekmekte. Aksi taktirde **"error: ‘Durum’ does not name a type Durum *durum;"** hatası alacktı.

```cpp
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
```

* Şimdi ise **"Durum"** sınıfını tanımlıyoruz. Bu sınıf içinde 2 method bulunmakta. Bunlar **"ac"** ve **"kapat**". farkındaysanız bu methodlar **"virtual"** türünde. Yani miras kalınca tekrar tanımlanabilir.

```cpp
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
```

* Şimdi durumumuz değiştiğinde yapılacak olan işlemleri görelim. İlk olarak açık konum için **"AC"** isminde bir sınıf tanımlıyoruz. Bu sınıfın Constructor methoduna ve Deconstructor methodunda loglar bulunmakta. Aynı zamanda **"kapat"** isminde de bir method bulunmakta. Aynı şekilde  **"KAPAT"** isminde de bir sınıd bulunmakta. Bu sınıftada aynı yapı bulunmakta. Fakat fark olarak içinde ac isminde bir komut bulunmakta.

```cpp
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
```

* Şimdi tanımladığımız sınıflardaki methodların tanımlamalarını inceleyelim. İlk olarak **"Makine"** constructor girildiğinde **"durum = new KAPAT();"** satırı çalışıyor. Bu satır, Makinayı kapalı bir şekilde konumlandırmaya yarıyor. 

```cpp
Makine::Makine()
{
    durum = new KAPAT();
    cout << '\n';
}
```
* **"Makine"** sınıfının **"setDurum"** fonksiyonunu incelediğimizde, dışarıdan bir **"Durum"** alıyor ve sınıfa o durumun sınıfını atamasını sağlıyor.

```cpp
void Makine::setDurum(Durum *durum)
{
    this->durum = durum;
}
```

* **"Makine"** sınıfında bulunan **"ac"** fonksiyonu çalıştırılınca, sınıfa atanan **"Durum"** nesnesinin **"ac"** fonksiyonunu çalıştırıyoruz.

```cpp
void Makine::ac()
{
    durum->ac(this);
}
```

* **"Makine"** sınıfında bulunan **"kapat"** fonksiyonu çalıştırılınca, sınıfa atanan **"Durum"** nesnesinin **"kapat"** fonksiyonunu çalıştırıyoruz.

```cpp
void Makine::kapat()
{
    durum->kapat(this);
}
```

* **"AC"** sınıfında bulunan **"kapat"** methodu kullanıcıdan **"Makine"** türünde nesne alır ve **" m->setDurum(new KAPAT());"** satırını çalıştırarak, komut değiştirir ve kendini siler.

```cpp
void AC::kapat(Makine *m)
{
    cout << "   AC konumundan KAPAT konumuna geçildi";
    m->setDurum(new KAPAT());
    delete this;
}
```

* **"KAPAT"** sınıfında bulunan **"ac"** methodu kullanıcıdan **"Makine"** türünde nesne alır ve **" makine->setDurum(new AC());"** satırını çalıştırarak, komut değiştirir ve kendini siler.

```cpp
void KAPAT::ac(Makine *makine)
{
    cout << "   KAPAT konumundan AC konumuna geçildi";
    makine->setDurum(new AC());
    delete this;
}

```

* Kullanım için ise;

```cpp
int main()
{
    void (Makine::*ptrs[])() = {&Makine::kapat, &Makine::ac};
    Makine makine;
    int num;
    while (1)
    {
        cout << "Durum Giriniz : 0 - 1: ";
        cin >> num;
        (makine.*ptrs[num])();
    }
}
```
