/***************************************************************/
/**                                                           **/
/**   VICTOR PEPE          Número USP - 13679565              **/
/**   Exercício-Programa 01                                   **/
/**   Professor: GUILHERME MOTA                               **/
/**   Turma: 01                                               **/
/**                                                           **/
/***************************************************************/

#include <stdio.h>

int main()
{

	int semente, senha;
	printf("Bem vinda(o) ao Numle\n");
	printf("Digite a semente para sortear a senha (0 a 10000): ");
	scanf("%d", &semente);
	semente = semente % 134456;
	/* sorteia um numero aleatorio entre 0 e 99999 */
	senha = ((8121 * semente + 28411) % 134456) % 100000;

	int digito1, digito2, digito3, digito4, digito5;
	/*digitos da senha, sendo digito 1 o primeiro da esquerda para a direita*/
	int resp1, resp2, resp3, resp4, resp5;
	/*digitos da resposta sendo resp1 o primeiro da esquerda para a direita*/
	int tentativas, contador_tentativas, resposta;
	/*contador_tentativas serve para contar quantas tentativas ja foram gastas*/
	int check1, check2, check3, check4, check5;
	/* essas variaveis servem para checar se o respectivo digito da senha ja foi
   utilizado na saida do console, seja indicando que o numero esta certo ou que esta na posicao errada. Se check=1, ainda esta disponivel. Se check=0, ja foi utilizada.*/
	int check_1, check_2, check_3, check_4, check_5;
	/*Essas variaveis, similarmente a anterior, indica quais digitos da tentativa terao uma saida associada a eles.
	Se check_=1, o digito nao esta certo nem na posicao errada. Se chech_=0, foi usado na posicao incorreta e se = 2, usado na posicao correta.*/
	check1 = 1;
	check2 = 1;
	check3 = 1;
	check4 = 1;
	check5 = 1;
	check_1 = 1;
	check_2 = 1;
	check_3 = 1;
	check_4 = 1;
	check_5 = 1;
	digito5 = senha % 10;
	digito4 = (senha / 10) % 10;
	digito3 = ((senha / 10) / 10) % 10;
	digito2 = ((((senha / 10) / 10) / 10) % 10);
	digito1 = ((((senha / 10) / 10) / 10) / 10) % 10;

	printf("\nQuantidade de tentativas(1 a 10):");
	scanf("%d", &tentativas);
	for (contador_tentativas = 0; contador_tentativas < tentativas; contador_tentativas++)
	{

		check1 = 1;
		check2 = 1;
		check3 = 1;
		check4 = 1;
		check5 = 1;
		check_1 = 1;
		check_2 = 1;
		check_3 = 1;
		check_4 = 1;
		check_5 = 1;
		printf("\n \nDigite a tentativa(0 a 99999):");
		scanf("%d", &resposta);
		resp5 = resposta % 10;
		resp4 = (resposta / 10) % 10;
		resp3 = ((resposta / 10) / 10) % 10;
		resp2 = (((resposta / 10) / 10) / 10) % 10;
		resp1 = ((((resposta / 10) / 10) / 10) / 10) % 10;
		if (resposta == senha)
		{
			printf("\nVoce acertou! A senha eh de fato %d.", senha);
			return 0;
		}

		if (digito1 == resp1)
		{

			check1 = 0;
			check_1 = 2;
		}

		if (digito2 == resp2)
		{

			check2 = 0;
			check_2 = 2;
		}

		if (digito3 == resp3)
		{

			check3 = 0;
			check_3 = 2;
		}

		if (digito4 == resp4)
		{

			check4 = 0;
			check_4 = 2;
		}

		if (digito5 == resp5)
		{

			check5 = 0;
			check_5 = 2;
		}

		if (resp1 == digito2 && check2 == 1 && check_1 == 1)
		{

			check2 = 0;
			check_1 = 0;
		}
		else
		{
			if (resp1 == digito3 && check3 == 1 && check_1 == 1)
			{

				check3 = 0;
				check_1 = 0;
			}
			else
			{
				if (resp1 == digito4 && check4 == 1 && check_1 == 1)
				{

					check4 = 0;
					check_1 = 0;
				}
				else
				{
					if (resp1 == digito5 && check5 == 1 && check_1 == 1)
					{

						check5 = 0;
						check_1 = 0;
					}
				}
			}
		}

		if (resp2 == digito1 && check1 == 1 && check_2 == 1)
		{

			check1 = 0;
			check_2 = 0;
		}
		else
		{
			if (resp2 == digito3 && check3 == 1 && check_2 == 1)
			{

				check3 = 0;
				check_2 = 0;
			}
			else
			{
				if (resp2 == digito4 && check4 == 1 && check_2 == 1)
				{

					check4 = 0;
					check_2 = 0;
				}
				else
				{
					if (resp2 == digito5 && check5 == 1 && check_2 == 1)
					{
						check5 = 0;
						check_2 = 0;
					}
				}
			}
		}

		if (resp3 == digito1 && check1 == 1 && check_3 == 1)
		{
			check1 = 0;
			check_3 = 0;
		}
		else
		{
			if (resp3 == digito2 && check2 == 1 && check_3 == 1)
			{

				check2 = 0;
				check_3 = 0;
			}
			else
			{
				if (resp3 == digito4 && check4 == 1 && check_3 == 1)
				{

					check4 = 0;
					check_3 = 0;
				}
				else
				{
					if (resp3 == digito5 && check5 == 1 && check_3 == 1)
					{
						check5 = 0;
						check_3 = 0;
					}
				}
			}
		}

		if (resp4 == digito1 && check1 == 1 && check_4 == 1)
		{
			check1 = 0;
			check_4 = 0;
		}
		else
		{
			if (resp4 == digito2 && check2 == 1 && check_4 == 1)
			{
				check2 = 0;
				check_4 = 0;
			}
			else
			{
				if (resp4 == digito3 && check3 == 1 && check_4 == 1)
				{
					check3 = 0;
					check_4 = 0;
				}
				else
				{
					if (resp4 == digito5 && check5 == 1 && check_4 == 1)
					{
						check5 = 0;
						check_4 = 0;
					}
				}
			}
		}

		if (resp5 == digito1 && check1 == 1 && check_5 == 1)
		{
			check1 = 0;
			check_5 = 0;
		}
		else
		{
			if (resp5 == digito2 && check2 == 1 && check_5 == 1)
			{
				check2 = 0;
				check_5 = 0;
			}
			else
			{
				if (resp5 == digito3 && check3 == 1 && check_5 == 1)
				{
					check3 = 0;
					check_5 = 0;
				}
				else
				{
					if (resp5 == digito4 && check4 == 1 && check_5 == 1)
					{
						check4 = 0;
						check_5 = 0;
					}
				}
			}
		}

		if (check_1 == 2)
		{
			printf("\nPrimeiro digito certo!");
		}
		if (check_1 == 0)
		{
			printf("\nPrimeiro digito em posicao incorreta.");
		}
		if (check_2 == 0)
		{
			printf("\nSegundo digito em posicao incorreta.");
		}
		if (check_2 == 2)
		{
			printf("\nSegundo digito certo!");
		}
		if (check_3 == 0)
		{
			printf("\nTerceiro digito em posicao incorreta.");
		}
		if (check_3 == 2)
		{
			printf("\nTerceiro digito certo!");
		}
		if (check_4 == 0)
		{
			printf("\nQuarto digito em posicao incorreta.");
		}
		if (check_4 == 2)
		{
			printf("\nQuarto digito certo!");
		}
		if (check_5 == 0)
		{
			printf("\nQuinto digito em posicao incorreta.");
		}
		if (check_5 == 2)
		{
			printf("\nQuinto digito certo!");
		}
	}

	printf("\nVoce perdeu! A senha era %d", senha);
	return 0;
}
