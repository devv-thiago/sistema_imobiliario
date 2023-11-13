#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 100

struct Cliente {
    char nome[50];
    char telefone[15];
    char cpf[11];
    char email[50];
};

void cadastrarCliente(struct Cliente clientes[], int *numClientes) {
    if (*numClientes < MAX_CLIENTES) {
        printf("Digite o nome do cliente: ");
        scanf("%s", clientes[*numClientes].nome);

        printf("Digite o telefone do cliente: ");
        scanf("%s", clientes[*numClientes].telefone);
        
        printf("Digite o CPF do cliente: ");
        scanf("%s", clientes[*numClientes].cpf);

        printf("Digite o email do cliente: ");
        scanf("%s", clientes[*numClientes].email);

        (*numClientes)++;
        printf("Cliente cadastrado com sucesso!\n");
    } else {
        printf("Limite de clientes atingido. Impossível cadastrar mais.\n");
    }
}

void exibirClientes(struct Cliente clientes[], int numClientes) {
    printf("\nClientes cadastrados:\n");
    for (int i = 0; i < numClientes; i++) {
        printf("Cliente %d:\n", i + 1);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Telefone: %s\n", clientes[i].telefone);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Email: %s\n\n", clientes[i].email);
    }
}

int main() {
    struct Cliente clientes[MAX_CLIENTES];
    int numClientes = 0;
    int escolha;

    do {
        printf("\n1 - Cadastrar Cliente\n");
        printf("2 - Exibir Clientes\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                cadastrarCliente(clientes, &numClientes);
                break;
            case 2:
                exibirClientes(clientes, numClientes);
                break;
            case 0:
                printf("Encerrando Sistema. Obrigado!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}