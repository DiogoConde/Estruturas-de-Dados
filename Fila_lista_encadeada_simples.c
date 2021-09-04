#include <stdio.h>
#include <stdlib.h>
struct no {
int info;
struct no *prox;
};
typedef struct no *noPtr;
noPtr inicio = NULL;
void insere();
void retira();
void listar();
int listaVazia();
int main() {
int op;
do {
 printf("\n1: Insere elemento na fila");
 printf("\n2: Retira elemento da fila");
 printf("\n3: Listar elementos");
 printf("\n0: Sair");
 printf("\nDigite a opcao (0 - 3): ");
 scanf("%d",&op);
 switch (op) {
   case 1: insere(); break;
   case 2: retira(); break;
   case 3: listar(); break;
 }
} while (op!=0);
}
void insere() {
int x;
noPtr aux, p=(noPtr) malloc(sizeof(struct no));
printf("\nDigite o valor do elemento: ");
scanf("%d",&x);
p->info=x;
p->prox = NULL;
if (listaVazia())
 inicio = p;
else {
 aux = inicio;
 while(aux->prox!=NULL)
   aux = aux->prox;
   aux->prox=p;
}
}
void retira () {
noPtr p;
if (listaVazia())
 printf("\nFila Vazia!");
else {
 p=inicio;
 inicio=p->prox;
 free(p);
 printf("\nO elemento foi retirado da Fila!\n");
}
}
void listar() {
noPtr p = inicio;
if (listaVazia())
 printf("\nFila Vazia!");
else {
 printf("\nOs elementos da fila sao: \n");
 printf("INICIO");
 while (p != NULL) {
   printf("-->%d",p->info);
   p = p->prox;
  }
 printf("--> NULL\n\n");
}
}
int listaVazia () {
if (inicio!=NULL)
 return 0;
else
 return 1;
}
