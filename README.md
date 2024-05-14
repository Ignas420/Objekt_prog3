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

**Kaip atrodo Doxygen dokumentacija:**

![image](https://github.com/Ignas420/Objekt_prog2/assets/145566919/dd0c14b6-ce8f-4a98-96fc-e10f8e265b1e)

**Unit testai:**

![image](https://github.com/Ignas420/Objekt_prog2/assets/145566919/3afb91e4-078b-4c5b-8399-01093ad1a483)

![image](https://github.com/Ignas420/Objekt_prog2/assets/145566919/9dac1d72-0d8e-42e6-bffe-f9bd5660e572)




