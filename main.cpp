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
#define SAIR 5

/* Estruturas */



/* Declaração de Funções */
int VerificaTeclasDeMovimentacao(char tecla);



/* Função Main */
int main(void)
{
	int opcao = 0;
	int indice = 0;
	int fim_de_jogo = 0;
	
	int linha = 0;
	int coluna = 0;
	
	
	int sentido = 0;
	int auxiliar = 0;	
	int posicao_carro = 0;
	int movimentar_carro = 0;
	
	int posicao_falha_pista = -1;
	int movimentar_falha_pista = 0;
	
	unsigned char tela_atual = 0;
	
	
	clock_t tempo_inicio;
	unsigned int milisegundos = 0;
	
	int pontuacao = 0;
	float tempo_decorrido = 0;
	
		
	
	/* Permite o uso de Acentuação */
	setlocale(LC_ALL, "ALL");
		
	
	Realiza_Inicializacao_das_Estruturas();
	Exibe_Tela(); // Exibe as Bordas da Tela
	Atualizar_Tela();
	
	
	tempo_inicio = Inicia_Cronometro();
	while(1)
	{		
		milisegundos = Tempo_Cronometro(tempo_inicio);
		
		
		if(milisegundos >= 10)
		{
			if(kbhit())
			{
				movimentar_carro = VerificaTeclasDeMovimentacao(getch());
								
				if(movimentar_carro)
				{
					Move_Carro(movimentar_carro);					
					movimentar_carro = 0;
				}
			}
			
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
			
			
			fim_de_jogo = Atualizar_Tela();
			
			if(fim_de_jogo)
			{
				getch();
				break;
			}
			
			tempo_inicio = Inicia_Cronometro();
			
		}
	}
	
	/*
	do
	{
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
		
	} while(opcao != SAIR);
	*/
	
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















