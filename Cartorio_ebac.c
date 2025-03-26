#include <stdio.h>//Biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//Biblioteca de aloca��o de espa�o na mem�ria 
#include <locale.h>//Biblioteca de aloca��o de texto por regi�o
#include <string.h>//Biblioteca das strings

int Registrar() //fun��o respons�vel por cadastrar os usu�rios 
{
	    //cria��o das vari�veis
	    char arquivo[40];
    	char cpf[40];
    	char nome[40];
    	char sobrenome[40];
    	char cargo[40];
    	//Final da cria��o das vari�veis 
    	
    	printf("Digite o cpf: ");//Coletando informa��es do usu�rio
    	scanf("%s", cpf);//%s � para armazenar o valor digitado nas strings
    	
    	strcpy(arquivo, cpf);//Reponsavel por copiar os valores das strings
    	
    	FILE *file; //cria o arquivo
    	file= fopen(arquivo, "w");//cria o arquivo
    	fprintf(file,cpf);//salva o valor da vari�vel cpf
    	fclose(file);//fecha o arquivo
    	
    	file=fopen(arquivo, "a");//Abrindo a pasta e colocando o "a" de atualizar
    	fprintf(file,",");//adicionando a virgula na pasta 
    	fclose(file);//Fechando a pasta 
    	
    	printf("Digite o nome: ");//Coletando informa��es 
    	scanf("%s", nome);//adicionando o nome na string nome 
    	
    	file=fopen(arquivo, "a");//abrindo a pasta para atualizar 
    	fprintf(file,nome);//colocando o nome que est� na vari�vel "nome" na pasta 
    	fclose(file);//Fechando a pasta 
    	
    	file=fopen(arquivo, "a");//Abrindo a pasta para atualizar
    	fprintf(file,",");//Adicionando a virgula 
    	fclose(file);//Fechando apasta 
    	
    	printf("Digite o sobrenome: ");//Coletando informa��es 
    	scanf("%s", sobrenome);//adicionando o sobrenome na string sobrenome 
    	
    	file=fopen(arquivo, "a");//abrindo a pasta para atualizar 
    	fprintf(file, sobrenome);//colocando o sobrenome que est� na vari�vel "sobrenome" na pasta 
    	fclose(file);//Fechando a pasta
    	
    	file=fopen(arquivo, "a");//Abrindo a pasta para atualizar
    	fprintf(file,",");//Adicionando a virgula 
    	fclose(file);//Fechando apasta 
    	
    	printf("Digite o cargo: ");//Coletando informa��es 
    	scanf("%s", cargo);//adicionando o cargo na string sobrenome 
    	
    	file=fopen(arquivo, "a");//Abrindo a pasta para atualizar
    	fprintf(file, cargo);//colocando o cargo que est� na vari�vel "cargo" na pasta 
    	fclose(file);//Fechando a pasta  	
}

int Consultar()
{
	setlocale(LC_ALL,"portuguese"); //Definindo a linguagem
	
	//definindo as vari�veis 
	char cpf[40]; 
	char conteudo [200];
	
        printf("\tDigite o CPF a ser consultado: ");//Coletando informa��es
	    scanf("%s", cpf);//Adicinando a informa��o a string cpf
	    
	    FILE *file;//encontrando a pasta 
	    file=fopen(cpf, "r");//Abrindo a pasta cpf colocando "r" de ready 
	    
	    if(file==NULL)//Colocando a estrutura de decis�o if, se for nulo aparece a mensagem abaixo
	    {
	    	printf("\nN�o foi poss�vel localizar o arquivo\n");
		}
	    while(fgets(conteudo, 200, file)!=NULL)//Se for diferente de nulo, o programa mostra os dados da pasta
	    {
	    	printf("\nEssas s�o as informa��es do usu�rio: ");
	    	printf("%s", conteudo);
	    	printf("\n\n");
	    
		}
	    system("pause");
	    
}

int Deletar()
{
	  char cpf [40];//Cria��o da vari�vel 
	  
	  printf("Informe o CPF a ser deletado: ");//Coletando informa��es 
	  scanf("%s", cpf);//Adicionando a informa��o a string CPF 
	  
	  
	  remove(cpf);//Remove o que est� na pasta cpf
	  
	  FILE*file;//Encontrando a pasta 
	  file=fopen(cpf, "r");//Abrindo a pasta cpf e lendo 
	  
	  if (file==NULL)
	{
	  	printf("O usu�rio n�o se encontra no sistema. \n");
	  	system("pause"); 	
	} 
	  
	    
		
}


int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1; 
	for(laco=1;laco=1;)
	{
	  system("cls");
	  setlocale(LC_ALL,"portuguese"); //Definindo a linguagem
	
      printf("\tCART�RIO DA EBAC\n\n"); // In�cio do menu
      printf("\tEscolha umas das op��es abaixo\n\n");
      printf("\t1-Registrar nomes\n\n");
      printf("\t2-Consultar nomes\n\n");
      printf("\t3-Deletar nomes\n\n");
     
      
	  printf("Op��o: "); // Final do menu
    
      scanf("%d", &opcao); //Armazenando as op��es do usu�rio

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
	 	
	 
	 	
	 		
	 	
	
	    }//final da sele��o
     
    }
}

