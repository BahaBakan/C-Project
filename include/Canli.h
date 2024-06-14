#ifndef _CANLI_H_
#define _CANLI_H_

struct CANLI
{
    int canliNumara;
    char *canliAd;
    char *gorunumStr;
    char canliKarakter;

    char *(*gorunum)();

    void (*canliSil)();
};

typedef struct CANLI *Canli;

Canli canliOlustur(int canliNo);
void canliSil(Canli canli);
char *gorunum(Canli canli);

#endif