#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


void selectionSort(int arr[], int n) {
	int i, j, aux;

	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				aux = arr[j];
				arr[j] = arr[i];
				arr[i] = aux;
			}
		}
	}

	for (i = 0; i < n; i++) {
		printf("%i ", arr[i]);
	}
}

struct Usuario {
	char username[30];
	char password[30];
};

int  binarySearch(int arr[], int valorBusca) {
	int esquerda = arr[0];
	int direita = sizeof(arr) - 1;

	while (esquerda <= direita) {
		int meio = (esquerda + direita) / 2;
		if (arr[meio] == valorBusca) {
			return valorBusca;
		} else {
			if (arr[meio] < valorBusca) {
				esquerda = meio + 1;
			} else {
				direita = meio - 1;
			}
		}
	}
}

int main() {
	char usuario[30];
	char senha[30];
	char confirmacaoSenha[30];
	int escolha;
	struct Usuario userInformation;
	int array[30] = {5,4,3,2,1,10,9,8,7,6,50,40,30,20,10,100,90,80,70,60,500,400,300,200,100,1000,900,800,700,600};
	//int arr[30] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
	int arrayItem = binarySearch(arr, 80);
	printf("%i", arrayItem);
	
	// Algoritmo de ordenação do array
	selectionSort(array, 30);

	bool continua = true;
/*
	while (continua) {
		printf("Digite a opcao que deseja:\n1- Entrar na minha conta.\n2- Criar nova conta.\n3- Sair\nEscolha: ");
		scanf("%i", &escolha);

		switch (escolha) {
			case 1:

				break;
			case 2:
				printf("Digite seu nome de usuario: ");
				scanf("%s", usuario);
				strcpy(userInformation.username, usuario); // copia para o atributo da struct o que foi digitado
				do {
					printf("Crie sua senha: ");
					scanf("%29s", senha);

					printf("Confirme sua senha: ");
					scanf("%29s", confirmacaoSenha);

				} while (strcmp(senha, confirmacaoSenha) != 0);
				strcpy(userInformation.password, senha); // copia para o atributo da struct o que foi digitado
				printf("Usuario cadastrado com sucesso!!\n");
				//printf("Nome: %s -\nSenha: %s\n", userInformation.username, userInformation.password);
				break;

			case 3:
				continua = false;
				break;
		}
	}
*/
	return 0;
}
