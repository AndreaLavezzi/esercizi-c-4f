#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printContacts(FILE *inputFile){
    int words = 0;
    char fileContent[100][100];
    char line[1024];
    int index = 0;
    char c = getc(inputFile);

    while ( c != EOF ) {
        if ( c != '\n'){
            line[index++] = c;
        }else {
            line[index] = '\0';
            index = 0;

            printf ( "%s\n", line );
        }
        c = getc ( inputFile );
    }
    // while(!feof(inputFile)){
    //     fscanf(inputFile, "%s ", fileContent[words]);
    //     words++;
    // }
    
    // for(int i = 0; i < words; i++){
    //     printf("%s\t", fileContent[i]);
    //     if((i + 1) % 3 == 0){
    //         printf("\n");
    //     }
    // }
    

   
}

int main(int argc, char *argv[]){
    FILE *inputFile;
    
    if((inputFile = fopen(argv[1], "r")) == NULL){
        printf("Can't open input file.\n");
        exit(0);
    }
    
    printContacts(inputFile);

    return 0;
}