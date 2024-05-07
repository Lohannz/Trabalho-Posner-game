#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "struct.h"
#include "combate.h"
#include "logo.h"

<<<<<<< HEAD
int pagina = 1;
#define TAM_TEX_MAXIMO 400

void imprimir_menu();
void save();// fun√ß√µes que gravam e carregam informa√ß√µes do jogo
=======

int pagina = 1;
#define TAM_TEX_MAXIMO 400
#define time_sleep sleep(0)
#define TAM_VET_SAVE 1000

void pausar();
void imprimir_menu();
void save();// funÁıes que gravam e carregam informaÁıes do jogo
>>>>>>> b53196fd0a27ae1dadec06e9f9b4bea4fa27679f
void load();//
void menu_principal();//menu principal do jogo
void atual(int pagina);// diz em que pagina/parte o personagem est·°
void mover(int posicao, PERSONAGEM *personagem);//aÁ„o de mover
void olhar(int posicao);//aÁ„o de olhar a posiÁ„o do jogador
void combate(PERSONAGEM *atacante, INIMIGO *inimigo);//combate
int rolagem_dado(int faces);// roda um dado
void status_personagem(PERSONAGEM personagem);//informa os atributos do jogador
void limpar_tela();//limpa o terminal
void final();//tela de final de jogo, recordes etc
PERSONAGEM *criarPersonagem();//cria personagem
PERSONAGEM *novo_personagem;

int main(){
	int rodando = 1;
	
	INIMIGO esqueleto;
	strcpy(esqueleto.nome,"esqueleto");
	esqueleto.id = 1;
	esqueleto.HP = 10;
	esqueleto.ATK = 2;
	esqueleto.DEF = 1;
	esqueleto.SPD = 10;
	esqueleto.posicao = 0;

	menu_principal();
	combate(novo_personagem, &esqueleto);

	while(rodando){	
	int nova_posicao;
	
	
	char comando;
	limpar_tela();

	atual(novo_personagem->posicao);
	imprimir_menu();
	scanf("%c", &comando);
<<<<<<< HEAD
	switch (comando){
=======
	switch (toupper(comando)){
>>>>>>> b53196fd0a27ae1dadec06e9f9b4bea4fa27679f
		case 'O':
			olhar(novo_personagem->posicao);
			pausar();
			break;
		case 'S':
			status_personagem(*novo_personagem);
			pausar();
			break;
		case 'M':
			printf("digite a nova posicao: ");
			scanf("%i", &nova_posicao);
			mover(nova_posicao, novo_personagem);
			pausar();
			break;
		case 'C':
			combate(novo_personagem, &esqueleto);
			break;
		case 'Q':
			rodando = 0;
			break;
<<<<<<< HEAD
=======
		case 'P':
			save(novo_personagem);
			break;
>>>>>>> b53196fd0a27ae1dadec06e9f9b4bea4fa27679f
		
		default:
			printf("comando invalido\n");
			break;
		}
	}
	

	//GRAVA√á√ÉO DA POSI√á√ÉO NA HISTORIA
	FILE *gravar;
	gravar = fopen("historia.dat", "wb");
	char texto[TAM_TEX_MAXIMO];
	fgets(texto,TAM_TEX_MAXIMO, stdin);
	fwrite(texto, sizeof(texto), 1, gravar);
	fgets(texto, TAM_TEX_MAXIMO, stdin);
	fwrite(texto, sizeof(texto), 1, gravar);
	fclose(gravar);
	
	//ANDAMENTO DA HIST√ìRIA

	/*while(rodando){
		atual();
	}*/

	free(novo_personagem); //liberar mem√≥ria alocada
	return 0;
}
void menu_principal(){
    int escolha=0; int rodando = 1;

	while(rodando){
		logo();
<<<<<<< HEAD
		printf("\n\n\t\t\t\t\t\t\t\t\t|1-Novo Jogo",sleep(1));
		printf("\n\t\t\t\t\t\t\t\t\t|2-Continuar", sleep(1));
		printf("\n\t\t\t\t\t\t\t\t\t|3-Ranking", sleep(1));
		printf("\n\t\t\t\t\t\t\t\t\t|4-Desenvolvedores", sleep(1));
		printf("\n\t\t\t\t\t\t\t\t\t|0-Fechar Programa\n\t\t\t\t\t\t\t\t\t", sleep(1));
=======
		printf("\n\n\t\t\t\t\t\t\t\t\t|1-Novo Jogo",time_sleep);
		printf("\n\t\t\t\t\t\t\t\t\t|2-Continuar", time_sleep);
		printf("\n\t\t\t\t\t\t\t\t\t|3-Ranking", time_sleep);
		printf("\n\t\t\t\t\t\t\t\t\t|4-Desenvolvedores", time_sleep);
		printf("\n\t\t\t\t\t\t\t\t\t|0-Fechar Programa\n\t\t\t\t\t\t\t\t\t", time_sleep);
>>>>>>> b53196fd0a27ae1dadec06e9f9b4bea4fa27679f

		scanf("%d", &escolha);
		
		limpar_tela();
        switch (escolha){
        case 1:
        //chama a cria√ß√£o de personagem
            
			novo_personagem = criarPersonagem();
			rodando = 0;
            break;
        case 2:
            limpar_tela();
            //load();
            break;
        
        case 3:
            printf("Ranking...");
            break;
        
        case 4:
            limpar_tela();
            printf("Fernando Brawl Stars\nGustavo Brawlhalla\nLohan\n");
            pausar();
            break;
		case 0:
			rodando = 0;
			break;
        

        default:
            break;
        }  
    }
}
//CRIA PERSONAGEM
PERSONAGEM *criarPersonagem(){
	
	PERSONAGEM *novo_personagem = (PERSONAGEM*) malloc(sizeof(PERSONAGEM));
	int classe=0;
	
	printf("Primeiro de tudo, escolha sua classe:\n");
<<<<<<< HEAD
	printf("|1-Guerreiro\n", sleep(1));
	printf("|2-Arqueiro\n",sleep(1));
	printf("|3-Paladino\n", sleep(1));
	printf("Sua escolha:", sleep(1));
=======
	printf("|1-Guerreiro\n", time_sleep);
	printf("|2-Arqueiro\n",time_sleep);
	printf("|3-Paladino\n", time_sleep);
	printf("Sua escolha:", time_sleep);
>>>>>>> b53196fd0a27ae1dadec06e9f9b4bea4fa27679f
	while(classe < 1 || classe > 3){
		scanf("%d", &classe);
		limpar_tela();
		switch (classe){
		case 1:
			printf("Voce escolheu o guerreiro");
			novo_personagem->HP = 12;
			novo_personagem->ATK = 2;
			novo_personagem->DEF = 2;
			novo_personagem->SPD = 11;
			break;
		case 2:
			printf("Voce escolheu o arqueiro");
			novo_personagem->HP = 10;
			novo_personagem->ATK = 4;
			novo_personagem->DEF = 1;
			novo_personagem->SPD = 30;
			break;
		case 3:
			printf("Voce escolheu o paladino");
			novo_personagem->HP = 14;
			novo_personagem->ATK = 1;
			novo_personagem->DEF = 4;
			novo_personagem->SPD = 9;
			break;
		
		default:
			printf("Classe invalidade. Tente novamente!");
			continue;
		}

<<<<<<< HEAD
	}sleep(1);
=======
	}time_sleep;
>>>>>>> b53196fd0a27ae1dadec06e9f9b4bea4fa27679f
	novo_personagem->posicao = 0;
	limpar_tela();
	printf("Agora, escolha o seu nome: ");
	scanf("%s", novo_personagem->nome);
	limpar_tela();
<<<<<<< HEAD
	sleep(1);
	printf("Seu personagem foi criado!");
	printf("\nSeus atributos sao:\nHP %i\nATAQUE %i\nDEFESA %i",novo_personagem->HP, novo_personagem->ATK, novo_personagem->DEF,sleep(1));
=======
	time_sleep;
	printf("Seu personagem foi criado!");
	printf("\nSeus atributos sao:\nHP %i\nATAQUE %i\nDEFESA %i",novo_personagem->HP, novo_personagem->ATK, novo_personagem->DEF,time_sleep);
>>>>>>> b53196fd0a27ae1dadec06e9f9b4bea4fa27679f
	pausar();
	limpar_tela();
	return novo_personagem;
}
//PRINTA OS ATRIBUTOS E POSI√á√ÉO DO PERSONAGEM
void status_personagem(PERSONAGEM personagem){
	printf("Nome:%s\nHP:%i\nAtaque:%i\nDefesa:%i\nAndamento:%i", personagem.nome,personagem.HP, personagem.ATK, personagem.DEF, personagem.posicao);
}
void limpar_tela(){
	system("cls");
}
void atual(int pagina){
	FILE *fp;
		char texto[TAM_TEX_MAXIMO];
		fp = fopen("historia.dat", "rb");
		fseek(fp, pagina * TAM_TEX_MAXIMO * sizeof(char), SEEK_SET);
		fread(texto, sizeof(texto), 1, fp);
		printf("%s\n", texto);
		fclose(fp);
		}
