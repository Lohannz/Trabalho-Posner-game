#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_TEX_MAXIMO 4000

#define NUMERO_DE_PAGINAS 30 // Defina o número total de páginas

int main() {
    FILE *gravar;
    char texto[TAM_TEX_MAXIMO];
    char linha[TAM_TEX_MAXIMO];

    // Abre o arquivo para gravação em modo binário
    gravar = fopen("historia.dat", "wb");
    if (gravar == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Escreve o texto de cada página no arquivo
    for (int i = 1; i <= NUMERO_DE_PAGINAS; i++) {
        printf("Digite o texto da pagina %d (termine com uma linha em branco):\n", i);
        texto[0] = '\0';  // Inicializa o texto como uma string vazia

        // Lê múltiplas linhas até encontrar uma linha em branco
        while (1) {
            fgets(linha, TAM_TEX_MAXIMO, stdin);
            if (strcmp(linha, "\n") == 0) break;  // Linha em branco indica fim da página

            // Verifica se há espaço suficiente para adicionar a nova linha
            if (strlen(texto) + strlen(linha) >= TAM_TEX_MAXIMO - 1) {
                printf("Texto muito longo para uma pagina!\n");
                return 1;
            }

            strcat(texto, linha);  // Adiciona a linha ao texto
        }

        fwrite(texto, sizeof(char), TAM_TEX_MAXIMO, gravar); // Escreve o texto no arquivo
    }

    // Fecha o arquivo
    fclose(gravar);

    printf("Historia gravada com sucesso!\n");

    return 0;
}
