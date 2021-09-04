#include <stdlib.h>
#include <stdio.h>
struct produto {
int codP;
float valor;
struct produto *proxP;
};
typedef struct produto *structP;
struct cliente {
int codC;
struct produto *prod;
struct cliente *proxC;
};
typedef struct cliente *structC;
void chegada();
void listarProd();
void consumo();
float saida();
void fechar();
void listarCli();
int menu();




structC inicio=NULL;
float totDin;

int main(){
totDin=0.0f;
int acao;
do {
  acao=menu();
  switch(acao){
    case 1: chegada(); break;
    case 2: consumo(); break;
    case 3: totDin+=saida(); break;
    case 4: listarProd(); break;
    case 5: listarCli(); break;
}
} while (acao!=0);
fechar();
}
int menu(){
int opcao;
printf("\nDinheiro de Hoje: %.2f",totDin);
printf("\n1: Chegada do cliente");
printf("\n2: Consumo de produto");
printf("\n3: Saida do cliente");
printf("\n4: Listagem de produtos");
printf("\n5: Listagem de Clientes");
printf("\n0: Fechar o restaurante");
printf("\nDigite a opcao (0 - 4): ");
scanf("%d",&opcao);
return opcao;
}
void chegada(){
structC p;
int n;
p=(structC) malloc(sizeof(struct cliente));
printf("\nDigite o codigo do cliente:\t");
scanf("%d",&n);
p->prod=NULL;
p->codC=n;
p->proxC=inicio;
inicio=p;
}
void consumo(){
structP z;
structC p;
int X;
int n;
printf("\nDigite o codigo do cliente:\t");
scanf("%d",&X);
p=inicio;
while(p->codC!=X){
  p=p->proxC;
}
z=(structP) malloc(sizeof(struct produto));
printf("\nDigite o codigo do produto:\t");
scanf("%d",&n);
printf("\nDigite o valor do produto:\t");
scanf("%f.2",&(z->valor));
z->codP=n;
z->proxP=p->prod;
p->prod=z;
}
/*
void saida() {
float somacliente;
structP z;
structP s;
structC p = inicio;
int X;
printf("\nDigite o codigo do cliente:\t");
scanf("%d",&X);
while(p->codC==!X){
  p=p->proxC;
}
z=p->prod;
if(p->prod!=NULL){
  while(z!=NULL){
    s=s->proxP;
    somacliente+=z->valor;
    z=z->proxP;
    free(s);
    s=p; //transferir o auxiliar que deleta para o presente elemento da lista
  }
}
else {
  printf("Nenhum produto foi pedido");
}
}
*/
float saida(){
  int X;
  structP z;
  structP x;
  structC p = inicio;
  structC q = NULL;
  float soma;
  printf("\nDigite o codigo do cliente:\t");
  scanf("%d",&X);
  while(p->codC!=X){
    q=p;
    p=p->proxC;
  }
  z=p->prod;
  while(z!=NULL){
    printf("\nCOD: %d PRECO: %.2f",z->codP,z->valor);
    soma+= z->valor;
    x=z->proxP;
    free(z);
    z=x;
  }
  printf("\nTotal: %.2f\n",soma);
  if (q) {
    q->proxC=p->proxC;
  } else {
    inicio=p->proxC;
  }
  free(p);
  return soma;
}
 
void listarCli(){
    structC p =inicio;
    printf("\n");
    while (p!=NULL){
        printf("\n%d",p->codC);
        p=p->proxC;
    }
    printf("\n");
}
void listarProd(){
  structP z;
  structC p = inicio;
  int X;
  printf("\n\nDigite o codigo do cliente: ");
  scanf("%d",&X);
  while(p->codC!=X){
    p=p->proxC;
  }
  z=p->prod;
  while(z!=NULL){
    printf("\nCOD: %d PRECO: %f",z->codP,z->valor);
    z=z->proxP;
  }
  printf("\nNão há mais produtos\n");
}
 
void fechar(){
  structP z;
  structP x;
  structC p = inicio;
  structC q = NULL;
  float soma;
  while(p){
    printf("\nCliente %d", p->codC);
    z=p->prod;
    while(z!=NULL){
      printf("\nCOD: %d PRECO: %.2f",z->codP,z->valor);
      soma+= z->valor;
      x=z->proxP;
      free(z);
      z=x;
    }
    printf("\nTotal: %.2f\n",soma);
    totDin+=soma;
    soma =0;
    q=p->proxC;
    free(p);
    p=q;
  }
  printf("\nTOTAL DO DIA: %.2f\n",totDin);
}