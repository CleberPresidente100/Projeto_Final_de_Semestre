/*
	Nome: Cleber da Silva Melo
	R.A.: 335338215650
	2º Semestre Ciência da Computação
*/

/*
	Jogo Enduro - Projeto de Final de Semestre
*/


/* Bibliotecas */
#include <stdio.h>

#include "tela.h"
#include "carro.h"
#include "caracteres.h"


/* Constantes */
# define POSICAO_PLACAR_DIGITO_1 0
# define POSICAO_PLACAR_DIGITO_2 5
# define POSICAO_PLACAR_DIGITO_3 10

/* Estruturas */
struct struct_Placar
{
	int pos_top_left_x; // Coordenada X (Coluna) na Tela Final do Pixel Superior Esquerdo do Placar
	int pos_top_left_y; // Coordenada Y (Linha) na Tela Final do Pixel Superior Esquerdo do Placar
	char placar[TAMANHO_PLACAR_LINHAS][TAMANHO_PLACAR_COLUNAS];
} placar;

struct struct_Tela
{
	int pos_top_left_x; // Coordenada X (Coluna) na Tela Final do Pixel Superior Esquerdo do Carro
	int pos_top_left_y; // Coordenada Y (Linha) na Tela Final do Pixel Superior Esquerdo do Carro
	struct_Carro carro;
	struct_Placar placar;
} tela;


/* Funções Privadas */



void Cria_Placar()
{
	int linha = 0;
	int coluna = 0;
	
	char auxiliar[TAMANHO_PLACAR_LINHAS][TAMANHO_PLACAR_COLUNAS] =	{
																		{201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187},
																		{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																		{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																		{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																		{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																		{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
																		{200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188}
																	};

	
	for(linha = 0; linha < TAMANHO_PLACAR_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_PLACAR_COLUNAS; coluna++)
		{
			placar.placar[linha][coluna] = auxiliar[linha][coluna];
		}
	}
}



void Alterar_Placar(int pontuacao)
{
	int linha = 0;
	int coluna = 0;
	int digito = 0;
	int numero[3];
	
	/* Separa os Dígitos da Pontuação */
	numero[0] = pontuacao / 100;
	numero[1] = (pontuacao - (numero[0] * 100)) / 10;
	numero[2] = (pontuacao - (numero[0] * 100) - (numero[1] * 10));
		
	/* Insere a Pontuação */
	for(digito = 0; digito < 3; digito++)
	{
		for(linha = ESPESSURA_BORDA_PLACAR; linha < (TAMANHO_PLACAR_LINHAS - ESPESSURA_BORDA_PLACAR); linha++)
		{
			
			for(coluna = ESPESSURA_BORDA_PLACAR; coluna < (TAMANHO_CARACTER_COLUNAS + ESPESSURA_BORDA_PLACAR); coluna++)
			{
				switch(digito)
				{
					case 0:
						placar.placar[linha][coluna + POSICAO_PLACAR_DIGITO_1] = Montar_Caractere(numero[0], (linha - ESPESSURA_BORDA_PLACAR), (coluna - ESPESSURA_BORDA_PLACAR));
					break;
					
					case 1:
						placar.placar[linha][coluna + POSICAO_PLACAR_DIGITO_2] = Montar_Caractere(numero[1], (linha - ESPESSURA_BORDA_PLACAR), (coluna - ESPESSURA_BORDA_PLACAR));
					break;
					
					case 2:
						placar.placar[linha][coluna + POSICAO_PLACAR_DIGITO_3] = Montar_Caractere(numero[2], (linha - ESPESSURA_BORDA_PLACAR), (coluna - ESPESSURA_BORDA_PLACAR));
					break;
				}
			}
		}
	}
}

void Exibe_Placar()
{
	int linha = 0;
	int coluna = 0;
		
	
	for(linha = 0; linha < TAMANHO_PLACAR_LINHAS; linha++)
	{
		printf("\n");
		for(coluna = 0; coluna < TAMANHO_PLACAR_COLUNAS; coluna++)
		{
			printf("%c", placar.placar[linha][coluna]);
		}
	}	
}
	





