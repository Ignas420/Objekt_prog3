#include "mokinys.h"
#include "funkcijos.h"

void Palyginimas()
{
    std::vector<int> Dydziai = {10000, 100000, 1000000, 10000000, 100000000};

    for(int j = 0; j<Dydziai.size(); j++){

    std::vector<int> v1;
    size_t default_exchange = 0;
    v1.clear();

    auto start = chrono::high_resolution_clock::now();
    auto st = start;

    for (int i = 1; i <= Dydziai[j]; ++i){
        v1.push_back(i);
        if (v1.capacity() == v1.size()) {
            default_exchange++;
        }
    }
    
    chrono::duration<double> diff = chrono::high_resolution_clock::now() - start;
    cout << "std :: vector push_back laikas su " << Dydziai[j] << " : " << diff.count() << endl;

    Vector<int> v2;
    size_t template_exchange = 0;
    v2.clear();

    auto start1 = chrono::high_resolution_clock::now();
    auto st1 = start1;

    for (int k = 1; k <= Dydziai[j]; ++k){
        v2.push_back(k);
        if (v2.capacity() == v2.size()) {
            template_exchange++;
        }
    }
    
    chrono::duration<double> diff1 = chrono::high_resolution_clock::now() - start1;
    cout << "template Vector push_back laikas su " << Dydziai[j] << " : " << diff.count() << endl;
    cout << endl;

    if(Dydziai[j] == 100000000){
        cout << "std::vector perskirstymu kiekis: " << default_exchange << endl;
        cout << "template Vector perskirstymu kiekis: " << template_exchange << endl;
    }
}

}
bool Patikrinimas(string kint)
{
    const int ilgis = kint.length();
    char *temp_array = new char[ilgis + 1];
    strcpy(temp_array, kint.c_str());
    for (int i = 0; i < ilgis; i++)
    {
        if (!isalpha(temp_array[i]))
            return false;
    }
    delete[] temp_array;
    return true;
}

void Mokinys ::Vidurkis(Vector<Mokinys> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        Mokinys &mok = A[i];
        double suma = 0;
        for (int pazymys : mok.ND)
        {
            suma += pazymys;
        }
        suma += mok.egzaminas;
        double vidurkis = suma / (mok.ND.size() + 1);
        mok.VID = vidurkis;
    }
}

bool Mokinys ::PagalVidurki(const Mokinys &a, const Mokinys &b)
{
    return a.VID < b.VID;
}

bool Mokinys ::PagalMediana(const Mokinys &a, const Mokinys &b)
{
    return a.MED < b.MED;
}

bool Mokinys ::PagalVarda(const Mokinys &a, const Mokinys &b)
{
    return a.vardas < b.vardas;
}

bool Mokinys ::PagalPavarde(const Mokinys &a, const Mokinys &b)
{
    return a.pavarde < b.pavarde;
}

