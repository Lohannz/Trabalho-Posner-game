#include"andamento.h"
#include"item.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TAM_TEX_MAXIMO 4000

void tela_final(PERSONAGEM *novo_personagem){
    printf("Voce terminou o jogo, eh possivel voltar para a tela inicial ou voltar do ultimo save caso nao tenha gostado do caminho tomado");
    printf("Nome do aventureiro:%s",novo_personagem->nome);
    if(novo_personagem->reputacao=-1)
    printf("\nVoce foi um pessimo companheiro de batalha");
    else if(novo_personagem->reputacao=0)
    printf("\nVoce foi um companheiro de batalha moralmente neutro");
    else
    printf("\nSua astucia numa batalha inspirava os aliados, foi um bom companheiro de batalha");
    printf("\nPontuação:%i\nInimigos mortos:%i",novo_personagem->pontos,novo_personagem->bichos_mortos);
}

void curar(PERSONAGEM *personagem){
    personagem->HP=personagem->HPMAX;
}

int ja_tem(PERSONAGEM *personagem, char *nome_item){
    for (int i = 0; i < personagem->qnt_itens; i++) {
        if (strcmp(personagem->item[i].nome, nome_item) == 0) {
            printf("Voce ja tem esse item!\n");
            return 0;
        }
    }
    return 1;
}

void save(PERSONAGEM *personagem){
    FILE *fp;
    fp = fopen("saves.dat", "wb");
    if (fp == NULL) {
        printf("Nao foi possivel abrir o arquivo para salvar.\n");
        return;
    }
    if(fwrite(personagem, sizeof(PERSONAGEM), 1, fp) != 1){
        printf("Nao foi possível gravar!");
    } else {
        printf("Jogo gravado com sucesso!");
    }
    fclose(fp);
}

