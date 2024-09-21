/***************************************************************/
/**                                                           **/
/**   VICTOR PEPE          N�mero USP - 13679565              **/
/**   Exercicio-Programa 03                                   **/
/**   Professor: GUILHERME MOTA                               **/
/**   Turma: 01                                               **/
/**                                                           **/
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define max 50
#define sim 1
#define nao 0
int seraquepode(int N, int coluna[max], int b, int c, int r, int i, int j); /*funcao que retorna sim se aquela posicao puder ser ocupada*/
void printatab(int N, int coluna[max]);                                     /*funcao que imprime o tabuleiro caso v=1*/
int abs(int x);                                                             /* funcao que retorna o valor absoluto*/
void generate(int N, int b, int c, int r, int f, int v);

int main(int argc, char *argv[])
{

    int N = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int r = atoi(argv[4]);
    int f = atoi(argv[5]);
    int v = atoi(argv[6]);
    generate(N, b, c, r, f, v);
    return 0;
}

void generate(int N, int b, int c, int r, int f, int v)
{
    int coluna[N], pode = 0, k, m, deubom, ifreq, jfreq, i = 1, j; /*a estrutura da variavel col(coluna) eh col[linha] = coluna*/
    int freq[N][N], solucoes = 0;
    double razao, numerador, denominador;
    for (k = 1; k <= N; k++)
    {
        for (m = 1; m <= N; m++)
        {
            freq[k][m] = 0; /*definir a frequencia de todas as posioes como 0*/
        }
    }
    for (i = 1; i <= N; i++)
    {
        coluna[i] = 1; /*definir a coluna inicial de todas as linhas como 1*/
    }
    i = 1;
    while (i > 0)
    {
        if (pode == sim)
        {
            pode = nao; /*depois de realizar as acoes necessarias quando uma rainha eh alocada no tabuleiro, devemos devolver o valor 0 (nao) para a variavel pode a fim de deixar o codigo continuar rodando*/
        }
        if (deubom == sim) /*deu bom indica se a tentativa anterior correspondeu a uma solucao*/
        {
            deubom = nao;
        }
        for (coluna[i] = coluna[i]; ((coluna[i] <= N) && (pode == nao)); coluna[i]++)
        {
            j = coluna[i];
            if (seraquepode(N, coluna, b, c, r, i, j) == sim)
            {
                coluna[i] = coluna[i];
                pode = sim;
                if (i == N)
                { /*se a rainha da ultima linha foi posicionada , eh porque uma nova solucao foi encontrada*/
                    solucoes++;
                    deubom = sim;
                    if (f == 1) /*aumentar a frequencia*/
                    {
                        for (ifreq = 1; ifreq <= N; ifreq++)
                        {
                            jfreq = coluna[ifreq];
                            freq[ifreq][jfreq] = freq[ifreq][jfreq] + 1; /*freq[i][j] eh a matriz que indica o numero de vezes que cada rainha foi alocada em cada posicao */
                        }
                    }
                    if (v == 1) /*imprimir o tabuleiro*/
                    {
                        printatab(N, coluna);
                    }
                }
                else /*se nao for a ultima linha do tabuleiro, devemos pular para a proxima*/
                {
                    i++;
                }
            }
        }
        if (pode == nao)
        { /*se pode=nao, eh porque nenhuma coluna daquela linha estava disponivel. Logo, devemos realocar a coluna daquela linha para 1 e retornar uma linha a fim de reposicionar a rainha anterior*/
            coluna[i] = 1;
            i--;
            coluna[i] = coluna[i] + 1;
        }
        if ((pode == sim) && (deubom == nao)) /*se conseguimos posicionar uma rainha, mas nao a ultima (logo nao eh solucao e deubom =0), devemos diminuir a coluna em 1 devido ao aumento indevido realizado pela laco for da Linha 60 do codigo*/
        {
            coluna[i]--;
        }
    }
    if (solucoes == 0)
    {
        printf("Nao ha solucao");
        return 0;
    }

    printf("Total de solucoes= %d\n \n", solucoes);
    if (f == sim)
    {
        printf("Mapa de frequencias: \n\n");
        for (k = 1; k <= N; k++)
        {
            for (m = 1; m <= N; m++)
            {
                numerador = (double)freq[k][m];
                denominador = (double)solucoes;
                razao = numerador / denominador;
                printf("%lf  ", razao);
            }
            printf("\n");
        }
        return 0;
    }
}
int seraquepode(int N, int coluna[max], int b, int c, int r, int i, int j)
{             /*blib define se a posicao vai ser bloqueada ou liberada*/
    int k, m; /*k e m sao variaveis auxiliares para testes */

    /*movimentos de torre*/
    for (k = i - 1; k >= 1; k--)
    {
        if (coluna[k] == j)
        {
            return nao;
        }
    }
    /*movimentos de bispo*/
    if (b == sim)
    {
        for (k = i - 1; k >= 1; k--)
        {
            if ((i - k) == (abs(j - coluna[k])))
            {
                return nao;
            }
        }
    }

    /*movimentos de rei*/
    if (r == sim)
    {
        k = i - 1;
        if (abs(j - coluna[k]) == 1)
        {
            return nao;
        }
        /*movimentos de cavalo*/
        if (c == 1)
        {
            for (k = i - 1; k >= 1; k--)
            {
                if (((i == k + 2) && (abs(j - coluna[k]) == 1)) || ((i == k + 1) && (abs(j - coluna[k]) == 2)))
                {
                    return nao;
                }
            }
        }
    }
    return sim;
}
void printatab(int N, int coluna[max])
{
    int i = 1, j = 1;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            if (coluna[i] == j)
            {
                printf("X ");
            }
            else
            {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int abs(int x)
{
    if (x >= 0)
    {
        return x;
    }
    else
    {
        return (-x);
    }
}
