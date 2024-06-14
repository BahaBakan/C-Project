/** 
* 
* @author Muhammed Baha Bakan baha.bakan@ogr.sakarya.edu.tr
* @since 11.05.2024 
* <p> 
*  Sinek sınıfım. 
* </p> 
*/ 



#include "../include/Sinek.h"
#include "stdlib.h"

Sinek sinekOlustur(int canliNo)
{
    Sinek sinek = (Sinek)malloc(sizeof(struct SINEK));

    sinek->bocek = bocekOlustur(canliNo);
    sinek->bocek->canli->canliAd = "Sinek";
    sinek->bocek->canli->canliKarakter = 'S';
    sinek->Sil = &sinekSil;

    return sinek;
}

void sinekSil(Sinek sinek)
{
    sinek->bocek->Sil(sinek->bocek);
    free(sinek);
}