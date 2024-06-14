/** 
* 
* @author Muhammed Baha Bakan baha.bakan@ogr.sakarya.edu.tr
* @since 11.05.2024 
* <p> 
*  pire sınıfım. 
* </p> 
*/ 


#include "../include/Pire.h"
#include "stdlib.h"

Pire pireOlustur(int canliNo)
{
    Pire pire = (Pire)malloc(sizeof(struct PIRE));

    pire->bocek = bocekOlustur(canliNo);
    if (canliNo == 0)
    {
        pire->bocek->canli->canliAd = "Bos";
        pire->bocek->canli->canliKarakter = 'X';
    }
    else
    {
        pire->bocek->canli->canliAd = "Pire";
        pire->bocek->canli->canliKarakter = 'P';
    }
    pire->Sil = &pireSil;

    return pire;
}

void pireSil(Pire pire)
{
    pire->bocek->Sil(pire->bocek);
    free(pire);
}