# Singleton Pattern

**Singleton** kelime anlamı olarak dilimize **"Tek Şey"** şeklinde çevrilebilir. İsimdende yola çıkarak, aslında **Tek** sınıf daha doğrusu bir sınıftan üretilen sadece tek bir obje  olmasıdır. Yani nereden çağırılırsa çağırılsın tek sonuç, aynı sonuç dönme durumudur. Kısaca bir **Singleton** sınıfını nerede çağırırsanız çağırın, hepsinde aynı şekilde işlemler sağlayacaktır. Kaç kere obje oluşturulursa oluşturulsun, ilk oluşturulan hali ile geri dönme durumudur. Bu patterni bir çok projede görebilirsiniz. 

Singleton patternini 2 porje olarak göreceksiniz. Bunun sebebi, bu pattern multithread yapılarda bazı istenmeyen sonuçlar sağlama olasılığıdır ve buna alınan önlemler içindir.

## Singleton Pattern Kullanım Adımları
Bu pattern kullanılması için uyulacak adımlar şu şekildedir.
* İlk adım olarak, **Singleton** olacak sınıf içinde **private** erişim hakkı olarak **static** biçiminde, **<Singleton_Sınıfınızın_ismi>** tipinde bir değişken tanımlıyoruz. Bizim projemizde bu şu şekilde tanımlıyoruz;
```cpp
class Mesaj // Singleton Sınıfımız
{
private: // Erişim Türü
  static Mesaj *INSTANCE; // "Singleton Sınıf" türünde "INSTANCE" değişkeni
};
```
* **Constructor** methodumuz, **kesinlikle** **public** erişim türünde olmamalıdır. Bunun sebebi, bu sınıftan isteğimiz dışında obje oluşturulmasını engellemektir. Fakat başka sınıflara miras bırakılma durumu için **protected** erişim hakkı içinda tanımlanabilir. İsteğe bağlı olarak **private** erişim hakkı seçilebilir. Biz projemizde, **protected** tercih ediyoruz.

```cpp
protected:
  // Constructor Methodumuz
  Mesaj()
  {
  }
```

* **Singleton** bir sınıf temel kullanım için son olarak, sınıfı çağıran bir method gerekmektedir. Bu method her yerden çağırılabilmesi için **public** erişim hakkında olması gerekmektedir. Bu method, geriye ilgili sınıf türünü döndürecektir. Bu method **static** olmasına dikkat etmek gerekmektedir. genel kullanım isimlendirmesi sebebi ile biz fonksiyonumuzun ismini **"getInstance"** yaptık. Bu fonksiyon içinde dikakt edilmesi gereken bir bölüm bulunmaktadır. **private** bölümünde oluşturduğumuz sınıf değişkeni -bizim projemizde **"INSTANCE"**- içi boş durumdadır. Yani **0** dır. Ve biz methodumuzda eğer **0** ise yani hiç değer atanmamış ise  **INSTANCE = new Mesaj();** kullanımı olarak ilk değeri atıyoruz. methodun sonunda ise geriye **"INSTANCE"** değerini döndürüyoruz. Yani, eğer bu method oluşturulmamış ise, ilk kez kullanılıyor ise, koşulumuz sayesinde, sınıfımızı değişkene atayıp geri döndürüyoruz. Eğer daha önce oluşturulmuş ise, var olan sınıfı geri döndürüyoruz. Bu durumda bize teklik sağlamış oluyor. 

```cpp
public:
  // Mesaj sınıfımızı kullanmak için oluşturduğumuz public türündeki method
  static Mesaj *getInstance()
  {
    // Eğer INSTANCE değeri 0 ise yani hiç bu sınıf çağırılmamışsa,
    // sınıfı oluşturuyoruz.
    if (INSTANCE == 0)
    {
      INSTANCE = new Mesaj();
    }
    // Eğer bu sınıf daha öncd oluşturulmuşsa, yani çağırılmışsa geriye
    // var olan "INSTANCE"yi döndürüyoruz
    return INSTANCE;
  }
```
## Singleton Pattern Kullanım Örneği

Örneğimizde basit bir **Singleton** sınıf tasarlanmıştır. Bu sınıf, **Singleton Pattern Kullanım Esasları** kısmında anlatılanların dışında, mesaj değişkeni eklenmiştir. Aynı zamanda güvenlik önlemleri de eklenmiştir.  

