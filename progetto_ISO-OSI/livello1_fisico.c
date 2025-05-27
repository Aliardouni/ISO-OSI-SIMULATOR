#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livello2_collegamento.h"
#include "livello1_fisico.h"
#include "mezzo_trasmissivo.h"

char* livello1_send(const char* dati){
    size_t len = strlen(dati);
    char* output = malloc(len * 8 + 1);

    char* p = output;

    for (size_t i = 0; i < len; ++i) {
        for (int b = 7; b >= 0; --b) {
            *p++ = (dati[i] & (1 << b)) ? '1' : '0';
        }
    }
    *p = '\0';
    printf("\n\nAndata Livello 1:\n%s", output);
    mezzo_fisico_send(output);
    free(output);
    return livello1_receive(mezzo_fisico_receive());
}

char* livello1_receive(const char* dati)
{
    char* buffer=strdup(dati);
    size_t len = strlen(buffer);
    char byte[8];

    char supBuffer[2048];
    int j=0;

    for(size_t i=0; i<len; i+=8)
    {
        char carattere=0;

        for(int k=0; k<8; k++)
        {
            byte[k]=buffer[k+i];
        }

        for(int y=7; y>=0; y--)
        {
            carattere|=(byte[y]=='1' ? 1:0) << (7-y);
        }
        supBuffer[j++]=carattere;
    }
    supBuffer[j]='\0';

    printf("\n\nRitorno Livello 1:\n%s", supBuffer);
    return livello2_receive(supBuffer);
}

