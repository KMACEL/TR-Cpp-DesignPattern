# C++ ile Design Pattern (Tasarım Kalıpları (Örüntüleri))

## Not
Bu projedeki örnekler, daha anlaşılabilir olması için Türkçe yazılmaya çalışılmıştır. Bazı kalıplar ise İngilizce olarak bırakılmıştır(get,set...). Bu kalıpları çevirmek, ileride proje geliştirme sırasında zorlanılacağını düşündüğümüz için bu şekilde kullanım gerçekleştirilmektedir. 

## **Creational** (Yaratılış)

Yaratılış kalıpları, nesneleri doğrudan oluşturmanıza değil, sizin için nesneler yaratan kalıplardır. Bu, belirli bir durum için hangi nesnelerin yaratılması gerektiğine karar vermede programınıza daha fazla esneklik sağlar.

* ✓✓ **Singleton** pattern,  bir sınıf için sadece bir nesne oluşturmayı sağlar.
* ✓✓ **Factory method** pattern, oluşturulacak tam sınıfı belirtmeden nesneleri oluşturur.
* ✓✓ **Abstract factory**  pattern, ortak gruplar, ortak bir temaya sahip olan sınıfların yaratılış biçimini hedefler.
* ✓✓ **Builder** pattern, karmaşık nesneler inşa eder.
* ✓✓ **Prototype** pattern, mevcut bir nesneyi klonlayarak nesneler oluşturur.

## **Behavioral** (Davranışsal)

Bu tasarım desenlerinin çoğu, özellikle nesneler arasındaki iletişim ile ilgili yapılardır.

* ✓✓ **Chain of Responsibility** delegates commands to a chain of processing objects.
* ✓✓ **Command** creates objects which encapsulate actions and parameters.
* ✓ **Interpreter** implements a specialized language.
* ✓ **Iterator** accesses the elements of an object sequentially without exposing its underlying representation.
* **Mediator** allows loose coupling between classes by being the only class that has detailed knowledge of their methods.
* **Memento** provides the ability to restore an object to its previous state (undo).
* ✓✓ **Observer** is a publish/subscribe pattern which allows a number of observer objects to see an event.
* ✓✓ **State** allows an object to alter its behavior when its internal state changes.
* ✓✓ **Strategy** allows one of a family of algorithms to be selected on-the-fly at runtime.
* ✓✓ **Template** method defines the skeleton of an algorithm as an abstract class, allowing its subclasses to provide concrete behavior.
* ✓ **Visitor** separates an algorithm from an object structure by moving the hierarchy of methods into one object.

## **Structural**
These concern class and object composition. They use inheritance to compose interfaces and define ways to compose objects to obtain new functionality.

* ✓✓ **Adapter** allows classes with incompatible interfaces to work together by wrapping its own interface around that of an already existing class.
* ✓ **Bridge** decouples an abstraction from its implementation so that the two can vary independently.
* ✓ **Composite** composes zero-or-more similar objects so that they can be manipulated as one object.
* ✓✓ **Decorator** dynamically adds/overrides behaviour in an existing method of an object.
* ✓✓ **Facade** provides a simplified interface to a large body of code.
* **Flyweight** reduces the cost of creating and manipulating a large number of similar objects.
* ✓ **Proxy** provides a placeholder for another object to control access, reduce cost, and reduce complexity.

## **Sistem Gereksinimleri**
Bu örnekler Linux Mint 18.3 Slvia ve Ubuntu 18.04.1 LTS işletim sistemlerinde test edilmiştir.

```bash
sudo apt-get install git -y
sudo apt-get install build-essential -y
sudo apt-get install cmake -y
sudo apt-get install g++ -y
```
## **Yükleme**
```bash
git clone https://github.com/KMACEL/TR-Cpp-DesignPattern.git
```
## **Çalıştırma**
```bash
cd <ornek_proje_yolu>
mkdir build
cd build
cmake ..
make
./../bin/<proje_ismi>
```

```bash
cd 01_Creational_Yaratilis/01_Singleton/01_Giris/
mkdir build
cd build
cmake ..
make
./../bin/Singleton-01_Giris
```

## **Kaynak**
> https://en.wikipedia.org/wiki/Design_Patterns 

> https://sourcemaking.com/

> https://www.geeksforgeeks.org

> https://cpppatterns.com

> https://www.codeproject.com/

> https://en.wikibooks.org/wiki/C++_Programming/Code/Design_Patterns

> http://simplestcodings.blogspot.com

> http://www.turtep.edu.tr/

> https://goalkicker.com/ - C++ Notes for Professionals book

> Design Patterns in Modern C++ - Dmitri Nesteruk

> Design Patterns Explained Simply - Alexander Shvets

> Modern C++ Design: Generic Programming and Design Patterns Applied - Andrei Alexandrescu
