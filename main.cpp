/*
	Nome: Cleber da Silva Melo
	R.A.: 335338215650
	2� Semestre Ci�ncia da Computa��o
*/

/*
	Jogo Enduro - Projeto de Final de Semestre
*/



/* Inclus�o das Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	/* Biblioteca com Fun��es para Strings */
#include <conio.h>	/* Biblioteca da fun��o getch */
#include <locale.h>	/* Biblioteca para Acentua��o */
#include <time.h>	/* Biblioteca para Data e Hora */


#include "tela.h"
#include "carro.h"
#include "pista.h"
#include "gotoxy.h"
#include "milisegundos.h"
#include "caracteres.h"


/* Constantes */
#define ESC 27
#define SAIR '3'

/* Estruturas */



/* Declara��o de Fun��es */
void Inicia_Jogo();
int VerificaTeclasDeMovimentacao(char tecla);



/* Fun��o Main */
int main(void)
{
	int opcao = 0;
	int exibir_menu = 1;
		
	
	/* Permite o uso de Acentua��o */
	setlocale(LC_ALL, "ALL");
	
	
	do
	{
		/* Verifica se a Tela deve ser Recarregada */
		if(exibir_menu)
		{			
			Realiza_Inicializacao_das_Estruturas();
			Exibe_Tela(); // Exibe as Bordas da Tela
			Exibe_Menu();
			exibir_menu = 0;
		}
		
		/* Espera o Usu�rio Escolher uma Op��o */
		fflush(stdin);
		opcao = getch();
		
		switch(opcao)
		{
			case '1':
				Inicia_Jogo();
				exibir_menu++;
			break;
			
			case '2':
				exibir_menu++;
			break;
			
			case SAIR:
			default:
			break;
		}
		
	}while(opcao != SAIR);
	
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



void Inicia_Jogo()
{
	/* Carro */
	int sentido = 0;
	int posicao_carro = 0;
	int movimentar_carro = 0;
	
	/* Falha na Pista que d� a impress�o de Movimento */
	int posicao_falha_pista = -1;
	int movimentar_falha_pista = 0;
	
	/* Contagem de Tempo */
	clock_t tempo_inicio;
	unsigned int milisegundos = 0;
	
	/* Pontua��o */
	int pontuacao = 0;
	float tempo_decorrido = 0; // n�mero de segundo que ser� substitu�do pela pontua��o de buracos
	
	/* Determina o Fim de Jogo */
	int fim_de_jogo = 0;
	
	
	
	tempo_inicio = Inicia_Cronometro();
	
	while(1)
	{		
		milisegundos = Tempo_Cronometro(tempo_inicio);
		
		
		if(milisegundos >= 10)
		{
			/* Movimenta o Carro */
			if(kbhit())
			{
				movimentar_carro = VerificaTeclasDeMovimentacao(getch());
								
				if(movimentar_carro)
				{
					Move_Carro(movimentar_carro);					
					movimentar_carro = 0;
				}
			}
			
			/* Movimenta Falha na Borda da Pista */
			movimentar_falha_pista++;
			if(movimentar_falha_pista >= 5)
			{
				movimentar_falha_pista = 0;
				
				posicao_falha_pista++;
				if(posicao_falha_pista > TAMANHO_PISTA_LINHAS)
				{
					posicao_falha_pista = 0;
				}
				
				Atualiza_Falha_Pista(posicao_falha_pista);
			}
						
			/* Alterar Pontua��o */
			tempo_decorrido += milisegundos;
			if(tempo_decorrido >= 1000)
			{
				tempo_decorrido = 0;
				
				/* Valida��o da Pontua��o */
				pontuacao++;
				if((pontuacao < 0) || (pontuacao > 999))
				{
					pontuacao = 0;
				}
				
				Alterar_Placar(pontuacao);
			}
			
			/* Atualiza a Tela */
			fim_de_jogo = Atualizar_Tela();
			
			/* Fim de Jogo */
			if(fim_de_jogo)
			{
				while(getch() != ESC);				
				break;
			}
			
			tempo_inicio = Inicia_Cronometro();
			
		}
	}
}














