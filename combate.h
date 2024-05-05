//ROLA o DADO PARA A BATALHA
int rolagem_dado(int faces){
    int resultado;
    resultado = rand() % faces + 1;
    return resultado;
}

void combate(PERSONAGEM *atacante, INIMIGO*defensor){
    int turno=0;
    while(defensor->HP > 0 || atacante->HP > 0){
    
        printf("\nVoce entrou em batalha com %s\n", defensor->nome);
        int dano = 0;
    
        int dado1 = rolagem_dado(6);
        int dado2 = rolagem_dado(6);

        printf("\ndado1:%d\ndado2:%d\n", dado1, dado2);
        if(atacante->SPD > defensor->SPD){
            dano = (defensor->DEF - atacante->ATK)/2;
            if(dano < 1){
                dano = 1;
            } 
            defensor->HP = defensor->HP - dano;
            printf("\nseu HP:%d\nHP do monstro:%d\n", atacante->HP, defensor->HP);
        }else if(defensor->SPD > atacante->SPD){
            dano = (atacante->DEF - defensor->ATK)/2;
            if(dano < 1){
                dano = 1;
            }
            atacante->HP = atacante->HP - dano;
            printf("\nseu HP:%d\nHP do monstro:%d\n", atacante->HP, defensor->HP);
        }else if(atacante->SPD == defensor->SPD){
            atacante->SPD = rolagem_dado(6);
            atacante->SPD = rolagem_dado(6);
        }
        
        if(turno % 2 == 0){
			int temp = atacante->SPD;
        	atacante->SPD = defensor->SPD;
        	defensor->SPD = temp;
		}
		
    }
    turno++;
}
