#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "struct.h"
#include "combate.h"
#include "logo.h"
#include "item.h"

#define TAM_TEX_MAXIMO 400
#define time_sleep sleep(0)
#define TAM_VET_SAVE 1000

int pagina = 1;

void gerar_item(ITEM *item, char *nome_item, int bonus_ataque, int bonus_vida, PERSONAGEM *personagem);
void printar_inventario(PERSONAGEM *personagem);

void pausar();
void imprimir_menu();
void save(PERSONAGEM *personagem);// funções que gravam e carregam informações do jogo
void load(PERSONAGEM **personagem);//
void menu_principal(PERSONAGEM **novo_personagem);//menu principal do jogo
void ranking();
void atual(int pagina, PERSONAGEM *novo_personagem);// diz em que pagina/parte o personagem está
void fazer_escolha(PERSONAGEM *novo_personagem, char escolha);
void olhar(int posicao);//ação de olhar a posição do jogador
void combate(PERSONAGEM *atacante, INIMIGO *inimigo);//combate
void limpar_tela();//limpa o terminal
void status_personagem(PERSONAGEM personagem);//informa os atributos do jogador
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

    while (rodando) {    
        char comando;
        limpar_tela();
        atual(novo_personagem->posicao, novo_personagem);
        imprimir_menu();
        scanf(" %c", &comando);

        switch (toupper(comando)) {
            case 'E':
                printar_inventario(novo_personagem);
                pausar();
                break;
            case 'O':
                olhar(novo_personagem->posicao);
                pausar();
                break;
            case 'S':
                status_personagem(*novo_personagem);
                pausar();
                break;
            case 'M':
                printf("Faça sua escolha:\n");
                scanf(" %c", &comando);
                fazer_escolha(novo_personagem, toupper(comando));
                limpar_tela();
                pausar();
                break;
            case 'C': {
                INIMIGO inimigo = gerar_mob(1);
                combate(novo_personagem, &inimigo);
                break;
            }
            case 'Q':
                rodando = 0;
                break;
            case 'P':
                save(novo_personagem);
                pausar();
                break;
            case 'I':
                menu_principal(&novo_personagem);
                break;
            default:
                printf("Comando invalido\n");
                break;
        }
    }

    free(novo_personagem); //liberar memória alocada
    return 0;
}

void menu_principal(PERSONAGEM **novo_personagem){
    int escolha = 0; 
    int rodando = 1;

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
                *novo_personagem = criarPersonagem();
                rodando = 0;
                break;
            case 2:
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

PERSONAGEM *criarPersonagem(){
    PERSONAGEM *novo_personagem = (PERSONAGEM*) malloc(sizeof(PERSONAGEM));
    int classe = 0;
    
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
    }
    time_sleep;
    novo_personagem->posicao = 1;
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

void status_personagem(PERSONAGEM personagem){
    printf("Nome:%s\nHP:%i\nAtaque:%i\nDefesa:%i\nPontos:%i\nAndamento:%i", personagem.nome, personagem.HP, personagem.ATK, personagem.DEF, personagem.pontos, personagem.posicao);
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

void pausar() {
    fflush(stdin);
    getchar();
}

void imprimir_menu(){
    printf("%10s %10s %10s %10s %10s %10s %10s \n", "[E] Inventario", "[S] Status", "[M] Mover", "[C] combate", "[Q] Sair", "[P] Salvar", "[I] Menu");
}

void save(PERSONAGEM *personagem){
    FILE *fp;
    fp = fopen("saves.dat", "wb");
    if (fp == NULL) {
        printf("Não foi possível abrir o arquivo para salvar.\n");
        return;
    }
    if(fwrite(personagem, sizeof(PERSONAGEM), 1, fp) != 1){
        printf("Não foi possível gravar!");
    } else {
        printf("Jogo gravado com sucesso!");
    }
    fclose(fp);
}

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
    } else {
        printf("Jogo carregado com sucesso!\n");
        limpar_tela();
        status_personagem(**personagem);
    }
    fclose(fp);
}

void atual(int pagina, PERSONAGEM *novo_personagem) {
    char texto[TAM_TEX_MAXIMO];

    switch(pagina) {
        case 1:
            strcpy(texto, "Você acorda em uma floresta escura e densa. À sua frente, há dois caminhos: um para a esquerda, que parece levar a uma clareira iluminada, e outro para a direita, que mergulha mais fundo na floresta escura.\nEscolha (L) para ir para a esquerda.\nEscolha (R) para ir para a direita.");
            break;
        case 2:
            strcpy(texto, "Você segue o caminho para a clareira iluminada e encontra uma cabana abandonada com uma espada brilhante e suprimentos.\nEscolha (T) para pegar a espada.\nEscolha (I) para investigar mais a fundo.");
            break;
        case 3:
            strcpy(texto, "Você se aventura mais fundo na floresta escura e é atacado por um esqueleto armado.\nEscolha (F) para lutar contra o esqueleto.\nEscolha (E) para tentar escapar.");
            break;
        default:
            strcpy(texto, "Fim da história.");
            break;
    }

    printf("%s\n", texto);
}

void fazer_escolha(PERSONAGEM *novo_personagem, char escolha) {
    switch (novo_personagem->posicao) {
        case 1:
            if (escolha == 'L') {
                novo_personagem->posicao = 2;
            } else if (escolha == 'R') {
                novo_personagem->posicao = 3;
            } else {
                printf("Escolha inválida!\n");
            }
            break;
        case 2:
            if (escolha == 'T') {
                // Código para pegar a espada
            } else if (escolha == 'I') {
                // Código para investigar mais a fundo
            } else {
                printf("Escolha inválida!\n");
            }
            break;
        case 3:
            if (escolha == 'F') {
                INIMIGO inimigo = gerar_mob(1);
                combate(novo_personagem, &inimigo);
            } else if (escolha == 'E') {
                // Código para tentar escapar
            } else {
                printf("Escolha inválida!\n");
            }
            break;
        default:
            printf("Página desconhecida.\n");
            break;
    }
}

void ranking(){};
