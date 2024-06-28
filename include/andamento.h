#include "struct.h"
#include "combate.h"
#ifndef ANDAMENTO_H
#define ANDAMENTO_H


void save(PERSONAGEM *personagem);// funções que gravam e carregam informações do jogo
void load(PERSONAGEM **personagem);//
void atual(int pagina, PERSONAGEM *novo_personagem);// diz em que pagina/parte o personagem está


#endif // ANDAMENTO_H


