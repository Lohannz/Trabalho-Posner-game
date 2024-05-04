//ROLA o DADO PARA A BATALHA
int rolagem_dado(int faces){
	int resultado;
	resultado = rand() % faces + 1;
	return resultado;
}

void combate(PERSONAGEM *atacante, INIMIGO*defensor){
	
	while(defensor->HP > 0 && atacante->HP > 0){
	
		printf("\nVoce entrou em batalha com %s\n", defensor->nome);
		int dano = 0;
	
		int dado1 = rolagem_dado(6);
		int dado2 = rolagem_dado(6);

		printf("\ndado1:%d\ndado2:%d\n", dado1, dado2);
		if(dado1 > dado2){
			dano = defensor->DEF - atacante->ATK;
			if(dano < 1){
				dano = 1;
			} 
			defensor->HP = defensor->HP - dano;
			printf("\nseu HP:%d\nHP do monstro:%d\n", atacante->HP, defensor->HP);
		}else if(dado2 > dado1){
			dano = atacante->DEF - defensor->ATK;
			if(dano < 1){
				dano = 1;
			}
			atacante->HP = atacante->HP - dano;
			printf("\nseu HP:%d\nHP do monstro:%d\n", atacante->HP, defensor->HP);
		}else if(dado1 == dado2){
			printf("\n||clash!||\n");
		}
	}
	
}