double visasLaikas = 0.0;
void GeneruotiFailus(Vector<Mokinys> &Nuskriaustieji, Vector<Mokinys> &Mokslinciai, Vector<int> &IrasuSk, Vector<Mokinys> &A)
{
    srand(time(NULL));

    for (int i = 0; i < IrasuSk.size(); i++)
    {
        /* auto start = chrono::high_resolution_clock::now();
        auto st = start; */
        cout << "~FAILAS " + to_string(i) + "~" << endl;
        cout << "Generuojama..." << endl;
        string filename = "new_file" + to_string(i) + ".txt";
        ofstream fr(filename);

        if (!fr)
            throw runtime_error("Failas nurodytoje vietoje neegzistuoja!");

        int temp = rand() % 10 + 1;

        fr << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde";
        for (int i = 0; i < temp; i++)
            fr << setw(10) << left << "ND";
        fr << setw(10) << left << "Egz." << endl;

        for (int j = 0; j < IrasuSk[i]; j++)
        {
            fr << setw(20) << left << ("Vardas" + to_string(j)) << setw(20) << left << ("Pavarde" + to_string(j));
            for (int k = 0; k < temp; k++)
                fr << setw(10) << left << rand() % 10 + 1;
            fr << setw(10) << left << rand() % 10 + 1 << endl;
        }

        fr.close();
        /* chrono::duration<double> diff = chrono::high_resolution_clock::now() - start;
        cout << "Failo " + to_string(i) + " kurimo laikas: " << diff.count() << "s\n"; */

        /* visasLaikas += diff.count(); */

        // Skaitymas(Nuskriaustieji, Mokslinciai, IrasuSk, filename, A, i);
    }
}
void Mokinys ::Skaitymas(Vector<Mokinys> &Nuskriaustieji, Vector<Mokinys> &Mokslinciai, Vector<int> &IrasuSk, string failas, Vector<Mokinys> &A, int &temp, char strategija)
{
    visasLaikas = 0.0;
    string eil;
    ifstream fd(failas);
    if (!fd)
        throw runtime_error("Failas nurodytoje vietoje neegzistuoja!");
    getline(fd, eil);
    auto start = chrono::high_resolution_clock::now();
    auto st = start;
    while (getline(fd, eil))
    {
        istringstream iss(eil);
        Mokinys temp;
        iss >> temp.vardas >> temp.pavarde;
        int pazymiai;
        while (iss >> pazymiai)
            temp.ND.push_back(pazymiai);

        if (!temp.ND.empty())
        {
            temp.egzaminas = temp.ND.back();
            temp.ND.pop_back();
        }

        sort(temp.ND.begin(), temp.ND.end());
        double mediana;

        if (!temp.ND.empty())
        {
            mediana = temp.ND[temp.ND.size() / 2];
            if (temp.ND.size() % 2 == 0)
            {
                mediana = (temp.ND[temp.ND.size() / 2 - 1] + temp.ND[temp.ND.size() / 2]) / 2.0;
            }
        }
        temp.MED = mediana;
        A.push_back(temp);
    }
    fd.close();
    chrono::duration<double> diff = chrono::high_resolution_clock::now() - start;
    cout << "Nuskaitymo laikas: " << diff.count() << "s\n";
    visasLaikas += diff.count();

    Vidurkis(A);
    if (strategija == '1')
        StudentuRusiavimas(Nuskriaustieji, Mokslinciai, A, IrasuSk, failas, temp);
    else if (strategija == '2')
        StudentuRusiavimas2(Nuskriaustieji, Mokslinciai, A, IrasuSk, failas, temp);
    else if (strategija == '3')
        StudentuRusiavimas3(Nuskriaustieji, Mokslinciai, A, IrasuSk, failas, temp);

    cout << endl;
}
void Mokinys ::StudentuRusiavimas(Vector<Mokinys> &Nuskriaustieji, Vector<Mokinys> &Mokslinciai, Vector<Mokinys> &A, Vector<int> &IrasuSk, string failas, int &temp)
{
    string filename = "nuskriaustieji" + to_string(temp) + ".txt";
    string filename1 = "mokslinciai." + to_string(temp) + ".txt";
    int kint;

    auto start = chrono::high_resolution_clock::now();
    auto st = start;

    sort(A.begin(), A.end(), PagalVidurki);

    chrono::duration<double> diff = chrono::high_resolution_clock::now() - start;
    cout << "Studentu rusiavimas didejimo tvarka uztruko: " << diff.count() << "s\n";
    visasLaikas += diff.count();

    auto start1 = chrono::high_resolution_clock::now();
    auto st1 = start1;

    for (auto &mok : A)
    {
        if (mok.VID > 5.0)
            Nuskriaustieji.push_back(mok);
        else
            Mokslinciai.push_back(mok);
    }

    chrono::duration<double> diff1 = chrono::high_resolution_clock::now() - start1;
    cout << "Studentu skirstymas uztruko: " << diff1.count() << "s\n";
    visasLaikas += diff1.count();
    cout << "Visa programa " + to_string(temp) + " uztruko: " << visasLaikas << "s\n";

    /* sort(Mokslinciai.begin(), Mokslinciai.end(), PagalVidurki);
    sort(Nuskriaustieji.begin(), Nuskriaustieji.end(), PagalVidurki); */

    // cout << "~Mokslinciai~" << endl;
    Isvedimas2(Mokslinciai, Mokslinciai.size(), filename);
    // cout << "~Nuskriaustieji~" << endl;
    Isvedimas2(Nuskriaustieji, Nuskriaustieji.size(), filename1);
}
void Mokinys ::StudentuRusiavimas2(Vector<Mokinys> &Nuskriaustieji, Vector<Mokinys> &Mokslinciai, Vector<Mokinys> &A, Vector<int> &IrasuSk, string failas, int &temp)
{
    string filename = "nuskriaustieji" + to_string(temp) + ".txt";
    string filename1 = "mokslinciai." + to_string(temp) + ".txt";
    int kint;

    auto start = chrono::high_resolution_clock::now();
    auto st = start;

    sort(A.begin(), A.end(), PagalVidurki);

    chrono::duration<double> diff = chrono::high_resolution_clock::now() - start;
    cout << "Studentu rusiavimas didejimo tvarka uztruko: " << diff.count() << "s\n";
    visasLaikas += diff.count();

    auto start1 = chrono::high_resolution_clock::now();
    auto st1 = start1;

    for (int i = A.size() - 1; i >= 0; i--)
    {
        if (A[i].VID > 5.0)
        {
            Nuskriaustieji.push_back(A[i]);
            A.pop_back();
        }
    }

    chrono::duration<double> diff1 = chrono::high_resolution_clock::now() - start1;
    cout << "Studentu skirstymas uztruko: " << diff1.count() << "s\n";
    visasLaikas += diff1.count();
    cout << "Visa programa " + to_string(temp) + " uztruko: " << visasLaikas << "s\n";

    /* sort(Mokslinciai.begin(), Mokslinciai.end(), PagalVidurki);
    sort(Nuskriaustieji.begin(), Nuskriaustieji.end(), PagalVidurki); */

    // cout << "~Mokslinciai~" << endl;
    Isvedimas2(A, A.size(), filename);
    // cout << "~Nuskriaustieji~" << endl;
    Isvedimas2(Nuskriaustieji, Nuskriaustieji.size(), filename1);
}
void Mokinys::StudentuRusiavimas3(Vector<Mokinys> &Nuskriaustieji, Vector<Mokinys> &Mokslinciai, Vector<Mokinys> &A, Vector<int> &IrasuSk, string failas, int &temp)
{
    string filename = "nuskriaustieji" + to_string(temp) + ".txt";
    string filename1 = "mokslinciai." + to_string(temp) + ".txt";

    auto start = chrono::high_resolution_clock::now();

    sort(A.begin(), A.end(), PagalVidurki);

    chrono::duration<double> diff = chrono::high_resolution_clock::now() - start;
    cout << "Studentu rusiavimas didejimo tvarka uztruko: " << diff.count() << "s\n";
    visasLaikas += diff.count();

    auto partition_point = partition(A.begin(), A.end(), [](const Mokinys &m){
        return m.VID < 5.0;
    });

    auto start1 = chrono::high_resolution_clock::now();

    size_t index = partition_point - A.begin();
    move(partition_point, A.end(), back_inserter(Nuskriaustieji));
    A.erase(index);

    chrono::duration<double> diff1 = chrono::high_resolution_clock::now() - start1;
    cout << "Studentu skirstymas uztruko: " << diff1.count() << "s\n";
    visasLaikas += diff1.count();

    cout << "Visa programa " + to_string(temp) + " uztruko: " << visasLaikas << "s\n";

    Isvedimas2(A, A.size(), filename);
    Isvedimas2(Nuskriaustieji, Nuskriaustieji.size(), filename1);
}

