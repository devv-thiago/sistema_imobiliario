#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

#define IMOVEL_ARQ "./Data/imoveis.txt"

int gerarNovoIDImovel() {
	FILE *arquivo = fopen(IMOVEL_ARQ, "rb");
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

int cadastrarImovelArq(int idImovel, char endereco[100], char tipo[50], char preco[20]) {
	FILE *arquivo = fopen(IMOVEL_ARQ, "a+");

	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo!");
		return 0;
	}

	fprintf(arquivo, "%i %s %s %s\n", idImovel, endereco, tipo, preco);

	return 1;
	fclose(arquivo);

}

void cadastrarImovel() {
	int idImovel;
	char endereco[100], tipo[50], preco[20];

	getchar();
	printf("Digite o tipo do imóvel: ");
	scanf("%s", tipo);
	getchar();
	printf("Digite o endereço do imóvel: ");
	scanf("%s", endereco);
	getchar();
	printf("Digite o valor do imóvel: ");
	scanf("%s", preco);
	getchar();

	idImovel = gerarNovoIDImovel();

	int imovelCadastrado = cadastrarImovelArq(idImovel, endereco, tipo, preco);

	if (imovelCadastrado == 1) {
		printf("Imóvel cadastrado com sucesso!\n");
	} else {
		printf("Erro ao cadastrar imóvel!\n");
	}
}

void listarImoveis() {
	FILE *arquivo = fopen(IMOVEL_ARQ, "r");

	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo %s\n", IMOVEL_ARQ);
		return;
	}

	printf("\nLista de Imóveis:\n");
	printf("ID\tEndereço\tTipo\tPreço\n");

	while (!feof(arquivo)) {
		int idImovel;
		char endereco[100], tipo[50], preco[20];

		fscanf(arquivo, "%i %s %s %s", &idImovel, endereco, tipo, preco);
		if (!feof(arquivo)) {
			printf("%i\t%s\t%s\t%s\n", idImovel, endereco, tipo, preco);
		}
	}
	printf("Aperte ENTER para continuar.\n");
	getchar();

	fclose(arquivo);
}

void MenuImovel() {
	int opcao;

	do {
		system("cls");
		printf("IMÓVEIS");
		printf("\n\n");

		printf("[1]Cadastrar imóveis.\n");
		printf("[2]Listar imóveis.\n");
		printf("[0]Retornar.\n\n");
		printf("Escolha: ");
		scanf("%d", &opcao);

		switch (opcao) {
			case 1:
				system("cls");
				printf("IMÓVEIS");
				printf("\n\n");
				cadastrarImovel();
				sleep(1);
				break;
			case 2:
				system("cls");
				printf("IMÓVEIS");
				printf("\n\n");
				listarImoveis();
				break;
			case 0:
				system("cls");
				break;
			default:
				printf("Opção inválida!!\n");
		}
	} while (opcao != 0);
}
