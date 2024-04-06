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

struct Mokinys
{
    string vardas;
    string pavarde;
    deque<int> ND;
    int egzaminas;
    double VID;
    double MED;
};

#endif
