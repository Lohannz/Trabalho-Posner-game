#ifndef STRUCT_H
#define STRUCT_H


typedef struct ITEM {
    char nome[20];
    int atk;
    int hp;
} ITEM;

typedef struct _personagem {
    char nome[50];
    int LEVEL;
    int HP;
    int HPMAX;
    int ATK;
    int DEF;
    int SPD;
    int pontos;
    ITEM item[2];
    int qnt_itens;
    int posicao;
    int reputacao;
    int final;
    int bichos_mortos;
} PERSONAGEM;

typedef struct _inimigo {
    int id;
    char nome[50];
    int HP;
    int ATK;
    int DEF;
    int SPD;
    int posicao;
    int pontos;
} INIMIGO;

#endif // STRUCT_H