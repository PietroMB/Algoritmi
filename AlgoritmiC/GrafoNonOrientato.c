//input: creare matrice tutti 0 di dimensione n*n
//inserire un arco di una matrice di adiacenza
//verificare grado massimo della matrice, ovvero l'elemento con più archi
//verificare i nodi isolati
//verificare se il grafo è regolare tutti lo stesso grado
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    clock_t b=clock();

    printf("inserisci la grandezza della matrice: ");
    int scelta,i,j;
    do {
        scanf("\n%i", &scelta);
    } while(scelta<0);

    int a[scelta][scelta];

    for ( i = 0; i < scelta; i++) {
        for ( j = 0; j < scelta; j++)
            a[i][j]=0;
    }

    for ( i = 0; i < scelta; i++) {
        for ( j = 0; j < scelta; j++)
            printf("%i ", a[i][j]);
        printf("\n");
    }

    char s[2];

    do{
        printf("vuoi inserire un arco?\n");
        scanf("\n%c", &s[0]);
        if (s[0]=='s') {
            printf("inserisci il primo valore: ");
            do {
                scanf("\n%i", &i);
            } while(i<0 && i>scelta);

            printf("inserisci il secondo valore: ");
            do {
                scanf("\n%i", &j);
            } while(j<0 && j>scelta);

            a[i][j]=1;
            a[j][i]=1;
        }
    }while(s[0]=='s');


    for ( i = 0; i < scelta; i++) {
        for ( j = 0; j < scelta; j++)
            printf("%i ", a[i][j]);
        printf("\n");
    }

    int conta[scelta];
    for ( i = 0; i < scelta; i++)
        conta[i]=0;

    for(i=0;i<scelta;i++){
        for(j=0;j<scelta;j++)
            if(a[i][j]==1)
                conta[i]++;
    }

    for(i=0;i<scelta;i++)
        if(conta[i]!=0)
            printf("all'indice %i, il numero %i\n", i,conta[i]);

    for(i=0;i<scelta;i++)
        if(conta[i]==0)
            printf("all'indice %i il nodo è isoltato\n", i);

    j=0;
    for(i=0;i<scelta-1;i++)
        if(conta[i] != conta[i+1])
            j++;

    if (j==0)
        printf("\nil grafo è regolare\n");
    else
        printf("\nil grafo non è regolare\n");

    clock_t c=clock();
    double f=(double)(c-b)/CLOCKS_PER_SEC;
    printf("\ntempo: %lf\n", f);

    return 0;
}
