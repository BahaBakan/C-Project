/** 
* 
* @author Muhammed Baha Bakan baha.bakan@ogr.sakarya.edu.tr
* @since 11.05.2024 
* <p> 
*  Bitki sınıfım. 
* </p> 
*/ 


#include "../include/Bitki.h"
#include "stdlib.h"

Bitki bitkiOlustur(int canliNo)
{
    Bitki bitki = (Bitki)malloc(sizeof(struct BITKI));

    bitki->canli = canliOlustur(canliNo);
    bitki->canli->canliAd = "Bitki";
    bitki->canli->canliKarakter = 'B';
    bitki->Sil = &bitkiSil;

    return bitki;
}

void bitkiSil(Bitki bitki)
{
    bitki->canli->canliSil(bitki->canli);
    free(bitki);
}