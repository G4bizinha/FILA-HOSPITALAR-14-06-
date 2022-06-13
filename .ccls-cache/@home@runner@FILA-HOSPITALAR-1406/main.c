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

//var globais
int tam; // guarda o tamanho da fila
int amarelo; // guarda a posição da fila amarela
int verde;// guarda a posiçãoda fila verde
  
  struct Paciente{
   	int valor;
  	char nome[20];
		char sobrenome[20];
		char prioridade;
		int posicao;
   struct Node *prox;
  };

typedef struct Paciente paciente;


void inserir(paciente **p){
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
}//Inserir

void remover(paciente *p){
	
	paciente  *aux = p;
	
	if(p == NULL){
		printf("❗ fila vazia...");
	}
	
		while(p !=NULL){
			p = p->prox;
			free(aux);
			printf("✔ Paciente removido com sucesso...");
		}
	}

void pesquisar(paciente *p){
	char nome[20] , sobrenome[20];
  printf("Qual o nome do paciente que você deseja procurar?");
	printf("Digite o nome: ");
	scanf("%s %s" , nome , sobrenome);
}

void mostraLista(paciente *p){
	printf("Lista: \n ");
    while(p != NULL){		
				printf("-> Paciente: ");
        printf("%d \n", p->valor);
				printf("Nome : ");
				printf("%s ", p->nome);
				printf("%s", p->sobrenome);
				printf("\n ");
        p = p->prox;
    }
}

void mostraListaTipoUrg(paciente *p){
	char prioridade;
	printf("qual a urgência?");
  scanf("%c" , &prioridade);


	if(p->prioridade == 'V' || p-> prioridade == 'v'){
    printf("Lista: \n ");
    while(p != NULL){		
				printf("-> Paciente: ");
        printf("%d \n", p->valor);
				printf("Nome : ");
				printf("%s ", p->nome);
				printf("%s", p->sobrenome);
        printf("Prioridade: ");
        printf("%c" , p->prioridade);
				printf("\n ");
        p = p->prox;
		
	  }//while
  }//if
    else if(p->prioridade == 'A' || p-> prioridade == 'a'){
    printf("Lista: \n ");
    while(p != NULL){		
				printf("-> Paciente: ");
        printf("%d \n", p->valor);
				printf("Nome : ");
				printf("%s ", p->nome);
				printf("%s", p->sobrenome);
        printf("Prioridade: ");
        printf("%c" , p->prioridade);
				printf("\n ");
        p = p->prox;
    }//while
  }//else if   
}//void lista tipo urgência

void consultarFila(paciente *p){
  
	
}

int main(void){ 
	paciente *inicio = NULL;
  char opcao = 's';

	do{
		printf(AZUL" \n \n ------------------ Menu ---------------- \n" RESET);
		printf(" 1 - 📝Cadastrar Paciente \n");
		printf(" 2 - 🚶Remover Paciente \n");
		printf(" 3 - 🔍Pesquisar Paciente por nível de urgência \n");
		printf(" 4 - 📋Visualizar fila completa \n");
		printf(" 5 - 📋Visualizar fila por tipo de urgência \n");
		printf(" 6 - 📋Consultar situação da fila \n");
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

		case 2:
			remover(inicio);
		break;

    case 3:
      pesquisar(p);
    break;
    
    case 4:
			mostraLista(inicio);
    break;

    case 5:
      mostraListaTipoUrg(p);
    break;

		case 6: //consultar situação da fila
			consultarFila();
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