#include"somefunctions.h"


void status_personagem(PERSONAGEM personagem){
    printf("Nome:%s\nLevel:%i\nHP:%i\nAtaque:%i\nDefesa:%i\nDinheiro:%i\nPontos:%i\nAndamento:%i", personagem.nome,personagem.LEVEL, personagem.HP, personagem.ATK, personagem.DEF,personagem.dinheiro, personagem.pontos, personagem.posicao);
}


void pausar() {
    fflush(stdin);
    getchar();
}

void limpar_tela(){
    system("cls");
}
