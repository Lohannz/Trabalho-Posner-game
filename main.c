#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "struct.h"
#include "combate.h"
#include "logo.h"

#include "item.h"


int pagina = 1;
#define TAM_TEX_MAXIMO 400
#define time_sleep sleep(0)
#define TAM_VET_SAVE 1000


void usar_item(ITEM item, PERSONAGEM *personagem);
void gerar_item(ITEM *item, char *nome_item, int bonus_ataque, int bonus_vida, PERSONAGEM *personagem);
void printar_inventario(PERSONAGEM *personagem);

void pausar();
void imprimir_menu();
void save(PERSONAGEM *personagem);// fun��es que gravam e carregam informa��es do jogo
void load(PERSONAGEM **personagem);//
void menu_principal();//menu principal do jogo
void ranking();
void atual(int pagina, PERSONAGEM *novo_personagem);// diz em que pagina/parte o personagem est�
void mover(int posicao, PERSONAGEM *personagem);//a��o de mover
void olhar(int posicao);//a��o de olhar a posi��o do jogador
void combate(PERSONAGEM *atacante, INIMIGO *inimigo);//combate
void morte(PERSONAGEM *personagem);
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
	
	menu_principal(&novo_personagem);
	combate(novo_personagem, &esqueleto);

	while(rodando){	
	int nova_posicao;
	
	
	char comando;
	limpar_tela();

	atual(novo_personagem->posicao, novo_personagem);
	imprimir_menu();
	scanf(" %c", &comando);

	switch (toupper(comando)){

		case 'E':// PRECISA CONSERTAR
			printar_inventario(novo_personagem);
			pausar();
			break;

		case 'S':
			status_personagem(*novo_personagem);
			pausar();
			break;
		
		case 'M':// PRECISA MUDAR PARA IR PARA FRENTE, E NAO PARA QUALQUER LUGAR DO LIVRO/HISTORIA
			printf("digite a nova posicao: ");
			scanf("%i", &nova_posicao);
			mover(nova_posicao, novo_personagem);
			limpar_tela();
			pausar();
			break;

		case 'C': {
                INIMIGO inimigo = gerar_mob(1); //pode usar diferentes tipos para gerar diferentes inimigos TIPOS ->COMBATE.C
                combate(novo_personagem, &inimigo);
                break;
            }
		case 'Q':
			rodando = 0;
			break;
		case 'P':

			save(novo_personagem);//salva os atributos do personagem
			pausar();
			break;
		case 'I':
			menu_principal(&novo_personagem);
			break;
		default:
			printf("comando invalido\n");
			break;
		}
	}
	
	//NAO SEI COMO VAI FUNCIONAR 

	/*//GRAVAÇÃO DA POSIÇÃO NA HISTORIA
	FILE *gravar;
	gravar = fopen("historia.dat", "wb");
	char texto[TAM_TEX_MAXIMO];
	fgets(texto,TAM_TEX_MAXIMO, stdin);
	fwrite(texto, sizeof(texto), 1, gravar);
	fgets(texto, TAM_TEX_MAXIMO, stdin);
	fwrite(texto, sizeof(texto), 1, gravar);
	fclose(gravar);
	*/

	free(novo_personagem); //liberar memória alocada
	return 0;
}
void menu_principal(PERSONAGEM **novo_personagem){
    int escolha=0; int rodando = 1;

	while(rodando){
		logo();
		printf("\n\n\t\t\t\t\t\t\t\t\t|1-Novo Jogo");time_sleep;
		printf("\n\t\t\t\t\t\t\t\t\t|2-Continuar");time_sleep;
		printf("\n\t\t\t\t\t\t\t\t\t|3-Ranking");time_sleep;
		printf("\n\t\t\t\t\t\t\t\t\t|4-Desenvolvedores");time_sleep;
		printf("\n\t\t\t\t\t\t\t\t\t|0-Fechar Programa\n\t\t\t\t\t\t\t\t\t");time_sleep;

		scanf("%d", &escolha);
		
		limpar_tela();
        switch (escolha){
        case 1:
        //chama a criação de personagem
            
			*novo_personagem = criarPersonagem();
			rodando = 0;
            break;
		
        case 2:// continua de onde parou no ultimo save
            limpar_tela();
            load(novo_personagem);
			rodando = 0;
			pausar();
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
	printf("|1-Guerreiro\n");time_sleep;
	printf("|2-Arqueiro\n");time_sleep;
	printf("|3-Paladino\n");time_sleep;
	printf("Sua escolha:");time_sleep;
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

	}time_sleep;
	novo_personagem->posicao = 0;
	novo_personagem->pontos = 0;
	novo_personagem->qnt_itens = 0;
	limpar_tela();
	printf("Agora, escolha o seu nome: ");
	scanf("%s", novo_personagem->nome);
	limpar_tela();
	time_sleep;
	printf("Seu personagem foi criado!");
	printf("\nSeus atributos sao:\nHP %i\nATAQUE %i\nDEFESA %i",novo_personagem->HP, novo_personagem->ATK, novo_personagem->DEF);time_sleep;
	pausar();
	limpar_tela();
	return novo_personagem;
}
//PRINTA OS ATRIBUTOS E POSIÇÃO DO PERSONAGEM
void status_personagem(PERSONAGEM personagem){
	printf("Nome:%s\nHP:%i\nAtaque:%i\nDefesa:%i\nPontos:%i\nAndamento:%i", personagem.nome,personagem.HP, personagem.ATK, personagem.DEF, personagem.pontos,personagem.posicao);
}
void limpar_tela(){
	system("cls");
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
void mover(int nova_posicao, PERSONAGEM *novo_personagem){
	novo_personagem->posicao = nova_posicao;

}
void pausar() {
    
    fflush(stdin);
    getchar();
}
void imprimir_menu()	
		{
		printf("%10s %10s %10s %10s %10s %10s %10s \n", "[E] Inventario", "[S] Status", "[M] Mover", "[C] combate", "[Q] Sair", "[P] Salvar", "[I] Menu");
		}
//funcao que salva o atributos do personagem
void save(PERSONAGEM *personagem){
	//cria um ponteiro para o arquivo saves.dat
	FILE *fp;
	fp = fopen("saves.dat", "wb");
	// se nao existe, cria um
	if (fp == NULL) {
        printf("Não foi possível abrir o arquivo para salvar.\n");
        return;
    }
	//se nao for possivel gravar, printa isso ai
	if(fwrite(personagem, sizeof(PERSONAGEM), 1, fp) != 1){
		printf("não foi possivel gravar!");
	}
	//se o arquivo gravar, printa isso ai
	else if(fwrite(personagem, sizeof(PERSONAGEM), 1, fp) == 1)
		printf("jogo gravado com sucesso!");
	fclose(fp);
}
//função que carrega o ultimo save
void load(PERSONAGEM **personagem) {
    FILE *fp = fopen("saves.dat", "rb");
    if (fp == NULL){
        printf("Não foi possível abrir o arquivo de save!\n");
        return;
    }
    *personagem = (PERSONAGEM*) malloc(sizeof(PERSONAGEM));
    if(*personagem == NULL){
        printf("Não foi possível alocar memória!\n");
        fclose(fp);
        return;
    }

    if(fread(*personagem, sizeof(PERSONAGEM), 1, fp) != 1){
        printf("Não leu do arquivo saves.dat\n");
        free(*personagem);
        *personagem = NULL;
    }
	else{
        printf("Jogo carregado com sucesso!\n");
		limpar_tela();
        status_personagem(**personagem);
    }

    fclose(fp);
}
void atual(int pagina, PERSONAGEM *novo_personagem){
	FILE *fp;
		char texto[TAM_TEX_MAXIMO];
		fp = fopen("historia.dat", "rb");
		fseek(fp, pagina * TAM_TEX_MAXIMO * sizeof(char), SEEK_SET);
		fread(texto, sizeof(texto), 1, fp);
		printf("%s\n", texto);
		fclose(fp);
	if(strstr(texto, "espada") !=NULL){
		ITEM espada;
		gerar_item(&espada,"espada flamenjante", 10, 0, novo_personagem);
	}
}
void ranking(){};