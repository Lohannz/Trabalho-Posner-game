#include"item.h"
#include<stdio.h>
#include<string.h>



void gerar_item(ITEM *item, char *nome_item, int bonus_ataque, int bonus_vida, PERSONAGEM *personagem) {
    // Verifica se o item já existe no inventário
    for (int i = 0; i < personagem->qnt_itens; i++) {
        if (strcmp(personagem->item[i].nome, nome_item) == 0) {
            printf("Você já tem esse item!\n");
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
        printf("Inventário cheio!\n");
    }
}
void printar_inventario(PERSONAGEM *personagem) {
    printf("Inventário:\n");
    for (int i = 0; i < personagem->qnt_itens; i++) {
        printf("%d - %s (ATK: %d, VIDA: %d)\n", i + 1, personagem->item[i].nome, personagem->item[i].atk, personagem->item[i].hp);
    }

    int item_usar;
    printf("Digite o número do item para usar ou 0 para voltar: ");
    scanf("%d", &item_usar);

    if (item_usar > 0 && item_usar <= personagem->qnt_itens) {
        usar_item(item_usar - 1, personagem);
    }
}

void usar_item(int indice, PERSONAGEM *personagem) {
    if (indice >= 0 && indice < personagem->qnt_itens) {
        ITEM item = personagem->item[indice];

        // Aplica os efeitos do item
        personagem->ATK += item.atk;
        personagem->HP += item.hp;
        // Remove o item do inventário
        for (int i = indice; i < personagem->qnt_itens - 1; i++) {
            personagem->item[i] = personagem->item[i + 1];
        }
        personagem->qnt_itens--;

        printf("Você usou %s!\n", item.nome);
    } else {
        printf("Índice de item inválido!\n");
    }
}
