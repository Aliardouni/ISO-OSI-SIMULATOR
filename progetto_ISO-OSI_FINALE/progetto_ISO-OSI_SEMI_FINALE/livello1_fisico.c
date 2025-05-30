#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mezzo_trasmissivo.h"
// developed by Bocchi, Kpante, Ardouni, Gizzi, Romanici
char* livello1_send(const char* dati){
    // here we convert the message to a sequence of bits and we pass it to the physical canal
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
    if(output!=NULL)
        free(output);
    return mezzo_fisico_receive();
}

char* livello1_receive(const char* dati)
{
    // here we convert the sequence of bits onto the original string, and we pass it to the next layer
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

    printf("\n\n\n\nRitorno Livello 1:\n%s", supBuffer);

    char* returner=strdup(supBuffer);

    return returner;
}

