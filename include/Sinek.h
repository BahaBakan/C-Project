#ifndef _SINEK_H_
#define _SINEK_H_

#include "../include/Bocek.h"

struct SINEK
{
    Bocek bocek;

    void (*Sil)();
};

typedef struct SINEK *Sinek;

Sinek sinekOlustur(int canliNo);
void sinekSil(Sinek sinek);

#endif