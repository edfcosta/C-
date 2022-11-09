typedef struct lista Lista;

int menu(void);
Lista *createList();
void verifyClear(Lista *lista);
void *insertBeggining(Lista *lista, char *vet, int num);
void *insertinPosition(Lista *a, char *vet, int num, int posi);
void *insertEnd(Lista *lista, char *vet, int num);
void *removeBeggining(Lista *lista);
void *removeinPosition(Lista *lista, int posi);
void *biggestElement(Lista *lista);
int strSize(Lista *lista);
void printerOnly(Lista* lista, int posi);
void printer(Lista *lista);
void BubbleSort(Lista *lista);
int returnInt(Lista *lista);
char *returnChar(Lista *lista);
void finish(Lista *lista);
void readString(char *vet); // função usada para ler string
