#include <stdio.h>
#include <stdlib.h>

// TRABALHO 1 - ESTRUTURAS DE DADOS I
// EQUIPE: Gabriel Vieira Cascaes & Letícia Aparecida de Oliveira Burlinski
// TURMA: 2026/1

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

// declaração de funcoes
// nas funcoes de soma e subtração, usamos a struct matriz como parâmetro porque consideramos ser uma prática interessante.
// devido às especificações do trabalho e a necessidade que sentimos de praticar ponteiros de maneira mais semelhante aos exercícios em sala,
// mantivemos as outras funções usando apenas a lista como parâmetro.

Nodo *Cria_Nodo();
void inicializa_lista(Nodo **N);
void insere_fim(Nodo **N, float dado, int linha, int coluna);
void insere_dados(Nodo **N, int linha, int coluna);
float busca_valor(Nodo *N, int linha, int coluna);
void printa_lista(Nodo **N);
void printa_zero(Nodo *N, int linhas, int colunas);
void deleta_lista(Nodo **N);
void subtrai_matrizes(Matriz *N1, Matriz *N2);
void soma_matrizes(Matriz *N1, Matriz *N2);
void mult_matrizes(Nodo **N1, Nodo **N2, int linha1, int col1, int linha2, int col2);
void transposta(Nodo **N1, int linha, int col);
void diagonal(Nodo **N, int linha, int col);
int option(Matriz *matrizes);
void printa_duas(Matriz *N1, Matriz *N2);

int main(){
	int menu;
	Matriz matrizes[2]; // armazena as 2 matrizes iniciais

	printf(" -------- TRABALHO 1 - ESTRUTURAS DE DADOS I --------\n\n                   BEM-VINDO(A)!\n\n");

	// extrai as dimensões das matrizes
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

// criação do nó
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

// inicializacao da lista linear encadeada
void inicializa_lista(Nodo **N)
{
	*N = NULL;
}

// mesma funcao dos exercicios, sem misterio
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

// obtem os valores da matriz conforme as dimensões informadas pelo usuário
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

// verifica se a posicao LxC de uma matriz existe na lista encadeada (é != 0)
float busca_valor(Nodo *N, int linha, int coluna)
{
	while (N != NULL)
	{
		if (N->linha == linha && N->coluna == coluna)
			return N->data; // se encontrar, retorna o valor
		N = N->prox; // procura até que a lista acabe
	}

	return 0.00;
}

// imprime a lista real, sem os zeros
void printa_lista(Nodo **N)
{
	Nodo *aux;
	aux = *N;
	int linha, coluna;

	if (aux == NULL)
		return;

	linha = aux->linha;
	
	while(aux != NULL)
	{
		if (aux->linha == linha)
			printf("%.2f ", aux->data); // se a linha do nó for a mesma que a do nó anterior, printa o elemento na mesma linha
		else 
			printf("\n%.2f ", aux->data); // caso contrário, quebra a linha
			
		linha = aux->linha;
		aux = aux->prox;
	}
}

// imprime a matriz com os zeros
void printa_zero(Nodo *N, int linhas, int colunas)
{
	for (int i = 0; i < linhas ; i ++ )
	{
		printf("| ");
		for (int j = 0; j < colunas; j ++)
		{
			printf("%.2f ", busca_valor(N, i, j));			
		}
		printf("|\n");
	}

}

// libera espaço da memoria
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
	{
		printf("As matrizes precisam ter a mesma dimensao!");
		return;
	}
		
	printa_duas(N1, N2);
		
	// inicia a lista para armazenar a matriz resultado	
	Nodo *matriz3;
	inicializa_lista(&matriz3);
	
	float sub;

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
	
	// pra cada linha da matriz 1
	for (int i = 0; i < linha1; i ++ )
	{
		// pra cada coluna da matriz 2
		for (int j = 0; j < col2; j++)
		{				
			soma = 0;
			// percorre os elementos das matrizes na linha x col correspondente
			for (int k = 0; k < col1; k++)
			{
				// multiplica os pares
				result = busca_valor(*N1, i, k);
				result *= busca_valor(*N2, k, j);
				// soma pra obter a posicao
				soma += result;
			}
			// só adiciona na matriz 3 se o valor NAO for 0!!!
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

	for (int i = 0; i < linha; i ++)
	{
		printf("%.2f ", busca_valor(*N, i, i));
	}

}

// no caso de funcoes que necessitam de apenas uma matriz, exibe as matrizes alocadas e pergunta ao usuário qual delas deseja selecionar
int option(Matriz *matrizes)
{
	int op;

	printa_duas(&matrizes[0], &matrizes[1]);
	while (op < 1 || op > 2)
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
