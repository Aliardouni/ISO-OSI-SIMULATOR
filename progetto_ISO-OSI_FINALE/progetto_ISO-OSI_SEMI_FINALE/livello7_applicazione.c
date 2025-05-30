#include "livello6_presentazione.h"
#include <stdio.h>
// developed by Bocchi, Kpante, Ardouni, Gizzi, Romanici
char* livello7_send(const char* dati){
    // here we send the message to the layer 6
    printf("Andata Livello 7:\n%s", dati);
    return livello6_send(dati);
}

char* livello7_receive(const char* dati)
{
    // here we return the final message, by retrieving the message from
    // underneath levels
    return livello6_receive(dati);
}
