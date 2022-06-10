#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <string.h>
#include <unistd.h>

int controleMenu=1;

// sistema de cores
#define VERDE "\x1b[32m"  
#define AMARELO "\x1b[93m"
#define VERMELHO "\x1b[31m"
#define AZUL "\x1b[34m"
#define RESET "\x1b[0m"
  
  struct Paciente{
   	int valor;
  	char nome[20];
		char sobrenome[20];
		char prioridade;
   struct Node *prox;
  };

typedef struct Paciente paciente;

void inserir(paciente **p)
{
    paciente *atual, *novo, *anterior;
	
    int num;
		char nome[20] , sobrenome[20];

    novo = (paciente *) malloc(sizeof(paciente));

    atual = *p;
    anterior = NULL;

    printf("Insira um valor: ");
    scanf("%d", &num);
		printf("Digite o nome completo:");
		scanf("%s%s" , nome , sobrenome);

    novo->valor = num;
		strcpy( novo->nome, nome);
		strcpy( novo->sobrenome, sobrenome);

    if(atual == NULL){
        novo->prox = NULL;
        *p = novo;
    } else{
      
        while(atual != NULL && atual->valor < num){
            anterior = atual;
            atual = atual->prox;
        }

        novo->prox = atual;

        if(anterior == NULL){
            *p = novo;
        } else{
            anterior->prox = novo;
        }
    }
}

void mostraLista(paciente *p){
	printf("Lista: \n \n");
    while(p != NULL)
    {		
				printf("-> Paciente: ");
        printf("%d \n", p->valor);
				printf("Nome : ");
				printf("%s ", p->nome);
				printf("%s", p->sobrenome);
				printf("\n\n");
        p = p->prox;
    }
}

int main(void){ 

	paciente *inicio = NULL;
  char opcao = 's';

	do{
		printf(AZUL" \n \n ------------------ Menu ---------------- \n" RESET);
		printf(" 1 - 📝Cadastrar Paciente \n 2 - 🚶Remover Paciente \n 3 - 🔍Pesquisar Paciente por nível de urgência \n");
		printf(" 4 - 📋Visualizar fila completa \n 5 - 📋Visualizar fila por tipo de urgência \n 6 - 📋Consultar situação da fila \n");
		printf(" 7 - Sair 👋\n");
		printf("Digite uma Opção: ");
		int op;
		scanf("%d", &op);
		printf(AZUL"---------------------------------------- \n \n " RESET);

	switch(op){

		case 1:
			
			   while( opcao == 's' || opcao == 'S' ){
        	inserir(&inicio);

        	printf("Deseja inserir outro paciente ? (S/N)\n");
        	scanf(" %c", &opcao);
    		}
		break;
    
    case 4:
			mostraLista(inicio);
    break;

    case 7:
      printf("Saindo... \n");
			exit(1);
    break;

    default:

      printf("Digite uma opção válida \n");
	}
	
	}while(controleMenu ==1);

}