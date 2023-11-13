#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define IMOVEL_ARQ "./Data/imoveis.txt"

struct Imovel {
	int id;
	char tipo[50];
	char endereco[100];
	char cliente[100];
	float preco;
};

int cadastrarImovelArq(int idImovel, char endereco[100], char tipo[50], float preco) {
	FILE *arquivo = fopen(IMOVEL_ARQ, "a+");
	if(arquivo == NULL) {
		printf("Erro ao abrir o arquivo!");
		return 0;
	} else {
		fprintf(arquivo, "%i %s %s %f", idImovel, endereco, tipo, preco);
		return 1;
	}

	fclose(arquivo);
}

void cadastrarImovel(struct Imovel imoveis[], int *totalImoveis) {
	if (*totalImoveis < 100) {
		struct Imovel novoImovel;
		novoImovel.id = (*totalImoveis) + 1;
		printf("Digite o tipo do imóvel: ");
		scanf("%s", novoImovel.tipo);
		printf("Digite o endereço do imóvel: ");
		scanf(" %[^\n]", novoImovel.endereco);
		printf("Digite o código do cliente: ");
		scanf(" %[^\n]", novoImovel.cliente);
		printf("Digite o preço do imóvel: ");
		scanf("%lf", &novoImovel.preco);

		int imovelCadastrado = cadastrarImovelArq(novoImovel.id, novoImovel.endereco, novoImovel.tipo, novoImovel.preco);
		if (imovelCadastrado == 1) {
			printf("Imóvel cadastrado com sucesso!");
		} else {
			printf("Erro ao cadastrar imóvel!");
		}

		imoveis[*totalImoveis] = novoImovel;
		(*totalImoveis)++;
	} else {
		printf("O limite de imóveis cadastrados foi atingido. Não é possível cadastrar mais imóveis.\n");
	}
}


void listarImoveis(const struct Imovel imoveis[], int totalImoveis) {
	printf("Lista de imóveis cadastrados:\n");
	for (int i = 0; i < totalImoveis; i++) {
		printf("ID: %i\n", imoveis[i].id);
		printf("Tipo: %s\n", imoveis[i].tipo);
		printf("Endereço: %s\n", imoveis[i].endereco);
		printf("Cliente: %s\n", imoveis[i].cliente);
		printf("Preço: %.2lf\n", imoveis[i].preco);
		printf("\n");
	}
}

void MenuImovel() {
	struct Imovel imoveis[100];
	int totalImoveis = 0;

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
				cadastrarImovel(imoveis, &totalImoveis);
				sleep(1);
				break;
			case 2:
				listarImoveis(imoveis, totalImoveis);
				break;
			case 0:
				system("cls");
				break;
			default:
				printf("Opção inválida!!\n");
		}
	} while (opcao != 0);
}