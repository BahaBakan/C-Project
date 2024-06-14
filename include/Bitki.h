#ifndef _BITKI_H_
#define _BITKI_H_

#include "../include/Canli.h"

struct BITKI
{
    Canli canli;

    void (*Sil)();
};

typedef struct BITKI *Bitki;

Bitki bitkiOlustur(int canliNo);
void bitkiSil(Bitki bitki);

#endif