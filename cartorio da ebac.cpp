#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocção de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // Função responsavel por cadastra os usuários no sistema
{
	// Inicio da criação de variaveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Final da cria~çao de variaveis/string
    
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf); //%S Refere-se a string

    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
    
    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w");// cria o arquivo e o-"w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel 
	fclose(file); // fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");   
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%S",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%S", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%S",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");    
    
    
}

int consulta()
{
	setlocale(LC_ALL,"portuguese");// Definindo a linguagem
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite op CPF a ser consultado:");
    scanf("%S",cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
    	  printf("não foi possivel abrir o arquivo, nocalizado!. \n");
	}
   
    while(fgets(conteudo, 200, file) != NULL )
	{
		printf("\nEssas são as informaçôes do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	  
    system("pause");
   
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf(" O usuario não se encontra no sitema!.\n");
		system("pause");
	}
	
}



int main()

{
	int opcao=8; // Definindo variâveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
	   system("cls"); 
		
	    setlocale(LC_ALL,"portuguese");// Definindo a linguagem
	
	    printf("### Cartorio da EBAC ###\n\n");//Inicio do menu 
      	printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - registrar nomes\n");
	    printf("\t2 - consultar nomes\n");
	    printf("\t3 - deletar nomes\n\n");
     	printf("opção:");// Fim do menu 

        scanf("%d", &opcao); // Armazendando a escolha do ususario
   
        system("cls"); //responsavel por limpar a tela
         
        switch(opcao) //inicio da seleção do menu
        {
            case 1:	
            registro(); //chamada de funções 
            break;
             
            case 2:
		    consulta();
            break;
             
            case 3:
            deletar();	
            break;
            
            default: 
            printf("essa opcao não está disponivel!\n");
     	    system("pause");
     	    break;	    
        }  //fim da seleção

    }
}