void load(PERSONAGEM **personagem) {
    FILE *fp = fopen("saves.dat", "rb");
    if (fp == NULL){
        printf("Nao foi possivel abrir o arquivo de save!\n");
        return;
    }
    *personagem = (PERSONAGEM*) malloc(sizeof(PERSONAGEM));
    if(*personagem == NULL){
        printf("Nao foi possível alocar memoria!\n");
        fclose(fp);
        return;
    }
    if(fread(*personagem, sizeof(PERSONAGEM), 1, fp) != 1){
        printf("Nao leu do arquivo saves.dat\n");
        free(*personagem);
        *personagem = NULL;
    } else {
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
    if (fp == NULL) {
        printf("Nao foi possivel abrir o arquivo da historia.\n");
        return;
    }
    fseek(fp, (pagina - 1) * TAM_TEX_MAXIMO * sizeof(char), SEEK_SET);
    fread(texto, sizeof(char), TAM_TEX_MAXIMO, fp);
    printf("%s\n", texto);
    fclose(fp);
}

void fazer_escolha(PERSONAGEM *novo_personagem, char escolha) { 
    switch (novo_personagem->posicao) {
        case 1: // Página inicial
            if(escolha == 'A'){
                INIMIGO aranha = gerar_mob(2);
                combate(novo_personagem, &aranha);
            }
            if(escolha == 'B'){
                    ITEM lanche;
                    if(ja_tem(novo_personagem,"lanche")==1){
                    printf("Voce faz um super sanduba, mas o presunto acaba");
                    gerar_item(&lanche,"lanche",0,20,novo_personagem);
                    }
            }
            if(escolha == 'C'){
                novo_personagem->posicao=2;

            }
            if(escolha == 'D'){
                if(novo_personagem->pontos>=3)
                novo_personagem->posicao=3;
                else
                printf("\nVoce ainda nao esta pronto");
            }
            break;
        case 2:
            if(escolha == 'A'){
                if(novo_personagem->SPD<=20 && novo_personagem->SPD>=15){
                    ITEM Anel_de_ouro;
                    if(ja_tem(novo_personagem,"Anel de ouro")==1){
                        gerar_item(&Anel_de_ouro,"Anel de ouro",2,5,novo_personagem);
                        printf("Voce acha um anel de ouro enferrujado do seu pai");
                    }
                }
                else if(novo_personagem->SPD>=30){
                    ITEM flechasfodas;
                    if(ja_tem(novo_personagem,"Flechas fodas")==1){
                        gerar_item(&flechasfodas,"Flechas fodas",5,0,novo_personagem);
                        printf("Voce acha uma aljava velha mas bonita de seu pai");
                    }
                }
                else if(novo_personagem->SPD>=9 && novo_personagem->SPD<15){
                    ITEM luvasboas;
                    if(ja_tem(novo_personagem,"Luvas boas")==1){
                        gerar_item(&luvasboas,"Luvas boas",3,5,novo_personagem);
                        printf("Voce acha um par de luvas velho de seu pai");
                    }
                }
            }
            if(escolha == 'B'){
                INIMIGO RATO = gerar_mob(3);
                combate(novo_personagem, &RATO);
            }
            if(escolha == 'C'){
                novo_personagem->posicao=1;
            }
            break;
        case 3:
            if(escolha == 'A'){
                novo_personagem->posicao=4;
            }
            if(escolha == 'B'){
                novo_personagem->posicao=5;
                novo_personagem->reputacao--;
            }
            break;
        case 4:
        if(escolha == 'A'){
            curar;
            novo_personagem->posicao=8;
        }
        break;
        case 5:
            if(escolha == 'A'){
                novo_personagem->posicao=6;
            }
            if(escolha == 'B'){
                novo_personagem->posicao=7;
            }
            break;
        case 6:
            if(escolha == 'A'){
                novo_personagem->reputacao+=2;
                novo_personagem->posicao=8;
            }
            break;
        case 7:
            if(escolha == 'A'){
                novo_personagem->posicao=8;
            }
            break;
        case 8:
            if(escolha == 'A'){
                novo_personagem->posicao=9;
            }
            if(escolha == 'B'){
                ITEM ataduras_de_babosa;
                gerar_item(&ataduras_de_babosa,"Ataduras de babosa",0,20,novo_personagem);
            }
            if(escolha == 'C'){

            }
            if(escolha == 'D'){
                novo_personagem->posicao=13;
            }
            break;
        case 9:
            if(escolha == 'A'){
                novo_personagem->posicao=10;
            }
            if(escolha == 'B'){
                novo_personagem->posicao=11;
            }
            if(escolha == 'C'){
                novo_personagem->posicao=12;
            }
            if(escolha == 'D'){
                novo_personagem->posicao=8;
            }
            break;
        case 10:
            if(escolha == 'A'){
                novo_personagem->posicao=8;
            }
            break;
        case 11:
            if(escolha == 'A'){
                novo_personagem->posicao=8;
            }
            break;
        case 12:
            if(escolha == 'A'){
                novo_personagem->posicao=8;
            }
            break;
        case 13:
            if(escolha == 'A'){
                novo_personagem->posicao=14;
            }
            if(escolha == 'B'){
                if(novo_personagem->SPD>30){
                    novo_personagem->posicao=15;
                }
                else
                printf("Seus bracos sao fraquinhos demais para quebrar na mao");
            }
            break;
        case 14:
            if(escolha == 'A'){
                novo_personagem->posicao=16;
            }
            break;
        case 15:
            if(escolha == 'A'){
                novo_personagem->posicao=16;
                ITEM barra;
                gerar_item(&barra,"Barra de ferro enferrujada",10,0,novo_personagem);
            }
            break;
        case 16:
            if(escolha == 'A'){
                novo_personagem->posicao=23;
            }
            if(escolha == 'B'){
                novo_personagem->posicao=17;
            }
            break;
        case 17:
            if(escolha == 'A'){
                novo_personagem->posicao=18;
            }
            if(escolha == 'B'){
                novo_personagem->posicao=21;
                novo_personagem->final=1;
            }
            break;
        case 18:
            if(escolha == 'A'){
                INIMIGO Orc = gerar_mob(4);
                combate(novo_personagem,&Orc);
                combate(novo_personagem,&Orc);
                novo_personagem->posicao=19;
            }
            break;
        case 19:
            if(escolha == 'A'){
                if(novo_personagem->final==0)
                    novo_personagem->posicao=20;
                else
                novo_personagem->posicao=22;
            }
            break;
        case 20:
            if(escolha == 'A'){
                tela_final(novo_personagem);
            }
            break;
        case 21:
            if(escolha == 'A'){
                novo_personagem->final=1;
                novo_personagem->posicao=18;
            }
            break;
        case 22:
            if(escolha == 'A'){
                tela_final(novo_personagem);
            }
            break;
        case 23:
            if(escolha == 'A'){
                INIMIGO Orc = gerar_mob(4);
                combate(novo_personagem,&Orc);
            }
            break;
        case 24:
            if(escolha == 'A'){
                novo_personagem->posicao=18;
            }
            if(escolha == 'B'){
                novo_personagem->posicao=25;
            }
            break;
        case 25:
            if(escolha == 'A'){
                INIMIGO reiorc = gerar_mob(5);
                combate(novo_personagem,&reiorc);
                novo_personagem->posicao=26;
            }
            break;
        case 26:
            if(escolha == 'A'){
                tela_final(novo_personagem);
            }
            break;    
            default:
            printf("Não existe essa pagina de escolha ainda");
            break;
    }
}