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
            if (escolha == 'L') {
                novo_personagem->posicao = 2;
            } else if (escolha == 'R') {
                novo_personagem->posicao = 3;
            } else {
                printf("Escolha invalida!\n");
            }
            break;
        case 2: // Página com a espada
            if (escolha == 'T') {
                printf("Voce puxou a espada com sucesso! Agora voce sente um grande poder fluindo atraves de voce.\n");
                novo_personagem->posicao = 4;
            } else if (escolha == 'I') {
                printf("Investigando a area ao redor, voce encontrou uma pocao de cura escondida perto da pedra.\n");
                novo_personagem->posicao = 5;
            } else {
                printf("Escolha invalida!\n");
            }
            break;
        case 3: // Página com o esqueleto
            if (escolha == 'F') {
                INIMIGO inimigo = gerar_mob(1);
                combate(novo_personagem, &inimigo);
                novo_personagem->posicao = 6;
            } else if (escolha == 'E') {
                printf("Voce consegue escapar do esqueleto e se esconde no vilarejo abandonado.\n");
                novo_personagem->posicao = 7;
            } else {
                printf("Escolha invalida!\n");
            }
            break;
        case 4: // Continuação após puxar a espada
        case 5: // Continuação após investigar a área
        case 6: // Continuação após lutar contra o esqueleto
        case 7: // Continuação após escapar do esqueleto
            printf("Voce continua sua jornada.\n");
            // Adicione a lógica para a próxima parte da história
            break;
        default:
            printf("Pagina desconhecida.\n");
            break;
    }
}
