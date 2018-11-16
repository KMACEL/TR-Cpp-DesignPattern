# Visitor Pattern 

**"Visitor Pattern"**, üzerinde çalıştığı öğelerin sınıflarını değiştirmeden yeni bir işlem tanımlamanıza izin vererek bir nesne yapısının öğeleri üzerinde gerçekleştirilecek bir işlemi temsil edecektir.

## Visitor Pattern Kullanım Adımları

* İlk önce projede kullancağımız sınıfların şablonlarını tanımlıyoruz.
```cpp
class Tekerlek;
class Motor;
class Govde;
class Araba;
```

* Ardından **"ArabaBirlesenleriVisitor"** isminde soyut bir sınıf belirliyoruz. Bu sınıf içinde, bütün birleşenleri ekliyoruz.

```cpp
class ArabaBirlesenleriVisitor
{
  public:
    virtual void visit(Tekerlek &tekerlek) const = 0;
    virtual void visit(Motor &motor) const = 0;
    virtual void visit(Govde &govde) const = 0;
    virtual void visitAraba(Araba &car) const = 0;
};
```

* Sonra **"ArabaBirlesenleri"** isminde bir soyut sınıf oluşturuyoruz. Bu sınıfta **"onayla"** ismind ebir method bulunmakta. 

```cpp
class ArabaBirlesenleri
{
  public:
    virtual void onayla(const ArabaBirlesenleriVisitor &visitor) = 0;
};
```

* Sonraki adım olarak birleşenleri somutlaştırıyoruz. Bizim arabamızın birleşenleri **"Tekerlek"**, **"Motor"**, **"Govde"** den oluşuyor. Bunun içinde ayrı ayrı tanımlamalar yapıyoruz. Bu sınıfları oluştururken **"ArabaBirlesenleri"** sınıfından miras alıyoruz. Burada dikkat edişmesi gereken husus **"onayla"** methodu. Bütün ontayla methodları içinde **"visitor.visit(*this);"** kodu bulunmakta. 

```cpp
class Tekerlek : public ArabaBirlesenleri
{
  private:
    string isim;

  public:
    Tekerlek(const string &isim) : isim(isim)
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
```

* Ardından arabımızı oluşturmak için **"Araba"** sınıfımızı oluşturuyoruz. Bu sınıfta bir adet **"vector"** bulunmakta. Bu vektör, bizim birleşenlerimizi barındırıyor. Constructor yardımı ile bütün birleşenleri ekliyoruz.

```cpp
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
```

* Ardından **"ArabaBirlesenleriVisitor"** sınıfından miras alan **"ArabaBirlesemleriYazdirVisitor"** sınıfını oluşturuyrouz. Bu sınıf, bize tek tek bütün birleşenler için **"visit"** methodunu tanımlıyor.

```cpp
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
```

* Son olarak yine **"ArabaBirlesenleriVisitor"** sınıfından miras alan **"ArabaBirlesemleriYapVisitor"** isminde bir sınıf oluşturuyoruz. Bu sınıf, artık araba montaj işlemini gerçekleştiriyor.

```cpp
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
```

* Kullanmak için bir **"Araba"** nesnesi üretiyoruz. Ardından  **"ArabaBirlesemleriYazdirVisitor"** ve **"ArabaBirlesemleriYapVisitor"** nesneleri üretiyoruz. ardından  **"visitAraba"** methodu ile, farklı işler yaptırabiliyoruz.

```cpp
int main()
{
    Araba araba;
    ArabaBirlesemleriYazdirVisitor arabaBirlesemleriYazdirVisitor;
    ArabaBirlesemleriYapVisitor arabaBirlesemleriYapVisitor;

    arabaBirlesemleriYazdirVisitor.visitAraba(araba);
    arabaBirlesemleriYapVisitor.visitAraba(araba);

    return 0;
}
```