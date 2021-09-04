#include <stdio.h>
#include <stdlib.h>
 
struct no {
int info;
struct no * esq, * dir;
};
 
typedef struct no * noPtr;
 
int menu();
int menu2();
void inserir(noPtr *, int);
void remover(noPtr *, int);
void removermenor(noPtr *);
void menordomaior(noPtr*);
int buscar(noPtr, int);
noPtr maior(noPtr *);
void listarEmOrdem(noPtr);
void listarPreOrdem(noPtr);
void listarPosOrdem(noPtr);
int celulaVazia(noPtr);
 
int main() {
int op1, op2, x;
int achei;
noPtr raiz = NULL;
do{
  op1 = menu();
  switch(op1) {
    case 1: printf("\nDigite o elemento que voce deseja inserir:\t");
    scanf("%d",&x);
    inserir(&raiz, x); break;
    case 2: printf("\nDigite o elemento que voce deseja remover:\t");
    scanf("%d",&x);
    remover (&raiz, x); break;
    case 3: op2 = menu2();
    if (op2==1) listarEmOrdem(raiz);
    if (op2==2) listarPreOrdem(raiz);
    if (op2==3) listarPosOrdem(raiz); break;
    case 4: printf("\nDigite o elemento que voce deseja consultar:\t");
    scanf("%d",&x);
    achei=buscar(raiz, x);
    if (!achei)
    printf("Elemento nao encontrado\n"); break;
   case 5: removermenor(&raiz);break;
   case 6: menordomaior(&raiz);break;
  }
 } while(op1 != 7);
}
 
int menu(){
int opcao;
printf("\n\n\n---- Menu Principal ----\n\n\n1.Inserir no na arvore\n2.Remover no da arvore\n3.Listar todos os nos da arvore\n4.Buscar no\n5.Remover menor no\n6.Remover menor do maior\n7.Sair\nDigite uma opcao:\t");
scanf("%d",&opcao);
return opcao;
}
 
int menu2(){
int opcao;
printf("\n\nTipos de listagem:\n\t1.Em Ordem\n\t2.Pre Ordem\n\t3.Pos Ordem\n\nEscolha o tipo de listagem: ");
scanf("%d",&opcao);
return opcao;
}
 
void inserir(noPtr * p, int x)
{
if (celulaVazia(*p)){
  *p=(noPtr)malloc(sizeof(struct no));
  (*p)->info = x;
  (*p)->esq = NULL;
  (*p)->dir = NULL;
 }
else{
  if (x<((*p)->info))
  inserir(&((*p)->esq), x);
else
  if (x>((*p)->info))
  inserir(&((*p)->dir), x);
else
  printf("Elemento repetido");
 }
}
 
int celulaVazia(noPtr p){
if (p)
return 0;
else
return 1;
}
 
int buscar(noPtr p, int x){
int achei = 0;
if(celulaVazia(p))
  printf("\nArvore vazia ");
else{
  if (x==(p-> info)){
    printf("\nO elemento: %d foi encontrado na arvore \n",p->info);
    achei=1;
    }
  else {
    if (x<(p->info))
      achei=buscar((p->esq), x);
    else
      achei=buscar((p->dir), x);
 }
return achei;
}
}

 
void remover(noPtr *p, int x){
noPtr aux;
if (celulaVazia(*p))
  printf("\nArvore vazia");
else {
  if (x == ((*p)->info)){
    aux = *p;
    if (((*p)->esq) == NULL)
      *p = (*p)->dir;
    else
        if (((*p)->dir) == NULL)
          *p = (*p)->esq;
      else{
        aux = maior(&((*p)->esq));
        (*p)->info = aux->info;
       }
free(aux);
printf("\nO elemento foi removido\n");
}
else
if ((x < ((*p)->info)))
remover(&((*p)->esq), x);
else
remover(&((*p)->dir), x);
}
}
 
noPtr maior(noPtr *p){
noPtr t;
t = *p;
if ((t->dir) == NULL){
  *p = (*p)->esq;
return(t);
}
else
  return (maior(&((*p)->dir)));
}
 
void listarEmOrdem(noPtr p){
if (!celulaVazia(p)){
  listarEmOrdem(p->esq);
  printf("\t%d\t",p->info);
  listarEmOrdem(p->dir);
}else
  printf("celula vazia");
}
 
void listarPosOrdem(noPtr p){
if (!celulaVazia(p)){
listarPosOrdem(p->esq);
listarPosOrdem(p->dir);
printf("\t%d\t",p->info);
}else
  printf("celula vazia");
}
 
void listarPreOrdem(noPtr p){
if (!celulaVazia(p)){
printf("\t%d\t",p->info);
listarPreOrdem(p->esq);
listarPreOrdem(p->dir);
}else
  printf("celula vazia");
}

void removermenor(noPtr *p){
noPtr aux;
if (celulaVazia(*p))
  printf("\nArvore vazia");
else {
    while(((*p)->esq)!=NULL){
        *p=(*p)->esq;
    }
free(p);
printf("\nO elemento foi removido\n");
}
}
 
void menordomaior(noPtr *p){
if (celulaVazia(*p))
printf("\nArvore vazia");
else {
    *p=(*p)->dir;
    while(((*p)->esq)!=NULL){
        *p=(*p)->esq;
    }
    free(p);
    printf("\nO elemento foi removido\n");
}
}