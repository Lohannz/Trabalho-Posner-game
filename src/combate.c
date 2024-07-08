#include"combate.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void upar(PERSONAGEM *personagem){
    personagem->LEVEL++;
    personagem->HP  += 10;
    personagem->ATK += 4;
    personagem->DEF += 2;
    personagem->SPD += 1;
}
void subir_level(PERSONAGEM *personagem){
    if(personagem->LEVEL = 1){
        if(personagem->pontos >= 5){
            upar(personagem);
        }
    }
    else if(personagem->LEVEL = 2){
        if(personagem->pontos >= 12){
            upar(personagem);
        }
    }
    else if(personagem->LEVEL = 3){
        if(personagem->pontos >= 20){
            upar(personagem);
        }
    }
    else if(personagem->LEVEL = 4){
        if(personagem->pontos >= 30){
            upar(personagem);
        }
    }
}
//ROLA o DADO PARA A BATALHA
int rolagem_dado(int faces){
    int resultado;
    resultado = rand() % faces + 1;
    return resultado;
}

void combate(PERSONAGEM *atacante, INIMIGO*defensor){
    int turno=0;
    printf("Voce achou %s!\n", defensor->nome);
    pausar();
        
    while(1){
        int escolha = 0;
        int dano = 0;
        int dado1 = rolagem_dado(6);
        int dado2 = rolagem_dado(6);
            
        // SISTEMA DE PONTOS
        // SE O PERSONAGEM MATAR O DEFENSOR, GANHA X PONTOS
        if(defensor->HP <= 0){
            printf("voce derrotou %s!\n", defensor->nome);
            printf("dinheiro: %i pontos: %i\n", defensor->dinheiro, defensor->pontos);
            atacante->pontos += defensor->pontos;
            atacante->dinheiro += defensor->dinheiro;
            atacante->bichos_mortos++;
            subir_level(atacante);
            break;

        }
        // SE PERDER, MENOS 2 PONTOS E VOLTA UMA POSIÇAO NA HISTORIA
        if(atacante->HP <= 0){
            printf("Voce morreu!\n");
            atacante->pontos -= 2;
            // restaura o hp do personagem
            atacante->HP = 100;
            morte(atacante);
            break;
        }
        limpar_tela();
        printf("\nseu HP:%d\nHP %s:%d\n", atacante->HP, defensor->nome, defensor->HP);
        printf("|1-Atacar\n");
        printf("|2-Tentar fugir!\n");
        printf("|3-Usar item\n");
        printf("turno: %d\n", (turno/2)+1);
        scanf("%i", &escolha);
        limpar_tela();
        
        if(escolha == 1){
            if(atacante->SPD > defensor->SPD){
                dano = (atacante->ATK - defensor->DEF)/2;
            if(dano < 1){
                dano = 1;
            } 
            defensor->HP = defensor->HP - dano;

            // verifica se o monstro tem menos de 0 hp
            if(defensor->HP < 0)
                defensor->HP = 0;
            printf("\nseu HP:%d\nHP do monstro:%d\n", atacante->HP, defensor->HP);
            printf("\n[Voce causou %d de dano no inimigo!]\n", dano);
            sleep(1);
        }
        else if(defensor->SPD > atacante->SPD){
            dano = (defensor->ATK - atacante->DEF)/2;
            if(dano < 1){
                dano = 1;
            }
            atacante->HP = atacante->HP - dano;
            printf("\nseu HP:%d\nHP do monstro:%d\n", atacante->HP, defensor->HP);
            printf("\n[Voce sofreu %d de dano do inimigo!]\n", dano);
            
        }
        else if(atacante->SPD == defensor->SPD){
            atacante->SPD = rolagem_dado(6);
            defensor->SPD = rolagem_dado(6);
        }
        
        if(turno % 2 == 0){
            int temp = atacante->SPD;
            atacante->SPD = defensor->SPD;
            defensor->SPD = temp;
            sleep(1);
        }
        turno+=2;    
        }
        
        // tentativa de fugir!
        if(escolha == 2){
            dado1 = rolagem_dado(6);
            dado2 = rolagem_dado(6);
            if(dado1 > dado2){
                printf("\nVoce conseguiu fugir!");
                break;
            }
            else  if(dado2 > dado1){
                printf("\nNao conseguiu fugir.");
                escolha = 1;
                pausar();
                continue;
                
            }
            else if(dado1 == dado2){
                printf("\nQuase conseguiu!");
                escolha = 1;
                pausar();
                continue;
            }
        }
        
        if(escolha == 3){
        	printar_inventario(atacante);
		}
        
        limpar_tela();
    }
    
    pausar();

}

INIMIGO gerar_mob(int tipo){
    INIMIGO mob;

    switch (tipo){
        case 1:
            strcpy(mob.nome, "esqueleto");
            mob.id = 1;
            mob.HP = 10;
            mob.ATK = 2;
            mob.DEF = 1;
            mob.SPD = 10;
            mob.pontos = 0;
            break;
        //outros casos para diferentes tipos de mobs
        case 2:
            strcpy(mob.nome, "aranha");
            mob.id = 2;
            mob.HP = 15;
            mob.ATK = 15;
            mob.DEF = 5;
            mob.SPD = 10;
            mob.dinheiro = 0;
            mob.pontos = 2;
            break;
        case 3:
            strcpy(mob.nome, "rato bombado");
            mob.id = 3;
            mob.HP = 23;
            mob.ATK = 25;
            mob.DEF = 13;
            mob.SPD = 15;
            mob.dinheiro = 0;
            mob.pontos = 3;
            break;
        case 4:
            strcpy(mob.nome, "Orc parrudo");
            mob.id = 4;
            mob.HP = 70;
            mob.ATK = 30;
            mob.DEF = 15;
            mob.SPD = 15;
            mob.dinheiro = 10;
            mob.pontos = 5;
            break;
        case 5:
            strcpy(mob.nome, "Rei Orc");
            mob.id = 5;
            mob.HP = 170;
            mob.ATK = 40;
            mob.DEF = 17;
            mob.SPD = 10;
            mob.dinheiro = 10;
            mob.pontos = 10;
            break;
        default:
            printf("NAO existe essa merda");
            break;
    }
    return mob;
}


void morte(PERSONAGEM *personagem){
    int escolha;
    printf("Voce morreu!\n");
    pausar();
    printf("1-Voltar no save\n");
    scanf("%i",&escolha);
    if(escolha == 1){
        load(&personagem);
    }

}