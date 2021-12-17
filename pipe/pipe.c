#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define DIM 10

/**
* \fn       generanumeri(int numeri[])
* \brief    genera dei numeri randomici minori di 50 e li inserisce in un array
* \param    int numeri[]: Array di numeri, la lunghezza è pari a DIM
* \details  Viene preso in input un array di int, e in ogni posizione viene messo un numero intero generato dalla funzione rand()   
*/
void generanumeri(int numeri[]){
  for(int i = 0; i < DIM; i++){
    numeri[i] = rand() % 50;
  }
}

/**
* \fn       int main()
* \brief    Genera due processi che comunicano tramite due pipe, il padre genera dei numeri, li manda al figlio che ne fa la somma e il padre la stampa a schermo
* \param    int numeri[DIM]: Array di numeri, la lunghezza corrisponde a DIM
* \param    int canale1[2]: Array che verrà predisposto ad ospitare una pipe, da cui il padre leggerà ciò che il figlio scrive
* \param    int canale2[2]: Array che verrà predisposto ad ospitare una pipe, da cui il figlio leggerà ciò che il padre scrive
* \param    int pid: Pid del processo figlio
* \param    int somma: Somma dei numeri generati
* \details  Viene inizialmente pulita la console tramite la chiamata di sistema "clear". Vengono predisposti i due canali di comunicazione ad ospitare due pipe tramite la funzione pipe().
* Viene generato un processo figlio tramite la funzione fork(). Il processo padre chiama la funzione generanumeri() che popola l'array di numeri con dei numeri casuali. Viene poi scritto
* l'array nella parte di scrittura del canale2 tramite la funzione write(). Il processo padre si sospende poi sulla funzione read() finchè non legge qualcosa nella parte di lettura del
* canale1. Ciò che viene letto viene inserito nella variabile somma. Viene infine stampata a schermo tramite la funzione printf().
* Il processo figlio dichiara e inizializza la variabile somma a 0. Chiude i canali che non utilizza e successivamente si sospende su una read, in attesa dell'array di numeri casuali.
* Quando li legge, tramite un ciclo for somma la variabile somma al numero contenuto nella posizione della iterazione corrente dell'array. Infine, scrive tramite la funzione write() il 
* numero nel canale1 e lancia una exit.
*/
int main(){
  int numeri[DIM];
  int canale1[2], canale2[2];
  system("clear");
  pipe(canale1);
  pipe(canale2);
  int pid = fork();
  if(pid > 0){
    int somma;
    generanumeri(numeri);
    close(canale1[1]);
    close(canale2[0]);
    write(canale2[1], numeri, sizeof(numeri));
    read(canale1[0], &somma, sizeof(int));
    printf("%d\n", somma);
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
