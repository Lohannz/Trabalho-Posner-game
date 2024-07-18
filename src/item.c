#include"item.h"

//Abre a loja
void loja(PERSONAGEM *personagem){
    printf("-------------LOJA-------------");
    printf("\n|1 - Baba de orc: 10 coins\n|2 - hp potion basica: 20 coins\n|3 - hp potion menos basica: 30 coins\n|4 - capitalista: 15 coins");
    ITEM item;
    // valor do item fora do case. Não pode declarar variavel dentro do switch
    int valor_item1 = 30;
    int valor_item2 = 20;
    int valor_item3 = 45;
    int valor_item4 = 15;
    int escolha;
    scanf(" %i", &escolha);

    switch (escolha)
    {
    case 1:
        
        if(personagem->dinheiro == valor_item1){
            gerar_item(&item, "baba de orc", (personagem->ATK * 30/100 ), (personagem->HP * 30/100), personagem);
            printf("Voce comprou %s", item.nome);
            personagem->dinheiro -= valor_item1;
        }
        else{
            printf("Voce nao tem dinheiro suficiente!");
        }
        break;
    case 2:

        if(personagem->dinheiro == valor_item2){
            gerar_item(&item, "hp potion basica", 0, 20, personagem);
            printf("Voce comprou %s", item.nome);
            personagem->dinheiro -= valor_item2;
        }
        else{
            printf("Voce nao tem dinheiro suficiente!");
        }
        break;

    case 3:
        if(personagem->dinheiro == valor_item3){
            gerar_item(&item, "hp potion menos basica que a outra", 0, 45, personagem);
            printf("Voce comprou %s", item.nome);
            personagem->dinheiro -= valor_item3;
        }
        else{
            printf("Voce nao tem dinheiro suficiente!");
        }
        break;
    
    case 4:
        if(personagem->dinheiro == valor_item4){
            gerar_item(&item, "capitalista", 0, 0 ,personagem);
            printf("Voce comprou %s", item.nome);
            printf("\n Voce consumiu seus pontos e transformou em dinheiro");
            personagem->dinheiro -= valor_item3;
            personagem->dinheiro += personagem->pontos;
            if(personagem->pontos < 0){
                personagem->pontos = 0;
            }
        }
        else{
            printf("Voce nao tem dinheiro suficiente!");
        }
        break;
        
    default:
        break;
    }


}



//Gera um item específico e dá uma opção ao player de usar ou nao, testando se ele realmente tem esse item
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
//Printa o inventario e faz a escolha de itens
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
//Função de usar o item e o remove do inventário;
void usar_item(int indice, PERSONAGEM *personagem) {
    if (indice >= 0 && indice < personagem->qnt_itens) {
        ITEM item = personagem->item[indice];

        // Aplica os efeitos do item
        personagem->ATK += item.atk;
        curar(personagem,item);
        // Remove o item do inventário
        for (int i = indice; i < personagem->qnt_itens - 1; i++) {
            personagem->item[i] = personagem->item[i + 1];
        }
    } else {
        printf("Indice de item invalido!\n");
    }
}