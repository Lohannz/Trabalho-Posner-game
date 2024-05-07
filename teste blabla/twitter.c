#include<stdio.h>
#include<stdlib.h>
#include<time.h> //biblioteca que permite recuperar a hora atual do sistema

int main()
	{
	int soma = 0, contador=0, i=0, freq[100]={0};
	srand(time(NULL)); //fun��o que escolhe nova semente para n�mero aleat�rio, sem ele cada vez que voc� rodar o programa dar� o mesmo n�mero

	while(i<1000) //realiza 1000 experimentos
		{
		soma = 0;
		contador = 0;
		while(soma < 100) //enquanto a soma dos dados de 6 faces n�o d� mais que 100
			{
			soma = soma + (rand()%6 + 1);
			contador++; 
			}
		freq[contador]++; //o contador diz quantos dados nessa rodada precisaram ser jogados para dar 100, aumenta frequencia em uma unidade
		i++;
		}	
	
	for(i=0; i<100; i++) //imprime a distribui��o dos 1000 experimentos na frequencia de quantos dados precisaram ser jogados para chegar ao valor 100
		printf("rodadas %d: %d\n", i, freq[i]);
	return 0;
	}
