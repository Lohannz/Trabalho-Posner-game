
#ifndef ANDAMENTO_H
#define ANDAMENTO_H


#include"item.h"
#include "combate.h"
#include "somefunctions.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// funções que gravam e carregam informações do jogo
void save(PERSONAGEM *personagem);
void load(PERSONAGEM **personagem);
void atual(int pagina, PERSONAGEM *novo_personagem);// carrega as páginas 
void fazer_escolha(PERSONAGEM *novo_personagem, char escolha); // responsável pelas manipulações de páginas, dependendo das escolhas


#endif // ANDAMENTO_H


