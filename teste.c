#include<stdio.h>
#include "menu.h"
#include "criarpersonagem.h"
typedef struct PERSONAGEM{
		char nome[51];
		int HP;
		int ATK;
		int DEF;
	}PERSONAGEM;
	
void menu();
void criarPersonagem(PERSONAGEM *personagem);

int main(){
	PERSONAGEM personagem;
	menu();
	criarPersonagem(&personagem);
	
	return 0;
}

void criarPersonagem(PERSONAGEM *personagem){
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
}

