
void gerar_item(ITEM *item, char *nome_item, int bonus_ataque, int bonus_vida, PERSONAGEM *personagem){
    for(int i = 0; i < personagem->qnt_itens; i++){
        if(strcmp(personagem->item[i].nome, nome_item)== 0){
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
void usar_item(ITEM item, PERSONAGEM *personagem){
    personagem->ATK += item.atk;
    personagem->HP += item.hp;
}

void printar_inventario(PERSONAGEM personagem){
    
    printf("----------------------------SEU INVENTARIO----------------------------");
    for(int i = 0; i < personagem.qnt_itens;i++){
        printf("\n\t\t\t\t%i\n%s \nbonus dmg:%i \nbonus hp:%i\n", i + 1 ,personagem.item[i].nome, personagem.item[i].atk, personagem.item[i].hp);
        printf("----------------------------------------------------------------------");

    }



}
