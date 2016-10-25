#include "include.h"
#include "ficheiros.h"


//Estrutura do pedido
typedef struct{
    int request_type;
    char file[30];
    int socket;
}pedido_struct;

int buffer_size;

pedido_struct buffer[buffer_size];
