#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No {
	int id;
	char nome[20];
	char origem[20];
	char destino[20];
	struct No *prox;
} Nodo;

typedef struct queue {
	int count;
	Nodo *start;
	Nodo *end;
} Queue;

Queue *decolagem;
Queue *pouso;


Nodo *create_nodo();
Nodo *set_plane();

void init_queue(Queue **N);
void add_plane(Queue *N, Nodo *plane);
Nodo*  authorize(Queue *N);
int get_count(Queue *N);
void get_planes(Queue *N);

int main(){
	printf("AEROPORTO\n\n");
	init_queue(&decolagem);
	init_queue(&pouso);
	
	int op = 0;
	int pista;
	
	do {
		
		printf("MENU\n---------------------------\n\n");
		printf("1 - Adicionar aviao\n2 - Decolar\n3 - Pousar\n4 - Visualizar avioes\n\nOpcao desejada: ");
		scanf("%d", &op);
		
		switch(op) {
			case 1:
				printf("\n1 - Decolagem\n2 - Pouso\n\nPista desejada: ");
				scanf("%d", &pista);
				
				Nodo *plane = set_plane();
				switch (pista)
				{
					case 1:
						add_plane(decolagem, plane);
						break;
					case 2:
						add_plane(pouso, plane);
						break;
					default:
						printf("Opção invalida!\n\n");
						printf("Pressione ENTER para continuar...");
						while (getchar() != '\n');
						getchar();
						break;
				}
				break;
				
			case 2:
				{
					printf("\nDECOLANDO...\n\n");
					Nodo *aux = authorize(decolagem);
					if (aux != NULL)
						add_plane(pouso, aux);
					break;	
				}
				
		
			case 3:
				printf("\nPOUSANDO...\n\n");
				authorize(pouso);
				break;
			
			case 4:
				printf("\n1 - Decolagem\n2 - Pouso\n\nPista desejada: ");
				scanf("%d", &pista);
				int qtde = 0;
				
				switch (pista){
					case 1:
						qtde = get_count(decolagem);
						printf("\nQUANTIDADE DE AVIOES: %d\n\n", qtde);
						get_planes(decolagem);	
						break;
						
					case 2:
						qtde = get_count(pouso);
						printf("\nQUANTIDADE DE AVIOES: %d\n", qtde);
						get_planes(pouso);
						break;	
				}
				break;
				
			case 0:
				printf("Finalizando...");
				break;
				
			default:
				printf("Opcao invalida!");	
				printf("Pressione ENTER para continuar...");
				while (getchar() != '\n');
				getchar();
				break;		
		}
		system("cls");
	} while (op != 0);
	
}

Nodo *create_nodo()
{
	Nodo *p;
	p = (Nodo *)malloc(sizeof(Nodo));
	if(!p)
	{
		printf("Problema de alocação");
		exit(0);
	}
	return p;
}

void init_queue(Queue **N)
{
    *N = malloc(sizeof(Queue));

    (*N)->count = 0;
    (*N)->start = NULL;
    (*N)->end = NULL;
}

Nodo *set_plane()
{
	Nodo *plane = create_nodo();
	
	printf("\nInsira o id: ");
	scanf("%d", &plane->id);
	
	getchar();
	
	printf("Insira o nome: ");
	fgets(plane->nome, sizeof(plane->nome), stdin);
	
	printf("Insira a origem: ");
	fgets(plane->origem, sizeof(plane->origem), stdin);
	
	printf("Insira o destino: ");
	fgets(plane->destino, sizeof(plane->destino), stdin);
	
	plane->prox = NULL;
	return plane;
	
}

void add_plane(Queue *N, Nodo *plane)
{
	plane->prox = NULL;
	
	if (N->start == NULL)
	{
		N->start = plane;
		N->end = plane;
		N->count ++;
		return;
	}
	
	N->end->prox = plane;
	N->end = plane;
	N->count++;
	
}

Nodo* authorize(Queue *N)
{
	Nodo *aux = N->start;
	
	if (N->start == NULL)
	{
		printf("Lista vazia!\n");
		printf("Pressione ENTER para continuar...");
		while (getchar() != '\n');
		getchar();
		return NULL;
	}	

	printf("AVIAO %d\n\n", N->start->id);
	printf("NOME:    %19s", N->start->nome);
	printf("ORIGEM:  %19s", N->start->origem);
	printf("DESTINO: %19s\n", N->start->destino);
		
	N->start = N->start->prox;
	
	if (N->start == NULL)
	{
		N->start = NULL;
		N->end = NULL;
	}

	N->count--;
	
	printf("Pressione ENTER para continuar...");
	while (getchar() != '\n');
	getchar();
	
	aux->prox = NULL;
	char origem[20];

	return aux;
}

int get_count(Queue *N)
{
	return N->count;
}

void get_planes(Queue *N)
{
	Nodo *aux = N->start;
	
	while (aux != NULL)
	{
		printf("\nAVIAO %d\n\n", aux->id);
		printf("NOME:    %19s", aux->nome);
		printf("ORIGEM:  %19s", aux->origem);
		printf("DESTINO: %19s", aux->destino);
		printf("\n--------------------------------\n");
		aux = aux->prox;
	}
	
	printf("Pressione ENTER para continuar...");
	while (getchar() != '\n');
	getchar();
}

