#include "livello3_rete.h"
#include "livello1_fisico.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

unsigned int checksum(const char* data, const char* var){
    char* pyl = strstr(data, var);
    pyl += strlen(var);
    int i = 0;
    int somma = 0;
    for(i = 0; (pyl[i] != '\0' && pyl[i] != '['); i++)
        somma += (int)pyl[i];
    return somma;

}


char* livello2_send(const char* dati){
    char buffer[2048];
    unsigned int check = checksum(dati, "[ENC=ROT13]");
    sprintf(buffer, "[MAC][SRC=AA:BB][DST=CC:DD]%s[CHECKSUM][%u]", dati, check);
    printf("\nAndata Livello 2:\n%s", buffer);
    return livello1_send(buffer);
}

char* livello2_receive(const char* dati) {
    char* buffer;
    int check_locale = checksum(dati, "[ENC=ROT13]");

    const char* inizio_check = strstr(dati, "[CHECKSUM][");

    inizio_check += strlen("[CHECKSUM][");
    int check_ricevuto = 0;
    sscanf(inizio_check, "%d", &check_ricevuto);

    if (check_locale == check_ricevuto) {
        buffer=strstr(dati, "]")+1;
        buffer=strstr(buffer, "]")+1;
        buffer=strstr(buffer, "]")+1;

        char* pos_check = strstr(buffer, "[CHECKSUM]");
        if (pos_check) *pos_check = '\0';

        printf("\n\nRitorno Livello 2:\n%s", buffer);
        return livello3_receive(buffer);
    } else {
        printf("\n\nErrore nella comunicazione nel livello 2: checksum non corrisponde.");
        return NULL;
    }
}
