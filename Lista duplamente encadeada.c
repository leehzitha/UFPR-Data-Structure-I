	#include <stdlib.h>
	
	typedef struct Bloco 	
	{
		int dado;
		struct Bloco *anterior, *prox;
	} Nodo;
	
	typedef struct Cabeca 
	{
		int total_elem;
		Nodo *inicio, *fim;
	} Cabecalho;
	
	Cabecalho listaDupla;
	
	int main() {
		int menu;
		int num;
		Nodo *N;
		
		do {
			printf("                 MENU                 \n");
			printf("-----------------------------------------\n\n");
			printf("1. Inicializa\n2. Insere no inicio\n3. Insere no fim\n4. Insere no meio\n5. Remove do inicio\n6. Remove do fim\n7. Remove um elemento qualquer\n8. Busca um elemento qualquer\n9. Imprime os elementos da lista\n10. Deleta a lista\n");
			printf("Opcao desejada: ");
			scanf("%d", &menu);
			system("cls");
			
			switch (menu){
			
				case 1:
					inicializa_lista();
					break;
					
				case 2:
					printf("Digite o numero que deseja inserir: ");
					scanf("%d", &num);
					insere_inicio(num);
					break;
					
				case 3:
					printf("Digite o numero que deseja inserir: ");
					scanf("%d", &num);
					insere_fim(num);
					break;
				
				case 4:
					printf("Digite o numero que deseja inserir: ");
					scanf("%d", &num);
					insere_meio(num);
					break;
				
				case 5:
					remove_inicio();
					break;
				
				case 6:
					remove_fim();
					break;
					
				case 7:
					printf("Digite o valor que deseja deletar: ");
					scanf("%d", &num);
					deleta_qualquer(num);
					break;
					
				case 8:
					printf("Digite o valor que deseja buscar: ");
					scanf("%d", &num);
					procura_qualquer(num);
					break;
					
				case 9:
					printa_lista();
					break;
					
				case 10:
					deleta_lista();
					break;
			}
	
		} while (menu != 0);
	
	}

Nodo *Cria_nodo()
{
	Nodo *p;
	p = (Nodo*)malloc(sizeof(Nodo));
	if(!p)
	{
		printf("Problema de alocação!");
		exit(0);
	}
	return p;
}
	
void inicializa_lista() {
	listaDupla.total_elem = 0;
	listaDupla.inicio = NULL;
	listaDupla.fim = NULL;
}
	
void insere_inicio(int dado) {
	Nodo *p;
	
	p = Cria_nodo();
	p->dado = dado;
	p->anterior = NULL;
	p->prox = listaDupla.inicio;
	
	if (listaDupla.inicio != NULL)
		listaDupla.inicio->anterior = p;
		
	listaDupla.inicio = p;
	listaDupla.total_elem += 1;
	
	if (listaDupla.fim == NULL)
		listaDupla.fim == p;
	
}
	
void insere_fim(int dado)
{
    Nodo *p = Cria_nodo();

    p->dado = dado;
    p->prox = NULL;
    p->anterior = listaDupla.fim;

    if (listaDupla.fim != NULL)
        listaDupla.fim->prox = p;
    else
        listaDupla.inicio = p;

    listaDupla.fim = p;
    listaDupla.total_elem++;
}
	
void insere_meio(int dado)
{
	if (listaDupla.inicio == NULL){
		insere_inicio(dado);
		return;
	}

	Nodo *aux = listaDupla.inicio;

	while (aux != NULL && aux->dado < dado){
		aux = aux->prox;
	}

	if (aux == listaDupla.inicio){
		insere_inicio(dado);
	}
	else if (aux == NULL){
		insere_fim(dado);
	}
	
	else{
		Nodo *p = Cria_nodo();
		p->dado = dado;

		p->prox = aux;
		p->anterior = aux->anterior;

		aux->anterior->prox = p;
		aux->anterior = p;

		listaDupla.total_elem++;
	}
}
	
	void remove_inicio(){
		if (listaDupla.inicio == NULL){
			return;
		}
		
		Nodo *aux, *remov;
		
		remov = listaDupla.inicio;
		aux = listaDupla.inicio->prox;
		
		if (aux != NULL)
			aux->anterior = NULL;
		else {
			listaDupla.fim = NULL;
		}
		
		listaDupla.inicio = aux;
		listaDupla.total_elem -= 1;
		
		free(remov);
		
	}
	
		void remove_fim() 
		{
			if (listaDupla.fim == NULL)
			{
				return;
			}
			
			Nodo *aux, *remov;
			
			remov = listaDupla.fim;
			aux = listaDupla.fim->anterior;
			
			if (aux != NULL)
			{
				aux->prox = NULL;
			}
			else {
				listaDupla.inicio = NULL;
			}
			
			listaDupla.fim = aux;
			free(remov);
			listaDupla.total_elem -= 1;
			
		}
		
	void deleta_qualquer(int dado)
	{
		Nodo *aux;
		
		aux = listaDupla.inicio;
		
		if (aux == NULL)
		{
			return;
		}
		
		while (aux != NULL && aux->dado != dado)
		{
			aux = aux->prox;	
		}
		
		if(aux == NULL)
			return;
		else {
			if (aux->anterior == NULL)
				remove_inicio();
			else if (aux->prox == NULL)
				remove_fim();
			else 
			{
				aux->anterior->prox = aux->prox;
				aux->prox->anterior = aux->anterior;
				free(aux);
				listaDupla.total_elem -=1;
			}
		}	
	}
	
	void procura_qualquer(int dado)
	{
		Nodo *aux;
		int pos;
		
		pos = 0;
		
		aux = listaDupla.inicio;
		
			
		while (aux != NULL && aux->dado != dado)
		{
			aux = aux->prox;
			pos += 1;
		}
		
		if (aux == NULL)
			return;
			
		printf("Achei! posicao %d", pos);
	}
	
	void printa_lista() 
	{
		Nodo *aux;
		
		aux = listaDupla.inicio;
		
		while(aux != NULL)
		{
			printf("%d", aux->dado);
			aux = aux->prox;
		}
	}
	
	void deleta_lista()
	{
		while (listaDupla.inicio != NULL){
			remove_inicio();
		}
	}