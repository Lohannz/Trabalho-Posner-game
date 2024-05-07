//gravacao arquivo depois
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//cria a estrutura do personagem
typedef struct _PERSONAGEM
	{
	int vida;
	int ataque;
	int velocidade;
	int defesa;
	}PERSONAGEM;

//função combate que recebe um personagem atacante e um personagem defensor
//se o ataque do personatem atacante é maior ou igual que a defesa do defensor
//atualiza a vida do defensor reduzindo o valor do ataque do atacante menos a defesa do defensor
void combate(PERSONAGEM *atacante, PERSONAGEM *defensor);

//função de combate que recebe um personagem atacante e um defensor
//rola um dado aleatorio de 20 faces
//se o resultado é maior que a defesa do defensor
//atualiza a vida do defensor reduzindo o valor do ataque do atacante
void combate2(PERSONAGEM *atacante, PERSONAGEM *defensor);

int main()
	{
	int turno = 1;
	PERSONAGEM p1, p2;
	scanf("%d %d %d %d", &p1.vida, &p1.ataque, &p1.velocidade, &p1.defesa); //le os dados do personagem 1
	scanf("%d %d %d %d", &p2.vida, &p2.ataque, &p2.velocidade, &p2.defesa); //le os dados do personagem 2
	
	srand(time(NULL));//inicializa semente aleatoria usando tempo sistema
	
	while(p1.vida > 0 && p2.vida > 0) //enquanto um dos personagens não ficou com vida negativa
		{
		if((turno % p1.velocidade == 0) && (turno % p2.velocidade == 0)) //se ambos atacam no turno
			{
			if(p1.velocidade >= p2.velocidade) //se a velocidade do p1 é maior ele ataca primeiro
				{
				combate2(&p1, &p2);
				combate2(&p2, &p1);
				}
			else
				{
				combate2(&p2, &p1);
				combate2(&p1, &p2);
				}
			}
		else if(turno % p1.velocidade == 0) //se só o p1 ataca no turno
			combate2(&p1, &p2);
		else if(turno % p2.velocidade == 0)	//se só o p2 ataca no turno
			combate2(&p2, &p1);
		turno++;
		printf("turno %d: vida p1: %d, vida p2: %d\n", turno, p1.vida, p2.vida);
		}
	
	
	return 0;
	}
	
void combate(PERSONAGEM *atacante, PERSONAGEM *defensor)
	{
	int dano = 0;
	
	if(atacante->ataque >= defensor->defesa)
		dano = atacante->ataque - defensor->defesa;
	
	defensor->vida = defensor->vida - dano;
	}

void combate2(PERSONAGEM *atacante, PERSONAGEM *defensor)	
	{
	int dado;
	dado = (rand() % 20) + 1; //rand()%20 aleatorio entre 0 e 19 +1 fica entre 1 e 20
	printf("\t dado %d, defesa %d\n", dado, defensor->defesa);
	if(dado >= defensor->defesa)
		defensor->vida = defensor->vida - atacante->ataque;
	}

