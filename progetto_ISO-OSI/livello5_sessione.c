#include "livello6_presentazione.h"
#include "livello4_trasporto.h"
#include <stdio.h>
#include <string.h>
#define SESSIONE_ID "12345"

char* livello5_send(const char* dati, const char action){
    char buffer[2048];
    sprintf(buffer, "[SESS][ID=%s]%s", SESSIONE_ID, dati );
    printf("\nAndata Livello 5:\n%s",buffer);
    return livello4_send(buffer);
}

char* livello5_receive(const char* dati, const char action)
{
    char* buffer;
    buffer=strstr(dati, "]")+1;
    buffer=strstr(buffer, "]")+1;

    printf("\nRitorno Livello 5:\n%s", buffer);
    return livello6_receive(buffer);
}
