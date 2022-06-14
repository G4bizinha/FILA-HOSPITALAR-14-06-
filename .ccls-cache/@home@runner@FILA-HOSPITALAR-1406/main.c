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
   	int posicao;
  	char nome[20];
		char sobrenome[20];
		char prioridade;
   struct Node *prox;
  };

typedef struct Paciente paciente;


void inserir(paciente **p){
  printf(AZUL" \n \n ----- 📝Cadastrar Paciente ----- \n" RESET);
	tam++;
    paciente *atual, *novo, *anterior;
	
    
		char nome[20] , sobrenome[20];

    novo = (paciente *) malloc(sizeof(paciente));

    atual = *p;
    anterior = NULL;


		printf("Digite o nome completo: ");
		scanf("%s%s" , nome , sobrenome);
    printf("\n \n");

    novo->posicao = tam;
		strcpy( novo->nome, nome);
		strcpy( novo->sobrenome, sobrenome);

    if(atual == NULL){
        novo->prox = NULL;
        *p = novo;
    } else{
      
        while(atual != NULL && atual->posicao < tam){
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

void remover(paciente **p){
  printf(AZUL" \n \n ----- 🚶Remover Paciente ----- \n" RESET);
	
	paciente  *atual = *p;
	
	if(atual == 0){
		printf(VERMELHO"❗ fila vazia..."RESET);
	}
	
		while(atual !=NULL){
			atual = atual->prox;
			*p = atual;
	
			printf(VERDE"✔ Paciente removido com sucesso..."RESET);
		}
	tam--;
	}

void pesquisar(paciente *p){
  printf(AZUL" \n \n ----- 🔍Pesquisar Paciente por Nível de Urgência ----- \n" RESET);
	char nome[20] , sobrenome[20];
  printf("Qual o nome do paciente que você deseja procurar?");
	printf("Digite o nome: ");
	scanf("%s %s" , nome , sobrenome);

	while(p !=NULL){
		if( p->nome == nome && p->sobrenome == sobrenome){
				printf("-> Paciente: ");
        printf("%d \n", p->posicao);
				printf("Nome : ");
				printf("%s ", p->nome);
				printf("%s", p->sobrenome);
				printf("\n \n");
		}
	}
}//void pesquisar

void mostraLista(paciente *p){
   printf(AZUL" \n \n ----- 📋Visualizar Fila Completa ----- \n" RESET);
	printf("Lista: \n ");
    while(p != NULL){		
				printf("-> Paciente: ");
        printf("%d \n", p->posicao);
				printf("Nome : ");
				printf("%s ", p->nome);
				printf("%s", p->sobrenome);
				printf("\n \n");
        p = p->prox;
    }
}

void mostraListaTipoUrg(paciente *p){
  printf(AZUL" \n \n ----- 📋Visualizar Fila por tipo de Urgência ----- \n" RESET);
	char prioridade;
	printf("qual a urgência?");
	printf(VERDE" V - verde"RESET);
  printf("|"); 
  printf(AMARELO"A- Amarelo"RESET);
  scanf("%c" , &prioridade);

	switch(prioridade)
		{
			case 'V':
      case 'v':

				 printf("Lista: \n ");
		    while(p != NULL){		
					if(p->prioridade == 'V' || p-> prioridade == 'v'){
						printf("-> Paciente: ");
		        printf("%d \n", p->posicao);
						printf("Nome : ");
						printf("%s ", p->nome);
						printf("%s", p->sobrenome);
		        printf("Prioridade: ");
		        printf("%c" , p->prioridade);
						printf("\n ");
		        p = p->prox;
			  }//if
		  }//while
				
			break;

			case 'A':
				case'a':

				printf("Lista: \n ");
		    while(p != NULL){		
					if(p->prioridade == 'A' || p-> prioridade == 'a'){
						printf("-> Paciente: ");
		        printf("%d \n", p->posicao);
						printf("Nome : ");
						printf("%s ", p->nome);
						printf("%s", p->sobrenome);
		        printf("Prioridade: ");
		        printf("%c" , p->prioridade);
						printf("\n ");
		        p = p->prox;
		    }//if
		  }//while

			break;

			default:
			 printf("digite uma opção valida");
		}
}//void lista tipo urgência

void consultarFila(paciente *p){
 	printf(AZUL" \n \n ----- 📋Consultar Situação da Fila ----- \n" RESET);
	printf("Tamanho da fila: ");
	printf("%d" , tam);
	printf(" \n");	
	printf("Posições ocupadas: ");
	printf("%d" , tam); 
	printf(" de 80 ocupadas\n");
	printf("Posições livres: ");
	printf("%d" , 80  - tam); 
	printf(" \n");
}

int main(void){ 
	paciente *inicio = NULL;
  char opcao = 's';

	do{
		printf(AZUL" \n \n ------------------ Menu ---------------- \n" RESET);
		printf(" 1 - 📝Cadastrar Paciente \n");
		printf(" 2 - 🚶Remover Paciente \n");
		printf(" 3 - 🔍Pesquisar Paciente por Nível de Urgência \n");
		printf(" 4 - 📋Visualizar Fila Completa \n");
		printf(" 5 - 📋Visualizar Fila por tipo de Urgência \n");
		printf(" 6 - 📋Consultar Situação da Fila \n");
		printf(" 7 - Sair 👋\n");
		printf("Digite uma Opção: ");
		int op;
		scanf("%d", &op);
		printf(AZUL"---------------------------------------- \n \n " RESET);

	switch(op){

		case 1:
			if(tam <81){
				while( opcao == 's' || opcao == 'S' ){
        	inserir(&inicio);
        	printf("Deseja inserir outro paciente ? (S/N)\n");
        	scanf(" %c", &opcao);
			}
    }else{
				printf("Todos os leitos estão ocupados \n");
		}
		break;

		case 2:
			remover(&inicio);
		break;

    case 3:
      pesquisar(inicio);
    break;
    
    case 4:
			mostraLista(inicio);
    break;

    case 5:
      mostraListaTipoUrg(inicio);
    break;

		case 6: 
			consultarFila(inicio);
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