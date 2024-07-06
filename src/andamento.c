#include"andamento.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TAM_TEX_MAXIMO 400

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
        default:
            printf("Não existe essa pagina de escolha ainda");
            break;
    }
}
