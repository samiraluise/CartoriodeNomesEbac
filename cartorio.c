#include <stdio.h> //biblioteca de comunicação da máquina com o usuário
#include <stdlib.h> //biblioteca de alocação de espaços em memória
#include <locale.h> //biblioteca de alocação de texto por região - indicado a partir da língua
#include <string.h> //biblioteca de alocação de strings

int registro()//cadastra usuários no sistema
{
	//criação de variáveis/strings - inicio
	char arquivo[40];//variável que salvará as informações na biblioteca
	char cpf[40];//variável pra o cpf do usuário
	char nome[40];//variável para o nome do usuário
	char sobrenome[40];//variável para o sobrenome do usuário
	char cargo[40];//variável para o cargo do usuário
	//criação de variáveis/strings - fim
	
	//definindo uma chave primária (variável com informação única de cada usuário)
	printf("Digite o CPF a ser cadastrado: ");//coletando informações do usuário - pede o cpf
	scanf("%s", cpf); //%s lê variáveis do tipo string
	
	//função para copiar dados de uma string pra outra = strcpy
	strcpy(arquivo, cpf); //do cpf para o arquivo
	
	//busca dentro da biblioteca
	FILE *file;//FILE *file = FILE diz ao computador o NOME do arquivo que procuramos e file é o TIPO do arquivo
	file = fopen(arquivo, "w"); //fopen para abrir o arquivo, arquivo para o nome e w de write, definindo a ação a ser feita
	fprintf(file, cpf);//salva o valor file na variável cpf
	fclose(file);//fecha o arquivo
	
	//a formatação normal faria com que as informações ficassem todas juntas, sem espaços, por isso:
	file = fopen(arquivo, "a");//arquivo = ação -> abrir (variável, "ação -> editar");
	fprintf(file, ",");//adcionou uma vírgula ao texto
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//pergunta ao usuário o nome
	scanf("%s", nome);//lê as informações
	
	file = fopen(arquivo, "a");//abre o arquivo pra editá-lo
	fprintf(file, nome);
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo pra editá-lo
	fprintf(file, ",");//escreve dentro do arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//pergunta ao usuário o sobrenome
	scanf("%s", sobrenome);//lê as informações
	
	file = fopen(arquivo, "a");//abre o arquivo para editá-lo
	fprintf(file, sobrenome);//escreve dentro do arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo para editá-lo
	fprintf(file, ",");//escreve dentro do arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//pergunta ao usuário o cargo
	scanf("%s", cargo);//lê informações do usuário
	
	file = fopen(arquivo, "a");//abre o arquivo para editá-lo
	fprintf(file, cargo);//escreve dentro do arquivo
	fclose(file);//fecha o arquivo
	
	system("pause");//para o programa e pede uma confirmação antes de continuar
	//fim da função de registro
}
	
int consulta()//faz consultas dentro do banco
{
	setlocale(LC_ALL, "Portuguese");//muda o idioma para português
	
	char cpf[40];//cria uma variável cpf pra verificar um cpf que já foi criado
	char conteudo[200];//armazena as informações lidas e trazem pro usuário
	
	printf("Digite o CPF a ser consultado: ");//pergunta ao usuário o cpf 
	scanf("%s", cpf);//lê as informações
	
	FILE *file;//faz uma busca no computador usando o nome e tipo
	file = fopen(cpf, "r"); //r = read - abre o arquivo e lê buscando o que precisa ser consultado

	if(fgets(conteudo, 200, file) !=NULL); //!=diferente de
	//se fgets for diferente de...
	//fgets procura o conteúdo dentro do arquivo
	{
		//mostra pro usuário as informações encontradas
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
    }
    
    if(file == NULL)//se file for idêntico a nulo...
    
	{
		//diz ao usuário que não foram encontradas informações
		printf("\n\nCrendeciais inválidas! \n");
	}
	
	fclose(file);//fecha o arquivo que foi aberto para a pesquisa
	
	system("pause");//para a tela do sistema
	
}

int deletar()//deleta usuários que foram registrados

{
	char cpf [40]; //char recebe número também e em gerenciamento de strings se faz mais eficiente
	
	printf("Digite o CPF do usuário a ser deletado: ");//diz para o usuário digitar o cpf 
	scanf("%s", cpf);//lê as informações
	
	FILE *file;//faz uma busca no computador usando o nome e tipo
	file = fopen(cpf, "r"); //abre e lê o arquivo "file"
	fclose(file);//fecha o arquivo
	
	if(file == NULL)//se file for idêntico a nulo...
	{
		printf("\nUsuário não encontrado!\n");//diz ao usuário que não foi encontrado nenhuma correspondência
		system("pause");//pausa o sistema
	}
	
	remove(cpf);//remove um dado fornecido
	
	if(file != NULL)//se file for diferente de nulo...
	{
		printf("\nUsuário deletado com sucesso!\n");//confirma a remoção para o usuário
		system("pause");//pausa o sistema
		
	}
	
	
}


int main()//função principal
    {
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1; laco=1;)//repetição
	{
		
	system("cls");//limpa o que foi escrito
		
    setlocale(LC_ALL, "Portuguese"); //definindo a língua
	
		printf("\t####Cartório da EBAC#### \n\n"); //ínicio do menu
		printf("\Escolha a opção desejada no menu abaixo: \n");//mostra as opções pro usuário
		printf("\t1-Registrar nome \n");
		printf("\t2-Consultar nome \n");
		printf("\t3-Deletar nome \n"); 
		printf("\t4-Sair do sistema \n");
		printf("Opção:"); //fim do menu
	
		scanf("%d",&opcao); //armazenando escolhas do usuário
	
		system("cls");//limpa a tela
		
		
		switch(opcao)//opções do menu
		{
			case 1://caso a opção escolhida seja 1...
			registro();//executa a função registro...
			break;//e finaliza
			
			case 2://caso a opção escolhida seja 2...
			consulta();//executa a função consulta...
			break;//e finaliza
			
			case 3://caso a opção escolhida seja 3...
			deletar();//executa a função deletar...
			break;//e finaliza
			
			case 4://caso a opção escolhida seja 4...
			printf("Obrigado por utilizar o sistema! \n");//mostre a mensagem na tela do usuário...
			return 0;//finalize o programa e saia
			break;

			default://caso a opção seja diferente das disponíveis...
			printf("Essa opção não está disponível! \n");//diz ao usuário que não foi possível executar...
			system("pause");//e finaliza
			break;
			//fim da seleção
		}	
	}		
}

