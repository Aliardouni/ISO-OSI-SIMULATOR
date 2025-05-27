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

char* livello2_receive(const char* dati){
    char* buffer;
    int oldCheck=checksum(dati, "[ENC=ROT13]");     //old is actually new, and new is the old one
    int i=0;
    int number=0;

    char* toCheck=strstr(dati, "[CHECKSUM]");       //old is actually new, and new is the old one
    toCheck+=12;
    char newCheck[10]={' '};

    newCheck[i++]=*toCheck;                         //old is actually new, and new is the old one

    while(*toCheck!=']')
    {
        newCheck[i++]=*toCheck++;
    }

    for (i = 0; i < 10; i++) {        //old is actually new, and new is the old one
        if (isdigit(newCheck[i])) {
            number=number*10+(newCheck[i]-'0');
        }
    }

    if(number==oldCheck)
    {
        buffer=strstr(dati, "]")+1;
        buffer=strstr(buffer, "]")+1;
        buffer=strstr(buffer, "]")+1;
        char* tagPos = strstr(buffer, "[CHECKSUM]");
        *tagPos = '\0';
        printf("\n\nRitorno Livello 2:\n%s", buffer);
        return livello3_receive(buffer);
    }
    else
    {
        printf("\n\nErrore nella comunicazione nel livello 2");
        return NULL;
    }
}
