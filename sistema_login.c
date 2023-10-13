#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <unistd.h>
#define ARQ_USUARIOS "Users.txt"

int addUserFile(char username[30], char password[30]) {
	FILE *file = fopen(ARQ_USUARIOS, "a+");

	// validação de erro no arquivo
	if (file == NULL) {
		return 0;
	} else {
		// grava informações no arquivo
		fprintf(file, "%s %s\n", username, password);
		fclose(file); // movido para fora do bloco else
		return 1;
	}
}

int validaUsuario() {
	FILE *userFile = fopen(ARQ_USUARIOS, "r");
	char usuario[30];
	char senha[30];

	printf("Digite seu nome de usuario: ");
	scanf("%29s", usuario);
	getchar();

	printf("Digite sua senha: ");
	scanf("%29s", senha);
	getchar();

	while(!feof(userFile)) {
		char usuarioFile[30];
		char senhaFile[30];

		fscanf(userFile, "%s %s", usuarioFile, senhaFile);

		if (strcmp(usuarioFile, usuario) == 0 && strcmp(senhaFile, senha) == 0) {
			fclose(userFile);
			return 1;
		}
	}
	fclose(userFile);
	return 0;
}

void registroUsuario() {
	FILE *userFile = fopen(ARQ_USUARIOS, "a+");
	char usuario[30];
	char senha[30];
	char confirmacaoSenha[30];

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

	int validacaoUsuario = addUserFile(usuario, senha); // função para adicionar usuários no arquivo

	if (validacaoUsuario == 1) {
		printf("Usuario cadastrado com sucesso!!\n");
		printf("Agora voce pode logar no sistema!!\n");
	} else {
		printf("Erro ao cadastrar usuario!!\n");
	}

	sleep(1);
	system("cls");
}

void Menu(int menu) {
	switch(menu) {
		case 1:
			printf("opcao 1");
			break;
		case 2:
			printf("opcao 2");
			break;
		case 3:
			printf("opcao 3");
			break;
		default:
			printf("Opcao invalida");
			break;
	}
}
void menuLogin() {
	bool continua = true;
	int usuarioEncontrado;// recebe um valor caso usuario seja encontrado
	int escolha;

	while (continua) {
		printf("Digite a opcao que deseja:\n1- Entrar na minha conta.\n2- Criar nova conta.\n3- Sair\nEscolha: ");
		scanf("%i", &escolha);

		switch (escolha) {
			case 1:
				usuarioEncontrado = validaUsuario(); 
				if (usuarioEncontrado == 1) {
					printf("Usuario encontrado, entrando no sistema.\n");
					sleep(3);
					system("cls");
				} else {
					printf("Usuario nao encontrado.\n");
					sleep(3);
					system("cls");
				}
				break;
			case 2:
				registroUsuario();
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
}

int main() {

	menuLogin();

	return 0;
}
