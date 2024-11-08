#include <stdio.h>
#define MAX 150

void danca(char v[])
{
    for (int i = 0; v[i] != '\0'; i++)
    {
        if (i != 0)
        {
            if (v[i - 1] < 65 && v[i - 1] > 90)
            {
                v[i] = v[i] + 32;
            }
            else if (v[i] > 96 && v[i] < 124)
            {
                v[i] = v[i] - 32;
            }
        }
        else
        {
            if (v[i] > 96 && v[i] < 124)
            {
                v[i] = v[i] - 32;
            }
        }
    }
    for (int i = 0; v[i] != '\0'; i++)
    {
        printf("%c", v[i]);
    }
}

int main()
{
    char frase[MAX];
    fgets(frase, sizeof(frase), stdin);
    danca(frase);
}
