#include"somefunctions.h"


void status_personagem(PERSONAGEM personagem){//Imprime os status do personagem
    printf("Nome:%s\nLevel:%i\nHP:%i/%i\nAtaque:%i\nDefesa:%i\nDinheiro:%i\nPontos:%i\nAndamento:%i", personagem.nome,personagem.LEVEL, personagem.HP,personagem.HPMAX, personagem.ATK, personagem.DEF,personagem.dinheiro, personagem.pontos, personagem.posicao);
}


void pausar() {
    fflush(stdin);
    getchar();
}

void limpar_tela(){
    system("cls");
}

void curar(PERSONAGEM *personagem,ITEM item){ //Cura o personagem sem ultrapassar o limite
    if(item.hp+personagem->HP>personagem->HPMAX){
        personagem->HP=personagem->HPMAX;
    }
    else
    personagem->HP+=item.hp;
}