void Mokinys ::Isvedimas(const Vector<Mokinys> &A, int MOK_kiekis, string isvedimas)
{
    char kint;
    cout << "Rezultatus matyti norite ekrane ar faile?(e/f): ";
    cin >> kint;
    if (kint == 'e')
    {
        auto start = chrono::high_resolution_clock::now();
        auto st = start;
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << right << "Galutinis (Vid.) / Galutinis(Med.)" << endl;
        cout << setfill('-') << setw(80) << " " << endl;
        cout << setfill(' ');

        for (int i = 0; i < MOK_kiekis; i++)
        {
            cout << setw(20) << left << A[i].vardas << setw(20) << left << A[i].pavarde << right << fixed << setprecision(2) << A[i].VID << setw(18) << right << A[i].MED;
            cout << endl;
        }
        chrono::duration<double> diff = chrono::high_resolution_clock::now() - start;
        cout << "Studentu isvedimas ekrane uztruko: " << diff.count() << "s\n";
    }
    else if (kint == 'f')
    {
        auto start = chrono::high_resolution_clock::now();
        auto st = start;
        ofstream fr(isvedimas);
        fr << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << right << "Galutinis (Vid.) / Galutinis(Med.)" << endl;
        fr << setfill('-') << setw(80) << " " << endl;
        fr << setfill(' ');

        for (int i = 0; i < MOK_kiekis; i++)
        {
            fr << setw(20) << left << A[i].vardas << setw(20) << left << A[i].pavarde << right << fixed << setprecision(2) << A[i].VID << setw(18) << right << A[i].MED;
            fr << endl;
        }
        fr.close();
        chrono::duration<double> diff = chrono::high_resolution_clock::now() - start;
        cout << "Studentu isvedimas i failus uztruko: " << diff.count() << "s\n";
    }
    else
        throw runtime_error("Netinkama ivestis!");
}
void Mokinys ::Isvedimas2(const Vector<Mokinys> &A, int MOK_kiekis, string isvedimas)
{
    /*     auto start = chrono::high_resolution_clock::now();
        auto st = start;
     */
    ofstream fr(isvedimas);
    fr << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << right << "Galutinis (Vid.) / Galutinis(Med.)" << endl;
    fr << setfill('-') << setw(80) << " " << endl;
    fr << setfill(' ');

    for (int i = 0; i < MOK_kiekis; i++)
    {
        fr << setw(20) << left << A[i].vardas << setw(20) << left << A[i].pavarde << right << fixed << setprecision(2) << A[i].VID << setw(18) << right << A[i].MED;
        fr << endl;
    }
    fr.close();
    /* chrono::duration<double> diff = chrono::high_resolution_clock::now() - start;
    cout << "Studentu isvedimas i failus uztruko: " << diff.count() << "s\n"; */
}
void Mokinys ::Rikiavimas(Vector<Mokinys> &Mokslinciai, Vector<Mokinys> &Nuskriaustieji, Vector<int> &IrasuSk)
{
    char kint;
    cout << "Pagal ka rikiuoti: varda, pavarde, vidurki, mediana?(v, p, V, m)" << endl;
    cin >> kint;
    if (kint == 'V')
    {
        sort(Mokslinciai.begin(), Mokslinciai.end(), PagalVidurki);
        sort(Nuskriaustieji.begin(), Nuskriaustieji.end(), PagalVidurki);
    }
    else if (kint == 'm')
    {
        sort(Mokslinciai.begin(), Mokslinciai.end(), PagalMediana);
        sort(Nuskriaustieji.begin(), Nuskriaustieji.end(), PagalMediana);
    }
    else if (kint == 'v')
    {
        sort(Mokslinciai.begin(), Mokslinciai.end(), PagalVarda);
        sort(Nuskriaustieji.begin(), Nuskriaustieji.end(), PagalVarda);
    }
    else if (kint == 'p')
    {
        sort(Mokslinciai.begin(), Mokslinciai.end(), PagalPavarde);
        sort(Nuskriaustieji.begin(), Nuskriaustieji.end(), PagalPavarde);
    }
    else
        throw runtime_error("Netinkama ivestis!");
}
void testConstructor()
{
    Vector<int> temp{1, 2, 3, 4};
    Mokinys mok("Vardenis", "Pavardenis", temp, 9, 8, 7);
    assert(mok.getVardas() == "Vardenis");
    assert(mok.getPavarde() == "Pavardenis");
    assert(mok.getND() == temp);
    assert(mok.getEgzaminas() == 9);
    assert(mok.getVID() == 8);
    assert(mok.getMED() == 7);
    cout << "Konstruktorius veikia!" << endl;
}

