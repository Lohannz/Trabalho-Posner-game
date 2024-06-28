#include"andamento.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TAM_TEX_MAXIMO 400

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

void atual(int pagina, PERSONAGEM *novo_personagem){
    FILE *fp;
    char texto[TAM_TEX_MAXIMO];
    fp = fopen("historia.dat", "rb");
    if (fp == NULL) {
        printf("Não foi possível abrir o arquivo da história.\n");
        return;
    }
    fseek(fp, (pagina - 1) * TAM_TEX_MAXIMO * sizeof(char), SEEK_SET); // Ajuste para garantir que a primeira página seja lida corretamente
    fread(texto, sizeof(char), TAM_TEX_MAXIMO, fp);
    printf("%s\n", texto);
    fclose(fp);
}

void fazer_escolha(PERSONAGEM *novo_personagem, char escolha) {
    switch (novo_personagem->posicao) {

        case 0:
            if(escolha == '0')
                printf("Ta na porra da pagina 0, na qual nao deveria existir!!!");
        case 1: // Página inicial
            if (escolha == 'L') {
                novo_personagem->posicao = 2;
            } else if (escolha == 'R') {
                novo_personagem->posicao = 3;
            } else {
                printf("Escolha inválida!\n");
            }
            break;
        case 2: // Exemplo de página 2
            if (escolha == 'T') {
                printf("Você puxa a espada da pedra e sente um grande poder fluindo através de você.\n");
                // Código para adicionar a espada ao inventário
            } else if (escolha == 'I') {
                printf("Você encontra uma poção de cura escondida perto da pedra.\n");
                // Código para adicionar a poção ao inventário
            } else {
                printf("Escolha inválida!\n");
            }
            break;
        case 3: // Exemplo de página 3
            if (escolha == 'F') {
                INIMIGO inimigo = gerar_mob(1);
                combate(novo_personagem, &inimigo);
            } else if (escolha == 'E') {
                printf("Você consegue escapar do esqueleto e se esconde no vilarejo abandonado.\n");
                // Código para mudar a posição do personagem
            } else {
                printf("Escolha inválida!\n");
            }
            break;
        default:
            printf("Página desconhecida.\n");
            break;
    }
}

