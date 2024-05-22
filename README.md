**v2.0**

Makefile set-up:
**Makefile idiegimas naudojant Chocolatey (Windows)**

Isitikinkite, kad turite Chocolatey idiegima: patikrinkite, ar jusu kompiuteryje yra idiegta Chocolatey. Jei ne, idiekite pagal instrukcijas https://chocolatey.org/install.

Idiekite Makefile: atidarykite PowerShell kaip administratorius ir ivykdykite sia komanda:

choco install make

Patikrinkite idiegima: patikrinkite, ar Makefile sekmingai idiegtas, vykdydami komanda:

make --version

Jei viskas sekminga, turetumete pamatyti Make versijos informacija

Makefile idiegimas naudojant kitus metodus
**MacOS:** Makefile iprastai yra idiegtas standartinėje MacOS distribucijoje, todel papildomu veiksmu paprastai nereikia

**Linux:** Daugumoje Linux distribuciju Makefile taip pat yra idiegtas is anksto. Jei reikia, naudokite savo paketu tvarkykle, pvz., apt-get, yum, dnf, arba kita pagal distribucija

**Windows (be Chocolatey):** Noredami idiegti Makefile Windows sistemoje be Chocolatey, galite naudoti rankinius idiegimo failus, kuriuos galite rasti internete. Paprastai tie failai turi .exe pletini ir gali buti lengvai idiegti, sekdamie pridedamas instrukcijas

Norint pradeti, i terminala reikia ivesti "make", kai viskas bus sukompiliuota, galima testi su programa, jei norima, galima rasyti "make clean" norint istrinti .o ir .exe failus

**Programos naudojimas veikimo metu:**

Vartotojas pasirenka, su kokiu konteineriu norima vygdyti programa ir pasirinktinai i terminala parasoma: ./vektoriai , ./list arba ./deque

Vos paleidus programa atsiras pasirinkimas ar pratestuoti musu turimus klases metodus , jei paspaudziame 't', tada pasirenkame numeri nuo 1-5 ir gauname testo rezultata

Toliau musu bus klausiama, ar norime ivesti duomenis ar skaityti is failo

1. Jei bus pasirenkamas duomenu ivedimas, bus reikalaujama pasirinkti ar norima ivesti/generuoti duomenis
   
1.1 Ar vienu, ar kitu budu reikes ivesti studentu vardus ir pavardes, toliau reikes ivesti studentu namu darbu ir egzamino pazymius

1.2 Jei bus pasirinktas duomenu generavimas, po vardu ir pavardziu irasymo nieko daryti nebereikes

1.3 Galiausiai reikes pasirinkti kur norime matyti duomenis ekrane ar faile

2. Jei pacioje pradzioje bus pasirinktas skaitymas, jusu bus klausiama ar norite generuoti naujus failus, jei ivesite 't'(taip), bus generuojami nauji failai, jei ivesite bet koki kita simboli, programa veiks toliau

2.1 Toliau, jusu bus klausiama ar norite skaityti naujai sukurtus failus, ar jau turimus

2.2 Bus prasoma ivesti, pasirinktinai, turimu/nauju failu kieki, jie bus nuskaitomi, isvedami apytiksliai testavimu laikai ekrane bei sukuriami nauji failai, kuriuose yra surusiuoti studentai pagal vidurki (nuskriaustieji/mokslinciai)

2.3 Galiausiai, kaip ir anksciau, bus isvedami apytiksliai testavimu laikai ekrane bei sukuriami nauji failai, kuriuose yra surusiuoti studentai pagal vidurki (nuskriaustieji/mokslinciai)

**RELEASAI**

**0.1**

Sukurta nauja repozitorija, realizuotos elementarios funkcijos, kaip vidurkio ir medianos skaiciavimas. Rezultate gavome, kad vektorius naudoti yra zymiai efektyviau atminties atzvilgiu.

**0.2**

Programa padaryta prieinamesne vartotojui, galima ne tik irasyti, bet ir skaityti is failo. Testuojama su 10000, 100000 ir 1000000 dydzio failais.

**0.3**

Prideti header failai, try/catch blokai. Rezultate programa tapo labiau strukturizuota bei klaidu gaudymas uzdrausdavo programos luzima.

**0.4**

Programa pagal vartotojo pasirinkima sukuria naujus failus, isskirsto mokinius i vargsiukus ir mokslincius, isveda i failus. Padaryti tikslus laiko matavimai.

**1.0**

