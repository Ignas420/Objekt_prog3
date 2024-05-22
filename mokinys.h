#ifndef MOKINYS_H
#define MOKINYS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Vector>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <cstring>
#include <stdexcept>
#include <list>
#include <deque>
#include <cassert>
#include <utility>
#include <initializer_list>
#include <iterator>

using namespace std;

const char CRfv[] = "rezultatai.txt";
const char CRfv2[] = "naujas_failas.txt";
const char CRfv3[] = "mokslinciai.txt";
const char CRfv4[] = "nuskriaustieji.txt";

// const char CDfv[] = "kursiokai.txt";
const char CDfv0[] = "studentai10000.txt";
const char CDfv1[] = "studentai100000.txt";
const char CDfv2[] = "studentai1000000.txt";

template <typename T>
class Vector
{
private:
    T *data;
    size_t _size;
    size_t _capacity;

    void reallocate(size_t newCapacity);

    template <typename InputIterator>
    void assign_impl(InputIterator first, InputIterator last, std::input_iterator_tag);

    template <typename RandomAccessIterator>
    void assign_impl(RandomAccessIterator first, RandomAccessIterator last, std::random_access_iterator_tag);

public:
    Vector(size_t size, size_t capacity, const T &defaultValue)
        : _size(size), _capacity(capacity)
    {
        data = new T[_capacity];
        for (size_t i = 0; i < _size; ++i)
        {
            data[i] = defaultValue;
        }
    }
    Vector();
    explicit Vector(size_t initialCapacity);
    Vector(size_t size, const T &defaultValue);
    Vector(std::initializer_list<T> initList);
    Vector(const Vector &other);
    Vector(Vector &&other) noexcept;
    Vector &operator=(const Vector &other);
    Vector &operator=(Vector &&other) noexcept;
    ~Vector();

    template <typename InputIterator>
    void assign(InputIterator first, InputIterator last);
    void assign(size_t count, const T &value);
    void assign(std::initializer_list<T> ilist);

    void insert(size_t index, const T &value);
    template <typename InputIterator>
    void insert_range(size_t index, InputIterator first, InputIterator last);
    void append_range(std::initializer_list<T> ilist);

    T &at(size_t index);
    const T &at(size_t index) const;

    typename std::reverse_iterator<T *> rbegin();
    typename std::reverse_iterator<T *> rend();
    typename std::reverse_iterator<const T *> rbegin() const;
    typename std::reverse_iterator<const T *> rend() const;
};

// Bazine ir Derived klases
class Zmogus
{
protected:
    string vardas;
    string pavarde;

public:
    Zmogus(string vard = "", string pav = "") : vardas(move(vard)), pavarde(move(pav)) {}
    virtual ~Zmogus() = default;
    virtual void patikrinimas() const = 0;
};

class Mokinys : public Zmogus
{
private:
    /* string vardas;
    string pavarde; */
    Vector<int> ND;
    int egzaminas;
    double VID;
    double MED;

public:
    // Constructor
    Mokinys(string vard = "", string pav = "", Vector<int> nd = {}, int e = 0, double vid = 0.0, double med = 0.0)
        : Zmogus(move(vard), move(pav)), ND(nd), egzaminas(e), VID(vid), MED(med) {}

    // Destructor
    ~Mokinys() = default;

    void patikrinimas() const override {};

    // Copy constructor
    Mokinys(const Mokinys &other) : Zmogus(other), ND(other.ND), egzaminas(other.egzaminas), VID(other.VID), MED(other.MED) {}

    // Move contructor
    Mokinys(Mokinys &&other) noexcept
        : Zmogus((move(other.vardas)), (move(other.pavarde))),
          ND(move(other.ND)), egzaminas(exchange(other.egzaminas, 0)),
          VID(exchange(other.VID, 0)), MED(exchange(other.MED, 0)) {}

