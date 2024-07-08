#include"item.h"
#include<stdio.h>
#include<string.h>



void loja(PERSONAGEM *personagem){
    printf("---------LOJA---------");
    printf("");
    ITEM item;

    int escolha;
    scanf(" %i", &escolha);

    switch (escolha)
    {
    case 1:
        
        gerar_item(&item, "baba de orc", (personagem->ATK * 30/100 ), (personagem->HP * 30/100), personagem);
        
        break;
    case 2:

        break;

    case 3:
        break;
    
    case 4:
        break;

    case 5:
        break;

    
    default:
        break;
    }


}




void gerar_item(ITEM *item, char *nome_item, int bonus_ataque, int bonus_vida, PERSONAGEM *personagem) {
    // Verifica se o item já existe no inventário
    for (int i = 0; i < personagem->qnt_itens; i++) {
        if (strcmp(personagem->item[i].nome, nome_item) == 0) {
            printf("Voce ja tem esse item!\n");
            return;
        }
    }

    if (personagem->qnt_itens < 3) {
        strcpy(item->nome, nome_item);
        item->atk = bonus_ataque;
        item->hp = bonus_vida;
        
        strcpy(personagem->item[personagem->qnt_itens].nome, item->nome);
        personagem->item[personagem->qnt_itens].atk = item->atk;
        personagem->item[personagem->qnt_itens].hp = item->hp;
        personagem->qnt_itens++;
    } else {
        printf("Inventario cheio!\n");
    }
}
void printar_inventario(PERSONAGEM *personagem){

    int escolha;
    printf("----------------------------SEU INVENTARIO----------------------------");
    for(int i = 0; i < personagem->qnt_itens;i++){
        printf("\n\t\t\t\t%i\n%s \nBonus Ataque:%i \nBonus HP:%i\n", i + 1 ,personagem->item[i].nome, personagem->item[i].atk, personagem->item[i].hp);
        printf("----------------------------------------------------------------------");

    }
    
    printf("\nAperte qualquer letra para sair");
    printf("\nSua escolha:");
    scanf("%i", &escolha);

    if(escolha > 0 && escolha <= personagem->qnt_itens){
        usar_item(escolha - 1, personagem);
        printf("Voce usou %s\n.", personagem->item[escolha - 1].nome);
    }
    

    else if (escolha >= 4){
        return;
    }
    
    else{
        printf("Escolha Invalida!");

    }
    
}

void usar_item(int indice, PERSONAGEM *personagem) {
    if (indice >= 0 && indice < personagem->qnt_itens) {
        ITEM item = personagem->item[indice];

        // Aplica os efeitos do item
        personagem->ATK += item.atk;
        personagem->HP += item.hp;
        personagem->HPMAX += item.hp;
        // Remove o item do inventário
        for (int i = indice; i < personagem->qnt_itens - 1; i++) {
            personagem->item[i] = personagem->item[i + 1];
        }
        personagem->qnt_itens--;
    } else {
        printf("Indice de item invalido!\n");
    }
}