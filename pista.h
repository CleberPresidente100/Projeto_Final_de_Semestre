/*
	Nome: Cleber da Silva Melo
	R.A.: 335338215650
	2º Semestre Ciência da Computação
*/

/*
	Jogo Enduro - Projeto de Final de Semestre
*/

#ifndef __PISTA__

	/* Constantes */
	#define __PISTA__
		
	#define TAMANHO_PISTA_LINHAS  (TAMANHO_TELA_LINHAS - (2 * ESPESSURA_BORDA_TELA))
	#define TAMANHO_PISTA_COLUNAS (TAMANHO_TELA_COLUNAS - (2 * ESPESSURA_BORDA_TELA)) //(TAMANHO_CARRO_COLUNAS * 3)
	/* Bibliotecas */	

	/* Estruturas */
	
	/* Funções */
	void Cria_Pistas();
	void Cria_Pista_Reta();
	void Atualiza_Pista(unsigned char pista[TAMANHO_PISTA_LINHAS][TAMANHO_PISTA_COLUNAS], int pista_linha_falha);
	
#endif





