#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listaCircular.h"

struct lista {
    char v[30];
    int x;
    struct lista *prox;
};

int menu(void){
    int val=0;
    do {
        printf("---- MENU:\n");
		printf("\t 1. verify list is clear\n");
		printf("\t 2. Insert at beggining\n");
		printf("\t 3. Insert in position\n");
		printf("\t 4. Insert at end\n");
		printf("\t 5. Remove at beggining\n");
		printf("\t 6. Remove in position\n");
		printf("\t 7. Size list\n");
		printf("\t 8. biggest element\n");
		printf("\t 9. Print list\n");
		printf("\t 10. Sort ascending\n");
		printf("\t 11. Exit\n");
		printf("-- Digite sua escolha: ");
		scanf("%d", &val);
    }while(val<0||val>12);
    getchar();
    return (val);
}

Lista *createList() {
    Lista *lista=NULL;
	lista=(Lista*) malloc (sizeof(Lista));
    lista->v[0]='\0';
    lista->x=-1;
    lista->prox=NULL;
    return lista;
}

void verifyClear(Lista *lista) {
    int cont=0;
    if (lista->v[0]==0)
        cont++;
    if(lista->x==-1)
        cont++;
    if(lista->prox==NULL)
        cont++;
    if(cont==3) {
        printf("\nLista Vazia\n\n");
    }else{
        printf("\nLista Ocupada\n\n");
    }
}

void *insertBeggining(Lista *lista, char *vet, int num) {
    Lista *a=NULL;
    a=createList();
    for (int i=0; i<30; i++){
        a->v[i]=vet[i];
    }
    a->x=num;
    a->prox = lista->prox;
	lista->prox = a;
}


void *insertinPosition(Lista *a, char *vet, int num, int posi){
    Lista *nova=NULL;
    nova=createList();
    for (int i=0; i<30; i++){
        nova->v[i]=vet[i];
    }
    nova->x=num;
    a=a->prox;
    for (int i=0; i<=posi; i++){
        if(a==NULL){
             printf("ERRO: POSITION DOES NOT EXIST");
             break;
        }
        if (i==posi){
            nova->prox=a->prox;
            a->prox=nova;
            nova->prox=a->prox->prox;
            a->prox=nova;
            break;
        }else
            a=a->prox;
    }
}

void *insertEnd(Lista *lista, char *vet, int num){
    Lista *a=NULL;
    a=createList();

    for (int i=0; i<30; i++){
        a->v[i]=vet[i];
    }
    a->x=num;
    for(lista=lista->prox; lista!=NULL;lista=lista->prox){
        if (lista->prox==NULL){
            lista->prox=a;
            a->prox=NULL;
            break;
        }
    }
}

void *removeBeggining(Lista *lista){
    if(lista==NULL) {
        return (0);
    }else{
        free (lista->prox);
        lista->prox=lista->prox->prox;
    }
}

void *removeinPosition(Lista *lista, int posi){
    for(int i=0; i<posi; i++) {
        if (i==posi-1){
            if(lista==NULL){
                printf("ERRO: POSITION DOES NOT EXIST");
            }else
                printf("\nElimined: [%s][%d]", lista->prox->v, lista->prox->x);
            free(lista);
            lista->prox=lista->prox->prox;

        }else {
            lista=lista->prox;
        }
    }
}

void *biggestElement(Lista *lista) {
    Lista *p=lista, *q=lista;
    Lista *aux0=NULL;
    int cont=0, aux2=0;
    int aux=strSize(lista);
    for (lista=lista; lista!=NULL; lista=lista->prox) {
        if(aux2==1)
            break;
        for (p=p->prox; p!=NULL; p=p->prox) {
            if (lista->prox->x > p->x){
                cont++;
                printf("\ncont %d ", cont);
            }
            if(cont==aux-1) {
                printf("\nBiggest element elimined: [%s][%d]\n",lista->prox->v, lista->prox->x);
                aux0 = lista->prox;
                lista->prox=NULL;
                free(lista->prox);
                lista->prox=aux0->prox;
                free (aux0);
                aux2=1;
                break;
            }
        }
        cont=0;
        p=q;
    }
    p=NULL;
    free(p);
    q=NULL;
    free (q);
}

void printerOnly(Lista* lista, int posi){
    int i=0;
    for (lista=lista->prox; lista!=NULL; lista=lista->prox) {
        if(i==posi){
            printf("\n[%s], [%d]", lista->v, lista->x);
            printf("\n\n");
            break;
        }else
            i++;
    }
}

void printer(Lista *lista) {
    Lista *p;
    for (p=lista->prox; p!=NULL; p=p->prox) {
        printf("\n[%s], [%d]", p->v, p->x);
    }
    printf("\n\n");
    free(p);
}

void BubbleSort(Lista *lista) {
    int size = strSize(lista);
    int dealer=0;
    char a[30];
    Lista *aux, *p=lista->prox;
    aux=(Lista*) malloc ((size-1) * sizeof(Lista));
    for (int i=0; i<size; i++) {
        aux[i].x = p->x;
        for (int j=0; j<30; j++)
            aux[i].v[j] = p->v[j];
        p=p->prox;
    }

    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            if(aux[i].x < aux[j].x) {
                dealer=aux[i].x;
                aux[i].x=aux[j].x;
                aux[j].x=dealer;
                for(int k=0; k<30; k++){
                    a[k]=aux[i].v[k];
                    aux[i].v[k]=aux[j].v[k];
                    aux[j].v[k]=a[k];
                }
            }
        }
    }
    for (int i=0; i<size; i++) {
        printf ("[%s][%d]\n", aux[i].v, aux[i].x);
    }
    p=NULL;
    free(p);
    aux=NULL;
    free(aux);
}
int strSize(Lista *lista){
    int cont=0;
    Lista *p;
    for(p=lista->prox; p!=NULL;p=p->prox){
        cont++;
    }
    printf("\n--Circular struct size: %d\n", cont);
    return (cont);
    free (p);
}

int returnInt(Lista *lista){
    if(lista==NULL){
        printf("ELEMENT NOT EXIST");
    }
    return (lista->x);
}


char *returnChar(Lista *lista) {
    char *p;
    if(lista==NULL){
        printf("ELEMENT NOT EXIST");
    }
    p= &lista->v;
    return (p);
    p=NULL;
    free(p);
}

void finish(Lista *lista){
    for(lista->prox; lista!=NULL; lista=lista->prox);
        free (lista);
    free(lista);
    if(lista==NULL)
        printf("\nclear\n");
}


void readString(char *vet) {
	int i=0;

    char c = getchar();
	do {
        vet[i++] = c;
		c = getchar();
	}while (c != '\n');
	vet[i++] = '\0';
}
