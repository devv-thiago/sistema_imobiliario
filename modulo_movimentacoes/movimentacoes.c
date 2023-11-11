#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQ_VENDAS "Data/Vendas.txt"

char* selecaoTipoImovel() {
    int opcao;
    char* opcaoRetorno = NULL;
    printf("1 - Casa\n2 - Apartamento\n3 - Terreno\nEscolha: ");
    scanf("%i", &opcao);
    switch (opcao) {
        case 1:
            printf("Tipo selecionado: Casa\n");
            opcaoRetorno = strdup("Casa");
            break;
        case 2:
            printf("Tipo selecionado: Apartamento\n");
            opcaoRetorno = strdup("Apartamento");
            break;
        case 3:
            printf("Tipo selecionado: Terreno\n");
            opcaoRetorno = strdup("Terreno");
            break;
        default:
            printf("Opcao invalida\n");
            opcaoRetorno = strdup("Terreno");
            break;
    }
    return opcaoRetorno;
}

// Save sale information to a file
void registraVendaArq(int idImovel, int idCliente, const char* endereco, const char* tipo, float valor) {
    FILE* vendas = fopen(ARQ_VENDAS, "a+");
    if (vendas == NULL) {
        printf("Erro ao abrir o arquivo de vendas.\n");
        return;
    }
    
    fprintf(vendas, "%d %d %s %s %.2f\n", idImovel, idCliente, endereco, tipo, valor);
    fclose(vendas);
}

void registraVenda() {
    int idImovel, idCliente;
    char endereco[100];
    
    printf("Digite o ID do imovel: ");
    scanf("%d", &idImovel);
    
    printf("Digite o ID do cliente: ");
    scanf("%d", &idCliente);
    
    printf("Digite o endereco do imovel: ");
    scanf("%s", endereco);
    
    char* tipo = selecaoTipoImovel();
    if (tipo != NULL) {
        registraVendaArq(idImovel, idCliente, endereco, tipo, 0.0); // Assume 0.0 como valor inicial
        free(tipo);
    }
}

void menuMovimentacao() {
    int continua;
    
    do {
        registraVenda();
        
        printf("Deseja continuar? (1 para Sim / 0 para Nao): ");
        scanf("%d", &continua);
        
    } while (continua == 1);
}
