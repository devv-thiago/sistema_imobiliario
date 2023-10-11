#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <unistd.h>

/*
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
*/

int addUserFile(FILE *file, char username[30], char password[30]) {
	file = fopen("Users.txt", "a+");

	// validação de erro no arquivo
	if (file == NULL) {
		return 0;
	} else {
		// grava informações no arquivo
		fprintf(file, "%s;%s\n", username, password);
		fclose(file); // movido para fora do bloco else
		return 1;
	}
}

int main() {
	int usuarioEncontrado = 0;
	char usuario[30];
	char senha[30];
	char confirmacaoSenha[30];
	int escolha;
	FILE * userFile;

	bool continua = true;

	while (continua) {
		printf("Digite a opcao que deseja:\n1- Entrar na minha conta.\n2- Criar nova conta.\n3- Sair\nEscolha: ");
		scanf("%i", &escolha);

		switch (escolha) {
			case 1:

				userFile = fopen("Users.txt", "a+");
				printf("Digite seu nome de usuario: ");
				scanf("%29s", usuario);
				getchar();

				printf("Digite sua senha: ");
				scanf("%29s", senha);
				getchar();

				while(!feof(userFile)) {
					char usuarioFile[30];
					char senhaFile[30];
					fscanf(userFile, "%s;%s", usuarioFile, senhaFile);
					if (strcmp(usuarioFile, usuario) == 0 && strcmp(senhaFile, senha) == 0) {
						usuarioEncontrado = 1;
					} else {
						usuarioEncontrado = 0;
					}
				}
				if (usuarioEncontrado = 1) {
					printf("Usuario encontrado, entrando no sistema.");
					sleep(3);
					system("cls");
				} else {
					printf("Usuario nao encontrado.");
					sleep(3);
					system("cls");
				}
				fclose(userFile);
				break;
			case 2:
				printf("Digite seu nome de usuario: ");
				scanf("%29s", usuario);
				do {
					printf("Crie sua senha: ");
					scanf("%29s", senha);

					printf("Confirme sua senha: ");
					scanf("%29s", confirmacaoSenha);

					if (strcmp(senha, confirmacaoSenha) != 0) {
						printf("As senhas nao coincidem. Tente novamente.\n\n");
					} else if (strlen(senha) < 8) {
						printf("A senha deve ter pelo menos 8 caracteres. Tente novamente.\n\n");
					}
				} while (strcmp(senha, confirmacaoSenha) != 0 || strlen(senha) < 8);
				int validacaoUsuario = addUserFile(userFile, usuario, senha);
				if (validacaoUsuario == 1) {
					printf("Usuario cadastrado com sucesso!!\n");
					printf("Agora voce pode logar no sistema!!\n");
				} else {
					printf("Erro ao cadastrar usuario!!\n");
				}
				// Limpa console
				sleep(1);
				system("cls");
				break;
			case 3:
				continua = false;
				break;
			default:
				printf("Digite uma opcao valida\n");
				sleep(1.5);
				system("cls");
		}
	}

	return 0;
}
