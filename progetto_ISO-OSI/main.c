#include <stdio.h>
#include <stdlib.h>
#include "livello7_applicazione.h"

int main()
{
    char* p1 = livello7_send("Ciao!\n");
    char* m1 = livello7_receive(p1);
    printf("\nRicevuto: %s", m1);

}
