/** 
* 
* @author Muhammed Baha Bakan baha.bakan@ogr.sakarya.edu.tr
* @since 11.05.2024 
* <p> 
*  bocek sınıfım. 
* </p> 
*/ 




#include "../include/Bocek.h"
#include "stdlib.h"

Bocek bocekOlustur(int canliNo)
{
    Bocek bocek = (Bocek)malloc(sizeof(struct BOCEK));

    bocek->canli = canliOlustur(canliNo);
    bocek->canli->canliAd = "Bocek";
    bocek->canli->canliKarakter = 'C';
    bocek->Sil = &bocekSil;

    return bocek;
}

void bocekSil(Bocek bocek)
{
    bocek->canli->canliSil(bocek->canli);
    free(bocek);
}