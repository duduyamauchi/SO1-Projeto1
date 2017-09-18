/* 
 * Uso da nova chamada de sistema
 */ 
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int aux;
  printf("Insira o tamanho do arquivo de teste em MB: ");
  scanf("%d",&aux); 
  printf("A cópia demorou %ld segundos.\n", syscall(358,aux));
  return 0;
}
