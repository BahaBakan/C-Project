/** 
* 
* @author Muhammed Baha Bakan baha.bakan@ogr.sakarya.edu.tr
* @since 11.05.2024 
* <p> 
*  Test sınıfım. 
* </p> 
*/ 

#include "stdio.h"
#include "stdlib.h"

#include "../include/Habitat.h"
#include "../include/Canli.h"
#include "../include/Bocek.h"
#include "../include/Sinek.h"
#include "../include/Bitki.h"
#include "../include/Pire.h"

void txtVeriAl(int *, int *, int *, int *, int *, int *, char *);
void txtVeriDoldur(Habitat, char *);

int main(int argc, char** argv)
{
	Habitat habitat;

    int satirSay = 0, enUzunSutun = 0, bitkiSay = 0, bocekSay = 0, pireSay = 0, sinekSay = 0;
    txtVeriAl(&satirSay, &enUzunSutun, &bitkiSay, &bocekSay, &pireSay, &sinekSay, "Veri.txt");

    habitat = habitatOlustur(satirSay, enUzunSutun, bitkiSay, bocekSay, pireSay, sinekSay);

    txtVeriDoldur(habitat, "Veri.txt");
    habitat->habitatYazdir();
    printf("\n");
    system("pause");
    baslat(habitat, habitat->canlilarDizi);

    bitir(habitat, habitat->canlilarDizi);
    printf("\n\n");
    system("pause");

    habitat->habitatSil(habitat);

    return 0;
}

void txtVeriAl(int *satir_s, int *sutun_s, int *bitki_s, int *bocek_s, int *pire_s, int *sinek_s, char *txtAdi)
{
    FILE *dosya = fopen(txtAdi, "r");

    char karakter;
    char sayi[3];
    int sayi_i;
    int index = 0;
    int tempSutun = 0;

    while ((karakter = fgetc(dosya)) != EOF)
    {
        if (karakter == ' ')
        {
            sayi[index] = '\0';
            index = 0;
            (*sutun_s)++;
            sayi_i = atoi(sayi);
            if (sayi_i >= 1 && sayi_i <= 9)
                (*bitki_s)++;
            else if (sayi_i >= 10 && sayi_i <= 20)
                (*bocek_s)++;
            else if (sayi_i >= 21 && sayi_i <= 50)
                (*sinek_s)++;
            else if (sayi_i >= 51 && sayi_i <= 99)
                (*pire_s)++;
        }
        else if (karakter == '\n')
        {
            sayi[index] = '\0';
            index = 0;
            (*satir_s)++;
            (*sutun_s)++;
            if (*sutun_s > tempSutun)
            {
                tempSutun = *sutun_s;
            }
            (*sutun_s) = 0;
            sayi_i = atoi(sayi);
            if (sayi_i >= 1 && sayi_i <= 9)
                (*bitki_s)++;
            else if (sayi_i >= 10 && sayi_i <= 20)
                (*bocek_s)++;
            else if (sayi_i >= 21 && sayi_i <= 50)
                (*sinek_s)++;
            else if (sayi_i >= 51 && sayi_i <= 99)
                (*pire_s)++;
        }
        else
        {
            sayi[index] = karakter;
            index++;
        }
    }
    (*sutun_s)++;
    if (*sutun_s > tempSutun)
    {
        tempSutun = *sutun_s;
    }
    *sutun_s = tempSutun;

    sayi[index] = '\0';
    index = 0;
    sayi_i = atoi(sayi);
    if (sayi_i >= 1 && sayi_i <= 9)
        (*bitki_s)++;
    else if (sayi_i >= 10 && sayi_i <= 20)
        (*bocek_s)++;
    else if (sayi_i >= 21 && sayi_i <= 50)
        (*sinek_s)++;
    else if (sayi_i >= 51 && sayi_i <= 99)
        (*pire_s)++;

    (*satir_s)++;

    //printf("%d %d %d %d %d %d\n\n", *satir_s, *sutun_s, *bitki_s, *bocek_s, *pire_s, *sinek_s);

    fclose(dosya);
}

void txtVeriDoldur(Habitat habitat, char *txtAdi)
{
    FILE *dosya = fopen(txtAdi, "r");

    char karakter;
    char sayi[3];
    int sayi_i;
    int index = 0;
    int satirUzunlugu = 0;

    while ((karakter = fgetc(dosya)) != EOF)
    {
        if (karakter == ' ')
        {
            sayi[index] = '\0';
            index = 0;
            sayi_i = atoi(sayi);

            habitat->canliEkle(habitat, sayi_i);
            satirUzunlugu++;
        }
        else if (karakter == '\n')
        {
            sayi[index] = '\0';
            index = 0;

            sayi_i = atoi(sayi);

            habitat->canliEkle(habitat, sayi_i);
            satirUzunlugu++;
            if (satirUzunlugu < habitat->sutunSayisi)
            {
                int fark = habitat->sutunSayisi - satirUzunlugu;
                for (int i = 0; i < fark; i++)
                {
                    habitat->canliEkle(habitat, 0);
                }
                satirUzunlugu = 0;
            }
            satirUzunlugu = 0;
        }
        else
        {
            sayi[index] = karakter;
            index++;
        }
    }

    sayi[index] = '\0';
    index = 0;
    sayi_i = atoi(sayi);
    habitat->canliEkle(habitat, sayi_i);
    satirUzunlugu++;
    if (satirUzunlugu < habitat->sutunSayisi)
    {
        int fark = habitat->sutunSayisi - satirUzunlugu;
        for (int i = 0; i < fark; i++)
        {
            habitat->canliEkle(habitat, 0);
        }
        satirUzunlugu = 0;
    }

    fclose(dosya);
}