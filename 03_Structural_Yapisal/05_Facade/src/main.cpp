//============================================================================
// İsim        : 05_Facade
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : Facade Pattern
//============================================================================
#include <string>
#include <iostream>

using namespace std;

class Alarm
{
  public:
    void alarmAc()
    {
        cout << "Alarm Açıldı. Eviniz güvende..." << endl;
    }

    void alarmKapat()
    {
        cout << "Alarm Kapatıldı..." << endl;
    }
};

class Elektrik
{
  public:
    void elektrikAc()
    {
        cout << "Elektrik Açık..." << endl;
    }

    void elektrikKapat()
    {
        cout << "Elektrik Kapalı..." << endl;
    }
};

class Tv
{
  public:
    void tvAc()
    {
        cout << "Tv Açık..." << endl;
    }

    void tvKapat()
    {
        cout << "TV Kapalı..." << endl;
    }
};

class EvFacade
{
    Alarm alarm;
    Elektrik elektrik;
    Tv tv;

  public:
    EvFacade() {}

    void evdenDisariCikinca()
    {
        elektrik.elektrikKapat();
        tv.tvKapat();
        alarm.alarmAc();
    }

    void eveDonunce()
    {
        alarm.alarmKapat();
        elektrik.elektrikAc();
        tv.tvAc();
    }
};

int main()
{
    EvFacade evFacade;

    cout << "Evden İşe Gidiliyor ..." << endl;
    evFacade.evdenDisariCikinca();

    cout << "---------------------------------------------" << endl;

    cout << "Eve Giriliyor..." << endl;
    evFacade.eveDonunce();
}
