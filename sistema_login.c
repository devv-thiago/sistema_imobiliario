#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


void selectionSort(int arr[], int n) {
    int i, j, aux;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                aux = arr[j];
                arr[j] = arr[i];
                arr[i] = aux;
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%i ", arr[i]);
    }
}


int main() {
	char usuario[30];
	char senha[30];
	char confirmacaoSenha[30];
	int escolha;
	int array[30] = {5,4,3,2,1,10,9,8,7,6,50,40,30,20,10,100,90,80,70,60,500,400,300,200,100,1000,900,800,700,600};

	selectionSort(array, 30);
	
	/*
	
	bool continua = true;

	while (continua) {
	    printf("Digite a opcao que deseja:\n1- Entrar na minha conta.\n2- Criar nova conta.\n3- Sair\nEscolha: ");
	    scanf("%i", &escolha);

	    switch (escolha) {
	        case 1:

	            break;
	        case 2:
	            printf("Digite seu nome de usuario: ");
	            scanf("%s", usuario);

	            do {
	                printf("Crie sua senha: ");
	                scanf("%29s", senha);

	                printf("Confirme sua senha: ");
	                scanf("%29s", confirmacaoSenha);

	            } while (strcmp(senha, confirmacaoSenha) != 0);

	            printf("Usuario cadastrado com sucesso!!");
	            break;

	        case 3:
	            continua = false;
	            break;
	    }
	}
	*/

	return 0;
}
