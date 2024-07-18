// Include
#include "andamento.h"
#include "combate.h"
#include "struct.h"
#include "item.h"
#include "somefunctions.h"
#include "logo.h"

//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
//
#define TAM_TEX_MAXIMO 400
#define time_sleep sleep(0)

//
void imprimir_menu();
void menu_principal(PERSONAGEM **novo_personagem);//menu principal do jogo
void ranking();
PERSONAGEM *criarPersonagem();//cria personagem
PERSONAGEM *novo_personagem;

//
int main(){
    int rodando = 1;
    menu_principal(&novo_personagem);

    //Looping do jogo
    while (rodando) {
        char comando;
        limpar_tela();
        atual(novo_personagem->posicao, novo_personagem);
        imprimir_menu();
        scanf(" %c", &comando);

    //Pega a escolha do player e realiza as funções
        switch (toupper(comando)) {
            case 'E':
                printar_inventario(novo_personagem);
                pausar();
                break;
            case 'S':
                status_personagem(*novo_personagem);
                pausar();
                break;
            case 'M':
                printf("ESCOLHA:\n");
                scanf(" %c", &comando);
                fazer_escolha(novo_personagem, toupper(comando));
                
                break;
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

    free(novo_personagem); //libera memoria alocada
    return 0;
}
//Tela inicial do jogo
void menu_principal(PERSONAGEM **novo_personagem){
    int escolha = 0; 
    int rodando = 1;

    while(rodando){
        logo();
        printf("\n\n\t\t\t\t\t\t\t\t\t|1-Novo Jogo");//////time_sleep;
        printf("\n\t\t\t\t\t\t\t\t\t|2-Continuar");//////time_sleep;
        printf("\n\t\t\t\t\t\t\t\t\t|3-Ranking");//////time_sleep;
        printf("\n\t\t\t\t\t\t\t\t\t|4-Desenvolvedores");//////time_sleep;
        printf("\n\t\t\t\t\t\t\t\t\t|0-Fechar Programa\n\t\t\t\t\t\t\t\t\t");//////time_sleep;

        scanf("%d", &escolha);
        
        limpar_tela();
        switch (escolha){
            case 1:
                printf("**  Voce acorda com seus 10 anos de idade e percebe sua vila em chamas e escuta gritos vindo de todas as direcoes, ao sair de casa voce se depara com uma gangue de orcs furiosos que levam seu pai embora enquanto sua mae te abraca forte enxugando suas lagrimas.");
                printf("\n  Eles te deixam jogados no chao enquanto riem e continuam a disseminar o caos, levando seu pai nocauteado embora...Naquele dia, voce jura vinganca e comeca seus treinamentos para tal.");
                printf("\n  Ao completar 18 anos, voce finalmente se forma na escola de aventureiros e pode escolher o que voce vai querer ser");
                pausar();
                *novo_personagem = criarPersonagem();
                printf("Diretor da guilda:Parabens pela formacao e a escolha da classe, tome uns equipamentos para sua jornada e boa sorte.");
                pausar();
                rodando = 0;
                break;
            case 2:
                limpar_tela();
                load(novo_personagem);
                rodando = 0;
                pausar();
                break;
            case 3:
                printf("Pontos conseguidos: %i", (*novo_personagem)->pontos);
                pausar();
                break;
            case 4:
                limpar_tela();
                printf("Fernando William\nGustavo Simplicio\nLohan Vieira\n");
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

//Função geradora de personagens e atributos
PERSONAGEM *criarPersonagem(){
    PERSONAGEM *novo_personagem = (PERSONAGEM*) malloc(sizeof(PERSONAGEM));
    char classe = ' ';
    int inteiro=0;
    while(inteiro != 1 && inteiro !=2 && inteiro != 3){
    printf("\nPrimeiro de tudo, escolha sua classe:\n");
    printf("|1-Guerreiro\n");//////time_sleep;
    printf("|2-Arqueiro\n");//////time_sleep;
    printf("|3-Paladino\n");//////time_sleep;
    printf("Sua escolha:");//////time_sleep;
        scanf(" %c", &classe);
        limpar_tela();
        inteiro=classe-'0';
        switch (inteiro){
            case 1:
                printf("Voce escolheu o guerreiro");
                novo_personagem->classe = 1;
                novo_personagem->LEVEL = 1;
                novo_personagem->HP = 100;
                novo_personagem->ATK = 19;
                novo_personagem->DEF = 10;
                novo_personagem->SPD = 15;
                break;
            case 2:
                printf("Voce escolheu o arqueiro");
                novo_personagem->classe = 2;
                novo_personagem->LEVEL = 1;
                novo_personagem->HP = 90;
                novo_personagem->ATK = 32;
                novo_personagem->DEF = 8;
                novo_personagem->SPD = 30;
                break;
            case 3:
                printf("Voce escolheu o paladino");
                novo_personagem->classe = 3;
                novo_personagem->LEVEL = 1;
                novo_personagem->HP = 140;
                novo_personagem->ATK = 14;
                novo_personagem->DEF = 29;
                novo_personagem->SPD = 9;
                break;
            default:
            printf("Classe invalida. Tente novamente!");
            continue;
        }
        pausar();
    }
    //////time_sleep;
    novo_personagem->HPMAX=novo_personagem->HP;
    novo_personagem->posicao = 1;
    novo_personagem->dinheiro = 0;
    novo_personagem->pontos = 0;
    novo_personagem->qnt_itens = 0;
    novo_personagem->bichos_mortos = 0;
    limpar_tela();
    printf("Agora, escolha o seu nome: ");
    scanf("%s", novo_personagem->nome);
    limpar_tela();
    //////time_sleep;
    printf("Seu personagem foi criado!");
    printf("\nSeus atributos sao:\nHP %i\nATAQUE %i\nDEFESA %i",novo_personagem->HP, novo_personagem->ATK, novo_personagem->DEF);////time_sleep;
    pausar();
    limpar_tela();
    return novo_personagem;
}
//

//
void imprimir_menu(){
    printf("%10s %10s %10s %10s %10s %10s %10s \n", "[M] Mover","[E] Inventario", "[S] Status", "[P] Salvar", "[I] Menu", "[Q] Sair");
}