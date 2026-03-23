#include <stdio.h>
#include <string.h>

int main(){
	char frase[100];
	
	printf("Digite a frase que deseja codificar (limite de 100 caracteres): ");
	fgets(frase, sizeof(frase), stdin);
	frase[strcspn(frase, "\n")] = '\0';
	
	char *palavra;
	int counter = 0;
	
	palavra = strtok(frase, " ");
	
	while (palavra != NULL){
		char new_word[50];
		
		strcpy(new_word, &palavra[1]);
		
		int size = strlen(new_word);
		
		new_word[size] = palavra[0];
		new_word[size+1] = 'a';
		new_word[size + 2] = '/0';
		
		printf("%s ", new_word);
		
		palavra = strtok(NULL, " ");
		
	}
	
}