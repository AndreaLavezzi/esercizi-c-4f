#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define DIM 10

void generanumeri(int numeri[]){
  for(int i = 0; i < DIM; i++){
    numeri[i] = rand() % 50;
  }
}

int main(){
  system("clear");
  int numeri[DIM];
  int canale1[2], canale2[2];
  pipe(canale1);
  pipe(canale2);
  int pid = fork();
  if(pid > 0){
    int numero;
    generanumeri(numeri);
    close(canale1[1]);
    close(canale2[0]);
    write(canale2[1], numeri, sizeof(numeri));
    read(canale1[0], &numero, sizeof(int));
    printf("%d\n", numero);
  }
  else{
    int somma = 0;
    close(canale1[0]);
    close(canale2[1]);
    read(canale2[0], numeri, sizeof(int) * DIM);
    for(int i = 0; i < DIM; i++){
      somma = somma + numeri[i];
    }
    
    write(canale1[1], &somma, sizeof(int));
    exit(0);
  }
  return 0;
}
