#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct heap{
    int dim;
    int a[100];
};

typedef struct heap *heapy;

int inserisci(heapy h, int v){
    int pos;
    int aux;

    if(h->dim==99)
        return 0;

    else{
        h->a[h->dim+1]=v;
        pos = h->dim + 1;

        while (pos!=1 && h->a[pos]>h->a[pos/2]) {
            aux=h->a[pos];
            h->a[pos]=h->a[pos/2];
            h->a[pos/2]=aux;
            pos/=2;
        }

        h->dim++;
        return 1;
    }//end else
}

int estrazione(heapy h){
    printf("\nestraggo:%i\n", h->a[1]);
    h->a[1]=h->a[h->dim];
    h->dim--;
    int c=1,aux,max;

    do{

        if (h->a[c*2]>h->a[c*2+1])
            max=c*2;

        else
            max = c*2+1;

        if (h->a[c] < h->a[max]) {
            aux=h->a[c];
            h->a[c] = h->a[max];
            h->a[max]=aux;
        }

        c*=2;
    }while((c/2)+1<=h->dim);
}

int main(int argc, char const *argv[]) {
    system("clear"); //eliminare se eseguito su windows
    srand(time(NULL));

    heapy a=malloc(sizeof(struct heap));
    for (int i = 0; i < 8; i++)
        inserisci(a, rand()%101);

    for (int i = 1; i <= a->dim; i++)
        printf("%i\n", a->a[i]);

    estrazione(a);

    for (int i = 1; i <= a->dim; i++)
        printf("%i\n", a->a[i]);

    return 0;
}
