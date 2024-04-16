#ifndef MOKINYS_H
#define MOKINYS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include <random>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <stdexcept>
#include <deque>
#include <cstring>

using namespace std;

const char CRfv[] = "rezultatai.txt";
const char CRfv3[] = "mokslinciai.txt";
const char CRfv4[] = "nuskriaustieji.txt";

class Mokinys {
private:
    string vardas;
    string pavarde;
    list<int> ND;
    int egzaminas;
    double VID;
    double MED;

public:
    // Constructor
    Mokinys() : egzaminas(0), VID(0), MED(0) {}

    ~Mokinys(){}

    // Getter functions
    string getVardas() const { return vardas; }
    string getPavarde() const { return pavarde; }
    list<int> getND() const { return ND; }
    int getEgzaminas() const { return egzaminas; }
    double getVID() const { return VID; }
    double getMED() const { return MED; }

    // Setter functions
    void setVardas(const string &name) { vardas = name; }
    void setPavarde(const string &surname) { pavarde = surname; }
    void addND(int nd) { ND.push_back(nd); }
    void clearND() { ND.clear(); }
    void setEgzaminas(int exam) { egzaminas = exam; }
    void setVID(double vid) { VID = vid; }
    void setMED(double med) { MED = med; }

    // Utility functions
    void Vidurkis(list<Mokinys> & A);
    void Isvedimas(const list<Mokinys> &A, int MOK_kiekis, string isvedimas);
    void Isvedimas2(const list<Mokinys> &A, int MOK_kiekis, string isvedimas);
    static bool PagalVidurki(const Mokinys &a, const Mokinys &b);
    static bool PagalMediana(const Mokinys &a, const Mokinys &b);
    static bool PagalVarda(const Mokinys &a, const Mokinys &b);
    static bool PagalPavarde(const Mokinys &a, const Mokinys &b);
    void Skaitymas(list<Mokinys> &Nuskriaustieji, list<Mokinys> &Mokslinciai, list<int> &IrasuSk, string failas, list<Mokinys> &A, int &temp, char strategija);
    void StudentuRusiavimas(list<Mokinys> &Nuskriaustieji, list<Mokinys> &Mokslinciai, list<Mokinys> &A, list<int> &IrasuSk, string failas, int &temp);
    void StudentuRusiavimas2(list<Mokinys> &Nuskriaustieji, list<Mokinys> &Mokslinciai, list<Mokinys> &A, list<int> &IrasuSk, string failas, int &temp);
    void StudentuRusiavimas3(list<Mokinys> &Nuskriaustieji, list<Mokinys> &Mokslinciai, list<Mokinys> &A, list<int> &IrasuSk, string failas, int &temp);
    void Rikiavimas(list<Mokinys>& Mokslinciai, list<Mokinys>& Nuskriaustieji, list<int>& IrasuSk);
};


#endif
