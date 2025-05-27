#ifndef LIVELLO2_COLLEGAMENTO_H_INCLUDED
#define LIVELLO2_COLLEGAMENTO_H_INCLUDED

char* livello2_send(const char* dati);
char* livello2_receive(const char* dati);
unsigned int checksum(const char* data, const char* var);

#endif // LIVELLO2_COLLEGAMENTO_H_INCLUDED
