#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#define IMOVEL_LOG "./Data/log_imovel.txt"
#define CLIENTE_LOG "./Data/log_cliente.txt"
#define MOVIMENTACAO_LOG "./Data/log_movimentacao.txt"

char* obterDataHora() {
    time_t horaAtual;
    time(&horaAtual);

    char* dataHoraFormatada = (char*)malloc(50);

    if (dataHoraFormatada == NULL) {
        return NULL;
    }

    strftime(dataHoraFormatada, 50, "%Y-%m-%d %H:%M:%S", localtime(&horaAtual));
    return dataHoraFormatada;
}


void logImovel(int cod, char tipoImovel[30], char usuario[30]) {
    FILE *arquivo = fopen(IMOVEL_LOG, "a+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char* dataHora = obterDataHora();
    fprintf(arquivo, "%i %s %s %s\n", cod, tipoImovel, usuario, dataHora);

    free(dataHora);
    fclose(arquivo);
}

void exibirLogImovel() {
    FILE *arquivo = fopen(IMOVEL_LOG, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int cod;
    char tipoImovel[30];
    char usuario[30];
    char dataHora[50];

    while (!feof(arquivo)) {
        fscanf(arquivo, "%i %s %s %s\n", &cod, tipoImovel, usuario, dataHora);
        printf("%i %s %s %s\n", cod, tipoImovel, usuario, dataHora);
    }

    fclose(arquivo);
}

void logCliente(int id, char cliente[30]) {
    FILE *arquivo = fopen(CLIENTE_LOG, "a+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char* dataHora = obterDataHora();
    fprintf(arquivo, "%i %s %s\n", id, cliente, dataHora);

    free(dataHora);
    fclose(arquivo);
}

void exibirLogCliente() {
    FILE *arquivo = fopen(CLIENTE_LOG, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int id;
    char cliente[30];
    char dataHora[50];

    while (!feof(arquivo)) {
        fscanf(arquivo, "%i %s %s\n", &id, cliente, dataHora);
        printf("%i %s %s\n", id, cliente, dataHora);
    }

    fclose(arquivo);
}

void logMovimentacao(char acao[20], char usuario[30]) {
    FILE *arquivo = fopen(MOVIMENTACAO_LOG, "a+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char* dataHora = obterDataHora();
    fprintf(arquivo, "%s %s %s\n", acao, usuario, dataHora);

    free(dataHora);
    fclose(arquivo);
}

void exibirLogMovimentacao() {
    FILE *arquivo = fopen(MOVIMENTACAO_LOG, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char acao[20];
    char usuario[30];
    char dataHora[50];

    while (!feof(arquivo)) {
        fscanf(arquivo, "%s %s %s\n", acao, usuario, dataHora);
        printf("%s %s %s\n", acao, usuario, dataHora);
    }

    fclose(arquivo);
}

void menuLog() {
    int op;

    while (1) {
        sleep(1);
        system("cls");

        printf("LOGS DO SISTEMA");
        printf("\n\n");

        printf("O que deseja fazer?\n\n[1]Log de Imóveis.\n[2]Log de Clientes.\n[3]Log de Movimentações.\n[0]Retornar.\n\nEscolha: ");

        fflush(stdin);
        scanf("%i", &op);

        switch(op) {
            case 1:
                logImovel(120, "casa", "thiago.fofano");
                logImovel(121, "apartamento", "thiago.fofano");
                logImovel(122, "terreno", "thiago.fofano");
                exibirLogImovel();
                break;
            case 2:
                logCliente(123, "Jose alves");
                logCliente(124, "Jose silva");
                logCliente(125, "Thiago fofano");
                exibirLogCliente();
                break;
            case 3:
                logMovimentacao("venda", "thiago.fofano");
                logMovimentacao("compra", "thiago.fofano");
                logMovimentacao("venda", "thiago.fofano");
                exibirLogMovimentacao();
                break;
            case 0:
                sleep(1);
                system("cls");
                return;
            default:
                printf("Opção inválida!!\n");
                sleep(1);
                system("cls");
                break;
        }
    }
}

