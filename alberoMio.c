#include <stdio.h>
#include <stdlib.h>

typedef struct nodes *node;

struct nodes{
    int dato;
    node sx;
    node dx;
};

node build(node n){
    printf("Insert the value: ");
    scanf("%d",&n->dato );

    char s[2];
    printf("build  a child? [r]ight - [l]eft - [a]ll: ");
    scanf("\n%s",s);

    if(s[0]=='l'){
        printf("left child node\n" );
        n->sx=malloc(sizeof(struct nodes));
        build(n->sx);
    }
    if(s[0]=='r'){
        printf("right child node\n" );
        n->dx=malloc(sizeof(struct nodes));
        build(n->dx);
    }
    if(s[0]=='a'){
        printf("right child node\n" );
        n->dx=malloc(sizeof(struct nodes));
        build(n->dx);

        printf("left child node\n" );
        n->sx=malloc(sizeof(struct nodes));
        build(n->sx);
    }


    return n;
}

int main(int argc, char const *argv[]) {
    system("clear");
    node root=malloc(sizeof(struct nodes));
    root=build(root);
    printf("\n\nvalue: %d\n", root->dato);
    return 0;
}
