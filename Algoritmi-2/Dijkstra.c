void Initialize_S_S (int n, int s, int *d, int *pi){
    int v;
    for (v=0; v<n; v++){
        d[v]=1000*n;
        pi[v]=n;
        }
    d[s] = 0;
    }

void Relax(int u, int v, int *w, int n, int *d, int *pi){
    if(d[v]> d[u]+ w[u+n*v]){
        d[v] = d[u]+ w[u+n*v];
        pi[v]=u;
        }
    }

void Dijkstra (int *w, int s, int *d, int *pi, int n){
    int v, k, min, u;
    int *S;
    S = calloc(n, sizeof(int));
    Initialize_S_S(n,s,d,pi);
    for (v=0; v<n; v++){
        Relax(s,v,w,n,d,pi);
        }
    S[s] =s;
    for (k=1; k<n; k++){
        u = n;
        min = 1000 * n;
        for(v=0; v<n; v++){
                if((d[v]<min) && (S[v] == 0)){
                    min = d[v];
                    u=v;
                }
            }
        S[u] = 1;
        for (v=0; v<n; v++){
                Relax(u,v,w,n,d,pi);
            }
        }
    }



int main(){

char ans;
int u,v,n,s;
int *w, *d, *pi;
printf("Quanti nodi ha il grafo? \n");
scanf("%d", &n);
w = calloc(n*n, sizeof(int));
d = calloc(n, sizeof(int));
pi = calloc(n, sizeof(int));

for (u=0; u<n; u++){
    for (v = 0; v<n; v++){
        if (u != v){
            printf("Esiste l'arco %d - %d ? (s/n)", u,v);
            scanf("\n%c", &ans);
            if (ans == 'n')
                w[u+n*v] = 1000 * n;
            else{
                printf("Inserire il costo dell'arco: %d - %d \n", u, v);
                scanf("%d", &w[u+n*v]);
            }
        }
    }
}
 printf("Inserisci il nodo sorgente \n");
        scanf("%d", &s);
        Dijkstra(w,s,d,pi,n);
        printf("Valore dei cammini minimi di %d \n", s);
        for(v = 0; v<n; v++){
            if (d[v] != 1000*n)
                printf("%d - %d \n", v, d[v]);
            else
                printf("%d : infinito \n", v);
            printf("Nodi padre: \n");
            for (v=0; v<n; v++){
                if(pi[v] != n)
                    printf("%d : %d \n", v, pi[v]);
                else
                    printf("%d : - \n", v);
            }
        }

}
