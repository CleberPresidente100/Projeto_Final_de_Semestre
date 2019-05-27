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
#define SAIR '4'

/* Estruturas */



/* Declara��o de Fun��es */
void Inicia_Jogo();
int Verifica_Pontuacao(int pontuacao);
int VerificaTeclasDeMovimentacao(char tecla);
int Determina_Velocidade_do_Jogo(int pontuacao);




/* Fun��o Main */
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
		
		/* Espera o Usu�rio Escolher uma Op��o */
		fflush(stdin);
		opcao = getch();
		
		switch(opcao)
		{
			case '1':
				Realiza_Inicializacao_das_Estruturas();
				Exibe_Tela(); // Exibe as Bordas da Tela
				Inicia_Jogo();
				exibir_menu++;
			break;
			
			case '2':
				Realiza_Inicializacao_das_Estruturas();
				Exibe_Tela(); // Exibe as Bordas da Tela
				Exibe_Menu_Recordes();
				while(getch() != ESC); // Espera a Tecla ESC ser Precionada
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
	
	/* Falha na Borda da Pista que d� a impress�o de Movimento */
	int posicao_falha_pista = -1;
	int movimentar_falha_pista = 0;
	
	/* Contagem de Tempo */
	clock_t tempo_inicio;
	unsigned int milisegundos = 0;
	unsigned int velocidade_do_jogo = 0;
	
	/* Pontua��o */
	int pontuacao = 0;
	int novo_recorde = 0;
	float tempo_decorrido = 0; // n�mero de segundo que ser� substitu�do pela pontua��o de buracos
	
	/* Determina o Fim de Jogo */
	int fim_de_jogo = 0;
	
	
	
	
	
	/* Configura��es Iniciais */
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
	
	//novo_recorde = Verifica_Pontuacao(pontuacao);
	
	if(novo_recorde)
	{
		//Exibe_Novo_Recorde(novo_recorde, pontuacao);
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



int Verifica_Pontuacao(int pontuacao)
{
	int linha = 0;
	int coluna = 0;
	int pontuacao_ranking = 0;
	
	FILE * Arquivo;	
	char linha_arquivo [100];
	
	
	/* Abre Arquivo para Leitura */
	Arquivo = fopen (ARQUIVO_RECORDS , "r");
	if (Arquivo != NULL)
	{
		while(!feof (Arquivo))
		{
			/* Armazena a Linha que est� sendo Lida do Arquivo */
			linha++;
			
			
			/* L� a pr�xima linha do arquivo */
			fgets(linha_arquivo, (RANKING_COLUNAS - 2), Arquivo);
			
			/* Determina se a Linha Lida � um Registro de Recorde */
			if	(
					(linha_arquivo[0] >= '0') && (linha_arquivo[0] <= '9') &&
					(linha_arquivo[1] >= '0') && (linha_arquivo[1] <= '9') &&
					(linha_arquivo[2] >= '0') && (linha_arquivo[2] <= '9')
				)
			{
				/* Transforma os Caracteres que Representam a Pontua��o em um N�mero */
				pontuacao_ranking  = linha_arquivo[0] * 100;
				pontuacao_ranking += linha_arquivo[1] * 10;
				pontuacao_ranking += linha_arquivo[2];
				
				/*	Se a Pontua�ao for Maior que a de um dos Registros,
					retorna a Linha a ser Substitu�da */
				if(pontuacao > pontuacao_ranking)
				{
					/* Fecha Arquivo */
					fclose (Arquivo);
					
					return linha;
				}
			}
		}
	}
	
	/* Fecha Arquivo */
	fclose (Arquivo);
	
	return 0;
	
}