void olhar(int posicao){
	FILE *fp;
	char texto[TAM_TEX_MAXIMO];
	fp = fopen("olhar.dat", "rb");
	fseek(fp, posicao * TAM_TEX_MAXIMO * sizeof(char), SEEK_SET);
	fread(texto, sizeof(texto), 1, fp);
	printf("%s", texto);
	fclose(fp);
}
void mover(int posicao, PERSONAGEM *novo_personagem){
	novo_personagem->posicao = posicao;
	printf("voce avancou para a pagina %i\n", posicao);
}
<<<<<<< HEAD

=======
>>>>>>> b53196fd0a27ae1dadec06e9f9b4bea4fa27679f
void pausar() {
    
    fflush(stdin);
    getchar();
}
void imprimir_menu()	
		{
<<<<<<< HEAD
		printf("%10s %10s %10s %10s %10s\n", "[O] Olhar", "[S] Status", "[M] Mover", "[C] combate", "[Q] Sair");
		}
=======
		printf("%10s %10s %10s %10s %10s %10s\n", "[O] Olhar", "[S] Status", "[M] Mover", "[C] combate", "[Q] Sair", "[P] Salvar");
		}
void save(PERSONAGEM personagem){
	FILE *fp;
	fp = fopen("saves.dat", "wb");
	int status = personagem.HP;
	fwrite(status, sizeof(status), 1, fp);
	fclose(fp);
}
>>>>>>> b53196fd0a27ae1dadec06e9f9b4bea4fa27679f
