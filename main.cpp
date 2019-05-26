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
#include <string.h>	/* Biblioteca com Funções para Strings */
#include <conio.h>	/* Biblioteca da função getch */
#include <locale.h>	/* Biblioteca para Acentuação */
#include <time.h>	/* Biblioteca para Data e Hora */


#include "tela.h"
#include "carro.h"
#include "pista.h"
#include "gotoxy.h"
#include "milisegundos.h"
#include "caracteres.h"


/* Constantes */
#define ESC 27
#define SAIR '4'

/* Estruturas */



/* Declaração de Funções */
void Inicia_Jogo();
int VerificaTeclasDeMovimentacao(char tecla);
int Determina_Velocidade_do_Jogo(int pontuacao);




/* Função Main */
int main(void)
{
	int opcao = 0;
	int exibir_menu = 1;
		
	
	/* Permite o uso de Caracteres da Tabela ASCII Extendida */
	setlocale(LC_ALL, "ALL");
	
	
	do
	{
		/* Verifica se a Tela deve ser Recarregada */
		if(exibir_menu)
		{			
			Realiza_Inicializacao_das_Estruturas();
			Exibe_Tela(); // Exibe as Bordas da Tela
			Exibe_Menu_Principal();
			exibir_menu = 0;
		}
		
		/* Espera o Usuário Escolher uma Opção */
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
			
			case '3':
				Realiza_Inicializacao_das_Estruturas();
				Exibe_Tela(); // Exibe as Bordas da Tela
				Exibe_Menu_Sobre();
				while(getch() != ESC); // Espera a Tecla ESC ser Precionada
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
	
	/* Falha na Borda da Pista que dá a impressão de Movimento */
	int posicao_falha_pista = -1;
	int movimentar_falha_pista = 0;
	
	/* Contagem de Tempo */
	clock_t tempo_inicio;
	unsigned int milisegundos = 0;
	unsigned int velocidade_do_jogo = 0;
	
	/* Pontuação */
	int pontuacao = 0;
	float tempo_decorrido = 0; // número de segundo que será substituído pela pontuação de buracos
	
	/* Determina o Fim de Jogo */
	int fim_de_jogo = 0;
	
	
	
	
	
	/* Configurações Iniciais */
	velocidade_do_jogo = Determina_Velocidade_do_Jogo(pontuacao);
	tempo_inicio = Inicia_Cronometro();
	
	
	/* Looping do Jogo */
	while(1)
	{		
		milisegundos = Tempo_Cronometro(tempo_inicio);
		
		
		if(milisegundos >= 1)
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
			if(movimentar_falha_pista >= velocidade_do_jogo)
			{
				movimentar_falha_pista = 0;
				
				posicao_falha_pista++;
				if(posicao_falha_pista > TAMANHO_PISTA_LINHAS)
				{
					posicao_falha_pista = 0;
				}				
				
				Atualiza_Falha_Pista(posicao_falha_pista);
				velocidade_do_jogo = Determina_Velocidade_do_Jogo(pontuacao);
			}
						
			/* Alterar Pontuação */
			tempo_decorrido += milisegundos;
			if(tempo_decorrido >= 1000)
			{
				tempo_decorrido = 0;
				
				/* Validação da Pontuação */
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



int Determina_Velocidade_do_Jogo(int pontuacao)
{
	int velocidade_do_jogo = 0;
	
	if(pontuacao < 10)
	{
		velocidade_do_jogo = 50;
	}
	else if(pontuacao < 20)
	{
		velocidade_do_jogo = 40;
	}
	else if(pontuacao < 30)
	{
		velocidade_do_jogo = 30;
	}
	else if(pontuacao < 40)
	{
		velocidade_do_jogo = 20;
	}
	else if(pontuacao < 50)
	{
		velocidade_do_jogo = 10;
	}
	else if(pontuacao < 60)
	{
		velocidade_do_jogo = 1;
	}
	
	return velocidade_do_jogo;
}













