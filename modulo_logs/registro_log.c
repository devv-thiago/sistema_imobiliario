#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#define IMOVEL_LOG "log_imovel.txt"
#define CLIENTE_LOG "log_cliente.txt"
#define MOVIMENTACAO_LOG "log_movimentacao.txt"

char* obterDataHora() {
	time_t horaAtual;
	time(&horaAtual);

	return ctime(&horaAtual);
}

void logImovel(int cod, char tipoImovel[30], char usuario[30]) {
	FILE *arquivo = fopen(IMOVEL_LOG, "a+");
	char* dataHora = obterDataHora();
	fprintf(arquivo,"%i %s %s %s\n", cod, tipoImovel, usuario, dataHora);
	fclose(arquivo);
}
void exibirLogImovel() {
	FILE *arquivo = fopen(IMOVEL_LOG, "r");
	int cod;
	char tipoImovel[30];
	char usuario[30];
	char* dataHora;
	while(!feof(arquivo)) {
		fscanf(arquivo,"%i %s %s %s\n", &cod, tipoImovel, usuario, dataHora);
		printf("%i %s %s %s\n", cod, tipoImovel, usuario, dataHora);
	}
	fclose(arquivo);
}

void logCliente(int id, char cliente[30]) {
	FILE *arquivo = fopen(CLIENTE_LOG, "a+");
	char* dataHora = obterDataHora();
	fprintf(arquivo, "%i %s %s\n", id, cliente, dataHora);
	fclose(arquivo);
}

void exibirLogCliente() {
	FILE *arquivo = fopen(CLIENTE_LOG, "r");
	int id;
	char cliente[30];
	char* dataHora;
	while(!feof(arquivo)) {
		fscanf(arquivo, "%i %s %s\n", &id, cliente, dataHora);
		printf("%i %s %s\n", id, cliente, dataHora);
	}
	fclose(arquivo);
}

void logMovimentacao(char acao[20], char usuario[30]) {
	FILE *arquivo = fopen(MOVIMENTACAO_LOG, "a+");
	char* dataHora = obterDataHora();
	fprintf(arquivo, "%s %s %s\n", acao, usuario, dataHora);
	fclose(arquivo);
}
void exibirLogMovimentacao() {
	FILE *arquivo = fopen(MOVIMENTACAO_LOG, "a+");
	char acao[20];
	char usuario[30];
	char* dataHora;
	while(!feof(arquivo)) {
		fscanf(arquivo, "%s %s %s\n", acao, usuario, dataHora);
		printf("%s %s %s\n", acao, usuario, dataHora);
	}
	fclose(arquivo);
}

void menuLog() {

	setLocale(LC_ALL,"");

	int op;
	do {
		sleep(1);
		system("cls");
		printf("Digite a opcao que deseja:\n1 - Log de imoveis.\n2 - Log de clientes.\n3 - Log de movimentacoes\n4 - Sair\nEscolha: ");
		scanf("%i",&op);
		switch(op) {
			case 1:
				exibirLogImovel();
				break;
			case 2:
				exibirLogCliente();
				break;
			case 3:
				exibirLogMovimentacao();
				break;
			case 4:
				sleep(1);
				system("cls");
				break;
			default:
				printf("Opção inválida!!\n");
				sleep(1);
				system("cls");
				break;
		}
	} while(op != 4);

}