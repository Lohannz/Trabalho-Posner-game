void menu_principal(){
    int escolha=0; int rodando = 1;

	while(rodando){
		
		printf("Escolha entre as opcoes numeradas:\n\n|1-Novo Jogo\n|2-Continuar\n|3-Ranking\n|4-Desenvolvedores\n|0-Fechar Programa\n\n");
		printf("Digite o numero da opcao: ");
		scanf("%d", &escolha);

        switch (escolha){
        case 1:
            PERSONAGEM* personagem = criarPersonagem();
            break;
        case 2:
            limpar_tela();
            load();
            break;
        
        case 3:
            printf("Ranking...");
            break;
        
        case 4:
            limpar_tela();
            printf("Fernando Brawl Stars\nGustavo Brawlhalla\nLohan");
            printf("clique em qualquer tecla para voltar");
            break;
        

        default:
            break;
        }  
    }
}