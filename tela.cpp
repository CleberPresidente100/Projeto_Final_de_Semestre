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
#include "pista.h"
#include "gotoxy.h"
#include "caracteres.h"


/* Constantes */
#define POSICAO_PLACAR_DIGITO_1 0
#define POSICAO_PLACAR_DIGITO_2 5
#define POSICAO_PLACAR_DIGITO_3 10

#define DERRORA_LINHA (TAMANHO_PLACAR_LINHAS + 1)
#define DERRORA_COLUNA ((TAMANHO_TELA_COLUNAS / 2) - 13)

#define NOME_DO_JOGO_LINHA (TAMANHO_PLACAR_LINHAS - 3)
#define NOME_DO_JOGO_COLUNA ((TAMANHO_TELA_COLUNAS / 2) - 11)



const unsigned char CARRO[TAMANHO_CARRO_LINHAS][TAMANHO_CARRO_COLUNAS] ={
																			{221, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 222},
																			{223, 223, 223, 223, 219, 219, 219, 219, 219, 219, 219, 223, 223, 223, 223},
																			{177, 177, 177, ' ', ' ', ' ', 219, 219, 219, ' ', ' ', ' ', 177, 177, 177},
																			{177, 177, 177, 220, 219, 219, 219, 219, 219, 219, 219, 220, 177, 177, 177},
																			{177, 177, 177, 223, 219, 219, 219, 219, 219, 219, 219, 223, 177, 177, 177},
																			{177, 177, 177, ' ', 223, 223, 223, 223, 223, 223, 223, ' ', 177, 177, 177}
																		};

