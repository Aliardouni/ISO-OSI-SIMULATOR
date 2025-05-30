#include "livello4_trasporto.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
// developed by Bocchi, Kpante, Ardouni, Gizzi, Romanici
int SESSIONE_ID=0;      //this gets a new random value every time it gets to layer 5

char* livello5_send(const char* dati, const char* action){
    // here we add headers containing the action value and the ID, then it proceeds to the next layer
    char buffer[2048];
    SESSIONE_ID=rand() % 90000 + 10000;
    printf("\n[INIT]");
    sprintf(buffer, "[SESS][%s][ID=%d]%s",action,SESSIONE_ID, dati );
    printf("\nAndata Livello 5:\n%s",buffer);
    return livello4_send(buffer);
}

char* livello5_receive(const char* dati, const char* action)
{
    // here we remove the headers and we check if the ID is the same after the communication, if its the same we proceed, else
    // we tell the user that there was a a problem with layer 5
    char* buffer=livello4_receive(dati);

    buffer=strstr(buffer, "]")+1;

    const char* start = strstr(buffer, "[ID=");
    start += strlen("[ID=");
    int session_id = 0;
    sscanf(start, "%d", &session_id);

    if (session_id == SESSIONE_ID)
    {
        buffer=strstr(buffer, "]")+1;

        printf("\nRitorno Livello 5:\n%s", buffer);
        printf("[CLOSE]\n");
        return buffer;
    }
    else
    {
        printf("\n\nErrore nella comunicazione nel livello 5: ID non corrispondente.");
        return NULL;
    }

    printf("\nRitorno Livello 5:\n%s", buffer);
    return buffer;
}
