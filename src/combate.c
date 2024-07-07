#include"combate.h"
#include<stdio.h>
#include <stdlib.h>
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
            upar;
        }
    }
    if(personagem->LEVEL = 2){
        if(personagem->pontos >= 12){
            upar;
        }
    }
    if(personagem->LEVEL = 3){
        if(personagem->pontos >= 20){
            upar;
        }
    }
    if(personagem->LEVEL = 4){
        if(personagem->pontos >= 30){
            upar;
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
    printf("Voce achou um %s!\n", defensor->nome);
    
        
    while(defensor->HP > 0 && atacante->HP > 0){
        int escolha = 0;
        int dano = 0;
        int dado1 = rolagem_dado(6);
        int dado2 = rolagem_dado(6);

        limpar_tela();
        printf("\nseu HP:%d\nHP do monstro:%d\n", atacante->HP, defensor->HP);
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
    // SISTEMA DE PONTOS
        // SE O PERSONAGEM MATAR O DEFENSOR, GANHA 1 PONTOS
    if(defensor->HP <= 0){
        printf("voce derrotou o %s!\n", defensor->nome);
        atacante->pontos += 1;
    }
    // SE PERDER, MENOS 2 PONTOS E VOLTA UMA POSIÇAO NA HISTORIA
    if(atacante->HP <= 0){
        printf("Voce morreu!\n");
        atacante->pontos -= 2;
        morte(atacante);
    }
    pausar();

}

INIMIGO gerar_mob(int tipo){
    INIMIGO mob;

    switch (tipo) {
        case 1:
            strcpy(mob.nome, "esqueleto");
            mob.id = 1;
            mob.HP = 10;
            mob.ATK = 2;
            mob.DEF = 1;
            mob.SPD = 10;
            break;
        //outros casos para diferentes tipos de mobs
        case 2:
            strcpy(mob.nome, "aranha");
            mob.id = 2;
            mob.HP = 10;
            mob.ATK = 6;
            mob.DEF = 5;
            mob.SPD = 10;
            break;
        case 3:
            strcpy(mob.nome, "rato bombado");
            mob.id = 3;
            mob.HP = 30;
            mob.ATK = 12;
            mob.DEF = 8;
            mob.SPD = 15;
        case 4:
            strcpy(mob.nome, "Orc parrudo");
            mob.id = 4;
            mob.HP = 40;
            mob.ATK = 22;
            mob.DEF = 12;
            mob.SPD = 12;
        case 5:
            strcpy(mob.nome, "Rei Orc");
            mob.id = 5;
            mob.HP = 100;
            mob.ATK = 25;
            mob.DEF = 15;
            mob.SPD = 5;
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
