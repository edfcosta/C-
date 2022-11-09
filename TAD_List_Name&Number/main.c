#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listaCircular.h"

int main () {
    Lista *list0=NULL;
    list0=createList();
    char vet[30];
    int num=0, posi=0;
    for (;;) {
        int change=menu();
        if(change==11)
            break;
        switch (change){
        case 1:
            verifyClear(list0);
            break;
        case 2:
            printf("Name: ");
            readString(vet);
            printf("Number:");
            scanf("%d", &num);
            insertBeggining(list0, vet, num);
            break;
        case 3:
            printf("Name: ");
            readString(vet);
            printf("Number:");
            scanf("%d", &num);
            printf("Position:");
            scanf("%d", &posi);
            insertinPosition(list0, vet, num, posi);
            break;
        case 4:
            printf("Name: ");
            readString(vet);
            printf("Number:");
            scanf("%d", &num);
            insertEnd(list0, vet, num);
            break;
        case 5:
            removeBeggining(list0);
            break;
        case 6:
            printf("Position:");
            scanf("%d", &posi);
            removeinPosition(list0, posi);
            break;
        case 7:
            strSize(list0);
            break;
        case 8:
            biggestElement(list0);
            break;
        case 9:
            printf("print: \n1.element:");
            printf("\n2.struct:");
            scanf("%d", &posi);
            if (posi==1) {
                printf("Position:");
                scanf("%d", &posi);
                printerOnly(list0, posi);
                break;
            }
            if (posi==2){
                printer(list0);
                break;
            }
        case 10:
            BubbleSort(list0);
            break;
        }
    }
    finish(list0);
    return 0;
}
