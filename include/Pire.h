#ifndef _PIRE_H_
#define _PIRE_H_

#include "../include/Bocek.h"

struct PIRE
{
    Bocek bocek;

    void (*Sil)();
};

typedef struct PIRE *Pire;

Pire pireOlustur(int canliNo);
void pireSil(Pire pire);

#endif