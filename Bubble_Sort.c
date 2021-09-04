#include <stdio.h>
int main() {
int n,i,j,A[20],aux;
printf("digite o numero de elementos no vetor\n");
scanf("%d",&n);
for (i=0;i<n;i++){
  printf("digite o %d elemento do vetor\n", i+1);
  scanf("%d", &A[i]);
 }
for(i=0;i<n-1;i++){
   for(j=i+1;j<n;j++){
     if (A[i]>A[j]){
       aux=A[i];
       A[i]=A[j];
       A[j]=aux;
     }
   }
 }
 printf("\nSeu vetor ficou assim:\n");
 for (i=0;i<n;i++){
   printf("\n%d\n",A[i]);
 }
return 0;
}