    // Copy Assignment Operator
    Mokinys &operator=(const Mokinys &other)
    {
        Zmogus::operator=(other);
        ND = other.ND;
        egzaminas = other.egzaminas;
        VID = other.VID;
        MED = other.MED;
        return *this;
    }

    void clear()
    {
        vardas.clear();
        pavarde.clear();
        ND.clear();
        egzaminas = 0;
        VID = 0;
        MED = 0;
    }

    // Move Assignment Operator
    Mokinys &operator=(Mokinys &&other) noexcept
    {
        if (this != &other)
        {
            // Copy data from 'other' to 'this'
            vardas = std::move(other.vardas);
            pavarde = std::move(other.pavarde);
            ND = std::move(other.ND);
            egzaminas = other.egzaminas;
            VID = other.VID;
            MED = other.MED;

            // Clear 'other'
            other.clear();
        }
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &fr, const Mokinys &temp1)
    {
        fr << "Vardas: " << temp1.vardas << endl;
        fr << "Pavarde: " << temp1.pavarde << endl;
        fr << "Namu darbai: ";
        for (int pazymys : temp1.ND)
        {
            fr << pazymys << " ";
        }
        cout << endl;
        fr << "Egzamino pazymys: " << temp1.egzaminas << endl;
        fr << "Mediana: " << temp1.MED << endl;
        fr << "Vidurkis: " << temp1.VID << endl;
        return fr;
    }

    friend istream &operator>>(istream &fd, Mokinys &temp1)
    {
        cout << "Iveskite varda: ";
        fd >> temp1.vardas;
        cout << "Iveskite pavarde: ";
        fd >> temp1.pavarde;
        cout << "Iveskite namu darbus: ";
        int pazymys;
        temp1.ND.clear();
        while (fd >> pazymys && pazymys != 0)
        {
            temp1.ND.push_back(pazymys);
        }
        cout << "Iveskite egzamino pazymi: ";
        fd >> temp1.egzaminas;
        cout << "Iveskite mediana: ";
        fd >> temp1.MED;
        cout << "Iveskite vidurki: ";
        fd >> temp1.VID;
        return fd;
    }

    // Getter functions
    string getVardas() const { return vardas; }
    string getPavarde() const { return pavarde; }
    Vector<int> getND() const { return ND; }
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
    void Vidurkis(Vector<Mokinys> &A);
    void Isvedimas(const Vector<Mokinys> &A, int MOK_kiekis, string isvedimas);
    void Isvedimas2(const Vector<Mokinys> &A, int MOK_kiekis, string isvedimas);
    static bool PagalVidurki(const Mokinys &a, const Mokinys &b);
    static bool PagalMediana(const Mokinys &a, const Mokinys &b);
    static bool PagalVarda(const Mokinys &a, const Mokinys &b);
    static bool PagalPavarde(const Mokinys &a, const Mokinys &b);
    void Skaitymas(Vector<Mokinys> &Nuskriaustieji, Vector<Mokinys> &Mokslinciai, Vector<int> &IrasuSk, string failas, Vector<Mokinys> &A, int &temp, char strategija);
    void StudentuRusiavimas(Vector<Mokinys> &Nuskriaustieji, Vector<Mokinys> &Mokslinciai, Vector<Mokinys> &A, Vector<int> &IrasuSk, string failas, int &temp);
    void StudentuRusiavimas2(Vector<Mokinys> &Nuskriaustieji, Vector<Mokinys> &Mokslinciai, Vector<Mokinys> &A, Vector<int> &IrasuSk, string failas, int &temp);
    void StudentuRusiavimas3(Vector<Mokinys> &Nuskriaustieji, Vector<Mokinys> &Mokslinciai, Vector<Mokinys> &A, Vector<int> &IrasuSk, string failas, int &temp);
    void Rikiavimas(Vector<Mokinys> &Mokslinciai, Vector<Mokinys> &Nuskriaustieji, Vector<int> &IrasuSk);
};

#endif