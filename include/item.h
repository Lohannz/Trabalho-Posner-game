#ifndef ITEM_H
#define ITEM_H

#include "struct.h"
#include "somefunctions.h"
#include<stdio.h>
#include<string.h>

void gerar_item(ITEM *item, char *nome_item, int bonus_ataque, int bonus_vida, PERSONAGEM *personagem);
void printar_inventario(PERSONAGEM *personagem);
void usar_item(int indice, PERSONAGEM *personagem);
void loja(PERSONAGEM *personagem);

#endif // ITEM_H