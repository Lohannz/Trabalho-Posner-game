//ROLA o DADO PARA A BATALHA
int rolagem_dado(int faces){
    int resultado;
    resultado = rand() % faces + 1;
    return resultado;
}

void combate(PERSONAGEM *atacante, INIMIGO*defensor){
    int turno=0;
    printf("Voce achou um %s!\n", defensor->nome);
    printf("\nseu HP:%d\nHP do monstro:%d\n", atacante->HP, defensor->HP);
        
    while(defensor->HP > 0 && atacante->HP > 0){
        int escolha = 0;
        int dano = 0;
        int dado1 = rolagem_dado(6);
        int dado2 = rolagem_dado(6);

        printf("\n|1-Atacar\n");
        printf("|2-Tentar fugir!\n");
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
            sleep(1);
        }
        else if(defensor->SPD > atacante->SPD){
            dano = (defensor->ATK - atacante->DEF)/2;
            if(dano < 1){
                dano = 1;
            }
            atacante->HP = atacante->HP - dano;
            printf("\nseu HP:%d\nHP do monstro:%d\n", atacante->HP, defensor->HP);
            
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
        turno++;    
        }
        
        
        if(escolha == 2){
            dado1 = rolagem_dado(6);
            dado2 = rolagem_dado(6);
            if(dado1 > dado2){
                printf("\nConseguiu fugir pelo ladinho hehe");
                break;
            }
            else  if(dado2 > dado1){
                printf("\nNao conseguiu. Se fodeu!");
                escolha = 1;
                continue;
                
            }
            else if(dado1 == dado2){
                printf("\nVoce quase conseguiu!");
                escolha = 1;
                continue;
            }
            limpar_tela();

        
        }
    }
    // SISTEMA DE PONTOS
        // SE O PERSONAGEM MATAR O DEFENSOR, GANHA 2 PONTOS
    if(defensor->HP <= 0){
        printf("voce derrotou o %s!\n", defensor->nome);
        atacante->pontos += 2;
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
        default:
            strcpy(mob.nome, "desconhecido");
            mob.id = 0;
            mob.HP = 5;
            mob.ATK = 1;
            mob.DEF = 1;
            mob.SPD = 5;
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