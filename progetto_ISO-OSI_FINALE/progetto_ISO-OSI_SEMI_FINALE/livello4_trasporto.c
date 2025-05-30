#include "livello3_rete.h"
#include <string.h>
#include <stdio.h>
#define MTU 20
// developed by Bocchi, Kpante, Ardouni, Gizzi, Romanici
char* livello4_send(const char* dati){
    // here we do not fragment it, instead we indicate how many fragments there would be if
    // it actually fragmented, then it adds the headers and passes it onto the next layer
    int frammentazioni = 0;
    char buffer[2048];
    int len = strlen(dati);
    if(len > 20){
        frammentazioni = len / 20;
    }
    sprintf(buffer, "[TRANS][FRAG=1/%d][ID=01]%s", frammentazioni, dati);
    printf("\nAndata Livello 4:\n%s",buffer);
    return livello3_send(buffer);
}

char* livello4_receive(const char* dati)
{
    // here we remove the headers and pass it to the next layer
    char* buffer=livello3_receive(dati);
    buffer=strstr(buffer, "]")+1;
    buffer=strstr(buffer, "]")+1;
    buffer=strstr(buffer, "]")+1;

    printf("\nRitorno Livello 4:\n%s", buffer);

    return (buffer);
}
