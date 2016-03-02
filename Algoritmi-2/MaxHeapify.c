#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Max Heap inserimento ed estrazione
//len è il numero di elementi da inserire 

int main(int argc, char const *argv[]) {
    system("clear"); //pulisce la finestra terminale nei sistemi UNIX-like
    int t[1000], i, len=20;

    srand(time(NULL)); // necessaria per generare numeri pseudo randomici

    for (i = 0; i < 1000; i++)
        t[i] = NULL;

    int x;

    for(x=0;x<len;x++)
        inserisci(t);
    for(x=0;x<len;x++)
        printf("%d\n", t[x]);

    ordina(t,len);
    printf("\nSPAZIO\n\n");

    for(x=0;x<len;x++)
        printf("%d\n", t[x]);

    return 0;
}

void inserisci(int *t){
    int i = 0;

    while (t[i]!=NULL)
        i++;

    t[i]=rand()%100;
    heapfy(t,i);

}

void heapfy(int *t, int i){
    int temp;

    while(i > 0){

        if (t[i]>t[i/2]) {
            temp = t[i];
            t[i]=t[i/2];
            t[i/2]=temp;
        }

        i=i/2;

  }//end while

}

void ordina(int *t, int i, int len){
    t[0]=0;

    for (i = len; i > len/2; i--)
        heapfy(t,i);

}
