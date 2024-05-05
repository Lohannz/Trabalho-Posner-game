#include <stdio.h>
#include <stdlib.h>

#define TAM_TEX_MAXIMO 400
#define NUMERO_DE_PAGINAS 10 // Defina o número total de páginas

int main() {
    FILE *gravar;
    char texto[TAM_TEX_MAXIMO];

    // Abre o arquivo para gravação em modo binário
    gravar = fopen("historia.dat", "wb");
    if (gravar == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Escreve o texto de cada página no arquivo
    for (int i = 0; i < NUMERO_DE_PAGINAS; i++) {
        printf("Digite o texto da pagina %d: ", i);
        fgets(texto, TAM_TEX_MAXIMO, stdin); // Obtém o texto da página
        fwrite(texto, sizeof(char), TAM_TEX_MAXIMO, gravar); // Escreve o texto no arquivo
    }

    // Fecha o arquivo
    fclose(gravar);

    printf("Historia gravada com sucesso!\n");

    return 0;
}
