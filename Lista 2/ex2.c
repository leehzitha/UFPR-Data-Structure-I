#include <stdio.h>

int main(){
	int vet[10] = {1, 2, 10, 20, 40, 32, 51, 22, 54, 0};
	int input = 0;
	int menor = 0;
	int maior = 100;
	int soma = 0;
	int somaP = 0
	int somaI = 0;
	
	
	for (int i = 0; i < 10; i++){
		// maior e menor elemento
		if (vet[i] > maior) maior = vet[i];
		if (vet[i] < menor) menor = vet[i];
		
		soma += vet[i];
		// par ou impar		
		if (vet % 2 == 0) {
			printf("Elemento %d (%d) é par!", i, vet[i]);
			somaP += vet[i];
		}
		else {
			printf("Elemento %d (%d) e impar!", i, vet[i]);
			somaI += vet[i];	
		} 
		
			
		
		if (vet[i] == input) {
			printf("Numero %d encontrado na posicao %d!", input, i);
			return 0;	
		}

	}
	printf("Numero nao encontrado!\n");
	printf("Soma: %d\n", soma)
	printf("Soma dos pares: %d\n", somaP);
	printf("Soma dos impares: %d\n", somaI);
	
	
}

void Menu(){
	int opcao = 0;
	
	printf("MENO\n");
	printf("---------------------------\n\n");
	
	printf("1 - Verificar numero\n2 - Maior e menor\n3 - Par e impar\n4 - Soma total\n5 - Soma dos positivos\n6 - Soma dos negativos\n ");
	printf("Opcao desejada: " );
	
	scanf("%d", &opcao);
	
	switch (opcao){
		case 1:
			printf("Digite o numero que deseja consultar: ");
			scanf("%d", &input);
			for (int i = 0; i < 10) {
				if ()
			}
			
	}
}