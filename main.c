#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "struct.h"
#include "combate.h"
#include "logo.h"

#define TAM_TEX_MAXIMO 400

void save();// funções que gravam e carregam informações do jogo
void load();//
void menu_principal();//menu principal do jogo
void atual(int pagina);// diz em que pagina/parte o personagem está
void mover(int posicao, PERSONAGEM *personagem);//ação de mover
void olhar(int posicao);//ação de olhar a posição do jogador
void combate(PERSONAGEM *atacante, INIMIGO *inimigo);//combate
int rolagem_dado(int faces);// roda um dado
void status_personagem(PERSONAGEM personagem);//informa os atributos do jogador
void limpar_tela();//limpa o terminal
void final();//tela de final de jogo, recordes etc
PERSONAGEM *criarPersonagem();//cria personagem
PERSONAGEM *novo_personagem;

int main(){
	
	INIMIGO esqueleto;
	strcpy(esqueleto.nome,"esqueleto");
	esqueleto.id = 1;
	esqueleto.HP = 100;
	esqueleto.ATK = 2;
	esqueleto.DEF = 1;
	esqueleto.posicao = 1;

	menu_principal();
	combate(novo_personagem, &esqueleto); 

	//GRAVAÇÃO DA POSIÇÃO NA HISTORIA
	/*FILE *gravar;
	gravar = fopen("historia.dat", "wb");
	char texto[TAM_TEX_MAXIMO];
	fgets(texto,TAM_TEX_MAXIMO, stdin);
	fwrite(texto, sizeof(texto), 1, gravar);
	fgets(texto, TAM_TEX_MAXIMO, stdin);
	fwrite(texto, sizeof(texto), 1, gravar);
	fclose(gravar);*/
	
	//ANDAMENTO DA HISTÓRIA

	/*while(rodando){
		atual();
	}*/

	//free(novo_personagem); //liberar memória alocada
	return 0;
}
void menu_principal(){
    int escolha=0; int rodando = 1;

	while(rodando){
		logo();
		printf("\n\n\t\t\t\t\t\t\t\t\t|1-Novo Jogo\n\t\t\t\t\t\t\t\t\t|2-Continuar\n\t\t\t\t\t\t\t\t\t|3-Ranking\n\t\t\t\t\t\t\t\t\t|4-Desenvolvedores\n\t\t\t\t\t\t\t\t\t|0-Fechar Programa\n\n");
		scanf("%d", &escolha);

        switch (escolha){
        case 1:
        //chama a criação de personagem
            
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
            printf("Fernando Brawl Stars\nGustavo Brawlhalla\nLohan");
			
            printf("clique em qualquer tecla para voltar");
			system("pause");
            break;
            
        case 0:
        	limpar_tela();
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
void limpar_tela(){
	system("cls");
}