const unsigned char DERROTA[9][29] =	{
										{201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187},
										{186, 219, 219, ' ', ' ', 219, 219, 219, ' ', 219, 219, ' ', ' ', 219, 219, ' ', ' ', 219, 219, 219, ' ', 219, 219, 219, ' ', 219, 219, 219, 186},
										{186, 219, ' ', 219, ' ', 219, ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', ' ', 219, ' ', ' ', 219, ' ', 219, 186},
										{186, 219, ' ', 219, ' ', 219, 219, 219, ' ', 219, 219, ' ', ' ', 219, 219, ' ', ' ', 219, ' ', 219, ' ', ' ', 219, ' ', ' ', 219, 219, 219, 186},
										{186, 219, ' ', 219, ' ', 219, ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', ' ', 219, ' ', ' ', 219, ' ', 219, 186},
										{186, 219, 219, ' ', ' ', 219, 219, 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, 219, 219, ' ', ' ', 219, ' ', ' ', 219, ' ', 219, 186},
										{200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188},
										{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
										{' ', ' ', ' ', ' ', ' ', 'A', 'p', 'e', 'r', 't', 'e', ' ', 'E', 'S', 'C', ' ', 'p', 'a', 'r', 'a', ' ', 'S', 'a', 'i', 'r', ' ', ' ', ' ', ' '}
									};

const unsigned char NOME_DO_JOGO[18][27] =	{
											{201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187},
											{186, ' ', ' ', ' ', 223, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
											{186, ' ', ' ', 223, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
											{186, ' ', 219, 219, 219, ' ', ' ', ' ', ' ', ' ', 219, 219, ' ', ' ', 219, ' ', 219, ' ', 219, 219, ' ', ' ', ' ', 219, ' ', ' ', 186},
											{186, ' ', 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 186},
											{186, ' ', 219, 219, 219, ' ', ' ', ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, 219, ' ', ' ', 219, ' ', 219, ' ', 186},
											{186, ' ', 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 219, ' ', 186},
											{186, ' ', 219, 219, 219, ' ', ' ', ' ', ' ', ' ', 219, 219, ' ', ' ', ' ', 219, ' ', ' ', 219, ' ', 219, ' ', ' ', 219, ' ', ' ', 186},
											{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
											{200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188},
											{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
											{201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187},
											{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
											{186, ' ', ' ', ' ', ' ', ' ', ' ', '1', ' ', ' ', ' ', 'J', 'o', 'g', 'a', 'r', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
											{186, ' ', ' ', ' ', ' ', ' ', ' ', '2', ' ', '-', ' ', 'R', 'e', 'c', 'o', 'r', 'd', 'e', 's', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
											{186, ' ', ' ', ' ', ' ', ' ', ' ', '3', ' ', ' ', ' ', 'S', 'a', 'i', 'r', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
											{186, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 186},
											{200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188}
										};



/* Estruturas */

struct struct_Carro
{
	//int pos_top_left_linha; // Coordenada X (Coluna) na Tela Final do Pixel Superior Esquerdo do Carro
	//int pos_top_left_coluna; // Coordenada Y (Linha) na Tela Final do Pixel Superior Esquerdo do Carro
	
	int posicao_atual_carro;
	unsigned char carro[TAMANHO_CARRO_LINHAS][TAMANHO_CARRO_COLUNAS];
} carro;
	
struct struct_Placar
{
	//int pos_top_left_linha; // Coordenada Y (Linha) na Tela Final do Pixel Superior Esquerdo do Placar
	//int pos_top_left_coluna; // Coordenada X (Coluna) na Tela Final do Pixel Superior Esquerdo do Placar
	
	unsigned char placar[TAMANHO_PLACAR_LINHAS][TAMANHO_PLACAR_COLUNAS];
} placar;

struct struct_Tela
{
	int pos_top_left_linha; // Coordenada Y (Linha) na Tela Final do Pixel Superior Esquerdo da Tela
	int pos_top_left_coluna; // Coordenada X (Coluna) na Tela Final do Pixel Superior Esquerdo da Tela
		
	unsigned char tela_atual;
	unsigned char proxima_tela;
	unsigned char tela[NUMERO_DE_TELAS][TAMANHO_TELA_LINHAS][TAMANHO_TELA_COLUNAS];
} tela;

int fim_de_jogo;
int pista_linha_falha;
unsigned char pista_a_ser_exibida[TAMANHO_PISTA_LINHAS][TAMANHO_PISTA_COLUNAS];



/* Funções Privadas */


/* GERAIS */
void Realiza_Inicializacao_das_Estruturas()
{
	pista_linha_falha = -1;
	Cria_Carro();
	Cria_Pistas();
	Cria_Placar();
	Alterar_Placar(0);
	Inicializa_Telas();
}



/* CARRO */
void Cria_Carro()
{
	int linha = 0;
	int coluna = 0;
	
	char auxiliar[TAMANHO_CARRO_LINHAS][TAMANHO_CARRO_COLUNAS] ={
																	{221, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 222},
																	{223, 223, 223, 223, 219, 219, 219, 219, 219, 219, 219, 223, 223, 223, 223},
																	{177, 177, 177, ' ', ' ', ' ', 219, 219, 219, ' ', ' ', ' ', 177, 177, 177},
																	{177, 177, 177, 220, 219, 219, 219, 219, 219, 219, 219, 220, 177, 177, 177},
																	{177, 177, 177, 223, 219, 219, 219, 219, 219, 219, 219, 223, 177, 177, 177},
																	{177, 177, 177, ' ', 223, 223, 223, 223, 223, 223, 223, ' ', 177, 177, 177}
																};

	
	/* Carrega o Carro para dentro da Matriz carro */
	for(linha = 0; linha < TAMANHO_CARRO_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_CARRO_COLUNAS; coluna++)
		{
			carro.carro[linha][coluna] = auxiliar[linha][coluna];
		}
	}
	
	carro.posicao_atual_carro = 0;
}



void Move_Carro(int movimentar_carro)
{
	carro.posicao_atual_carro += movimentar_carro;
}



int Inserir_Carro_na_Tela()
{
	int linha = 0;
	int coluna = 0;
	//int fim_de_jogo = 0;
	
		
	for(linha = 0; linha < TAMANHO_CARRO_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_CARRO_COLUNAS; coluna++)
		{
			tela.tela[tela.proxima_tela][linha + POSICAO_CARRO_LINHA][coluna + POSICAO_CARRO_COLUNA + carro.posicao_atual_carro] = carro.carro[linha][coluna];
			
			/* Verifica se o Carro Bateu em Algo */	/*		
			if	(
					(tela.tela[tela.tela_atual][linha + POSICAO_CARRO_LINHA][coluna + POSICAO_CARRO_COLUNA + carro.posicao_atual_carro] != 0) &&
					(tela.tela[tela.tela_atual][linha + POSICAO_CARRO_LINHA][coluna + POSICAO_CARRO_COLUNA + carro.posicao_atual_carro] != BRANCO) &&
					(tela.tela[tela.tela_atual][linha + POSICAO_CARRO_LINHA][coluna + POSICAO_CARRO_COLUNA + carro.posicao_atual_carro] != carro.carro[linha][coluna])
					 
				)*/
			{
				fim_de_jogo++;
			}
		}
	}
	
	
	/* Verifica se o Carro Bateu em Algo */
	if	(
			Verifica_Colisao_Buraco(carro.posicao_atual_carro) ||
			Verifica_Colisao_Pista(carro.posicao_atual_carro)
		)
	{
		return 1;
	}
	
	return 0;	
}



/* PLACAR */
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

	
	/* Define a Posição na Tela onde o Placar deve começar a ser desenhado */
	//placar.pos_top_left_linha = ESPESSURA_BORDA_TELA + 1;
	//placar.pos_top_left_coluna = ESPESSURA_BORDA_TELA + 1;
	
	/* Carrega o Placar para dentro da Matriz placar */
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
	int numero[3] = {0, 0, 0};
	
	/* Validação da Pontuação */
	if((pontuacao < 0) || (pontuacao > 999))
	{
		pontuacao = 0;
	}
	else
	{
		/* Separa os Dígitos da Pontuação */
		numero[0] = pontuacao / 100;
		numero[1] = (pontuacao - (numero[0] * 100)) / 10;
		numero[2] = (pontuacao - (numero[0] * 100) - (numero[1] * 10));
	}
	
		
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



void Inserir_Placar_na_Tela()
{
	int linha = 0;
	int coluna = 0;
	
		
	for(linha = 0; linha < TAMANHO_PLACAR_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_PLACAR_COLUNAS; coluna++)
		{
			tela.tela[tela.proxima_tela][linha + POSICAO_PLACAR_LINHA][coluna + POSICAO_PLACAR_COLUNA] = placar.placar[linha][coluna];
		}
	}	
}



void Exibe_Placar()
{
	int linha = 0;
	int coluna = 0;
		
	
	for(linha = 0; linha < TAMANHO_PLACAR_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_PLACAR_COLUNAS; coluna++)
		{
			printf("%c", placar.placar[linha][coluna]);
		}
		
		printf("\n");
	}	
}



/* TELA */
void Inicializa_Telas()
{
	int indice = 0;
	
	/* Inicializa Variáveis */
	tela.pos_top_left_linha = 0; // Coordenada Y (Linha) na Tela Final do Pixel Superior Esquerdo da Tela
	tela.pos_top_left_coluna = 0; // Coordenada X (Coluna) na Tela Final do Pixel Superior Esquerdo da Tela
		
	tela.tela_atual = 0;
	tela.proxima_tela = 1;
	
	for(indice = 0; indice < NUMERO_DE_TELAS; indice++)
	{
		Limpa_Tela(indice);
	}	
}



void Limpa_Tela(unsigned char indice_tela)
{
	int linha = 0;
	int coluna = 0;
		
	
	/* Preenche a Tela com o caracter Espaço (Deixa a Tela "Em Branco") */
	for(linha = 0; linha < TAMANHO_TELA_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_TELA_COLUNAS; coluna++)
		{
			tela.tela[indice_tela][linha][coluna] = BRANCO; // Caractere Espaço
		}
	}
	
	/* Coloca as Bordas Horizontais (Superior e Inferior) */
	for(coluna = 0; coluna < TAMANHO_TELA_COLUNAS; coluna++)
	{			
		tela.tela[indice_tela][0][coluna] = 205;
		tela.tela[indice_tela][TAMANHO_TELA_LINHAS - 1][coluna] = 205;
	}
	
	/* Coloca as Bordas Verticais (Esquerda e Direita) */
	for(linha = 0; linha < TAMANHO_TELA_LINHAS; linha++)
	{			
		tela.tela[indice_tela][linha][0] = 186;
		tela.tela[indice_tela][linha][TAMANHO_TELA_COLUNAS - 1] = 186;
	}
	
	/* Coloca as Bordas nos Vértices */
	tela.tela[indice_tela][0][0] = 201;
	tela.tela[indice_tela][0][TAMANHO_TELA_COLUNAS - 1] = 187;
	tela.tela[indice_tela][TAMANHO_TELA_LINHAS - 1][0] = 200;
	tela.tela[indice_tela][TAMANHO_TELA_LINHAS - 1][TAMANHO_TELA_COLUNAS - 1] = 188;
	
}



void Exibe_Tela()
{
	int linha = 0;
	int coluna = 0;
		
	
	for(linha = 0; linha < TAMANHO_TELA_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_TELA_COLUNAS; coluna++)
		{
			if(tela.tela[TELA_AUXILIAR][linha][coluna] != 0)
			{
				gotoxy(linha, coluna);
				printf("%c", tela.tela[TELA_AUXILIAR][linha][coluna]);
			}
		}
	}
}



int Atualizar_Tela()
{
	int fim_de_jogo = 0;
	
	Limpa_Tela(tela.proxima_tela);
	Inserir_Pista_na_Tela();
	Inserir_Placar_na_Tela();
	fim_de_jogo = Inserir_Carro_na_Tela();
	if(fim_de_jogo)
	{
		Inserir_Mensagem_Derrota();
	}	
	Comparar_Tela_Atual_com_Proxima_Tela();
	Exibe_Tela();
	
	/* Atualiza Índices */
	tela.tela_atual		= (~tela.tela_atual) & 0x01;
	tela.proxima_tela	= (~tela.proxima_tela) & 0x01;
	
	return fim_de_jogo;
}



void Comparar_Tela_Atual_com_Proxima_Tela()
{
	int linha = 0;
	int coluna = 0;
	
	
	for(linha = 0; linha < TAMANHO_TELA_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_TELA_COLUNAS; coluna++)
		{
			if(tela.tela[tela.tela_atual][linha][coluna] != tela.tela[tela.proxima_tela][linha][coluna])
			{
				/* Se na Tela Atual existe um Caractere e na Próxima Tela ele foi Substituido
				por um Caractere Vazio, significa que este Caractere deve ser Apagado. */
				if((tela.tela[tela.tela_atual][linha][coluna] != 0) && (tela.tela[tela.proxima_tela][linha][coluna] == 0))
				{
					tela.tela[TELA_AUXILIAR][linha][coluna] = BRANCO;
				}
				else
				{
					tela.tela[TELA_AUXILIAR][linha][coluna] = tela.tela[tela.proxima_tela][linha][coluna];
				}
			}
			else
			{
				tela.tela[TELA_AUXILIAR][linha][coluna] = 0;
			}
		}
	}
	
}



void Inserir_Pista_na_Tela()
{
	int linha = 0;
	int coluna = 0;
	
	/* Atualiza a Pista */	
	Atualiza_Pista(pista_a_ser_exibida, pista_linha_falha);
	
	/* Copia a Pista para a Próxima Tela */
	for(linha = 0; linha < TAMANHO_PISTA_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_PISTA_COLUNAS; coluna++)
		{
			tela.tela[tela.proxima_tela][linha + POSICAO_PISTA_LINHA][coluna + POSICAO_PISTA_COLUNA] = pista_a_ser_exibida[linha][coluna];
		}
	}
	
}



void Atualiza_Falha_Pista(int linha)
{
	pista_linha_falha = linha;
}



void Inserir_Mensagem_Derrota()
{
	int linha = 0;
	int coluna = 0;
	
	
	for(linha = 0; linha < 9; linha++)
	{
		for(coluna = 0; coluna < 29; coluna++)
		{
			tela.tela[tela.proxima_tela][linha + DERRORA_LINHA][coluna + DERRORA_COLUNA] = DERROTA[linha][coluna];
		}
	}
	
}


void Inserir_Nome_do_Jogo()
{
	int linha = 0;
	int coluna = 0;
	
	
	for(linha = 0; linha < 18; linha++)
	{
		for(coluna = 0; coluna < 27; coluna++)
		{
			tela.tela[tela.proxima_tela][linha + NOME_DO_JOGO_LINHA][coluna + NOME_DO_JOGO_COLUNA] = NOME_DO_JOGO[linha][coluna];
		}
	}
	
}


void Exibe_Menu()
{
	Inserir_Pista_na_Tela();
	Inserir_Placar_na_Tela();
	Inserir_Carro_na_Tela();
	Inserir_Nome_do_Jogo();
	Comparar_Tela_Atual_com_Proxima_Tela();
	Exibe_Tela();
}

/* Template */
/*
void Montar_Proxima_Tela()
{
	int linha = 0;
	int coluna = 0;
	
	
	for(linha = 0; linha < TAMANHO_TELA_LINHAS; linha++)
	{
		for(coluna = 0; coluna < TAMANHO_TELA_COLUNAS; coluna++)
		{
		}
	}
	
}
*/











