#ifndef COMBATE_H
#define COMBATE_H

#include"struct.h"
#include"item.h"
#include"somefunctions.h"
#include "andamento.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

int rolagem_dado(int faces);
void combate(PERSONAGEM *atacante, INIMIGO *inimigo);//combate
void morte(PERSONAGEM *personagem);
INIMIGO gerar_mob(int tipo);
#endif // COMBATE_H