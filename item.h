
void gerar_item(ITEM *item, char *nome_item, int bonus_ataque, int bonus_vida, PERSONAGEM *personagem){

    //verifica se o item ja existe no inventario
    for(int i = 0; i < personagem->qnt_itens; i++){
        if(strcmp(personagem->item[i].nome, nome_item)== 0){
            printf("Voce ja tem esse item!");
            return;
        }
    }
    strcpy(item->nome, nome_item);
    item->atk = bonus_ataque;
    item->hp = bonus_vida;
    
    
    strcpy(personagem->item[personagem->qnt_itens].nome,item->nome );
    personagem->item[personagem->qnt_itens].atk = item->atk;
    personagem->item[personagem->qnt_itens].hp = item->hp;
    personagem->qnt_itens++;
    
}
void usar_item(int indice, PERSONAGEM *personagem) {
    ITEM item = personagem->item[indice];
    personagem->ATK += item.atk;
    personagem->HP += item.hp;
    // Copia o último item do inventário para a posição do item usado
    personagem->item[indice] = personagem->item[personagem->qnt_itens - 1];
    // Diminui a quantidade de itens no inventário
    personagem->qnt_itens--;
}


void printar_inventario(PERSONAGEM *personagem){
    
    int escolha;
    printf("----------------------------SEU INVENTARIO----------------------------");
    for(int i = 0; i < personagem->qnt_itens;i++){
        printf("\n\t\t\t\t%i\n%s \nbonus dmg:%i \nbonus hp:%i\n", i + 1 ,personagem->item[i].nome, personagem->item[i].atk, personagem->item[i].hp);
        printf("----------------------------------------------------------------------");

    }
    printf("\nAperte qualquer letra para sair");
    printf("\nSua escolha:");
    scanf("%i", &escolha);

    if(escolha > 0 && escolha <= personagem->qnt_itens){
        usar_item(escolha - 1, personagem);
        printf("voce usou %s\n.", personagem->item[escolha - 1].nome);
    }
    else
        return;
    
    
}



