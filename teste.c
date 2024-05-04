#include<stdio.h>
#include <stdlib.h>
#define TAM_TEX_MAXIMO 400

typedef struct PERSONAGEM{
		char nome[50];
		int HP;
		int ATK;
		int DEF;
		int posicao;
}PERSONAGEM;

typedef struct INIMIGO{
		char nome[50];
		int HP;
		int ATK;
		int DEF;
		int posicao;
}INIMIGO;

void atual();
void mover(int posicao, PERSONAGEM *personagem);
void combate(PERSONAGEM *personagem, INIMIGO *inimigo);
void menu();
int rolagem_dado(int faces);
void status_personagem(PERSONAGEM personagem);
void limpar_tela();
PERSONAGEM *criarPersonagem();


int main(){
	int parar = 1;
	menu();
	PERSONAGEM personagem;
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

	/*while(parar){
		atual();
	}*/
	return 0;
}
//CRIA PERSONAGEM
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
//FUNÇÃO MENU
void menu(){
	int escolha=0, parar=1;
	//char nickname[51]
	
	while(parar!=0){
		
		printf("Escolha entre as opcoes numeradas:\n\n|1-Novo Jogo\n|2-Continuar\n|3-Ranking\n|4-Desenvolvedores\n|0-Fechar Programa\n\n");
		printf("Digite o numero da opcao: ");
		scanf("%d", &escolha);
		
		if(escolha == 1){
			system("cls");
			escolha = 0;
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
//PRINTA OS ATRIBUTOS E POSIÇÃO DO PERSONAGEM
void status_personagem(PERSONAGEM personagem){
	printf("Nome:%s\nHP:%i\nAtaque:%i\nDefesa%i\nAndamento:%i", personagem.nome,personagem.HP, personagem.ATK, personagem.DEF, personagem.posicao);
}
//ROLA DADOS PARA A BATALHA
int rolagem_dado(int faces){
	int resultado;
	resultado = rand() % faces + 1;
	return resultado;
}
//LIMPA O TERMINAL
void limpar_tela(){
	system("cls");
}
