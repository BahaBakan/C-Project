/** 
* 
* @author Muhammed Baha Bakan baha.bakan@ogr.sakarya.edu.tr
* @since 11.05.2024 
* <p> 
*  Habitat sınıfım. Ekleme yapma,birbirleri ile karşılaştırıp yeme durumlarının yapıldığı sınıf
* </p> 
*/ 



#include "../include/Habitat.h"
#include "stdio.h"
#include "stdlib.h"
#include "Windows.h"


Habitat habitatOlustur(int satirSay, int sutunSay, int bitkiSay, int bocekSay, int pireSay, int sinekSay)
{
    Habitat habitat = (Habitat)malloc(sizeof(struct HABITAT));
    int bos = 0;

    habitat->satirSayisi = satirSay;
    habitat->sutunSayisi = sutunSay;
    habitat->bitkiSayisi = bitkiSay;
    habitat->bocekSayisi = bocekSay;
    habitat->pireSayisi = pireSay;
    habitat->sinekSayisi = sinekSay;

    habitat->eklenenBitkiSayisi = 0;
    habitat->eklenenBocekSayisi = 0;
    habitat->eklenenPireSayisi = 0;
    habitat->eklenenSinekSayisi = 0;
    habitat->eklenenCanliSayisi = 0;

    bos = (habitat->satirSayisi * habitat->sutunSayisi) - (habitat->bitkiSayisi + habitat->bocekSayisi + habitat->pireSayisi + habitat->sinekSayisi);

    habitat->canliEkle = &canliEkle;
    habitat->habitatSil = &habitatSil;
    habitat->habitatYazdir = &habitatYazdir;

    habitat->canlilarDizi = (struct canliDizi **)malloc(habitat->satirSayisi * sizeof(struct canliDizi *));
    for (int i = 0; i < habitat->satirSayisi; i++)
    {
        habitat->canlilarDizi[i] = (struct canliDizi *)malloc(habitat->sutunSayisi * sizeof(struct canliDizi));
    }

    habitat->bitkiler = (Bitki *)malloc(habitat->bitkiSayisi * sizeof(struct BITKI));
    habitat->bocekler = (Bocek *)malloc(habitat->bocekSayisi * sizeof(struct BOCEK));
    habitat->pireler = (Pire *)malloc((habitat->pireSayisi + bos) * sizeof(struct PIRE));
    habitat->sinekler = (Sinek *)malloc(habitat->sinekSayisi * sizeof(struct SINEK));

    return habitat;
}

void canliEkle(Habitat habitat, int canliNo)
{
    int x = (int)(habitat->eklenenCanliSayisi / habitat->sutunSayisi);
    int y = habitat->eklenenCanliSayisi % habitat->sutunSayisi;
    if (canliNo >= 1 && canliNo <= 9)
    {
        habitat->bitkiler[habitat->eklenenBitkiSayisi] = bitkiOlustur(canliNo);
        habitat->canlilarDizi[x][y].canliTur = 1;
        habitat->canlilarDizi[x][y].canliStructAdres = habitat->bitkiler[habitat->eklenenBitkiSayisi];
        habitat->eklenenBitkiSayisi++;
        habitat->eklenenCanliSayisi++;
    }
    else if (canliNo >= 10 && canliNo <= 20)
    {
        habitat->bocekler[habitat->eklenenBocekSayisi] = bocekOlustur(canliNo);
        habitat->canlilarDizi[x][y].canliTur = 2;
        habitat->canlilarDizi[x][y].canliStructAdres = habitat->bocekler[habitat->eklenenBocekSayisi];
        habitat->eklenenBocekSayisi++;
        habitat->eklenenCanliSayisi++;
    }
    else if (canliNo >= 21 && canliNo <= 50)
    {
        habitat->sinekler[habitat->eklenenSinekSayisi] = sinekOlustur(canliNo);
        habitat->canlilarDizi[x][y].canliTur = 3;
        habitat->canlilarDizi[x][y].canliStructAdres = habitat->sinekler[habitat->eklenenSinekSayisi];
        habitat->eklenenSinekSayisi++;
        habitat->eklenenCanliSayisi++;
    }
    else if (canliNo >= 51 && canliNo <= 99)
    {
        habitat->pireler[habitat->eklenenPireSayisi] = pireOlustur(canliNo);
        habitat->canlilarDizi[x][y].canliTur = 4;
        habitat->canlilarDizi[x][y].canliStructAdres = habitat->pireler[habitat->eklenenPireSayisi];
        habitat->eklenenPireSayisi++;
        habitat->eklenenCanliSayisi++;
    }
    else if (canliNo == 0)
    {
        habitat->pireler[habitat->eklenenPireSayisi] = pireOlustur(canliNo);
        habitat->canlilarDizi[x][y].canliTur = 0;
        habitat->canlilarDizi[x][y].canliStructAdres = habitat->pireler[habitat->eklenenPireSayisi];
        habitat->eklenenPireSayisi++;
        habitat->eklenenCanliSayisi++;
    }
}

