#include <stdio.h>
int main() {
int i, menor, prox, A[20], aux, n;
 printf("digite o numero de elementos no vetor\n");
 scanf("%d",&n);
 for (i=0;i<n;i++){
   printf("digite o %d elemento do vetor\n", i+1);
   scanf("%d", &A[i]);
 }
 for(i=0;i<n-1;i++){
   menor=i;
   for(prox=i+1;prox<n;prox++){
     if (A[prox]<A[menor]){
       menor=prox;
     }
   }
   aux=A[i];
   A[i]=A[menor];
   A[menor]=aux;
 }
  printf("\nSeu vetor ficou assim:\n");
 for (i=0;i<n;i++){
   printf("\n%d\n",A[i]);
 }
return 0;
}
