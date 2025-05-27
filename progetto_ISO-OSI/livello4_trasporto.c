#include "livello5_sessione.h"
#include "livello3_rete.h"
#include <string.h>
#include <stdio.h>
#define MTU 20

char* livello4_send(const char* dati){
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
    char* buffer;
    buffer=strstr(dati, "]")+1;
    buffer=strstr(buffer, "]")+1;
    buffer=strstr(buffer, "]")+1;

    printf("\nRitorno Livello 4:\n%s", buffer);

    return livello5_receive(buffer, "NORMAL");
}
