#ifndef _HABITAT_H_
#define _HABITAT_H_

#include "../include/Bocek.h"
#include "../include/Bitki.h"
#include "../include/Pire.h"
#include "../include/Sinek.h"

struct canliDizi
{
    int canliTur;
    void *canliStructAdres;
};

struct HABITAT
{
    struct canliDizi **canlilarDizi;
    int satirSayisi;
    int sutunSayisi;

    int eklenenBitkiSayisi;
    int eklenenBocekSayisi;
    int eklenenPireSayisi;
    int eklenenSinekSayisi;
    int eklenenCanliSayisi;

    Bitki *bitkiler;
    Bocek *bocekler;
    Pire *pireler;
    Sinek *sinekler;

    int bitkiSayisi;
    int bocekSayisi;
    int pireSayisi;
    int sinekSayisi;

    void (*canliEkle)();
    void (*habitatYazdir)();
    void (*habitatSil)();
};

typedef struct HABITAT *Habitat;

Habitat habitatOlustur(int satirSay, int sutunSay, int bitkiSay, int bocekSay, int pireSay, int sinekSay);
void habitatSil(Habitat habitat);
void canliEkle(Habitat habitat, int canliNo);
void habitatYazdir(Habitat habitat);
char canliKarakter(struct canliDizi canliStruct);
int *canliDeger(struct canliDizi canliStruct);
void baslat(Habitat habitat, struct canliDizi **canliStruct);
void bitir(Habitat habitat, struct canliDizi **canliStruct);
char hangiCanli(int canli);

#endif