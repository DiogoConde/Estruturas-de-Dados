#include <stdio.h>
#include <stdlib.h>
int menu() {
int opcao;
printf("\n1: Insere elemento na lista");
printf("\n2: Retira elemento da lista");
printf("\n3: Listar elementos");
printf("\n0: Sair");
printf("\nDigite a opcao (0 - 3): ");
scanf("%d",&opcao);
return opcao;
}
struct no {
int info;
struct no *prox;
};
typedef struct no *noPtr;
noPtr inicio = NULL;
int menu();
void insere();
void retira();
void listar();
int listaVazia();
int main() {
int op;
do {
  op = menu();
  switch (op) {
    case 1: insere(); break;
    case 2: retira(); break;
    case 3: listar(); break;
  }
} while (op!=0);
}
 
void listar() {
if (!listaVazia()) {
  noPtr p;
  p=inicio;
  printf("\nOs elementos da lista sao:\n");
  while (p!=NULL) {
    printf("%d\n",p->info);
    p=p->prox;
   }
 }
else printf("\nLista Vazia!");
}
 
int listaVazia () {
if (inicio!=NULL)
  return 0;
else
  return 1;
}
void insere () {
noPtr p;
int x;
p=(noPtr) malloc(sizeof(struct no));
printf("\nDigite o valor do elemento: ");
scanf("%d",&x);
p->info=x;
p->prox=inicio;
inicio=p;
}
void retira () {
if (!listaVazia()){
  noPtr p;
  p=inicio;
  inicio=p->prox;
  free(p);
  printf("\nO elemento foi retirado!");
 }
 else
  printf("\nLista Vazia!");
}
