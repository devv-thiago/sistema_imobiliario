#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#define MAX 80


float calculoPrice(float valorFinanciado,float taxaJuros, int numParcelas)
{
    return valorFinanciado / (((pow(1.0+(taxaJuros/100),numParcelas)) - 1.0) / ((pow(1.0+(taxaJuros/100),numParcelas)) * (taxaJuros/100)));
}

void price()
{
    float vlImovel, vlEntrada, valorFinanciado, taxaJuros, vlParcelasPorMes, amort, vlPorcInicial;
    float totalJuros=0, totalAmort=0;
    int numParcelas;
    char iniciar;
    char tabDet;


    setlocale(LC_ALL,"");

    do
    {
        sleep(1);
        system("cls");
        linha(MAX);
        printf("Deseja fazer uma nova simula��o de financiamento no modelo Price?\n\n[s]SIM\n[n]NAO\n\n");
        scanf(" %c",&iniciar); //Espa�o usado antes de %c para limpar o scanf do ENTER pressionado para retornar
        getchar();
        if(iniciar=='n' || iniciar=='N')
        {
            return 0;     //sai do loop e volta para o simulacao_main()
        }
        if (iniciar != 's' && iniciar != 'S' && iniciar != 'n' && iniciar != 'N')
        {
            printf("Op��o incorreta! Digite 's' para SIM e 'n' para N�O\n\n");
            sleep(1);
            system("cls");
        }
        else
        {
            if(iniciar=='s' || iniciar=='S')
            {
                sleep(1);
                system("cls");
                linha(MAX);
                styleLine(34);
                printf("TABELA PRICE");
                styleLine(34);
                printf("\n\n");
                printf("Digite o valor do im�vel: R$");
                scanf("%f",&vlImovel);

                printf("Digite o valor de entrada: R$");
                scanf("%f",&vlEntrada);
                printf("\n");

                valorFinanciado = vlImovel - vlEntrada;
                printf("Valor a ser financiado: R$ %.2f\n", valorFinanciado);

                printf("Digite a taxa de juros(%%): ");
                scanf("%f",&taxaJuros);

                printf("Digite o n�mero de parcelas: ");
                scanf("%i",&numParcelas);

                printf("\n");


                vlParcelasPorMes = calculoPrice(valorFinanciado, taxaJuros, numParcelas);

                linha(MAX);
                printf("Valor do financiamento:R$ %.2f reais.\n",valorFinanciado);
                printf("Valor fixo das parcelas: R$ %.2f reais.\n",vlParcelasPorMes);
                printf("N�meros de parcelas: %i vezes\n", numParcelas);
                printf("Taxa de juros(%%): %.2f%% a.m.\n\n",taxaJuros);

                printf("Valor fixo das parcelas: R$ %.2f reais.\n",vlParcelasPorMes);

                vlPorcInicial = valorFinanciado * (taxaJuros/100);

                amort = vlParcelasPorMes - vlPorcInicial;

                printf("Valor do juros no primeiro m�s: R$ %.2f reais.\n",vlPorcInicial);
                printf("Valor da amortiza��o no primeiro m�s: R$ %.2f reais.\n\n",amort);
                getchar();

                do
                {
                    styleLine(33);
                    printf("DETALHES - SAC");
                    styleLine(33);
                    printf("\n\n");

                    printf("Deseja ver tabela detalhada?\n\n[s]SIM\n[n]N�O\n\n\n");
                    scanf("%c",&tabDet);
                    getchar();
                    if(tabDet != 's' && tabDet != 'S' && tabDet != 'n' && tabDet != 'N')
                    {
                        printf("Op��o incorreta! Digite 's' para SIM e 'n' para N�O\n\n");
                        sleep(1);
                        system("cls");
                    }
                    else
                    {
                        if(tabDet=='s' || tabDet=='S')
                        {
                            sleep(1);
                            system("cls");
                            linha(MAX);

                            styleLine(25);
                            printf("DETALHES DE SIMULA��O - PRICE");
                            styleLine(26);
                            printf("\n\n");

                            printf("Valor do financiamento:R$ %.2f reais.\n",valorFinanciado);
                            printf("Valor fixo das parcelas: R$ %.2f reais.\n",vlParcelasPorMes);
                            printf("N�meros de parcelas: %i vezes\n", numParcelas);
                            printf("Taxa de juros(%%): %.2f%% a.m.\n\n",taxaJuros);

                            styleLine(28);
                            printf("TABELA DETALHADA - PRICE");
                            styleLine(28);
                            printf("\n\n");

                            printf("Valor fixo das parcelas: R$ %.2f reais.\n",vlParcelasPorMes);

                            vlPorcInicial = valorFinanciado * (taxaJuros/100);

                            amort = vlParcelasPorMes - vlPorcInicial;

                            printf("Valor do juros no primeiro m�s: R$ %.2f reais.\n",vlPorcInicial);
                            printf("Valor da amortiza��o no primeiro m�s: R$ %.2f reais.\n\n",amort);

                            for(int i=2; i<=numParcelas; i++)
                            {
                                valorFinanciado-=amort;
                                vlPorcInicial = valorFinanciado * (taxaJuros/100);
                                amort = vlParcelasPorMes - vlPorcInicial;
                                totalJuros+=vlPorcInicial;
                                totalAmort+=amort;

                                printf("%i%c mes - Parcela fixa de R$ %.2f reais\n", i, 248, vlParcelasPorMes);

                                if(valorFinanciado<0 && vlPorcInicial<0)
                                {
                                    printf("Valor atualizado da amortiza��o: R$ %.2f reais\n",amort);
                                    printf("Valor atualizado do juros: SEM JUROS.\n");
                                    printf("Valor atualizado do saldo devedor: R$ %.2f reais\n\n",valorFinanciado);

                                }
                                else
                                {
                                    printf("Valor atualizado da amortiza��o: R$ %.2f reais\n",amort);
                                    printf("Valor atualizado do juros: R$ %.2f reais\n",vlPorcInicial);
                                    printf("Saldo devedor: R$ %.2f reais\n\n",valorFinanciado);

                                }
                            }
                            break;

                        }
                    }

                }
                while(tabDet != 'n' && tabDet != 'N');
                printf("Pressione ENTER para retornar.");
                getchar();

            }
        }

    }
    while(1);  //loop enquanto n�o for 'n' ou 'N'

}
