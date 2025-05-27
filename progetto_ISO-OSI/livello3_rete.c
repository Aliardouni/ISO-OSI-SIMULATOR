#include "livello4_trasporto.h"
#include "livello2_collegamento.h"
#include <string.h>
#include <stdio.h>

#define SRC "192.168.1.1"
#define DST "192.168.1.2"
int TTL=5;

char* livello3_send(const char* dati){
    char buffer[2048];
    sprintf(buffer, "[NET][SRC=%s][DST=%s][TTL=%d]%s", SRC, DST, TTL, dati);
    printf("\nAndata Livello 3:\n%s",buffer);

    return livello2_send(buffer);
}

char* livello3_receive(const char* dati)
{
    char* buffer;



    buffer=strstr(dati, "]")+1;
    buffer=strstr(buffer, "]")+1;
    buffer=strstr(buffer, "]")+1;

    TTL--;

    if(TTL<=0)
    {
        printf("\n\nErrore nella comunicazione nel livello 3");
        return NULL;
    }


    buffer=strstr(buffer, "]")+1;

    printf("\nRitorno Livello 3:\n%s", buffer);

    return livello4_receive(buffer);
}
