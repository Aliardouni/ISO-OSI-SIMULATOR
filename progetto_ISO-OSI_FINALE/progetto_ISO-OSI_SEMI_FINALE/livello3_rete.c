#include "livello2_collegamento.h"
#include <string.h>
#include <stdio.h>

#define SRC "192.168.1.1"
#define DST "192.168.1.2"
int TTL=5;
// developed by Bocchi, Kpante, Ardouni, Gizzi, Romanici
char* livello3_send(const char* dati){
    // here we add the IPs and TTL and pass it onto the next layer
    char buffer[2048];
    sprintf(buffer, "[NET][SRC=%s][DST=%s][TTL=%d]%s", SRC, DST, TTL, dati);
    printf("\nAndata Livello 3:\n%s",buffer);

    return livello2_send(buffer);
}

char* livello3_receive(const char* dati)
{
    // here we remove them headers and we check if the TTL is valid, if so, we pass it to the next layer, else
    // we tell the user that there is an error with layer 3
    char* buffer=livello2_receive(dati);

    buffer=strstr(buffer, "]")+1;
    buffer=strstr(buffer, "]")+1;
    buffer=strstr(buffer, "]")+1;

    TTL--;

    if(TTL<=0)
    {
        printf("\n\nErrore nella comunicazione nel livello 3: TTL scaduto");
        return NULL;
    }


    buffer=strstr(buffer, "]")+1;

    printf("\nRitorno Livello 3:\n%s", buffer);

    return buffer;
}
