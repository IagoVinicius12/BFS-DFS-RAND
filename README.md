<h1 align="center"> BFS-DFS-RAND </h1>
<div style="display: inline-block;">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Maintained%3F-yes-green.svg"/> 
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Contributions-welcome-brightgreen.svg?style=flat"/>
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Compilation-Make-orange.svg"/>
</div>
<br><div align=center>
<img src="https://github.com/Guiliard/BFS-DFS-RAND/assets/127882640/2271e7af-6bdd-4e7d-ac3c-2a8d3768ad8a.png" width="850px">
</div>

# Introdução
<p>Foi proposto um problema de caminhamento de matrizes quadradas (NxN) de três formas distintas: largura (BFS), profundidade (DFS) e randômica (RAND). A primeira forma analisa quais direções são possíveis de ir, explorando, sempre, as posições vizinhas adjacentes das escolhidas. A segunda opta por uma determinada direção e continua o caminhamento até que o limite daquela movimentação seja atingido. Já a terceira caminha de modo alatório, com possibilidade de retorno. Nesse exercício, todas as três formas de movimentação se dão nas quatro direções cardeais (Norte, Sul, Leste, Oeste).</p> 

# Descrição do Problema
<p>Em um arquivo do tipo ".data", localiza-se uma matriz quadrada, a qual possui, em suas posições, quatro tipos de elementos: inteiro positivo (1), paredes (#), perigos (*) e saída (?). Os inteiros positivos representados por "1" significam pontos de passagens livres da matriz, as paredes significam as posições que não podem ser acessadas, os asteriscos, os perigos a serem enfrentados, e a saída, a posição que se quer atingir.<br>
Na matriz, os três tipos de caminhamentos realizados devem seguir, além de suas regras principais descritas na "Introdução", as seguintes orientações:

- A posição inicial deve ser a mesma para todos os tipos de caminhamento (linha 0 - coluna 0).
- Caso, durante a movimentação, seja encontrado um inteiro positivo (1), tal processo poderá seguir normalmente.
- Caso, no caminhamento, seja encontrado uma parede (#), a movimentação não poderá continuar naquela posição.
- Caso, durante o deslocamento, seja encontrado um perigo (*), todo o processo de caminhamento terá que ser reiniciado, começando, novamente, na posição primária (linha 0 - coluna 0). Após isso, o perigo que se encontrava naquela posição deve ser substituído por um ponto de acesso possível (inteiro positivo "1").
- Caso, na movimentação, seja encontrado a saída (?), a exploração se encerra.<br>

Todos os elementos da matriz devem ser escaneados e transferidos para o código de programação, que tem como objetivo realizar o caminhamento e salvar todos os dados obtidos. É importante salientar que, terminado um tipo de exploração, os restantes devem ser inicados, ou seja, expera-se explorar a matriz de três formas diferentes.

# Solução Proposta
<p>Para esse tipo de problema, foi proposto um código que contém 11 arquivos: Largura.hpp, Largura.cpp, Profundidade.hpp, Profundidade.cpp, Randomico.hpp, Randomico.cpp, Fila.hpp, Fila.cpp, Pilha.hpp, Pilha.cpp e Main.cpp.<br>
  
- ```Largura.hpp``` : Classe que possui a declaração dos atributos (características) e métodos (funções) envolvidos no caminhamento BFS. <br>
- ```Largura.cpp``` : Arquivo que retém a estruturação das funções envolvidas. <br><br>
- ```Profundidade.hpp``` : Classe que possui a declaração das variáveis e funções envolvidas no caminhamento DFS. <br>
- ```Profundidade.cpp``` : Arquivo que retém a estruturação das funções envolvidas. <br><br>
- ```Randomico.hpp``` : Classe que possui a declaração dos atributos e métodos  envolvidos no caminhamento aleatório (RAND). <br>
- ```Randomico.cpp``` : Arquivo que retém a estruturação das funções envolvidas. <br><br>
- ```Fila.hpp``` : Arquivo que possui a declaração das variáveis e funções da estrutura auxiliar. <br>
- ```Fila.cpp``` : Arquivo que retém a estruturação das funções envolvidas. <br><br>
- ```Pilha.hpp``` : Arquivo que possui a declaração dos atributos e métodos da estrutura auxiliar. <br>
- ```Pilha.cpp``` : Arquivo que retém a estruturação das funções envolvidas. <br><br>
- ```Main.cpp``` : Arquivo mais importante, responsável por chamar as funções contidas nas classes e realizar o processo de caminhamento.<br>
  
Em primeiro lugar, destaca-se a utilização das estruturas "Fila" e "Pilha" para auxílio no processo de movimentação. Para o caminhamento em largura (BFS), a "Fila" foi utilizada, já que, para garantir a correta ordem de chegada dos vértices, as posições visitadas posteriormente deveriam ser armazenadas após as primeiras, tal qual, literalmente, uma fila, onde o primeiro elemento adicionado também é o primeiro elemento eliminado. Já para o caminhamento em profundidade (DFS) e para o caminhamento randômico (RAND), a "Pilha" foi utilizada, tendo em vista que, para ambas as movimentações, a próxima busca sempre começa no próxima posição, assim como, literalmente, uma pilha, onde o primeiro elemento adicionado também é o último elemento eliminado. <br>
Outro ponto importante é a forma que o carregamento da matriz foi realizado. Tendo em vista que o processo aconteceria três vezes, carregar 3 matrizes em memória seria uma alternativa de demandaria um grande custo, ou seja, negativo para o processamento. Para contornar essa situação, utilizou-se programação orientada à objeto, ou seja, a mesma matriz é utilizada três vezes. Com isso, obtém-se um baixo custo de memória e uma otimização do programa.    
Dito esses assuntos, vale ressaltar as três funções comuns declaradas nos arquivos Largura.cpp, Profundidade.cpp e Randomico.cpp, as quais contribuem para o caminhamento:
  
- ```Leitura``` :
- ```VerMatriz``` :
- ```CriaTrajetoria``` :

# Casos Especiais

# Casos Sem Tratamento

# Implementação

# Conclusão

# Especificações do Dispositivo Utilizado

# Compilação e Execução