char canliKarakter(struct canliDizi canliStruct)
{
    if (canliStruct.canliTur == 1)
        return 'B';
    else if (canliStruct.canliTur == 2)
        return 'C';
    else if (canliStruct.canliTur == 3)
        return 'S';
    else if (canliStruct.canliTur == 4)
        return 'P';
    else if (canliStruct.canliTur == 0)
        return 'X';
}

int *canliDeger(struct canliDizi canliStruct)
{
    if (canliStruct.canliTur == 1)
    {
        Bitki temp = canliStruct.canliStructAdres;
        return &temp->canli->canliNumara;
    }
    else if (canliStruct.canliTur == 2)
    {
        Bocek temp = canliStruct.canliStructAdres;
        return &temp->canli->canliNumara;
    }
    else if (canliStruct.canliTur == 3)
    {
        Pire temp = canliStruct.canliStructAdres;
        return &temp->bocek->canli->canliNumara;
    }
    else if (canliStruct.canliTur == 4)
    {
        Sinek temp = canliStruct.canliStructAdres;
        return &temp->bocek->canli->canliNumara;
    }
    else if (canliStruct.canliTur == 0)
    {
        Pire temp = canliStruct.canliStructAdres;
        return &temp->bocek->canli->canliNumara;
    }
}

char hangiCanli(int canli)
{
    if (canli >= 1 && canli <= 9)
        return 'B';
    else if (canli >= 10 && canli <= 20)
        return 'C';
    else if (canli >= 21 && canli <= 50)
        return 'S';
    else if (canli >= 51 && canli <= 99)
        return 'P';
    else if (canli == 0)
        return 'X';
}

void baslat(Habitat habitat, struct canliDizi **canliStruct)
{
    int *suankiDeger = canliDeger(canliStruct[0][0]);
    int *sonrakiDeger;

    for (int i = 0; i < habitat->satirSayisi; i++)
    {
        for (int j = 0; j < habitat->sutunSayisi; j++)
        {
            if ((j + 1) > habitat->sutunSayisi - 1)
            {
                if ((i + 1) > habitat->satirSayisi - 1)
                    break;

                sonrakiDeger = canliDeger(canliStruct[i + 1][0]);
            }
            else
                sonrakiDeger = canliDeger(canliStruct[i][j + 1]);

            if (hangiCanli(*suankiDeger) == hangiCanli(*sonrakiDeger))
            {
                if (*suankiDeger >= *sonrakiDeger)
                    *sonrakiDeger = 0;
                else if (*sonrakiDeger > *suankiDeger)
                {
                    *suankiDeger = 0;
                    suankiDeger = sonrakiDeger;
                }
            }
            else if ((hangiCanli(*suankiDeger) == 'B' && (hangiCanli(*sonrakiDeger) == 'X' || hangiCanli(*sonrakiDeger) == 'P' || hangiCanli(*sonrakiDeger) == 'S')) ||
                     (hangiCanli(*suankiDeger) == 'C' && (hangiCanli(*sonrakiDeger) == 'X' || hangiCanli(*sonrakiDeger) == 'P' || hangiCanli(*sonrakiDeger) == 'B')) ||
                     (hangiCanli(*suankiDeger) == 'S' && (hangiCanli(*sonrakiDeger) == 'X' || hangiCanli(*sonrakiDeger) == 'P' || hangiCanli(*sonrakiDeger) == 'C')))
            {
                *sonrakiDeger = 0;
            }
            else if ((hangiCanli(*sonrakiDeger) == 'B' && (hangiCanli(*suankiDeger) == 'X' || hangiCanli(*suankiDeger) == 'P' || hangiCanli(*suankiDeger) == 'S')) ||
                     (hangiCanli(*sonrakiDeger) == 'C' && (hangiCanli(*suankiDeger) == 'X' || hangiCanli(*suankiDeger) == 'P' || hangiCanli(*suankiDeger) == 'B')) ||
                     (hangiCanli(*sonrakiDeger) == 'S' && (hangiCanli(*suankiDeger) == 'X' || hangiCanli(*suankiDeger) == 'P' || hangiCanli(*suankiDeger) == 'C')))
            {
                *suankiDeger = 0;
                suankiDeger = sonrakiDeger;
            }

            habitat->habitatYazdir(habitat);
            
            system("cls");
        }
    }
}

