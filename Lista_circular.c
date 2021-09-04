#include <stdio.h>
#include <stdlib.h>
struct no{
 int info;
 struct no *prox;
};
typedef struct no *noPtr;
int insere(noPtr *, int *);
void checacircular(noPtr, int);
void retira(noPtr *, int *);
void listar(noPtr, int);
int listaVazia(noPtr);
int menu();
int main(){
     int op, qtde = 0;
     noPtr inicio = NULL;
     do{
         op = menu();
         switch (op){
             case 1: qtde=insere(&inicio, &qtde);
             printf("\nA lista possui %d no(s).\n\n",qtde); break;
             case 2: retira(&inicio, &qtde); break;
             case 3: listar(inicio, qtde); break;
             case 4: checacircular(inicio, qtde);
            }
        } while (op != 0);
    }
   
int insere (noPtr *i, int *q){
     noPtr p = (noPtr)malloc(sizeof(struct no));
     printf("\nDigite o valor do elemento:\t");
     scanf("%d",&p->info);
     if (listaVazia(*i)==1){
         *i = p;
         p->prox = *i;
     }
     else{
         p->prox=(*i)->prox;
         (*i)->prox=p;
     }
     return *q+1;
}
void retira (noPtr *i,int *q){ //Mantém a lista circular??? O que fazer?
     noPtr p = (*i)->prox;
     if (!listaVazia(*i)){
         if (*q == 1){
             *i = NULL;
            } else
     (*i)->prox = p->prox;//*i = (*i)->prox
     free(p);
     printf("\nO elemento foi retirado da lista!\n");
     *q = *q - 1;
     } else printf("\n\nLista Vazia!\n");
}
void listar(noPtr i, int q){
     if (!listaVazia(i)){
  for (int j=0;j<q;j++){
  printf("\n%d\n",i->info);
  i = i->prox;
 }
}
else
printf("\n\nLista vazia!");
}
int listaVazia(noPtr i){
if(i!=NULL)
return 0;
else
return 1;
}
int menu(){
int opcao;
printf("\n1: Insere elemento na lista");
printf("\n2: Retira elemento da lista");
printf("\n3: Listar elementos");
printf("\n4: Checa se eh circular");
printf("\n0: Sair");
printf("\nDigite a opcao (0 - 3): ");
scanf("%d",&opcao);
return opcao;
}
void checacircular(noPtr i,int q){
noPtr p = i;
printf("\nEndereco do inicio:%p\n",p);
for (int j=0;j<=q;j++){
  p = p->prox;
}
printf("\np:%p\np->prox:%p\n",p,p->prox);
}