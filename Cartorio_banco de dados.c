#include <stdio.h>  // Biblioteca de Comunica��o com o usu�rio 
#include <stdlib.h> // Blblioteca de Respons�bilidade pela aloca��o de espa�os na memoria
#include <locale.h> // Biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings. 
//Aula para criar o banco de dados. 


int registro(){ // criando fun��es para n�o ocupar a memoria. 
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf("Digite o cpf para ser cadastrado: ");
	scanf("%s",&cpf);
	
	strcpy(arquivo,cpf); // responsavel por copiar os valores das strings
	FILE *file; //criar arquivo
	file = fopen (arquivo, "w"); // abrir o arquivo fopen como � um arquivo novo chamamos com "w"
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", &nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", &sobrenome);
	file = fopen (arquivo, "a"); // "a" de atualiza��o
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf ("Digite o cargo a ser cadastrado: ");
	scanf("%s", &cargo);
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system ("pause");
}

int consulta(){
	
	setlocale (LC_ALL, "portuguese"); // para poder utilizar acentos. 
	char cpf [40];
	char conteudo [200];
	
	printf ("Digite o cpf a ser consultado: "); //RECEBENDO QUAL USUARIO VAI SER CONSULTADO
	scanf("%s", &cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" de LER.
	
	if (file == NULL){
		printf("N�o localizado!\n");
	}	
	printf ("\n Essas s�o as informa��es do usu�rio: ");
	while (fgets(conteudo, 200, file) != NULL){ // fgets - s� estamos falando para ele ir buscar o arquivo. 
		printf("%s", &conteudo);
		printf("\n\n");
	}
	system("pause");
}


int deletar(){
	
	char cpf [40];
	
	printf ("Digitar o cpf do usu�rio a ser deletado: ");
	scanf("%s", &cpf);
	
	remove (cpf);
	
	FILE *file; 
	file = fopen (cpf, "r");
	
	if (file == NULL){
		printf("Arquivo n�o existe!\n");
		system("pause");
	}
	
}

int main () {
	int opcao = 0; // Definindo as variaveis 
	int x=1;
	char senhadigitada[] = "a";
	int comparacao;
	
	printf("###Cartorio ebac###");
	printf("\nLogin de administrador!\n\nDigite a sua senha: ");
	scanf("%s",&senhadigitada);
	comparacao = strcmp(senhadigitada,"admin"); // compara o que o usuario digitou com a senha admin
	
	if (comparacao == 0){
		
		system ("cls");
	
		for (x=1; x=1;){ // usuario sempre ficar no la�o, mas se quiser sair pode clicar em 4.
			
			system("cls"); // fun��o limpar a tela
		
			setlocale(LC_ALL, "Portuguese");
		
			printf("### Cart�rio da EBAC ### \n\n");
			printf("Escolha a op��o desejada do menu:\n\n"); // inicio do menu
			printf("\t1 - Registrar Nomes\n"); // \t da espa�o na mensagem
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar Nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			// Fim do menu
			printf("Op��o: ");
			scanf("%d",&opcao);
	
			system("cls"); // fun��o limpar a tela
		
			switch(opcao){
				case 1: 
					registro();
				break;
			
				case 2: 
					consulta();
				break;
			
				case 3: 
					deletar();
				break;
			
				case 4: 
					printf("Voc� escolheu a op��o sair do sistema!");
				return 0;
				break;
			
				default: 
					printf ("Essa op��o n�o � valida, por favor retornar ao menu e escolher uma op��o de 1 a 3!\n\n");
					system("pause"); // aparece a op��o at� o usu�rio n�o querer mais
				break;
			}
		}
	}
	else printf("senha incorreta!");
}
