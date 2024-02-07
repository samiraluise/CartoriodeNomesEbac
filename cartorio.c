#include <stdio.h> //biblioteca de comunica��o da m�quina com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�os em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o - indicado a partir da l�ngua
#include <string.h> //biblioteca de aloca��o de strings

int registro()//cadastra usu�rios no sistema
{
	//cria��o de vari�veis/strings - inicio
	char arquivo[40];//vari�vel que salvar� as informa��es na biblioteca
	char cpf[40];//vari�vel pra o cpf do usu�rio
	char nome[40];//vari�vel para o nome do usu�rio
	char sobrenome[40];//vari�vel para o sobrenome do usu�rio
	char cargo[40];//vari�vel para o cargo do usu�rio
	//cria��o de vari�veis/strings - fim
	
	//definindo uma chave prim�ria (vari�vel com informa��o �nica de cada usu�rio)
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��es do usu�rio - pede o cpf
	scanf("%s", cpf); //%s l� vari�veis do tipo string
	
	//fun��o para copiar dados de uma string pra outra = strcpy
	strcpy(arquivo, cpf); //do cpf para o arquivo
	
	//busca dentro da biblioteca
	FILE *file;//FILE *file = FILE diz ao computador o NOME do arquivo que procuramos e file � o TIPO do arquivo
	file = fopen(arquivo, "w"); //fopen para abrir o arquivo, arquivo para o nome e w de write, definindo a a��o a ser feita
	fprintf(file, cpf);//salva o valor file na vari�vel cpf
	fclose(file);//fecha o arquivo
	
	//a formata��o normal faria com que as informa��es ficassem todas juntas, sem espa�os, por isso:
	file = fopen(arquivo, "a");//arquivo = a��o -> abrir (vari�vel, "a��o -> editar");
	fprintf(file, ",");//adcionou uma v�rgula ao texto
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//pergunta ao usu�rio o nome
	scanf("%s", nome);//l� as informa��es
	
	file = fopen(arquivo, "a");//abre o arquivo pra edit�-lo
	fprintf(file, nome);
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo pra edit�-lo
	fprintf(file, ",");//escreve dentro do arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//pergunta ao usu�rio o sobrenome
	scanf("%s", sobrenome);//l� as informa��es
	
	file = fopen(arquivo, "a");//abre o arquivo para edit�-lo
	fprintf(file, sobrenome);//escreve dentro do arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo para edit�-lo
	fprintf(file, ",");//escreve dentro do arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//pergunta ao usu�rio o cargo
	scanf("%s", cargo);//l� informa��es do usu�rio
	
	file = fopen(arquivo, "a");//abre o arquivo para edit�-lo
	fprintf(file, cargo);//escreve dentro do arquivo
	fclose(file);//fecha o arquivo
	
	system("pause");//para o programa e pede uma confirma��o antes de continuar
	//fim da fun��o de registro
}
	
int consulta()//faz consultas dentro do banco
{
	setlocale(LC_ALL, "Portuguese");//muda o idioma para portugu�s
	
	char cpf[40];//cria uma vari�vel cpf pra verificar um cpf que j� foi criado
	char conteudo[200];//armazena as informa��es lidas e trazem pro usu�rio
	
	printf("Digite o CPF a ser consultado: ");//pergunta ao usu�rio o cpf 
	scanf("%s", cpf);//l� as informa��es
	
	FILE *file;//faz uma busca no computador usando o nome e tipo
	file = fopen(cpf, "r"); //r = read - abre o arquivo e l� buscando o que precisa ser consultado

	if(fgets(conteudo, 200, file) !=NULL); //!=diferente de
	//se fgets for diferente de...
	//fgets procura o conte�do dentro do arquivo
	{
		//mostra pro usu�rio as informa��es encontradas
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
    }
    
    if(file == NULL)//se file for id�ntico a nulo...
    
	{
		//diz ao usu�rio que n�o foram encontradas informa��es
		printf("\n\nCrendeciais inv�lidas! \n");
	}
	
	fclose(file);//fecha o arquivo que foi aberto para a pesquisa
	
	system("pause");//para a tela do sistema
	
}

int deletar()//deleta usu�rios que foram registrados

{
	char cpf [40]; //char recebe n�mero tamb�m e em gerenciamento de strings se faz mais eficiente
	
	printf("Digite o CPF do usu�rio a ser deletado: ");//diz para o usu�rio digitar o cpf 
	scanf("%s", cpf);//l� as informa��es
	
	FILE *file;//faz uma busca no computador usando o nome e tipo
	file = fopen(cpf, "r"); //abre e l� o arquivo "file"
	fclose(file);//fecha o arquivo
	
	if(file == NULL)//se file for id�ntico a nulo...
	{
		printf("\nUsu�rio n�o encontrado!\n");//diz ao usu�rio que n�o foi encontrado nenhuma correspond�ncia
		system("pause");//pausa o sistema
	}
	
	remove(cpf);//remove um dado fornecido
	
	if(file != NULL)//se file for diferente de nulo...
	{
		printf("\nUsu�rio deletado com sucesso!\n");//confirma a remo��o para o usu�rio
		system("pause");//pausa o sistema
		
	}
	
	
}


int main()//fun��o principal
    {
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1; laco=1;)//repeti��o
	{
		
	system("cls");//limpa o que foi escrito
		
    setlocale(LC_ALL, "Portuguese"); //definindo a l�ngua
	
		printf("\t####Cart�rio da EBAC#### \n\n"); //�nicio do menu
		printf("\Escolha a op��o desejada no menu abaixo: \n");//mostra as op��es pro usu�rio
		printf("\t1-Registrar nome \n");
		printf("\t2-Consultar nome \n");
		printf("\t3-Deletar nome \n"); 
		printf("\t4-Sair do sistema \n");
		printf("Op��o:"); //fim do menu
	
		scanf("%d",&opcao); //armazenando escolhas do usu�rio
	
		system("cls");//limpa a tela
		
		
		switch(opcao)//op��es do menu
		{
			case 1://caso a op��o escolhida seja 1...
			registro();//executa a fun��o registro...
			break;//e finaliza
			
			case 2://caso a op��o escolhida seja 2...
			consulta();//executa a fun��o consulta...
			break;//e finaliza
			
			case 3://caso a op��o escolhida seja 3...
			deletar();//executa a fun��o deletar...
			break;//e finaliza
			
			case 4://caso a op��o escolhida seja 4...
			printf("Obrigado por utilizar o sistema! \n");//mostre a mensagem na tela do usu�rio...
			return 0;//finalize o programa e saia
			break;

			default://caso a op��o seja diferente das dispon�veis...
			printf("Essa op��o n�o est� dispon�vel! \n");//diz ao usu�rio que n�o foi poss�vel executar...
			system("pause");//e finaliza
			break;
			//fim da sele��o
		}	
	}		
}

