//Server
/* Passo a passo
5 - Aceite uma conex�o de um cliente.
6 - Receber e enviar dados.
7 - Desconectar.
*/

// Pesquisar sobre a DLL windows.h


#include <stdio.h>
#include <winsock2.h>
#define PORT "5000"

int main() {
	WSADATA wsaData; // armazena informa��es do Windows Socket
	int iResult; // valida se a inicializa��o foi correta
	int meuSocket;
	char buff[200];

	struct sockaddr_in clientAddr;
	struct sockaddr_in serverAddr = {
		.sin_family = AF_INET,
		.sin_addr.s_addr = htonl(INADDR_ANY),
		.sin_port = htons(PORT)
	};

	// Inicializa��o do Winsock
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
		return 1;
	}

	//Cria��o do Socket
	meuSocket = socket(AF_INET, SOCK_STREAM, 0);

	//Associa��o do Socket
	bind(meuSocket, (struct sockaddr *) &serverAddr, sizeof serverAddr);

	//Ouvir o socket
	listen(meuSocket, 5);
	int clientSize = sizeof clientAddr;

	int client = accept(meuSocket, (struct sockaddr *) &clientAddr, &clientSize);
	recv(meuSocket, buff, sizeof buff, 0);

	printf("\nMensagem recebida: %s", buff);

	closesocket(meuSocket);

	return 0;
}


