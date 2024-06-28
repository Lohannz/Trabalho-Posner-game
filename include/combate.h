#ifndef COMBATE_H
#define COMBATE_H

#include"struct.h"
#include"item.h"

int rolagem_dado(int faces);
void combate(PERSONAGEM *atacante, INIMIGO *inimigo);//combate
void morte(PERSONAGEM *personagem);
INIMIGO gerar_mob(int tipo);
#endif // COMBATE_H