#include <stdio.h> //biblioteca de comunica��o com usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca que ira cuidar das strings

int registro()
{
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado:  ") ;
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Resposavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo
	fprintf(file,cpf); //salva o calor da variavel
	fclose(file); //fecha o arquivo
	
	file=fopen(arquivo, "a"); 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file=fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo, "a"); 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);

    file=fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a"); 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file=fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s" , cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");		
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:  ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

	
int deletar()
{

	char cpf[40];
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
	  printf("O usuario n�o se encontra no sistema!.\n");
		system("pause");
	}
	

	
	
	
}	
	
	

int main()
{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	
	for(laco=1;laco=1;)
	{
	
	
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
		printf("###Cartorio da EBAC###\n\n"); //inicio do menu
		printf("Escolha a op��o deseajada: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar Nomes\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o: ");//fim do menu
	
		scanf("%d" , &opcao); //armazenando a escolha do usuario
	
	
		system("cls");
	
		switch(opcao)
		{
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
			printf("Obrigada por utilizar o sistema!\n");
			return 0;
			break;	
			
			default:
			printf("Essa op��o n�o esta disponivel!\n");
			system("pause");
			break;
			
	
		}
	}
		
}
