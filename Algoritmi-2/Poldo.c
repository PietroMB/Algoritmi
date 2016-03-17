#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
    system("clear"); //eliminare se eseguito su windows
    srand(time(NULL));
    int a[100],com=0,ris=0;

    for (int i = 0; i < 100; i++)
        a[i]=rand()%100;

    for (int i = 0; i < 100; i++) {
        printf("%2i ", a[i]);
        if (i%10==9) printf("\n");
    }

    for (int i = 0; i < 100; i++) {
        while (a[i]<a[i+1] && i<100){
            com++;
            i++;
        }

        if(com>ris) ris=com;

        com=0;
    }

    printf("\n\nris: %i\n", ris);

    return 0;
}
