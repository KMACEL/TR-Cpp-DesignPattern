## GOF

> https://en.wikipedia.org/wiki/Design_Patterns 

## **Creational** (Yaratılış)

Yaratılış kalıpları, nesneleri doğrudan oluşturmanıza değil, sizin için nesneler yaratan kalıplardır. Bu, belirli bir durum için hangi nesnelerin yaratılması gerektiğine karar vermede programınıza daha fazla esneklik sağlar.

* **Singleton** pattern,  bir sınıf için sadece bir nesne oluşturmayı sağlar.
* **Factory method**  pattern creates objects without specifying the exact class to create.
* **Abstract factory**  pattern groups object factories that have a common theme.
* **Builder** pattern constructs complex objects by separating construction and representation.
* **Prototype** pattern creates objects by cloning an existing object.

## **Structural**
These concern class and object composition. They use inheritance to compose interfaces and define ways to compose objects to obtain new functionality.

* **Adapter** allows classes with incompatible interfaces to work together by wrapping its own interface around that of an already existing class.
* **Bridge** decouples an abstraction from its implementation so that the two can vary independently.
* **Composite** composes zero-or-more similar objects so that they can be manipulated as one object.
* **Decorator** dynamically adds/overrides behaviour in an existing method of an object.
* **Facade** provides a simplified interface to a large body of code.
* **Flyweight** reduces the cost of creating and manipulating a large number of similar objects.
* **Proxy** provides a placeholder for another object to control access, reduce cost, and reduce complexity.

## **Behavioral**

Most of these design patterns are specifically concerned with communication between objects.

* **Chain** of responsibility delegates commands to a chain of processing objects.
* **Command** creates objects which encapsulate actions and parameters.
* **Interpreter** implements a specialized language.
* **Iterator** accesses the elements of an object sequentially without exposing its underlying representation.
* **Mediator** allows loose coupling between classes by being the only class that has detailed knowledge of their methods.
* **Memento** provides the ability to restore an object to its previous state (undo).
* **Observer** is a publish/subscribe pattern which allows a number of observer objects to see an event.
* **State** allows an object to alter its behavior when its internal state changes.
* **Strategy** allows one of a family of algorithms to be selected on-the-fly at runtime.
* **Template** method defines the skeleton of an algorithm as an abstract class, allowing its subclasses to provide concrete behavior.
* **Visitor** separates an algorithm from an object structure by moving the hierarchy of methods into one object.

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