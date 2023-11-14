#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLIENTE_ARQ "./Data/clientes.txt"


int gerarNovoIDCliente() {
	FILE *arquivo = fopen(CLIENTE_ARQ, "rb");
	int numRegistros = 0;

	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo\n");
		return 0;
	}

	while (fgetc(arquivo) != EOF) {
		char c = fgetc(arquivo);
		if (c == '\n') {
			numRegistros++;
		}
	}
	fclose(arquivo);

	int novoID = numRegistros + 1;

	return novoID;
}

void cadastrarClienteArq(int idCliente, char nome[50], char telefone[15], char cpf[11], char email[50]) {
	FILE *arquivo = fopen(CLIENTE_ARQ, "a+");

	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo!");
		return;
	}

	fprintf(arquivo, "%i %s %s %s %s\n", idCliente, nome, telefone, cpf, email);

	fclose(arquivo);
}

void cadastrarCliente() {
	int idCliente;
	char nome[50];
	char telefone[15];
	char cpf[11];
	char email[50];
	
	getchar();
	printf("Digite o nome do cliente: ");
	scanf("%s", nome);
	getchar();

	printf("Digite o telefone do cliente: ");
	scanf("%s", telefone);
	getchar();

	printf("Digite o CPF do cliente: ");
	scanf("%s", cpf);
	getchar();

	printf("Digite o email do cliente: ");
	scanf("%s", email);
	getchar();

	idCliente = gerarNovoIDCliente();

	cadastrarClienteArq(idCliente, nome, telefone, cpf, email);
	
	printf("Cliente cadastrado com sucesso!\n");
	sleep(0.7);
}

void exibirClientes() {
	FILE *arquivo = fopen(CLIENTE_ARQ, "r");

	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo clientes.txt\n");
		return;
	}

	printf("\nClientes cadastrados:\n");
	char nome[50];
	char telefone[15];
	char cpf[11];
	char email[50];

	while (fscanf(arquivo, "%s %s %s %s", nome, telefone, cpf, email) != EOF) {
		printf("Nome: %s\n", nome);
		printf("Telefone: %s\n", telefone);
		printf("CPF: %s\n", cpf);
		printf("Email: %s\n\n", email);
	}
	printf("Aperte ENTER para continuar.\n");
	getchar();
	
	fclose(arquivo);
}

int menuCliente() {
	int escolha;

	do {
		system("cls");

		printf("CLIENTES");
		printf("\n\n");

		printf("[1] Cadastrar Cliente.\n");
		printf("[2] Exibir Clientes.\n");
		printf("[0] Retornar.\n\n");
		printf("Escolha: ");
		scanf("%d", &escolha);

		switch (escolha) {
			case 1:
				cadastrarCliente();
				break;
			case 2:
				exibirClientes();
				break;
			case 0:
				system("cls");
				break;
			default:
				printf("Opção inválida!!\n");
		}
	} while (escolha != 0);

}
