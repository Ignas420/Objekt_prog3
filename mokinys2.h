#ifndef MOKINYS_H
#define MOKINYS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <deque>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <cstring>
#include <stdexcept>
#include <list>

using namespace std;

const char CRfv[] = "rezultatai.txt";
const char CRfv2[] = "naujas_failas.txt";
const char CRfv3[] = "mokslinciai.txt";
const char CRfv4[] = "nuskriaustieji.txt";

class Mokinys {
private:
    string vardas;
    string pavarde;
    deque<int> ND;
    int egzaminas;
    double VID;
    double MED;

public:
    // Constructor
    Mokinys() : vardas(""), pavarde(""), egzaminas(0), VID(0), MED(0) {}

    ~Mokinys(){}

    // Getter functions
    string getVardas() const { return vardas; }
    string getPavarde() const { return pavarde; }
    deque<int> getND() const { return ND; }
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
    void Vidurkis(deque<Mokinys> & A);
    void Isvedimas(const deque<Mokinys> &A, int MOK_kiekis, string isvedimas);
    void Isvedimas2(const deque<Mokinys> &A, int MOK_kiekis, string isvedimas);
    static bool PagalVidurki(const Mokinys &a, const Mokinys &b);
    static bool PagalMediana(const Mokinys &a, const Mokinys &b);
    static bool PagalVarda(const Mokinys &a, const Mokinys &b);
    static bool PagalPavarde(const Mokinys &a, const Mokinys &b);
    void Rikiavimas(deque<Mokinys> &Mokslinciai, deque<Mokinys> &Nuskriaustieji, deque<int> &IrasuSk);
    void Skaitymas(deque<Mokinys> &Nuskriaustieji, deque<Mokinys> &Mokslinciai, deque<int> &IrasuSk, string failas, deque<Mokinys> &A, int &temp, char strategija);
    void StudentuRusiavimas(deque<Mokinys> &Nuskriaustieji, deque<Mokinys> &Mokslinciai, deque<Mokinys> &A, deque<int> &IrasuSk, string failas, int &temp);
    void StudentuRusiavimas2(deque<Mokinys> &Nuskriaustieji, deque<Mokinys> &Mokslinciai, deque<Mokinys> &A, deque<int> &IrasuSk, string failas, int &temp);
    void StudentuRusiavimas3(deque<Mokinys> &Nuskriaustieji, deque<Mokinys> &Mokslinciai, deque<Mokinys> &A, deque<int> &IrasuSk, string failas, int &temp);
};


#endif
