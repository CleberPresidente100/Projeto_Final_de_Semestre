/*
	Nome: Cleber da Silva Melo
	R.A.: 335338215650
	2º Semestre Ciência da Computação
*/

/*
	Jogo Enduro - Projeto de Final de Semestre
*/



/* Inclusão das Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* Biblioteca com Funções para Strings */
#include <conio.h> /* Biblioteca da função getch */
#include <locale.h>	/* Biblioteca para Acentuação */
#include <time.h>/* Biblioteca para Data e Hora */


#include "tela.h"
#include "gotoxy.h"
#include "milisegundos.h"
#include "caracteres.h"


/* Constantes */
#define SAIR 5
#define NUM_CADASTROS 3
#define TAMANHO_NOME 100

#define ASCII_1 176
#define ASCII_2 177
#define ASCII_3 178

#define ASCII_11 219
#define ASCII_12 220
#define ASCII_13 221
#define ASCII_14 222
#define ASCII_15 223
#define ASCII_16 254


#define MOVER_CARRO_PARA_DIREITA 1
#define MOVER_CARRO_PARA_ESQUERDA -1


#define TAMANHO_CARRO_LINHAS 6
#define TAMANHO_CARRO_COLUNAS 15

#define TAMANHO_PISTA (TAMANHO_CARRO_COLUNAS * 3)




char CARRO[TAMANHO_CARRO_LINHAS][TAMANHO_CARRO_COLUNAS] =	{
																{221, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 222},
																{223, 223, 223, 223, 219, 219, 219, 219, 219, 219, 219, 223, 223, 223, 223},
																{177, 177, 177, ' ', ' ', ' ', 219, 219, 219, ' ', ' ', ' ', 177, 177, 177},
																{177, 177, 177, 220, 219, 219, 219, 219, 219, 219, 219, 220, 177, 177, 177},
																{177, 177, 177, 223, 219, 219, 219, 219, 219, 219, 219, 223, 177, 177, 177},
																{177, 177, 177, ' ', 223, 223, 223, 223, 223, 223, 223, ' ', 177, 177, 177}
															};


/* Estruturas */



/* Declaração de Funções */
int VerificaTeclasDeMovimentacao(char tecla);



/* Função Main */
int main(void)
{
	int movimentar_carro = 0;
	int opcao = 0;
	int indice = 0;	
	
	int linha = 0;
	int coluna = 0;
	
	
	int sentido = 0;
	int auxiliar = 0;	
	int posicao_carro = 0;
	
	
	clock_t tempo_inicio;
	unsigned int milisegundos = 0;
	
	
	/* Permite o uso de Acentuação */
	setlocale(LC_ALL, "ALL");
	/*
	for(indice = 0; indice < 256; indice++)	
	{
		printf("\n %c = %d", indice, indice);
	}
	
	printf("\n %c = %d", ASCII_1, ASCII_1);
	printf("\n %c = %d", ASCII_2, ASCII_2);
	printf("\n %c = %d", ASCII_3, ASCII_3);
	
	printf("\n %c = %d", ASCII_11, ASCII_11);
	printf("\n %c = %d", ASCII_12, ASCII_12);
	printf("\n %c = %d", ASCII_13, ASCII_13);
	printf("\n %c = %d", ASCII_14, ASCII_14);
	printf("\n %c = %d", ASCII_15, ASCII_15);
	printf("\n %c = %d", ASCII_16, ASCII_16);
	*/
	
	
	//printf("\n\n\n");
	
	
	for(linha = 0; linha < TAMANHO_CARRO_LINHAS; linha++)
	{
		printf("\n");
		for(coluna = 0; coluna < TAMANHO_CARRO_COLUNAS; coluna++)
		{
			printf("%c", CARRO[linha][coluna]);
		}
	}
	
	
	//printf("\n\n\n");
	
	/*
	Exibir_Numero(0);printf("\n");
	Exibir_Numero(1);printf("\n");
	Exibir_Numero(2);printf("\n");
	Exibir_Numero(3);printf("\n");
	Exibir_Numero(4);printf("\n");
	Exibir_Numero(5);printf("\n");
	Exibir_Numero(6);printf("\n");
	Exibir_Numero(7);printf("\n");
	Exibir_Numero(8);printf("\n");
	Exibir_Numero(9);printf("\n");
	*/
	
	Cria_Placar();
	Alterar_Placar(789);
	Exibe_Placar();
	
	getch();
	
	tempo_inicio = Inicia_Cronometro();
	while(1)
	{		
		milisegundos = Tempo_Cronometro(tempo_inicio);
		
		
		if(kbhit())
		{
			//opcao = getch();
			movimentar_carro = VerificaTeclasDeMovimentacao(getch());
		}
		
		
		
		if(movimentar_carro)
		//if(milisegundos > 1)
		{
			//system("cls");
			//printf("\n\n\n");
			if(movimentar_carro == MOVER_CARRO_PARA_DIREITA)
			{
				if(posicao_carro < 10)
				{
					posicao_carro++;
				}
			}
			else if(movimentar_carro == MOVER_CARRO_PARA_ESQUERDA)
			{
				if(posicao_carro > 0)
				{
					posicao_carro--;
				}
			}
			
			movimentar_carro = 0;
			
			for(linha = 0; linha < TAMANHO_CARRO_LINHAS; linha++)
			{
				gotoxy(posicao_carro, linha + 1);
				//printf("\n");
				/*
				for(auxiliar = posicao_carro; auxiliar > 0; auxiliar--)
				{
					printf(" ");
				}
				*/
				for(coluna = 0; coluna < TAMANHO_CARRO_COLUNAS; coluna++)
				{
					printf("%c", CARRO[linha][coluna]);
				}
			}
			/*
			if(posicao_carro >= 5)
			{
				sentido = -1;
			}
			else if(posicao_carro <= 0)
			{
				sentido = 1;
			}
			
			if(sentido > 0)
			{
				posicao_carro++;
			}
			else
			{
				posicao_carro--;
			}
			*/
			//tempo_inicio = Inicia_Cronometro();
		}
	}
	
	do
	{
		/*
		system("cls");
		
		printf("\n\t\t Agenda Eletrônica\n");
		
		printf("\n [1] - Cadastrar");
		printf("\n [2] - Pesquisar");
		printf("\n [3] - Listar");
		printf("\n [4] - Classificar");
		printf("\n [5] - Sair");
		printf("\n ");		
		printf("\n Digite a sua Opção: ");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1:
				Cadastrar(agenda);
			break;
			
			case 2:
				Pesquisar(agenda);
			break;
			
			case 3:
				Listar(agenda);
			break;
			
			case 4:
				Classificar(agenda);
			break;
			
			case 5:
				system("cls");
				printf("\n\n Programa Finalizado !");
				printf("\n\n\n");
			break;
			
			default:
				system("cls");
				printf("\n\n Opção Inválida !!!");
				getch();
			break;
		}
		*/
		//while(!kbhit());
		
		
		if(kbhit())
		{
			opcao = getch();
			printf("\n %c = %d", opcao, opcao);
		}
		
		
		
		
				
	//} while(opcao != SAIR);
	} while(opcao != '5');
	
	
}




int VerificaTeclasDeMovimentacao(char tecla)
{
	if	(
			(tecla == 'a') ||
			(tecla == 'A') ||
			(tecla == 75) 
		)
	{
		return MOVER_CARRO_PARA_ESQUERDA;
	}
	
	if	(
			(tecla == 'd') ||
			(tecla == 'D') ||
			(tecla == 77) 
		)
	{
		return MOVER_CARRO_PARA_DIREITA;
	}
	
	return 0;
}















