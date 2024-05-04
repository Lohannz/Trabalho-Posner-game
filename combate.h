//ROLA o DADO PARA A BATALHA
int rolagem_dado(int faces){
	int resultado;
	resultado = rand() % faces + 1;
	return resultado;
}

void combate(PERSONAGEM *atacante, INIMIGO*defensor){
	printf("Voce entrou em batalha com %s", defensor->nome);
	int dano = 0;

	int dado1 = rolagem_dado(6);
	int dado2 = rolagem_dado(6);
	if(dado1 > dado2){
		dano = defensor->DEF - atacante->ATK;
		defensor->HP = defensor->HP - dano;
	}
	if(dado2 > dado1){
		dano = atacante->DEF - atacante->ATK;
		atacante->HP = atacante->HP - dano;
	}
	INIMIGO esqueleto;
	esqueleto.id = 1;
	esqueleto.HP = 100;
	esqueleto.ATK = 2;
	esqueleto.DEF = 1;
	esqueleto.posicao = 1;

}

