#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H
#include "mokinys.h"

bool Patikrinimas(string kint);
void GeneruotiFailus(Vector<Mokinys>& Nuskriaustieji, Vector<Mokinys>& Mokslinciai, Vector<int>& IrasuSk, Vector<Mokinys>& A);
void testConstructor();
void testCopyConstructor();
void testMoveConstructor();
void testCopyAssignment();
void testMoveAssignment();
void Palyginimas();

#endif
