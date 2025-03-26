#include <stdio.h>//Biblioteca de comunicação com o usuário
#include <stdlib.h>//Biblioteca de alocação de espaço na memória 
#include <locale.h>//Biblioteca de alocação de texto por região
#include <string.h>//Biblioteca das strings

int Registrar() //função responsável por cadastrar os usuários 
{
	    //criação das variáveis
	    char arquivo[40];
    	char cpf[40];
    	char nome[40];
    	char sobrenome[40];
    	char cargo[40];
    	//Final da criação das variáveis 
    	
    	printf("Digite o cpf: ");//Coletando informações do usuário
    	scanf("%s", cpf);//%s é para armazenar o valor digitado nas strings
    	
    	strcpy(arquivo, cpf);//Reponsavel por copiar os valores das strings
    	
    	FILE *file; //cria o arquivo
    	file= fopen(arquivo, "w");//cria o arquivo
    	fprintf(file,cpf);//salva o valor da variável cpf
    	fclose(file);//fecha o arquivo
    	
    	file=fopen(arquivo, "a");//Abrindo a pasta e colocando o "a" de atualizar
    	fprintf(file,",");//adicionando a virgula na pasta 
    	fclose(file);//Fechando a pasta 
    	
    	printf("Digite o nome: ");//Coletando informações 
    	scanf("%s", nome);//adicionando o nome na string nome 
    	
    	file=fopen(arquivo, "a");//abrindo a pasta para atualizar 
    	fprintf(file,nome);//colocando o nome que está na variável "nome" na pasta 
    	fclose(file);//Fechando a pasta 
    	
    	file=fopen(arquivo, "a");//Abrindo a pasta para atualizar
    	fprintf(file,",");//Adicionando a virgula 
    	fclose(file);//Fechando apasta 
    	
    	printf("Digite o sobrenome: ");//Coletando informações 
    	scanf("%s", sobrenome);//adicionando o sobrenome na string sobrenome 
    	
    	file=fopen(arquivo, "a");//abrindo a pasta para atualizar 
    	fprintf(file, sobrenome);//colocando o sobrenome que está na variável "sobrenome" na pasta 
    	fclose(file);//Fechando a pasta
    	
    	file=fopen(arquivo, "a");//Abrindo a pasta para atualizar
    	fprintf(file,",");//Adicionando a virgula 
    	fclose(file);//Fechando apasta 
    	
    	printf("Digite o cargo: ");//Coletando informações 
    	scanf("%s", cargo);//adicionando o cargo na string sobrenome 
    	
    	file=fopen(arquivo, "a");//Abrindo a pasta para atualizar
    	fprintf(file, cargo);//colocando o cargo que está na variável "cargo" na pasta 
    	fclose(file);//Fechando a pasta  	
}

int Consultar()
{
	setlocale(LC_ALL,"portuguese"); //Definindo a linguagem
	
	//definindo as variáveis 
	char cpf[40]; 
	char conteudo [200];
	
        printf("\tDigite o CPF a ser consultado: ");//Coletando informações
	    scanf("%s", cpf);//Adicinando a informação a string cpf
	    
	    FILE *file;//encontrando a pasta 
	    file=fopen(cpf, "r");//Abrindo a pasta cpf colocando "r" de ready 
	    
	    if(file==NULL)//Colocando a estrutura de decisão if, se for nulo aparece a mensagem abaixo
	    {
	    	printf("\nNão foi possível localizar o arquivo\n");
		}
	    while(fgets(conteudo, 200, file)!=NULL)//Se for diferente de nulo, o programa mostra os dados da pasta
	    {
	    	printf("\nEssas são as informações do usuário: ");
	    	printf("%s", conteudo);
	    	printf("\n\n");
	    
		}
	    system("pause");
	    
}

int Deletar()
{
	  char cpf [40];//Criação da variável 
	  
	  printf("Informe o CPF a ser deletado: ");//Coletando informações 
	  scanf("%s", cpf);//Adicionando a informação a string CPF 
	  
	  
	  remove(cpf);//Remove o que está na pasta cpf
	  
	  FILE*file;//Encontrando a pasta 
	  file=fopen(cpf, "r");//Abrindo a pasta cpf e lendo 
	  
	  if (file==NULL)
	{
	  	printf("O usuário não se encontra no sistema. \n");
	  	system("pause"); 	
	} 
	  
	    
		
}


int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1; 
	for(laco=1;laco=1;)
	{
	  system("cls");
	  setlocale(LC_ALL,"portuguese"); //Definindo a linguagem
	
      printf("\tCARTÓRIO DA EBAC\n\n"); // Início do menu
      printf("\tEscolha umas das opções abaixo\n\n");
      printf("\t1-Registrar nomes\n\n");
      printf("\t2-Consultar nomes\n\n");
      printf("\t3-Deletar nomes\n\n");
     
      
	  printf("Opção: "); // Final do menu
    
      scanf("%d", &opcao); //Armazenando as opções do usuário

      system("cls");
      
      switch(opcao)
       {
      	case 1:
      	Registrar();
    	break;
    	
    	case 2:
    	Consultar();
	 	break;
	 	
	 	case 3:
	    Deletar();
	 	break;
	 	
	 
	 	
	 		
	 	
	
	    }//final da seleção
     
    }
}

