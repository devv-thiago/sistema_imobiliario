#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define ARQ_VENDAS "Data/Vendas.txt"

// Definindo uma estrutura para representar uma venda imobiliária
struct VendaImobiliaria {
	int idImovel;
	int idCliente;
	char tipo[20];
	char endereco[100];
	float valor;
};

char* selecaoTipoImovel() {
	int opcao;
	char* opcaoRetorno;
	printf("1 - Casa\n2 - Apartamento\n3 - Terreno\nEscolha: ");
	switch(opcao) {
		case 1:
			printf("Tipo selecionado: Casa");
			opcaoRetorno = strdup("Casa");
			return opcaoRetorno;
			break;
		case 2:
			printf("Tipo selecionado: Apartamento");
			opcaoRetorno = strdup("Apartamento");
			return opcaoRetorno;
			break;
		case 3:
			printf("Tipo selecionado: Terreno");
			opcaoRetorno = strdup("Terreno");
			return opcaoRetorno;
			break;
	}
}

// salva informações em arquivo de registro
void registraVendaArq(int idImovel, int idCliente, char endereco[100], float valor) {
	FILE *vendas = fopen(ARQ_VENDAS, "a+");
	char tipo[20] = selecaoTipoImovel();
	fprintf(ARQ_VENDAS,"%i %i %s %f", idImovel, idCliente, endereco, valor);
}

// Função para exibir os detalhes de uma venda
void exibirVenda(const struct VendaImobiliaria *venda) {
	printf("ID: %d\n", venda->id);
	printf("Tipo: %s\n", venda->tipo);
	printf("Descrição: %s\n", venda->descricao);
	printf("Valor: %.2f\n", venda->valor);
	printf("\n");
}

int main() {
	// Definindo um array para armazenar vendas imobiliárias
	struct VendaImobiliaria vendas[5];
	opcao = 1;
	/*
	    // Solicitando ao usuário inserir informações sobre as vendas
	    for (int i = 0; i < 5; i++) {
	        printf("Insira os detalhes da venda #%d:\n", i + 1);
	        vendas[i].id = i + 1;

	        printf("Tipo (casa/apartamento/terreno): ");
	        scanf("%s", vendas[i].tipo);

	        printf("Descrição: ");
	        scanf(" %[^\n]s", vendas[i].descricao);

	        printf("Valor: ");
	        scanf("%f", &vendas[i].valor);
	    }

	    // Filtrar e exibir vendas com base no tipo (por exemplo, "casa")
	    char tipoFiltrado[20];
	    printf("Filtrar por tipo (casa/apartamento/terreno): ");
	    scanf("%s", tipoFiltrado);

	    printf("Vendas imobiliárias do tipo %s:\n", tipoFiltrado);
	    for (int i = 0; i < 5; i++) {
	        if (strcmp(vendas[i].tipo, tipoFiltrado) == 0) {
	            exibirVenda(&vendas[i]);
	        }
	    }
	*/
	return 0;
}