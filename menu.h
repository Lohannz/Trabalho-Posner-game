#include<stdio.h>
#include <stdlib.h>

typedef struct PERSONAGEM{
		char nome[51];
		int HP;
		int ATK;
		int DEF;
	}PERSONAGEM;
	
void menu();
PERSONAGEM *criarPersonagem();

int main(){
	
	menu();
	return 0;
}

PERSONAGEM *criarPersonagem(){
	PERSONAGEM *personagem = (PERSONAGEM*) malloc(sizeof(PERSONAGEM));
	int classe=0;
	
	printf("Primeiro de tudo, escolha sua classe:\n|1-Guerreiro\n|2-Arqueiro\n|3-Paladino\n");
	
	while(classe < 1 || classe > 3){
		scanf("%d", &classe);
		switch (classe){
		case 1:
			printf("Voce escolheu o guerreiro");
			personagem->HP = 120;
			personagem->ATK = 2;
			personagem->DEF = 2;
			break;
		case 2:
			printf("Voce escolheu o arqueiro");
			personagem->HP = 100;
			personagem->ATK = 4;
			personagem->DEF = 1;
			break;
		case 3:
			printf("Voce escolheu o paladino");
			personagem->HP = 130;
			personagem->ATK = 1;
			personagem->DEF = 4;
			break;
		}	
	}
	
	printf("\nAgora, escolha o seu nome: ");
	scanf("%s", personagem->nome);
	printf("Seu personagem foi criado!\nSeus atributos sao:\nHP %i\nATAQUE %i\nDEFESA %i", personagem->HP, personagem->ATK, personagem->DEF);
	return personagem;
}


void menu(){
	int escolha=0, parar=1;
	//char nickname[51]
	
	while(parar!=0){
		
		printf("Escolha entre as opcoes numeradas:\n\n|1-Novo Jogo\n|2-Continuar\n|3-Ranking\n|4-Desenvolvedores\n|0-Fechar Programa\n\n");
		printf("Digite o numero da opcao: ");
		scanf("%d", &escolha);
		
		if(escolha == 1){
			system("cls");
		/*printf("Bem vindo a criacao de personagem!\n\n");
			printf("Digite o seu nickname(no maximo 50 caracteres): ");
			scanf("%s", nickname);
			printf("\n\nSeja bem vindo(a) %s!\nAqui no mundo de xurumelas existem 4 classes: guerreiros, magos, arqueiros e clerigos.", nickname);*/
			
			PERSONAGEM *personagem = criarPersonagem();
	
			printf("\n\nDigite 1 para voltar ao menu e 0 para fechar o jogo: ");
			scanf("%d", &escolha);
			if(escolha == 1){
				parar = 1;
				system("cls");
				
			}else{
				parar = 0;
			}
		}else if(escolha == 2){
			system("cls");
			printf("\nvoce escolheu a opcao %d", escolha);
			printf("\n\nDigite 1 para voltar ao menu e 0 para fechar o jogo: ");
			scanf("%d", &escolha);
			if(escolha == 1){
				parar = 1;
				system("cls");
				
			}else{
				parar = 0;
			}
		} else if(escolha == 3){
			system("cls");
			printf("\nvoce escolheu a opcao %d", escolha);
			printf("\n\nDigite 1 para voltar ao menu e 0 para fechar o jogo: ");
			scanf("%d", &escolha);
			if(escolha == 1){
				parar = 1;
				system("cls");
				
			}else{
				parar = 0;
			}
		} else if(escolha == 4){
			system("cls");
			printf("Gustavo Simplicio Bernardo\nLohan :Nerd_Emoji:\nCalango");
			printf("\n\nDigite 1 para voltar ao menu e 0 para fechar o jogo: ");
			scanf("%d", &escolha);
			if(escolha == 1){
				parar = 1;
				system("cls");
				
			}else{
				parar = 0;
			}
		}else if(escolha ==0){
			parar = 0;
		}else{
			system("cls");
			printf("\nopcao nao existente!");
			printf("\n\nDigite 1 para voltar ao menu e 0 para fechar o jogo: ");
			scanf("%d", &escolha);
			if(escolha == 1){
				parar = 1;
				system("cls");
				
			}else{
				parar = 0;
			}
		}
	
	}
}
