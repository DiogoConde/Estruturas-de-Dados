#include <stdio.h>
int busca(int elemproc,int A[],int i,int f){
int meio, pos = -1;
   if (i<f){
     meio = (i+f)/2;
     if(A[meio]==elemproc){
       pos=meio;
       }
     else if(elemproc<A[meio]){
         pos=busca(elemproc,A,i,meio);
        }
     else if(elemproc>A[meio]){
         pos=busca(elemproc,A,meio+1,f);
       }
 }
 return pos;
}
 
int main() {
int A[20],n,i,f,meio,elemproc,posicao;
 printf("Digite o numero de elementos no vetor\n");
 scanf("%d",&n);
 for (i=0;i<n;i++){
   printf("Digite o %d elemento do vetor\n", i+1);
   scanf("%d", &A[i]);
 }
 printf("Digite o elemento procurado\n");
 scanf("%d",&elemproc);
 posicao=busca(elemproc,A,0,n-1);
 printf("A posicao do elemento procurado e:%d",posicao);
return 0;
}