void bitir(Habitat habitat, struct canliDizi **canliStruct)
{
    for (int i = 0; i < habitat->satirSayisi; i++)
    {
        for (int j = 0; j < habitat->sutunSayisi; j++)
        {
            if (*canliDeger(canliStruct[i][j]) != 0)
            {
                habitat->habitatYazdir(habitat);
                printf("\nKazanan: %c : (%d,%d)", hangiCanli(*canliDeger(canliStruct[i][j])), i, j);
            }
        }
    }
}

void habitatYazdir(Habitat habitat)
{
    for (int i = 0; i < habitat->satirSayisi; i++)
    {
        for (int j = 0; j < habitat->sutunSayisi; j++)
        {

            if (habitat->canlilarDizi[i][j].canliTur == 1)
            {
                Bitki temp = habitat->canlilarDizi[i][j].canliStructAdres;
                if (temp->canli->canliNumara == 0)
                    temp->canli->canliKarakter = 'X';
                printf("%c ", temp->canli->canliKarakter);
            }
            else if (habitat->canlilarDizi[i][j].canliTur == 2)
            {
                Bocek temp = habitat->canlilarDizi[i][j].canliStructAdres;
                if (temp->canli->canliNumara == 0)
                    temp->canli->canliKarakter = 'X';
                printf("%c ", temp->canli->canliKarakter);
            }
            else if (habitat->canlilarDizi[i][j].canliTur == 3)
            {
                Pire temp = habitat->canlilarDizi[i][j].canliStructAdres;
                if (temp->bocek->canli->canliNumara == 0)
                    temp->bocek->canli->canliKarakter = 'X';
                printf("%c ", temp->bocek->canli->canliKarakter);
            }
            else if (habitat->canlilarDizi[i][j].canliTur == 4)
            {
                Pire temp = habitat->canlilarDizi[i][j].canliStructAdres;
                if (temp->bocek->canli->canliNumara == 0)
                    temp->bocek->canli->canliKarakter = 'X';
                printf("%c ", temp->bocek->canli->canliKarakter);
            }
            else if (habitat->canlilarDizi[i][j].canliTur == 0)
            {
                printf("X ");
            }
        }
        printf("\n");
    }
}

void habitatSil(Habitat habitat)
{
    for (int i = 0; i < habitat->bitkiSayisi; i++)
    {
        habitat->bitkiler[i]->Sil(habitat->bitkiler[i]);
    }
    for (int i = 0; i < habitat->bocekSayisi; i++)
    {
        habitat->bocekler[i]->Sil(habitat->bocekler[i]);
    }
    for (int i = 0; i < habitat->sinekSayisi; i++)
    {
        habitat->sinekler[i]->Sil(habitat->sinekler[i]);
    }
    for (int i = 0; i < habitat->pireSayisi; i++)
    {
        habitat->pireler[i]->Sil(habitat->pireler[i]);
    }

    for (int i = 0; i < habitat->satirSayisi; i++)
    {
        free(habitat->canlilarDizi[i]);
    }
    free(habitat->canlilarDizi);
    free(habitat->bitkiler);
    free(habitat->bocekler);
    free(habitat->sinekler);
    free(habitat->pireler);

    free(habitat);
}