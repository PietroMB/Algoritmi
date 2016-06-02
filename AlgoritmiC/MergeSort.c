#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAX 300


/*
 * Legge in input il numero n ed n numeri interi
 * che memorizza nell'array. Restituisce il numero
 * di elementi letti (n).
 */

int leggi_array(int V[]) {
  int n, i;
  printf("quanti elementi vorresti vedere ordinati?\n");
  scanf("%d", &n);
  srand(time(NULL));
  for (i=0; i<n; i++)
    V[i]=rand()%100;
  return(n);
}


/*
 * Stampa in output l'array.
 */

void stampa_array(int V[], int n) {
  int i;

  for (i=0; i<n; i++) {
    printf("%d ", V[i]);
  }
  printf("\n");
  return;
}

/*
 *  Funzione Merge per la fusione di due
 *  componenti ordinate dell'array.
 */

void Merge(int A[], int p, int q, int r) {
  int i, j, k, B[MAX];

  i = p;
  j = q+1;
  k = 0;
  while (i<=q && j<=r) {
    if (A[i]<A[j]) {
      B[k] = A[i];
      i++;
    } else {
      B[k] = A[j];
      j++;
    }
    k++;
  }
  while (i<=q) {
    B[k] = A[i];
    i++;
    k++;
  }
  while (j<=r) {
    B[k] = A[j];
    j++;
    k++;
  }
  for (k=p; k<=r; k++)
    A[k] = B[k-p];
  return;
}


/*
 *  Funzione ricorsiva MergeSort.
 */

void MergeSort(int A[], int p, int r) {
  int q;

  if (p<r) {
    q = (p+r)/2;
    MergeSort(A, p, q);
    MergeSort(A, q+1, r);
    Merge(A, p, q, r);
  }
  return;
}


/*
 *  Funzione principale
 */

int main(void) {
  int n, V[MAX];

  n = leggi_array(V);
  MergeSort(V, 0, n-1);
  stampa_array(V, n);
  return(1);
}
