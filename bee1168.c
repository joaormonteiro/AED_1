#include <stdio.h>
#include <string.h>

#define MAX_EXPRESSAO 1001
#define MAX_ENTRADAS 10000

void verificar_balanceamento(char* expressao) {
    int contador = 0;

    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            contador++;
        } else if (expressao[i] == ')') {
            contador--;
            if (contador < 0) {
                printf("incorrect\n");
                return;
            }
        }
    }

    if (contador == 0) {
        printf("correct\n");
    } else {
        printf("incorrect\n");
    }
}

int main() {
    char expressao[MAX_EXPRESSAO];

    // Enquanto houver entrada
    while (fgets(expressao, MAX_EXPRESSAO, stdin) != NULL) {
        // Remove o '\n' do final da string
        expressao[strcspn(expressao, "\n")] = '\0';

        // Verifica o balanceamento da expressão
        verificar_balanceamento(expressao);
    }

    return 0;
}
