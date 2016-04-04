#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elementi *elemento;

struct elementi{
    int dato;
    elemento next;
};

elemento inserisci(elemento e, int d){
    while (e != NULL) {
        e=e->next;
    }
    e->dato=d;
    elemento nuovo = calloc(1,sizeof(struct elementi));
    nuovo->next=NULL;
    e->next=nuovo;
}

void stampa(elemento e){
    while (e != NULL) {
        printf("%d ", e->dato);
        e=e->next;
    }
}
int main(int argc, char const *argv[]) {
    system("clear"); //eliminare se eseguito su windows
    srand(time(NULL));

    elemento a[100];
    int d,ran;
    printf("inserisci dimensione array max 99: \n");

    do {
        scanf("\n%d", &d);
    } while(d>=99 && d>0);

    for(int i=0; i<d; i++)
        a[i]=calloc(1,sizeof(struct elementi));

    for (int i = 0; i < 1000; i++){
        ran=rand()%1001;
        inserisci(a[ran%d], ran);
    }

    for (int i = 0; i < d; i++) {
        printf("\n%d:\n", i);
        stampa(a[i]);
        printf("\n");
    }

    return 0;
}
