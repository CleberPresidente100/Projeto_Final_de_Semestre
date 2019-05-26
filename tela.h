/*
	Nome: Cleber da Silva Melo
	R.A.: 335338215650
	2� Semestre Ci�ncia da Computa��o
*/

/*
	Jogo Enduro - Projeto de Final de Semestre
*/



#ifndef __TELA__

	/* Constantes */
	#define __TELA__
	
	/* TELA */
		// Tela sendo Exibida Atualmente, Pr�xima Tela a ser Exibida, Tela Auxiliar para Compara��o
		// As Telas Atual e Pr�xima s�o din�micas e ocupar�o as posi��es 0 e 1 do Vetor.
		// J� a Tela Auxiliar ser� sempre �ltima posi��o do Vetor.
		#define NUMERO_DE_TELAS 3
		#define TELA_AUXILIAR (NUMERO_DE_TELAS - 1)
		
		#define BRANCO 32
		#define ESPESSURA_BORDA_TELA 1
		#define TAMANHO_TELA_LINHAS 30
		#define TAMANHO_TELA_COLUNAS 80
	
	/* PLACAR */
		#define ESPESSURA_BORDA_PLACAR 1
		#define TAMANHO_PLACAR_LINHAS 7
		#define TAMANHO_PLACAR_COLUNAS 16
		#define POSICAO_PLACAR_LINHA ESPESSURA_BORDA_TELA
		#define POSICAO_PLACAR_COLUNA ESPESSURA_BORDA_TELA
	
	/* CARRO */
		#define POSICAO_CARRO_LINHA (TAMANHO_TELA_LINHAS - ESPESSURA_BORDA_TELA - TAMANHO_CARRO_LINHAS)
		#define POSICAO_CARRO_COLUNA (((TAMANHO_TELA_COLUNAS / 2) - (TAMANHO_CARRO_COLUNAS / 2)) + 1)
	
	/* PISTA */
		#define POSICAO_PISTA_LINHA ESPESSURA_BORDA_TELA
		#define POSICAO_PISTA_COLUNA ESPESSURA_BORDA_TELA
		

	
	/* Estruturas */
	
	/* Fun��es */
		/* Gerais */
		void Realiza_Inicializacao_das_Estruturas();
	
		/* Placar */
		void Cria_Placar();
		void Exibe_Placar();
		void Inserir_Placar_na_Tela();
		void Alterar_Placar(int pontuacao);
	
		/* Tela */
		void Inicializa_Telas();
		void Limpa_Tela(unsigned char indice_tela);
		void Exibe_Tela();
		void Atualizar_Tela();
		void Comparar_Tela_Atual_com_Proxima_Tela();
	
		/* Carro */
		void Cria_Carro();
		void Inserir_Carro_na_Tela();
		void Move_Carro(int movimentar_carro);
		
		/* Pista */
		void Inserir_Pista_na_Tela();
		void Atualiza_Falha_Pista(int linha);
	
#endif






