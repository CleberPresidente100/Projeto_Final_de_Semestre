# Projeto Final de Semestre
**Este é um projeto do Final do Semestre onde aplicaremos todos os conhecimentos adquiridos em Linguagem C através das matérias "Algoritmos e Técnicas de Programação" e "Algoritmos e Estrutura de Dados", ministradas pelo professor Claudinei na Universidade Anhanguera (UNIABC) de Santo André.**

**O objetivo deste projeto é criar um jogo similar ao Enduro do Atari com as seguintes restrições:**
  * **Utilizar apenas os caracteres da tabela ASCII extendida para se desenhar na tela;**
  * **Utilizar apenas o comando printf para se exibir algo na tela.**

**Obs.: Este projeto deve ser realizado em apenas 6 dias.**


# Relatório

**Dia 1 - (22/05/2019 - quarta-feira)**

No primeiro dia eu comecei a trabalhar neste projeto no dia 22/05/2019, uma quarta-feira. Neste primeiro dia eu analisei um vídeo (no Youtube) de um gameplay do Enduro para ver como era o desenho dos carros, da pista e dos demais elementos do jogo.
Após a análise, eu tentei reproduzir o carro através de caracteres ASCII.

**Dia 2 - (23/05/2019 - quinta-feira)**

No segundo dia eu comecei a desenvolver a lógica de criação e manipulação das telas do jogo. A princípio a ideia era utilizar apenas os comandos system("cls") - para limpar a tela - e printf() - para imprimir algo na tela. 

Entretanto, isto se mostrou excepcionalmente ineficiente ! Pois, desta forma, eu não tinha controle sobre a posição do cursor. Ou seja, para mudar apenas um caractere na tela, era necessário limpar a tela (para posicionar o cursor na primeira linha e primeira coluna da tela) para então reescrever todos os 2400 caracteres que formam a tela do jogo.

Isto faria com que o jogo tivesse uma taxa de atualização de tela maior do que 1 segundo (FPS menor que 1).:scream::scream::scream: Em outras palavras, tornaria o jogo totalmente inviável.:sob::sob::sob:

**Dia 3 - (24/05/2019 - sexta-feira)**

No terceiro dia eu pesquisei sobre como eu poderia posicionar o cursor em uma coordenada específica da tela. E descobri que era possível fazer isto utilizando a biblioteca windows.h.

Com isto, o projeto se tornou viável e eu comecei a criar os elementos que seriam exibidos como a pista, o carro e o placar. Após isto eu comecei a desenvolver uma forma de montar e inserir estes elementos no frame e ser exibido e a lógica de exibição dos frames (só exibir o que for alterado).

**Dia 4 e 5 - (25 e 26/05/2019 - sábado e domingo)**

Todo o restante do projeto (do que foi desenvolvido no dia 3 até a versão final) foi desenvolvido nestes dois dias.

Porém, eu verifiquei que o tempo seria um impeditivo para se fazer um jogo com as mesmas regras do Enduro. Por este motivo eu decidi que o jogo consistiria em um carro andando por uma pista reta na qual seria necessário desviar dos buracos que aparecem na pista.

Outra consequência do prazo curto, foi que eu ignorei todas as boas práticas de programação e comecei a escrever o código de forma a otimizar o tempo (isto fez com que quase todo o programa ficasse dentro do arquivo tela.c e com diversos códigos replicados). :grin: :blush: :innocent:

Segue uma lista das funcionalidade implementadas nestes dois dias:
  * Movimentação do Carro.
  * Aceleração do Carro.
  * Detecção de Colisão.
  * Movimentação da Pista.
  * Buracos.
  * Movimentação dos Buracos.
  * Pontuação.
  * Tela Inicial com Menu.
  * Sistema de Recordes.
  * Tela de Recordes (Ranking).
  * Tela Sobre.



# Conclusão

Este desafio foi concluído faltando se implementar os seguintes pontos para se atingir o objetivo original:
  * Pistas Curvas;
  * Carros Rivais;
  * Aceleração;
  * Lógica de Batida (No Enduro, ao bater você perde velocidade e posições);
  * Pista Nevada (Na pista nevada o carro escorrega e as consequencias de uma batida são mais severas).
  
Os 6 dias, provavelmente, seriam suficientes para se criar o jogo caso eu pudesse ter trabalhado tempo integral neste projeto. Mas como eu tive que dividir o tempo para a realização deste projeto com o trabalho, aulas e afazeres escolares (o que me deixou com praticamente apenas a sexta de noite, sábado e domingo para fazer o projeto - algo em torno de 3 dias invés de 6 :grin:) algumas adaptações foram necessárias. :innocent:

Entretanto, mesmo com o projeto final não estando perfeito, eu considero que **o projeto foi um sucesso !** :sunglasses: E os motivos que me levaram a considerar o projeto como um sucesso são:
  1. Levando-se em consideração que inicialmente (como descrito no dia 2 do relatório), eu cheguei a duvidar se era realmente possivel fazer este jogo com estas limitações tão impeditivas.
  
  2. **_Este é um projeto extremamente didático !_**
    Normalmente os projetos da área de programação são projetos de formulário. Ou seja, são cadastros de informações, pesquisa de informações, geração de relatórios etc. Consequentemente, não é algo que você pode fazer e se orgulhar de mostrar para seus amigos.
    Todavia, **_um jogo, é algo que todos conseguem entender, interagir, brincar e se divertir com ele. E este projeto é jogo um extremamente simples de se codificar, pois utiliza apenas os conhecimentos básicos de C._**


# Futuro

Como eu gostei os resultados obtidos com este projeto. Eu iniciarei um novo projeto onde implementarei as seguintes melhorias:
  1. Limparei e Organizarei o código para que ele se torne realmente didático;  
  2. Corrigirei os bugs que existem na versão atual.  
  3. Implementarei melhorias nos desenhos dos buracos e na lógica de movimentação dos mesmos.
  4. Implementarei melhorias na lógica de aceleração do carro.
 
 Link para o Novo Projeto que contém a Nova Verão do Jogo:
  * :oncoming_automobile:
  * :red_car: Jogo ["É Duro"](https://github.com/Presidente100/E_Duro) :red_car:
  * :oncoming_automobile:
 
 
 
 
  
