#include "livello5_sessione.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// developed by Bocchi, Kpante, Ardouni, Gizzi, Romanici
char* rot13(const char* input) {
    // this function encodes the original string by using a rot13 algorithm
    char* output = strdup(input);
    for (int i = 0; output[i]; i++) {
        if ('A' <= output[i] && output[i] <= 'Z')
            output[i] = ((output[i] - 'A' + 13) % 26) + 'A';
        else if ('a' <= output[i] && output[i] <= 'z')
            output[i] = ((output[i] - 'a' + 13) % 26) + 'a';
    }
    return output;
}

char* livello6_send(const char* dati){
    // here we encode the message and add the headers and then we pass it onto the next layer
    char* codifica = rot13(dati);
    char buffer[2048];
    sprintf(buffer, "[PRES][ENC=ROT13]%s", codifica);
    if (codifica!=NULL)
         free(codifica);
    printf("\nAndata Livello 6:\n%s",buffer);
    return livello5_send(buffer, "NORMAL");
}

char* livello6_receive(const char* dati)
{
    // here we remove the headers and decode it before passing it to the next layer
    char* buffer=livello5_receive(dati,"NORMAL");
    buffer=strstr(buffer, "]")+1;
    buffer=strstr(buffer, "]")+1;
    buffer=strstr(buffer, "]")+1;

    buffer=rot13(buffer);
    printf("\nRitorno Livello 6:\n%s", buffer);
    return buffer;
}
