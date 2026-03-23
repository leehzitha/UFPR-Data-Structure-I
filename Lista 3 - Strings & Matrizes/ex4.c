#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int table[17][2];
	int cargo = -1;
	int salario = 0;
	
	
	for (int i = 0; i < 17; i ++){
		printf("Digite o salario para o cargo %d: ", i + 1);
		scanf("%d", &salario);
		table[i][0] = i+1;
		table[i][1] = salario;
	}
		
	printf("Cargo         Salario\n\n");
	
	system("cls");
	
	do {
		printf("Digite o número do cargo que deseja consultar (ou 0 para encerrar): ");
		scanf("%d", &cargo);
		
		if (cargo == 0){
			return;
		}
		
		printf("\nCargo          Salario\n\n");
		printf(" %d              %d   ", cargo, table[cargo-1][1]); 
		
		getchar();
		getchar();
		
		system("cls");
	} while (cargo != 0);
	
}