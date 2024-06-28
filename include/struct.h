#ifndef STRUCT_H
#define STRUCT_H


typedef struct ITEM {
    char nome[20];
    int atk;
    int hp;
} ITEM;

typedef struct _personagem {
    char nome[50];
    int HP;
    int ATK;
    int DEF;
    int SPD;
    int pontos;
    ITEM item[2];
    int qnt_itens;
    int posicao;
} PERSONAGEM;

typedef struct _inimigo {
    int id;
    char nome[50];
    int HP;
    int ATK;
    int DEF;
    int SPD;
    int posicao;
} INIMIGO;

#endif // STRUCT_H