#include<stdio.h>

void menu(){
	int escolha=0, parar=1;
	//char nickname[51]
	
	while(parar!=0){
		
		printf("Escolha entre as opcoes numeradas:\n\n|1-Novo Jogo\n|2-Continuar\n|3-Ranking\n|4-Desenvolvedores\n|0-Fechar Programa\n\n");
		printf("Digite o numero da opcao: ");
		scanf("%d", &escolha);
		
		if(escolha == 1){
			system("cls");
		/*printf("Bem vindo a criacao de personagem!\n\n");
			printf("Digite o seu nickname(no maximo 50 caracteres): ");
			scanf("%s", nickname);
			printf("\n\nSeja bem vindo(a) %s!\nAqui no mundo de xurumelas existem 4 classes: guerreiros, magos, arqueiros e clerigos.", nickname);*/
			criarPersonagem();
			printf("\n\nDigite 1 para voltar ao menu e 0 para fechar o jogo: ");
			scanf("%d", &escolha);
			if(escolha == 1){
				parar = 1;
				system("cls");
				
			}else{
				parar = 0;
			}
		}else if(escolha == 2){
			system("cls");
			printf("\nvoce escolheu a opcao %d", escolha);
			printf("\n\nDigite 1 para voltar ao menu e 0 para fechar o jogo: ");
			scanf("%d", &escolha);
			if(escolha == 1){
				parar = 1;
				system("cls");
				
			}else{
				parar = 0;
			}
		} else if(escolha == 3){
			system("cls");
			printf("\nvoce escolheu a opcao %d", escolha);
			printf("\n\nDigite 1 para voltar ao menu e 0 para fechar o jogo: ");
			scanf("%d", &escolha);
			if(escolha == 1){
				parar = 1;
				system("cls");
				
			}else{
				parar = 0;
			}
		} else if(escolha == 4){
			system("cls");
			printf("Gustavo Simplicio Bernardo\nLohan :Nerd_Emoji:\nCalango");
			printf("\n\nDigite 1 para voltar ao menu e 0 para fechar o jogo: ");
			scanf("%d", &escolha);
			if(escolha == 1){
				parar = 1;
				system("cls");
				
			}else{
				parar = 0;
			}
		}else if(escolha ==0){
			parar = 0;
		}else{
			system("cls");
			printf("\nopcao nao existente!");
			printf("\n\nDigite 1 para voltar ao menu e 0 para fechar o jogo: ");
			scanf("%d", &escolha);
			if(escolha == 1){
				parar = 1;
				system("cls");
				
			}else{
				parar = 0;
			}
		}
	
	}
}
