#include <stdio.h>

int main(){
    int A, C;
    
    while(scanf("%d %d", &A, &C) == 2){
        if(A == 0 && C == 0)
            break;
            
        int prev, curr;
        int laser = 0;
        
        // Lê a primeira coluna
        scanf("%d", &prev);
        // No início, temos o bloco inteiro (altura A) e precisamos remover a diferença
        laser += (A - prev);
        
        // Para as demais colunas
        for(int i = 1; i < C; i++){
            scanf("%d", &curr);
            if(prev > curr)
                laser += (prev - curr);
            prev = curr;
        }
        
        printf("%d\n", laser);
    }
    return 0;
}
