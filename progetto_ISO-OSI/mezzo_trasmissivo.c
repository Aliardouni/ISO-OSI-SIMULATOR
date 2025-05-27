#include <stdlib.h>
#define FIFO_SIZE 1024
#include <string.h>

char* fifo[FIFO_SIZE];
int fifo_head = 0;
int fifo_tail = 0;

void mezzo_fisico_send(const char* bitstream) {
    fifo[fifo_tail] = strdup(bitstream);  // Copia stringa
    fifo_tail = (fifo_tail + 1) % FIFO_SIZE;
}

char* mezzo_fisico_receive() {
    if (fifo_head == fifo_tail) return NULL;  // FIFO vuota
    char* data = fifo[fifo_head];
    fifo_head = (fifo_head + 1) % FIFO_SIZE;
    return data;
}
