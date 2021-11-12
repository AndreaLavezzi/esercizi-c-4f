#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *inputStream;
    FILE *outputStream;
    char stringa[100][100];
    int numParole = 0;
    if(argc != 6){
        printf("Argomenti errati. Utilizzo: /prg.out <file di input> <file di output> <-s> <carattere da sostuituire> <carattere sostituito>\n");
        exit(0);
    }

    if((inputStream = fopen(argv[1], "r")) == NULL){
        printf("Errore nell'apertura del file di input. Inserire un file di testo valido.\n");
        exit(1);
    }

    if(strcmp(argv[3], "-s") != 0){
        printf("Modalità errata. Inserire \"-s\" per sostituire un carattere con un altro.\n");
        exit(2);
    }

    if(strlen(argv[4]) > 1 || strlen(argv[5]) > 1){
        printf("Inserire solamente un carattere da sostituire o sostituito.\n");
        exit(3);
    }

    while(!feof(inputStream)){
        fscanf(inputStream, "%s\t", stringa[numParole]);
        numParole++;
    }
    fclose(inputStream);

    for(int j = 0; j < numParole; j++){
        for(int i = 0; i < strlen(stringa[j]); i++){
            if(stringa[j][i] == argv[4][0]){
                stringa[j][i] = argv[5][0];
            }
        }
    }

    outputStream = fopen(argv[2], "w");
    char str[100];

    fprintf(outputStream, "%s", stringa);
    fclose(outputStream);
}