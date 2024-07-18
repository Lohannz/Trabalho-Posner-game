#ifndef SOMEFUNCTIONS_H
#define SOMEFUNCTIONS_H

#include "struct.h"
#include "item.h"
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void limpar_tela();//limpa o terminal
void status_personagem(PERSONAGEM personagem);//informa os atributos do jogador
void pausar();
void curar(PERSONAGEM *personagem,ITEM item);


#endif // SOMEFUNCTIONS