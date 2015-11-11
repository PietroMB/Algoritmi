#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define max 80

int main() {
      system("clear");
    char st[]="ciao mondo",inv[max],stack[max],data;
    int top=0;

    printf("Stringa dritta e con spazi: %s\n",st );

    for (int i = 0; i < strlen(st); i++)
        push(stack, &top, &st[i]);

    printf("Stringa rovesciata e senza spazi: " );
    for (int i = 0; i < strlen(st); i++) {
        pop(stack,&top,&data);
        inv[i]=data;
        printf("%c",inv[i] );
    }
    printf("\n" );
    return 0;
}//main

int push( char stack[max],int *top, char *data){
	if( *top == max -1 )
		return(-1);
	else{
		*top=*top+1;
            if(isspace(*data))
                  return 1;
            else
		          stack[*top] = *data;
		return(1);
	} // else
} // push

int pop( char stack[max], int *top, char *data){
	if( *top == -1 )
		return(-1);
	else{
		*data = stack[*top];
		*top = *top - 1;
		return(1);
	} //else
} // pop
