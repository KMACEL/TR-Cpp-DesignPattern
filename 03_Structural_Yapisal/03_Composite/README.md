# Composite Pattern 
**"Composite Pattern"**, belli bir türde olan nesnelerin tek tek veya eşit olarak ele almasını sağlar. **"Composite Pattern"**, her iki durumu da temsil edebilir. Bu modelde, bir bütün olarak hiyerarşileri temsil etmek için ağaç yapıları geliştirilebilir.

## Composite Pattern Kullanım Adımları

* İlk önce **"Grafik"** isminde ana soyut sınıfımızı oluşturuyoruz.

```cpp
class Grafik
{
  public:
    virtual void yazdir() const = 0;
};
```

* Ardından bu sınıftan türeyecek olan **"Elips"**, **"Ucgen"**, **"Elips"**, türlerinde nesneler oluşturuyoruz.

```cpp
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
```

* Daha önce oluşturuduğumuz sınıfları tek tek kullanılabileceği gibi, **"CompositeGrafik"** olduğu gibi toplu işlerde yapılabilmektedir. Burada **"ekle"** methodu sayesinde, **"Grafik"** sınıf türündeki nesneleri ortak olarak kullanabilmekteyiz.

```cpp
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
```

* Kullanım için ilk önce **"Elips"**, **"Ucgen"**, **"Elips"**, türlerinden nesneler üretiyoruz. Ardından **"CompositeGrafik"** türünden nesneler üretiyoruz. Ürettiğimiz **"CompositeGrafik"** nesnelerine kendileri dahil olmak üzere istediğimiz verilileri ekleme ve eklediğimiz nenslerin **"yazdır"** methodunu çalıştırabiliğyoruz.

```cpp
int main()
{
    Elips *elips1 = new Elips();
    Elips *elips2 = new Elips();
    Kare *kare = new Kare();
    Ucgen *ucgen = new Ucgen();

    // Initialize three composite graphics
    CompositeGrafik *graphic1 = new CompositeGrafik();
    CompositeGrafik *graphic2 = new CompositeGrafik();
    CompositeGrafik *graphic3 = new CompositeGrafik();

    // Composes the graphics
    graphic2->ekle(elips1);
    graphic2->ekle(elips2);
    graphic3->ekle(kare);
    graphic2->ekle(ucgen);

    graphic1->ekle(graphic2);
    graphic1->ekle(graphic3);

    // Prints the complete graphic (four times the string "Ellipse")
    graphic1->yazdir();
    return 0;
}
```