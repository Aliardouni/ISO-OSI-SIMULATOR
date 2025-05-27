#include "livello5_sessione.h"
#include "livello7_applicazione.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* rot13(const char* input) {
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
    char* codifica = rot13(dati);
    char buffer[2048];
    sprintf(buffer, "[PRES][ENC=ROT13]%s", codifica);
    free(codifica);
    printf("\nAndata Livello 6:\n%s",buffer);
    return livello5_send(buffer, "NORMAL");
}

char* livello6_receive(const char* dati)
{
    char* buffer;
    buffer=strstr(dati, "]")+1;
    buffer=strstr(buffer, "]")+1;

    buffer=rot13(buffer);
    printf("\nRitorno Livello 6:\n%s", buffer);
    return livello7_receive(buffer);
}
