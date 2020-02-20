#include<stdio.h>
#include<netdb.h>
#escaner de portas
#Modo de uso: portscan IPalvo
main(int argc, char *argv[]){

	int meusocket, conecta, port, inicio=0, final=65535;
	char *destino;
	destino=argv[1];

	struct sockaddr_in alvo;

	for(port=inicio;port<final;port++){
	//estrutura responsavel pelo socket
	meusocket=socket(AF_INET, SOCK_STREAM, 0);
	alvo.sin_family=AF_INET;
	alvo.sin_port = htons(port);
	alvo.sin_addr.s_addr=inet_addr(destino);

	//conectar no socket
	conecta=connect(meusocket, (struct sockaddr *)&alvo, sizeof alvo);

	//checar se a conexao deu certo
	if(conecta==0){
		printf("Porta %d - status [ABERTA]\n",port);
		close(meusocket);
		close(conecta);
	}
	else{
		close(meusocket);
		close(conecta);
	}
	}
}
