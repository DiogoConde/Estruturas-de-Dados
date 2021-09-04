#include <stdio.h>
#include<stdlib.h>
struct no{
int info;
struct no *ant;
struct no *prox;
};
typedef struct no *noPtr;
void inserir(noPtr *,noPtr *);
void retirar(noPtr *, noPtr *f);
void listar(noPtr);
void listavazia();
int listaVazia=1;
int main(){
int op;
noPtr inicio = NULL;
noPtr fim = NULL;
do {
 printf("\n1: Inserir elemento na lista");
 printf("\n2: Retirar elemento da lista");
 printf("\n3: Listar elementos");
 printf("\n4: Lista vazia?");
 printf("\n0: Sair");
 printf("\n\nDigite a opcao (0 - 3): ");
 scanf("%d",&op);
 if(inicio==NULL)
   listaVazia=1;
 else
   listaVazia=0;
 switch (op){
   case 1: inserir(&inicio,&fim); break;
   case 2: retirar(&inicio, &fim); break;
   case 3: listar(inicio); break;
   case 4: printf("\n%d\n",listaVazia); break;
  }
 } while (op != 0);
return 0;
 }
void inserir (noPtr *i, noPtr *f){
noPtr p =(noPtr)malloc(sizeof(struct no));
printf("\nDigite o valor do elemento: ");
scanf("%d",&p->info);
if (listaVazia==1){
 *i = p;
 *f = p;
 p->prox = NULL;
 p->ant = NULL;
 }
else{
 p->ant= NULL;
 p->prox = *i;
 (*i)->ant = p;
  *i = p;
 }
}
void retirar (noPtr * i, noPtr *f){
noPtr aux=*f;
noPtr p = *i;
if (listaVazia==0){
 if (p->prox == NULL)
   *i = NULL;
 else{
   *f=aux->ant;
   free(aux);
   aux=*f;
   aux->prox=NULL;
  }
  printf("\nO elemento foi retirado da lista!\n");
 }
else printf("\n\nLista está Vazia!\n");
}
 
void listar(noPtr p){
if (listaVazia==0){
 printf("\nElementos da lista : \n");
 printf("INICIO");
 while (p != NULL){
   printf(" --> %d",p->info);
   p = p->prox;
   }
 printf(" -- > NULL");
 }
else
 printf("\n\nLista está Vazia!\n");
}
