#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int menu = 0;
	char string[100];
	char string2[100];

	do {
		printf("             MENU\n");
		printf("-----------------------------\n");
		printf("1 - Copiar o conteudo da string\n");
		printf("2 - Comparar duas strings\n");
		printf("3 - Ver o tamanho da string\n\n");
		printf("Opcao desejada: ");
		scanf("%d", &menu);
		fflush(stdin);
				
		switch(menu) {
			case 1:
				
				printf("Digite a string: ");
				
				fgets(string, sizeof(string), stdin);
				string[strcspn(string, "\n")] = '\0';
				
				strcpy(string2, string);
				printf("String digitada: %s\n", string);
				printf("String copiada: %s\n", string2);
				break;
			case 2:
				printf("Digite a string 1: ");
				fgets(string, sizeof(string), stdin);
				
				printf("Digite a string 2: ");
				fgets(string2, sizeof(string2), stdin);
				
				string[strcspn(string, "\n")] = '\0';
				string2[strcspn(string2, "\n")] = '\0';
				
				if (!strcmp(string, string2)) {
					printf("Sao iguais!");
				}
				else {
					printf("Sao diferentes!");
				}
				break;
			case 3:
				printf("Digite a string: ");
				fgets(string, sizeof(string), stdin);
				string[strcspn(string, "\n")] = '\0';
				
				printf("Tamanho: %d caracteres", strlen(string));
				break;
				
			case 0: 
				printf("Ate mais");
				break;
				
			default:
				printf("Opcao invalida!");
				break;
		}
		
		printf("\n\n");
		
		
	} while (menu != 0);
}