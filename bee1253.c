#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

// Função para decodificar uma string usando a cifra de César
void decifrar_cifra_de_cesar(char* texto, int deslocamento) {
    int i;
    int tamanho = strlen(texto);

    for (i = 0; i < tamanho; i++) {
        // Subtraímos o deslocamento da letra atual
        texto[i] = ((texto[i] - 'A' - deslocamento + 26) % 26) + 'A';
    }
}

int main() {
    int n, deslocamento;
    char texto[MAX_LEN + 1];

    // Lê o número de casos de teste
    scanf("%d", &n);

    while (n--) {
        // Lê o texto codificado e o deslocamento
        scanf("%s", texto);
        scanf("%d", &deslocamento);

        // Decodifica o texto
        decifrar_cifra_de_cesar(texto, deslocamento);

        // Imprime o texto decodificado
        printf("%s\n", texto);
    }

    return 0;
}
