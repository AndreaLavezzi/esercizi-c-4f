#include <stdio.h>
#include <stdlib.h>
#define DIM 4

typedef struct{
    char name[12];
    char surname[12];
    int age;
} Person_T;

Person_T addPerson(){
    Person_T person;
    printf("\nInserisci il nome della persona: ");
    scanf("%s", person.name);
    printf("Hai inserito: %s", person.name);
    printf("\nInserisci il cognome della persona: ");
    scanf("%s", person.surname);
    printf("Hai inserito: %s", person.surname);
    printf("\nInserisci l'eta' della persona: ");
    scanf("%d", &person.age);
    printf("Hai inserito: %d", person.age);
    return person;
}

Person_T findOldest(Person_T people[]){
    Person_T oldest;
    for (int i = 0; i < DIM; i++)
    {
        if(i == 0){
            oldest = people[i];
        }else if(oldest.age < people[i].age){
            oldest = people[i];
        }
    }
    return oldest;
}

int main(){
    Person_T oldest;
    Person_T people[DIM];
    for(int i = 0; i < DIM; i++){
        people[i] = addPerson();
    }
    oldest = findOldest(people);
    printf("\nLa persona piu' vecchia e' %s %s, di eta': %d", oldest.name, oldest.surname, oldest.age);
    return 0;
}