```cpp
#include <iostream>
#include <string>

using namespace std;

class Mesaj
{
private:
  // INSTANCE değişkenini tanımlıyoruz
  static Mesaj *INSTANCE;
  string mesaj;

protected:
  // Constructor Methodumuz
  Mesaj()
  {
  }

  // c++ 11 ile gelen, constructor kopyalanmasını engellenyen yapı
  Mesaj(const Mesaj &) = delete;

  // Atama operatörü "=" derleyici tarafından
  // otomatik üretebilinen bir operatördür.
  // Bu da singleton için işlevini kaybetmeye sebep olabilir.
  // Bunuda tanımlamamız karşılaşılacak problemleri azaltır.
  Mesaj &operator=(const Mesaj &) = delete;

  // Güvenlik olarak Destructor özel yapmaktır. Bu önlem,
  // Singleton nesnesinin  istem dışı olarak silmesini engeller.
  ~Mesaj();

public:
  // Mesaj sınıfımızı kullanmak için oluşturduğumuz public türündeki method
  static Mesaj *getInstance()
  {
    // Eğer INSTANCE değeri 0 ise yani hiç bu sınıf çağırılmamışsa,
    // sınıfı oluşturuyoruz.
    if (INSTANCE == 0)
    {
      INSTANCE = new Mesaj();
    }
    // Eğer bu sınıf daha öncd oluşturulmuşsa, yani çağırılmışsa geriye
    // var olan "INSTANCE"yi döndürüyoruz
    return INSTANCE;
  }

  // mesaj değişkenine veri atamamıza yardımcı olan method
  void setMesaj(string mesaj)
  {
    this->mesaj = mesaj;
  }

  // mesaj değişkeninden veri almaya yarayan method
  string getMesaj()
  {
    return this->mesaj;
  }

  // mesaj değişken içeriğini yazmaya yarayan method
  void mesajYazir()
  {
    cout << "Mesajınız : " << getMesaj() << endl;
  }
};

// INSTANCE değerine ilk atama, sıfırlama işlemi yapan kısım
Mesaj *Mesaj::INSTANCE = 0;

int main()
{
  // 1. Kullanış Biçimi : Bir "Mesaj" sınıfından "m1" adında nesne yaratıp,
  // Mesaj sınıfının "Instance"sini içeri aktrıyoruz
  Mesaj *m1 = Mesaj::getInstance();
  m1->setMesaj("Test");
  m1->mesajYazir();

  // 2. Kullanış Biçimi : Hiç bir nesne yaratmadan direk kullanabiliyoruz.
  Mesaj::getInstance()->setMesaj("Merhaba");
  Mesaj::getInstance()->mesajYazir();

  // Burada da gösterilmek istenen, tekrar bir nesne yaratılmasına rağmen ve
  // setMesaj() fonksiyonunu kullanmamamıza rağmen, bir önceki hali oluyor.
  Mesaj *m2 = Mesaj::getInstance();
  m2->mesajYazir();

  return 0;
}

```

## Singleton Pattern Multithread Eklentisi

**Singleton**, multithread bir yapıda, istenmeyen durumlar oluşturabilir. Aynı anda birden fazla sınıf yaratma durumu ile karşılaşılabilir. Bunu önlemek için, sınıfımıza bazı eklentiler yapmak gerekmektedir. 

* İlk olarak içeriye **<mutex>** sınıfını ekliyoruz. Bu sınıf bizim **"lock"** yani kitleme mekanizmasını kazandıracak.
```cpp
#include <mutex>
```

* Ardından bu sınıftan, Singleton sınıfımızdan önce bir nesne oluşturuyoruz.
```cpp
mutex mtx;
```

* Son olarak **"getInstance"** sınıfımıza eklemelerimiz gerçekleştiriyoruz.

```cpp
 static Mesaj *getInstance()
  {
    // Eğer çift kontrollü olursa daha güvenli olduğu gözlemlenmiştir 
    if (INSTANCE == 0)
    {
      mtx.lock();
      if (INSTANCE == 0)
      {
        INSTANCE = new Mesaj();
      }
      mtx.unlock();
    }
    return INSTANCE;
  }
```