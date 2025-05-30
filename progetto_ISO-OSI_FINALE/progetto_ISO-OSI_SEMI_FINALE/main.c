#include <stdio.h>
#include <stdlib.h>
#include "livello7_applicazione.h"
#include <time.h>
// developed by Bocchi, Kpante, Ardouni, Gizzi, Romanici
int main()
{
    srand(time(NULL));
    char* p1 = livello7_send("buongiornooa!\n");
    char* m1 = livello7_receive(p1);


    printf("\nRicevuto: %s", m1);

    if(p1!=NULL)
        free(p1);
    if(m1!=NULL)
        free(m1);

}
