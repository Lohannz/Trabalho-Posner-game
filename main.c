#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "struct.h"
#include "combate.h"
#include "menu_principal.h"

#define TAM_TEX_MAXIMO 400


void load();
void atual();
void mover(int posicao, PERSONAGEM *personagem);
void combate(PERSONAGEM *atacante, INIMIGO *inimigo);
void menu();
int rolagem_dado(int faces);
void status_personagem(PERSONAGEM personagem);
void limpar_tela();
PERSONAGEM *criarPersonagem();


int main(){
	PERSONAGEM *personagem = NULL;
	INIMIGO esqueleto;
	strcpy(esqueleto.nome,"esqueleto");
	esqueleto.id = 1;
	esqueleto.HP = 100;
	esqueleto.ATK = 2;
	esqueleto.DEF = 1;
	esqueleto.posicao = 1;

	menu_principal(); 

	
	//GRAVAÇÃO DA POSIÇÃO NA HISTORIA
	FILE *gravar;
	gravar = fopen("historia.dat", "wb");
	char texto[TAM_TEX_MAXIMO];
	fgets(texto,TAM_TEX_MAXIMO, stdin);
	fwrite(texto, sizeof(texto), 1, gravar);
	fgets(texto, TAM_TEX_MAXIMO, stdin);
	fwrite(texto, sizeof(texto), 1, gravar);
	fclose(gravar);
	
	//ANDAMENTO DA HISTÓRIA

	/*while(rodando){
		atual();
	}*/

	free(personagem); // Liberar memória alocada
	return 0;
}
//CRIA PERSONAGEM
PERSONAGEM *criarPersonagem(){
	
	PERSONAGEM *novo_personagem = (PERSONAGEM*) malloc(sizeof(PERSONAGEM));
	int classe=0;
	
	printf("Primeiro de tudo, escolha sua classe:\n|1-Guerreiro\n|2-Arqueiro\n|3-Paladino\n");
	
	while(classe < 1 || classe > 3){
		scanf("%d", &classe);
		switch (classe){
		case 1:
			printf("Voce escolheu o guerreiro");
			novo_personagem->HP = 120;
			novo_personagem->ATK = 2;
			novo_personagem->DEF = 2;
			break;
		case 2:
			printf("Voce escolheu o arqueiro");
			novo_personagem->HP = 100;
			novo_personagem->ATK = 4;
			novo_personagem->DEF = 1;
			break;
		case 3:
			printf("Voce escolheu o paladino");
			novo_personagem->HP = 130;
			novo_personagem->ATK = 1;
			novo_personagem->DEF = 4;
			break;
		}	
	}
	
	printf("\nAgora, escolha o seu nome: ");
	scanf("%s", novo_personagem->nome);
	printf("Seu personagem foi criado!\nSeus atributos sao:\nHP %i\nATAQUE %i\nDEFESA %i", novo_personagem->HP, novo_personagem->ATK, novo_personagem->DEF);
	return novo_personagem;
}
//PRINTA OS ATRIBUTOS E POSIÇÃO DO PERSONAGEM
void status_personagem(PERSONAGEM personagem){
	printf("Nome:%s\nHP:%i\nAtaque:%i\nDefesa%i\nAndamento:%i", personagem.nome,personagem.HP, personagem.ATK, personagem.DEF, personagem.posicao);
}
//LIMPA O TERMINAL
void limpar_tela(){
	system("cls");
}

