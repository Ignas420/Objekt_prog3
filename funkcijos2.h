#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "mokinys2.h"

bool Patikrinimas(string kint);
void GeneruotiFailus(deque<Mokinys>& Nuskriaustieji, deque<Mokinys>& Mokslinciai, deque<int>& IrasuSk, deque<Mokinys>& A);
void testConstructor();
void testCopyConstructor();
void testMoveConstructor();
void testCopyAssignment();
void testMoveAssignment();

#endif
