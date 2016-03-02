#include <stdio.h>
#include <stdlib.h>

typedef struct liste *lista;

struct liste{
    int data;
    lista next;
};

lista crealista(lista l){
    printf("inserisci il valore ");
    scanf("%d", &l->data);

    char s[2];
    printf("continuare? ");
    scanf("%s", &s);

    if (s[0]=='y') {
        l->next=malloc(sizeof(struct liste));
        crealista(l->next);
    }
    else
        l->next=NULL;
    return l;
}

void leggilista(lista l){
    if (l!=NULL){
        printf("%d\n", l->data);
        leggilista(l->next);
    }

    else
        return;
}

int contaValori(lista l, int val){
    int i=0;
    while (l!=NULL) {
        if (l->data==val)
            i++;
        l=l->next;
    }
    return i;
}

int main(int argc, char const *argv[]) {
    system("clear");
    lista l1 = malloc(sizeof(struct liste));
    l1=crealista(l1);
    leggilista(l1);
    printf("nella lista sono presenti %d numeri 4\n", contaValori(l1,4));
    return 0;
}
