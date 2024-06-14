/** 
* 
* @author Muhammed Baha Bakan baha.bakan@ogr.sakarya.edu.tr
* @since 11.05.2024 
* <p> 
*  Canlı sınıfım. 
* </p> 
*/ 


#include "../include/Canli.h"
#include "stdio.h"
#include "stdlib.h"

Canli canliOlustur(int canliNo)
{
    Canli canli = (Canli)malloc(sizeof(struct CANLI));
    canli->gorunumStr = malloc(100);

    canli->canliNumara = canliNo;
    canli->canliSil = &canliSil;
    canli->gorunum = &gorunum;

    return canli;
}

void canliSil(Canli canli)
{
    free(canli->gorunumStr);
    free(canli);
}

char *gorunum(Canli canli)
{
    sprintf(canli->gorunumStr, "Canli Numarasi: %d\nCanli Adi: %s\nCanli Karakter: %c\n-----------\n", canli->canliNumara, canli->canliAd, canli->canliKarakter);

    return canli->gorunumStr;
}