#include <stdio.h>
#include <stdlib.h>

// struct do nó
typedef struct No 
{
	float data;
	int linha, coluna;
	struct No *prox;
	
} Nodo;

// struct para armazenar os dados das matrizes, facilita o acesso
typedef struct 
{
	Nodo *lista;
	int linhas;
	int colunas;
	
} Matriz;
	
int main(){
	int menu, a;
	
	Matriz matrizes[2]; // armazena as 2 matrizes iniciais
	printf(" -------- TRABALHO 1 - ESTRUTURAS DE DADOS I --------\n\n                   BEM-VINDO(A)!\n\n");
	for (int i = 0; i < 2; i++)
	{
		printf("          | INSERCAO DE MATRIZES ESPARSAS |\n\n");
		printf("\n * MATRIZ %d* \n\n", i+1);
		printf("DIMENSOES\n");
		printf("Altura: ");
		scanf("%d", &matrizes[i].linhas);
		printf("Largura: ");
		scanf("%d", &matrizes[i].colunas);
	
		// inicializa matriz
		inicializa_lista(&matrizes[i].lista);
		system("cls");
		
		// insere dados na matriz
		insere_dados(
			&matrizes[i].lista,
			matrizes[i].linhas,
			matrizes[i].colunas);
	}

	// printa as matrizes (com os zeros)
	printf("MATRIZES ADICIONADAS COM SUCESSO!\n\nMatriz 1: \n\n");
	printa_zero(matrizes[0].lista, matrizes[0].linhas, matrizes[0].colunas);
	printf("\n\nMatriz 2: \n\n");
	printa_zero(matrizes[1].lista, matrizes[1].linhas, matrizes[1].colunas);
	getchar();	
	
	do {	
		printf("\nMENU\n\n");
		printf("1 - Soma\n2 - Subtracao\n3 - Multiplicacao\n4 - Transposta\n5 - Diagonal principal\n6 - Alterar matriz\n0 - Encerrar\n\nOpcao desejada: ");
		scanf("%d", &menu);
		system("cls");
		
		switch(menu)
		{
			case 1:	
				printf("SOMA\n\n");
				soma_matrizes(&matrizes[0], &matrizes[1]);
				break;
				
			case 2:
				printf("SUBSTRACAO\n\n");
				subtrai_matrizes(&matrizes[0], &matrizes[1]);
				break;
			
			case 3:
				printf("MULTIPLICACAO\n\n");
				mult_matrizes(&matrizes[0].lista, &matrizes[1].lista, matrizes[0].linhas, matrizes[0].colunas, matrizes[1].linhas, matrizes[1].colunas);
				break;
			
			case 4: {
				printf("MATRIZ TRANSPOSTA\n\n");
				int op = option(matrizes);
				transposta(&matrizes[op-1].lista, matrizes[op-1].linhas, matrizes[op-1].colunas);
				break;
			}
			
			case 5: {
				printf("DIAGONAL PRINCIPAL\n\n");
				int op = option(matrizes);
				diagonal(&matrizes[op-1].lista, matrizes[op-1].linhas, matrizes[op-1].colunas);
				break;
			}
			
			case 6: {
				int op = option(matrizes);
				int linha, col;
				
				deleta_lista(&matrizes[op-1].lista);
				
				system("cls");
				printf("MATRIZ %d SELECIONADA\n\n", op);
				printf("DIMENSOES\n");
				printf("Altura: ");
				scanf("%d", &matrizes[op-1].linhas);
				printf("Largura: ");
				scanf("%d", &matrizes[op-1].colunas);
				
				insere_dados(
					&matrizes[op-1].lista ,
					matrizes[op-1].linhas,
					matrizes[op-1].colunas);
				
				printf("MATRIZ %d ALTERADA!\n\n", op);
				printa_zero(matrizes[op-1].lista, matrizes[op-1].linhas, matrizes[op-1].colunas);
				break;
			}
		}
		printf("\n\nEnter para continuar");
		getchar(); getchar();
		system("cls");
		
	} while (menu != 0);
}

Nodo * Cria_Nodo()
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

void inicializa_lista(Nodo **N)
{
	*N = NULL;
}

void insere_fim(Nodo **N, float dado, int linha, int coluna)
{
	Nodo *novo, *aux;
	
	novo = Cria_Nodo();
	
	novo->data = dado;
	novo->linha = linha;
	novo->coluna = coluna;
	novo->prox = NULL;
	
	if (*N == NULL)
		*N = novo;
	else {
		aux = *N;
		while(aux->prox != NULL)
			aux = aux->prox;
		aux->prox = novo;
	}
}

void insere_dados(Nodo **N, int linha, int coluna) 
{
	float value;
	
	for (int i = 0; i < linha; i++) {
		
		printf("INSIRA OS VALORES (LINHA X COLUNA)\n\n");
		
		for (int j = 0; j < coluna; j ++) {
			
			printf("Linha %d coluna %d: ", i+1, j+1);
			scanf("%f", &value);
			if (value == 0) 
				continue;
			insere_fim(N, value, i, j);
		}	
		system("cls");
	}
}

float busca_valor(Nodo *N, int linha, int coluna)
{
    while (N != NULL)
    {
        if (N->linha == linha && N->coluna == coluna)
            return N->data;

        N = N->prox;
    }

    return 0.00;
}

void printa_lista(Nodo **N)
{
	Nodo *aux;
	aux = *N;
	int linha, coluna;
	linha = aux->linha;
	
	while(aux != NULL)
	{
		if (aux->linha == linha)
			printf("%.2f ", aux->data);
		else 
			printf("\n%.2f ", aux->data);
			
		linha = aux->linha;
		aux = aux->prox;
	}
}

