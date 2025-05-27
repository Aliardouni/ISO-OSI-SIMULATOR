#include "livello6_presentazione.h"
#include <stdio.h>

char* livello7_send(const char* dati){
    printf("Andata Livello 7:\n%s", dati);
    return livello6_send(dati);
}

char* livello7_receive(const char* dati)
{
    return dati;
}
