#include <stdio.h>
#include <string.h>

	int main(){
		char word[80];
		int count = 0;
		int size = 0;
		
		while (strcmp(word, "FIM") != 0) {
			printf("Digite a palavra desejada: ");
			scanf("%s", word);
			word[strcspn(word, "\n")] = '\0';
			size = strlen(word);
			
			printf("%d carateres!\n", size);
		}
	}