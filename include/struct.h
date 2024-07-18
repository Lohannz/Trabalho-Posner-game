#ifndef STRUCT_H
#define STRUCT_H


typedef struct ITEM { //struct do item
    char nome[20];
    int atk;
    int hp;
} ITEM;

typedef struct _personagem { //struct do personagem
    char nome[50];
    int LEVEL;
    int HP;
    int HPMAX;
    int ATK;
    int DEF;
    int SPD;
    int pontos;
    int dinheiro;
    ITEM item[10];
    int qnt_itens;
    int posicao;
    int reputacao;
    int final;
    int bichos_mortos;
    int classe;
} PERSONAGEM;

typedef struct _inimigo {  //struct do inimigo
    int id;
    char nome[50];
    int HP;
    int ATK;
    int DEF;
    int SPD;
    int posicao;
    int dinheiro;
    int pontos;
} INIMIGO;

#endif // STRUCT_H