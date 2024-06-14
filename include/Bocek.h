#ifndef _BOCEK_H_
#define _BOCEK_H_

#include "../include/Canli.h"

struct BOCEK
{
    Canli canli;

    void (*Sil)();
};

typedef struct BOCEK *Bocek;

Bocek bocekOlustur(int canliNo);
void bocekSil(Bocek bocek);

#endif