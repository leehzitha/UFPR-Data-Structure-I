#include <stdio.h>
#define MAX_VETOR 5

typedef struct Vetor
{
 	int dados[MAX_VETOR];
 	int inicio, fim;
} Tipo_Vetor; 


int main(){
	int menu;
	int num;
	Tipo_Vetor *V;
	
	*V = (Tipo_Vetor*)malloc(MAX_VETOR * sizeof(Tipo_Vetor));
	
	printf("                 MENU                 \n");
	printf("-----------------------------------------\n\n");
	printf("1. Inicializa\n2. Insere no inicio\n3. Insere no fim\n4. Insere no meio\n5. Remove do inicio\n6. Remove do fim\n7. Remove um elemento qualquer\n8. Busca um elemento qualquer\n9. Imprime os elementos da lista\n10. Deleta a lista");
	printf("Opcao desejada: ");
	scanf("%d", &menu);
	
	switch (menu){
		case 1:
			inicializa_lista(*V);
			default;
			
		case 2:
			printf("Digite o numero que deseja inserir: ");
			scanf("%d", &num);
			insere_inicio(*V, num);
			default;
			
		case 3:
			printf("Digite o numero que deseja inserir: ");
			scanf("%d", &num);
			insere_vetor(*V, num);
			default;
		
		case 4:
			printf("Digite o numero que deseja inserir: ");
			scanf("%d", &num);
			insere_meio(*V, num);
			default;
		
		case 5:
			remove_inicio(*V);
			default;
		
		case 6:
			remove_fim(*V);
			default;
			
	}
}



void inicializa_lista(Tipo_Vetor *V){
	*V->inicio = 0;
	*V->fim = 0;
}

int insere_vetor(Tipo_Vetor *V, int dado)
{
	if(V->fim < MAX_VETOR)
	{
		V->dados[V->fim] = dado;
		(V->fim)++;
		return 1;
	}
	Else
	return 0;
} 

int insere_inicio(Tipo_vetor *V, int dado)
{
	
	if(V->fim < MAX_VETOR)
	{
		for(int i = V->fim; i > 0; i--)
		{
			V->dados[i] = V->dados[i-1];
		}
		V->dados[0] = dado;
		(V->fim)++;
		
		return 1;
	}
	return 0;
}

int insere_meio(Tipo_vetor *V, int dado)
{
	if(V->fim < MAX_VETOR)
	{
	 	if(V->fim == 0)
	 	{
	 		insere_inicio(*V, dado);
	 		return 1;
		}
		
	
		while (V->dados[i] > dado)
		{
			i++;
		}
		
		for (int j = V->fim; j > i; j--)
		{
			V->dados[j] = V->dados[j-1];
		}
		
		V->dados[i] = dado;
				
		V->fim ++;
		
	}
}

int remove_inicio(Tipo_vetor *V)
{
	if (V->fim == 0){
		return 0;
	}
	
	for (int i = 0; i < V->fim-1; i++)
		V->dados[i] = V->dados[i+1];
	
	(V->fim)--;
	
}

int remove_fim(Tipo_vetor *V)
{
	if (V->fim == 0){
		return 0;
	}
	
	V->dados[V->fim-1] = 0;
	(V->fim)--;
}