Programa padaryta veikti su atskiro tipo konteineriais: deque, list ir vector. Kiekvienas pagal tris strategijas. Pagal matavimo rezultatus greiciausiai buvo vykdoma vector programa naudojant 3 strategija.

**1.1**

Atliktas repozitorijos kopijavimas. Programoje is strukturu pereinama i klases. Rezultate, programa veikia nasiau naudojant klases.

**1.2**

Igyvendinti visi "Rule of Five" ir isviesties bei ivesties operatoriai savai klasei.

**1.5**

Sukurta dar viena **bazine**, abstrakcioji klase, kuriai priklauso klase derived. Prideti konstruktoriaus, copy konstruktoriaus... testavimai.

**2.0**

Per Doxygen HTML formatu sukurta dokumentacija bei padaryti Unit testai naudojant patogu C++ framework'a supratimui.

**3.0**

Sukurta template Vector klase, kuri is esmes atlieka tas pacias funkcijas kaip ir std::vector, istestuota su funkcijomis programoje bei catch2 unit testais (./test), paruostas diegimo failas

**5 Naudojami metodai:**

**pop_back**

![image](https://github.com/Ignas420/Objekt_prog3/assets/145566919/53ec21ab-59a5-4934-8dbb-938b8cad7da8)

"pop_back" metodas salina paskutini vektoriaus elementa. Tai daroma sumazinant _size (vektoriaus dydi) vienetu, jei vektorius neturi jokiu elementu, nieko nedaroma.

**reserve**

![image](https://github.com/Ignas420/Objekt_prog3/assets/145566919/e6a47b50-b1bf-479a-82ed-51b008045ada)

"reserve" metodas skirtas rezervuoti vieta vektoriuje, kad jame galetu buti saugomi tam tikro dydzio elementai, be naujos atminties isskirimo. Tai padidina vektoriaus talpa (capacity) iki nurodyto dydzio, jei jis mazesnis nei nurodytas dydis.

**back**

![image](https://github.com/Ignas420/Objekt_prog3/assets/145566919/b419907a-2224-4e1c-86ae-d83c0580e3c7)

"back" metodas grazina nuoroda i paskutini vektoriaus elementa. Tai leidzia gauti prieiga prie paskutinio elemento, saugomo vektoriaus viduje, bet nedaro jokiu pakeitimu pries ta elementa.

**front**

![image](https://github.com/Ignas420/Objekt_prog3/assets/145566919/7e87c30b-aa13-4d49-a431-73694209edad)

"front" metodas grazina nuoroda i pirmaji vektoriaus elementa. Tai leidzia gauti prieiga prie pirmo elemento, saugomo vektoriaus viduje, bet nedaro jokiu pakeitimu priesais si elementa.

**erase**

![image](https://github.com/Ignas420/Objekt_prog3/assets/145566919/9574a191-a903-49a7-bdef-1cbfe618501c)

"erase" metodas istrina elementa is vektoriaus pagal nurodyta indeksa. Kai elementas yra istrinamas, visi vektoriaus elementai, kurie yra i desine nuo istrintojo, yra perkelti i kaire, kad uzimtu istrinto elemento vieta. Po sio veiksmo vektoriaus dydis sumazinamas vienetu.

**Spartos analize su 10000, 100000, 1000000, 10000000 ir 100000000 int elementu ir atminties perskirstymai:**

![image](https://github.com/Ignas420/Objekt_prog3/assets/145566919/32940120-1de0-4de6-b9ae-07d2c95f8c2c)

**Spartos analize su 100 000, 1 000 000 ir 10 000 000 studentu irasu:**

| Konteinerio Tipas | Skaitymo Laikas (s) | Rusiavimo Laikas (s) | Skirstymo Laikas (s) | Visas Laikas (s) |
|----------------|------------------|------------------|------------------------|----------------|
| Vector su 100 000         | 0.0884473        | 0.017344         | 0.0116114              | 0.117403       |
| Vector su 1 000 000       | 1.52174          | 0.247492         | 0.156395               | 1.92562        |
| Vector  su 10 000 000       | 7.74136          | 3.02246          | 1.19803                | 11.9618        |
| Average (Vector) | 3.117515       | 1.095432         | 0.455678               | 4.66894        |
| std::vector su 100 000    | 0.072177         | 0.0153995        | 0.00548                | 0.0930565      |
| std::vector su 1 000 000   | 1.22695          | 0.210847         | 0.0592042              | 1.497          |
| std::vector su 10 000 000    | 6.17829          | 2.52657          | 0.465224               | 9.17009        |
| Average (std::vector) | 2.492472       | 0.9172721667    | 0.1766368667          | 3.195382833    |







