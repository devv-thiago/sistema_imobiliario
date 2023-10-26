#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#define MAX 80

void sac() {
	float vlImovel, vlEntrada, vlFinanciado, txJuros, saldoDev=0, vlParcelasPorMes, amort, juros, vlParcela, jurosAtual, totalJuros=0, totalAmort=0;
	int nParcelas;
	char iniciar, tabDet;

	setlocale(LC_ALL,"");

	do {
		sleep(1);
		system("cls");
		linha(MAX);

		styleLine(35);
		printf("TABELA SAC");
		styleLine(35);
		printf("\n\n");

		printf("Deseja fazer uma nova simulação de financiamento no modelo SAC?\n\n[s]SIM\n[n]NAO\n\n");
		scanf(" %c",&iniciar);  //Espaço usado antes de %c para limpar o scanf do ENTER pressionado para retornar
		getchar();
		if(iniciar=='n' || iniciar=='N') {
			return 0;     //sai do loop e volta para o simulacao_main()
		}
		if (iniciar != 's' && iniciar != 'S' && iniciar != 'n' && iniciar != 'N') {
			printf("Opção incorreta! Digite 's' para SIM e 'n' para NÃO\n\n");
			sleep(1);
			system("cls");
		} else {
			if(iniciar=='s' || iniciar=='S') {
				sleep(1);
				system("cls");
				linha(MAX);

				styleLine(35);
				printf("TABELA SAC");
				styleLine(35);
				printf("\n\n");

				printf("Digite o valor do imóvel: R$");
				scanf("%f",&vlImovel);

				printf("Digite o valor de entrada: R$");
				scanf("%f",&vlEntrada);
				printf("\n");

				vlFinanciado = vlImovel - vlEntrada;
				printf("Valor a ser financiado: R$ %.2f\n", vlFinanciado);

				printf("Digite a taxa de juros(%%): ");
				scanf("%f",&txJuros);

				printf("Digite o número de parcelas: ");
				scanf("%i",&nParcelas);

				printf("\n");

				linha(MAX);
				printf("Valor do financiamento:R$ %.2f reais.\n",vlFinanciado);
				printf("Números de parcelas: %i vezes\n", nParcelas);
				printf("Taxa de juros(%%): %.2f%% a.m.\n\n",txJuros);

				amort = vlFinanciado / nParcelas;
				saldoDev += vlFinanciado;
				juros = saldoDev * (txJuros/100);
				vlParcela = juros + amort;




				printf("Valor da parcela no primeiro mês: R$ %.2f reais.\n",vlParcela);
				printf("Valor do juros no primeiro mês: R$ %.2f reais.\n",juros);
				printf("Valor fixo de amortização mensal: R$ %.2f reais.\n\n",amort);
				getchar();

				do {
					styleLine(32);
					printf("DETALHES - PRICE");
					styleLine(32);
					printf("\n\n");

					printf("Deseja ver tabela detalhada?\n\n[s]SIM\n[n]NÃO\n\n\n");
					scanf("%c",&tabDet);
					getchar();
					if(tabDet != 's' && tabDet != 'S' && tabDet != 'n' && tabDet != 'N') {
						printf("Opção incorreta! Digite 's' para SIM e 'n' para NÃO\n\n");
						sleep(1);
						system("cls");
					} else {
						if(tabDet=='s' || tabDet=='S') {
							sleep(1);
							system("cls");

							linha(MAX);

							styleLine(26);
							printf("DETALHES DE SIMULAÇÃO - SAC");
							styleLine(27);
							printf("\n\n");

							printf("Valor do financiamento:R$ %.2f reais.\n",vlFinanciado);
							printf("Números de parcelas: %i vezes\n", nParcelas);
							printf("Taxa de juros(%%): %.2f%% a.m.\n\n",txJuros);

							styleLine(29);
							printf("TABELA DETALHADA - SAC");
							styleLine(29);
							printf("\n\n");

							printf("Valor da parcela no primeiro mês: R$ %.2f reais.\n",vlParcela);
							printf("Valor do juros no primeiro mês: R$ %.2f reais.\n",juros);
							printf("Valor fixo de amortização mensal: R$ %.2f reais.\n\n",amort);

							for(int i=2; i<=nParcelas; i++) {
								float pmt;
								saldoDev -= amort;
								jurosAtual = saldoDev * (txJuros/100);
								pmt = jurosAtual + amort;

								if(saldoDev<0 && jurosAtual<0) {
									printf("%i%c mes - Valor da Parcela: R$ %.2f reais\n", i, 248, pmt);
									printf("Valor fixo mensal de amortização: R$ %.2f reais\n",amort);
									printf("Valor atualizado do juros: SEM JUROS.\n");
									printf("Valor atualizado do saldo devedor: R$ %.2f reais\n\n",saldoDev);

								} else {
									printf("%i%c mes - Valor da Parcela: R$ %.2f reais\n", i, 248, pmt);
									printf("Valor fixo mensal de amortização: R$ %.2f reais\n",amort);
									printf("Valor atualizado do juros: R$ %.2f reais\n",jurosAtual);
									printf("Saldo devedor: R$ %.2f reais\n\n",saldoDev);

								}
							}
							break;

						}
					}

				} while(tabDet != 'n' && tabDet != 'N');
				printf("Pressione ENTER para retornar.");
				getch();

			}
		}
	} while(1);

}
