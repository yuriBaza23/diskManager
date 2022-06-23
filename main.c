#include <stdio.h>
#include <stdlib.h>

#include "disco.c"

int main() {
  Disco* disk = disco_cria("dados", 15);

  printf("Nome do disco: %s\n", disk->nome);
  
  return 0;
}