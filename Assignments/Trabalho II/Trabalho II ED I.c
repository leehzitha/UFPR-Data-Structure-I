#include <stdio.h>
#define FREE 0
#define WALL 1
#define VISITED 2
#define DEAD_END 3
#define SIZE 30
#define NOW 4

int tabuleiro[SIZE][SIZE];

typedef struct No {
	int pos;
	struct No *prox;
} Nodo;

Nodo *topo;

int main() {
	generate_maze(tabuleiro);
	print_maze(tabuleiro);
	move(tabuleiro, &topo);
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

void move(int maze[SIZE][SIZE], Nodo **N)
{
	int row, col, pos;
	row = 2;
	col = 2; 9
	int dr[4] = {1, 0, -1, 0};
	int dc[4] = {0, 1, 0, -1};
	int found = 0;
		
	while(row != 28 || col != 29) // verificar se é nulo primeiro
	{	
		int pos = row * 100 + col;
		
		for (int i = 0; i < 4; i++)
		{
			if(maze[row + dr[i]][col + dc[i]] == FREE)
			{
				push(N, pos);
				maze[row][col] = VISITED;
				col += dc[i];
				row += dr[i];
				found = 1;
				maze[row][col] = NOW;
				break;
			}
		}
		system("cls");
		print_maze(maze);
		
		if(!found)
		{
			maze[row][col] = DEAD_END;
			
			if(*N == NULL)
			{
				printf("Sem saida!");
				return;
			}
			pos = pop(N);
			row = pos / 100;
			col = pos % 100;
			maze[row][col] = NOW;
		}
		
		found = 0;
		Sleep(250);
	}	
		
}
void generate_maze(int maze[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (j == 0 || j == 29 || i == 0 || i == 29)
			{
				maze[i][j] = WALL;
				continue;
			}
			
			if(rand() % 100 < 30)
			{
				maze[i][j] = WALL;	
			}
			else
			{
				maze[i][j] = FREE;
			}
		}
	}	
	init_stack(&topo);
	maze[2][2] = NOW;
	maze[28][29] = FREE;
}

void print_maze(int maze[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			switch (maze[i][j])
			{
				case WALL:
					printf("%c%c", 219, 219);
					break;
				case FREE:
					printf("  ");
					break;
				case VISITED:
					printf("..");
					break;
				case DEAD_END:
					printf("XX");
					break;
				case NOW:
					printf("oo");
					break;
			}
		}	
		printf("\n");
	}	
} 

void init_stack(Nodo **N)
{
	*N = NULL;
}

void push(Nodo **N, int pos)
{
	Nodo *novo;
	novo = create_nodo();
	novo->pos = pos;
	novo->prox = *N;
	*N = novo;
}

int pop(Nodo **N)
{
	Nodo *aux;
	if (*N == NULL)
		return;

	aux = *N;
	int pos = aux->pos;
	*N = aux->prox;
	free(aux);
	
	return pos;
}