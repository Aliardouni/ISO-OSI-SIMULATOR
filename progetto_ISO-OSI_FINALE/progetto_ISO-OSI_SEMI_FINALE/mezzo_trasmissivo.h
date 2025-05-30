#ifndef MEZZO_TRASMISSIVO_H_INCLUDED
#define MEZZO_TRASMISSIVO_H_INCLUDED

//trasmette il frame di bit
void mezzo_fisico_send(const char* bitstream);
//legge dal mezzo trasmissivo il frame di bit
char* mezzo_fisico_receive();


#endif // MEZZO_TRASMISSIVO_H_INCLUDED