void testCopyConstructor()
{
    Vector<int> temp{1, 2, 3, 4};
    Mokinys mok("Vardenis", "Pavardenis", temp, 9, 8, 7);
    Mokinys mok1 = mok;
    assert(mok1.getVardas() == "Vardenis");
    assert(mok1.getPavarde() == "Pavardenis");
    assert(mok1.getND() == temp);
    assert(mok1.getEgzaminas() == 9);
    assert(mok1.getVID() == 8);
    assert(mok1.getMED() == 7);
    cout << "Copy konstruktorius veikia!" << endl;
}

void testMoveConstructor()
{
    Vector<int> temp{1, 2, 3, 4};
    Mokinys mok("Vardenis", "Pavardenis", temp, 9, 8, 7);
    Mokinys mok1 = move(mok);
    assert(mok1.getVardas() == "Vardenis");
    assert(mok1.getPavarde() == "Pavardenis");
    assert(mok1.getND() == temp);
    assert(mok1.getEgzaminas() == 9);
    assert(mok1.getVID() == 8);
    assert(mok1.getMED() == 7);
    cout << "Move konstruktorius veikia!" << endl;
}


void testMoveAssignment()
{
    Vector<int> temp{1, 2, 3, 4};
    Mokinys mok("Vardenis", "Pavardenis", temp, 9, 8, 7);
    Mokinys mok1;
    mok1 = move(mok);
    assert(mok1.getVardas() == "Vardenis");
    assert(mok1.getPavarde() == "Pavardenis");
    assert(mok1.getND() == temp);
    assert(mok1.getEgzaminas() == 9);
    assert(mok1.getVID() == 8);
    assert(mok1.getMED() == 7);
    cout << "Move assignment veikia!" << endl;
}

void testCopyAssignment()
{
    Vector<int> temp{1, 2, 3, 4};
    Mokinys mok("Vardenis", "Pavardenis", temp, 9, 8, 7);
    Mokinys mok1;
    mok1 = mok;
    assert(mok1.getVardas() == "Vardenis");
    assert(mok1.getPavarde() == "Pavardenis");
    assert(mok1.getND() == temp);
    assert(mok1.getEgzaminas() == 9);
    assert(mok1.getVID() == 8);
    assert(mok1.getMED() == 7);
    cout << "Copy assignment veikia" << endl;
}