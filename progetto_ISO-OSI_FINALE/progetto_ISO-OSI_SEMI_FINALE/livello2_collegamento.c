#include "livello1_fisico.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
// developed by Bocchi, Kpante, Ardouni, Gizzi, Romanici
unsigned int checksum(const char* data, const char* var){
    // here we calculate the checksum of the payload
    char* pyl = strstr(data, var);
    pyl += strlen(var);
    int i = 0;
    int somma = 0;
    for(i = 0; (pyl[i] != '\0' && pyl[i] != '['); i++)
        somma += (int)pyl[i];
    return somma;

}


char* livello2_send(const char* dati){
    // here we add the headers and the checksum, then we pass it to the next layer
    char buffer[2048];
    unsigned int check = checksum(dati, "[ENC=ROT13]");
    sprintf(buffer, "[MAC][SRC=AA:BB][DST=CC:DD]%s[CHECKSUM][%u]", dati, check);
    printf("\nAndata Livello 2:\n%s", buffer);
    return livello1_send(buffer);
}

char* livello2_receive(const char* dati) {
    // here we calculate the checksum of the received string and compare it to the previous checksum, if it is the same
    // it can go to the next layer, else we tell the user that there was an error with layer 2. Also it removes the headers
    char* buffer=livello1_receive(dati);

    int check_locale = checksum(buffer, "[ENC=ROT13]");

    const char* inizio_check = strstr(buffer, "[CHECKSUM][");

    inizio_check += strlen("[CHECKSUM][");
    int check_ricevuto = 0;
    sscanf(inizio_check, "%d", &check_ricevuto);

    if (check_locale == check_ricevuto)
    {
        buffer=strstr(buffer, "]")+1;
        buffer=strstr(buffer, "]")+1;
        buffer=strstr(buffer, "]")+1;

        char* pos_check = strstr(buffer, "[CHECKSUM]");
        if (pos_check) *pos_check = '\0';

        printf("\n\nRitorno Livello 2:\n%s", buffer);
        return buffer;
    }
    else
    {
        printf("\n\nErrore nella comunicazione nel livello 2: checksum non corrispondente.");
        return NULL;
    }
}
