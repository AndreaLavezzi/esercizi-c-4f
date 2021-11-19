#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int pidPadre = getpid(), pidFiglio; // Ottengo il pid del padre. Dichiaro la variabile contenente il pid del figlio.
    printf("Sono il padre. Il mio pid è: %d. Ora eseguo una fork.\n", pidPadre); // Comunico il pid del padre. 
    pidFiglio = fork(); // Creo un processo figlio, inizializzo la variabile pidFiglio dandole come valore quello di ritorno della fork.
    if(pidFiglio == 0){ // Il figlio vede il proprio pid come 0, quindi questo pezzo verrà eseguito solo dal figlio.
        printf("Ciao sono il figlio. Io ho pid: %d. \nIl mio daddy ha pid: %d.\n", getpid(), pidPadre); // Il figlio comunica il suo pid e quello del padre
        exit(0); // Il figlio si termina
    }else{
        wait(0); // Aspetto il segnale dal figlio
        printf("Sono il padre. Mio figlio con pid: %d è appena morto.\n", pidFiglio); // Il padre comunica la morte del figlio
    }
}