void printa_zero(Nodo *N, int linhas, int colunas)
{
	for (int i = 0; i < linhas ; i ++ )
	{
		printf("| ");
		for (int j = 0; j < colunas; j ++)
		{
			
			printf("%.2f ", busca_valor(N, i, j));
					
		}
		printf("|");
		printf("\n");
	}

}

void deleta_lista (Nodo **N)
{
	Nodo *aux =  *N;
	Nodo *prox;
	
	while (aux != NULL) {
		prox = aux->prox;
		free(aux);
		aux = prox;
		} 
		
	*N = NULL;
}

void subtrai_matrizes (Matriz *N1, Matriz *N2)
{
	// verifica a dimensão das matrizes
	if (N1->linhas != N2->linhas || N1->colunas != N2->colunas)
		return;
		
	printa_duas(N1, N2);
		
	// inicia a lista para armazenar a matriz resultado	
	Nodo *matriz3;
	inicializa_lista(&matriz3);
	
	int linha, col;
	float sub;
	
	Nodo *aux1, *aux2;
	
	sub = 0;

	for (int i = 0; i < N1->linhas; i ++) 
	{
		for (int j = 0; j < N1->colunas; j ++)
		{
			sub = 0;
			
			sub = busca_valor(N1->lista, i, j);
			sub -= busca_valor(N2->lista, i, j);

			if (sub != 0)
				insere_fim(&matriz3, sub, i, j);
		}
	}
	
	printa_zero(matriz3, N1->linhas, N1->colunas);
	deleta_lista(&matriz3);
//	return matriz3;
}

void soma_matrizes (Matriz *N1, Matriz *N2)
{
	// verifica a dimensão das matrizes
	if (N1->linhas != N2->linhas || N1->colunas != N2->colunas) 
	{
		printf("As duas matrizes precisam ter as mesmas dimensoes!");
		return;
	}
	
	// printa as matrizes para visualizar se o resultado está correto
	printa_duas(N1, N2);
	
	// inicia a lista para armazenar a matriz resultado
	Nodo *matriz3;
	inicializa_lista(&matriz3);
	
	float soma = 0;
	
	for (int i = 0; i < N1->linhas; i++)
	{
		for (int j = 0; j < N1->colunas; j++)
		{
			soma = busca_valor(N1->lista, i, j);
			soma += busca_valor(N2->lista, i, j);
		
			if (soma != 0)
				insere_fim(&matriz3, soma, i, j);
		}
	}

	printa_zero(matriz3, N1->linhas, N1->colunas);
	deleta_lista(&matriz3);
	
}

void mult_matrizes (Nodo **N1, Nodo **N2, int linha1, int col1, int linha2, int col2)
{
	Nodo *matriz3;
	inicializa_lista(&matriz3);
	Nodo *aux1, *aux2;
	
	aux1 = *N1;
	aux2 = *N2;
	float soma = 0;
	float result = 0;
	
	printf("MATRIZ 1\n\n");
	printa_zero(*N1, linha1, col1);
	printf("\n\nMATRIZ 2\n\n");
	printa_zero(*N2, linha2, col2);
	
	if (col1 != linha2){
		printf("Dimensoes invalidas!");
		return;
	}	
	
	for (int i = 0; i < linha1; i ++ )
	{
		for (int j = 0; j < col2; j++)
		{				
			soma = 0;
			for (int k = 0; k < col1; k++)
			{
				result = busca_valor(*N1, i, k);
				result *= busca_valor(*N2, k, j);
				soma += result;
			}
			
			if (soma != 0)
				insere_fim(&matriz3, soma, i, j);
			
		}
	}
	
	printf("\n\nRESULTADO\n\n");
	printa_zero(matriz3, linha1, col2);
	deleta_lista(&matriz3);
}

void transposta(Nodo **N1, int linha, int col)
{
	Nodo *aux, *matriz3;
	inicializa_lista(&matriz3);
	
	float data;
	
	for (int i = 0; i < linha; i ++) 
	{
		for (int j = 0; j < col; j++)
		{
			data = busca_valor(*N1, i, j);
			if (data != 0)
				insere_fim(&matriz3, data, j, i);
		}	
	}
	printf("\n\nMATRIZ TRANSPOSTA\n\n");
	printa_zero(matriz3, col, linha);
	deleta_lista(&matriz3);
}

void diagonal(Nodo **N, int linha, int col)
{
	if (linha != col)
	{
		printf("A matriz precisa ser quadrada!\n");
		return;
	}

	Nodo *aux;
	
	for (int i = 0; i < linha; i ++)
	{
		printf("%.2f ", busca_valor(*N, i, i));
	}

}

int option(Matriz *matrizes)
{
	int op;
	printf("MATRIZ 1:\n\n");
	printa_zero(matrizes[0].lista, matrizes[0].linhas, matrizes[0].colunas);
	printf("\nMATRIZ 2\n\n");
	printa_zero(matrizes[1].lista, matrizes[1].linhas, matrizes[1].colunas);
	printf("\n\nInsira a matriz desejada: ");
	scanf("%d", &op);
	return op;
}

void printa_duas(Matriz *N1, Matriz *N2)
{
	// printa as matrizes para visualizar se o resultado está correto
	printf("MATRIZ 1\n\n");
	printa_zero(N1->lista, N1->linhas, N1->colunas);
	printf("\n\nMATRIZ 2\n\n");
	printa_zero(N2->lista , N2->linhas, N2->colunas);
	printf("\n\n");
}
