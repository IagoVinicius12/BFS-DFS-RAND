<h1 align="center"> BFS-DFS-RAND </h1>
<div style="display: inline-block;">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Maintained%3F-yes-green.svg"/> 
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Contributions-welcome-brightgreen.svg?style=flat"/>
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Compilation-Make-orange.svg"/>
</div>
<br><div align=center>
<img src="https://github.com/Guiliard/BFS-DFS-RAND/assets/127882640/923ba054-3c9b-4b27-bb43-646b474568e1.png" width="850px">
</div>

# Introdução
<p>Foi proposto um problema de caminhamento de matrizes quadradas (NxN) de três formas distintas: largura (BFS), profundidade (DFS) e randômica (RAND). A primeira forma analisa quais direções são possíveis de ir, sempre explorando as posições vizinhas adjacentes das escolhidas. A segunda opta por uma determinada direção e continua o caminhamento até que o limite daquela movimentação seja atingido. Já a terceira caminha de modo alatório, com possibilidade de retorno. Nesse exercício, todas as três formas de movimentação se dão nas quatro direções cardeais (Norte, Sul, Leste, Oeste).</p> 

# Descrição do Problema
<p>Em um arquivo do tipo ".data", localiza-se uma matriz quadrada, a qual possui, em suas posições, quatro tipos de elementos: inteiro positivo (1), paredes (#), perigos (*) e saída (?). Os inteiros positivos representados por "1" significam pontos de passagens livres da matriz, as paredes significam as posições que não podem ser acessadas, os asteriscos são os perigos a serem enfrentados, e a saída, a posição que se quer atingir.<br>
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
  
Em primeiro lugar, destaca-se a utilização das estruturas "Fila" e "Pilha" para auxílio no processo de movimentação. Para o caminhamento em largura (BFS), a "Fila" foi utilizada, já que, para garantir a correta ordem de chegada dos vértices, as posições visitadas posteriormente deveriam ser armazenadas após as primeiras, tal qual uma fila, onde o primeiro elemento adicionado também é o primeiro elemento eliminado. Já para o caminhamento em profundidade (DFS) e para o caminhamento randômico (RAND), a "Pilha" foi utilizada, tendo em vista que, para ambas as movimentações, a próxima busca sempre começa na próxima posição, assim como uma pilha, onde o primeiro elemento adicionado também é o último elemento eliminado. <br>
Outro ponto importante é a forma que o carregamento da matriz foi realizado. Tendo em vista que o processo aconteceria três vezes, carregar três matrizes em memória seria uma alternativa de demandaria um grande custo, ou seja, negativo para o processamento. Para contornar essa situação, utilizou-se programação orientada à objeto, ou seja, a mesma matriz é utilizada três vezes. Com isso, obtém-se um baixo custo de memória e uma otimização do programa.   
<br>
<div align=center>
<img src="https://github.com/Guiliard/Labirinto-Recorrente/assets/127882640/10a4d84a-de7a-4a17-8d69-33b0b15ce691.png" hspace="50px" width="420px"/>
<img src="https://github.com/Guiliard/Labirinto-Recorrente/assets/127882640/3b326664-be7d-472a-b331-2ce0c809fc0c.png" width="420px"/>
</div>
<p  align="center">
Estruturas auxiliares utilizadas nos processos de caminhamento.
</p>
<br>
Dito esses assuntos, vale ressaltar as funções declaradas nos arquivos Largura.cpp, Profundidade.cpp e Randomico.cpp, as quais contribuem para o caminhamento:

<strong><h4>Largura.cpp (BFS):</h4></strong>
  
- ```Leitura``` : Função que possui como objetivo ler o arquivo do tipo ".data" e carregá-lo em uma matriz.
- ```Andando``` :  Função responsável por buscar, nas quatro direções cardeais, a saída (?) da matriz. Essa função também determina se existe algum empecilho na busca (parede - # ou perigo - *). Caso exista, as atitudes em acordo com as regras do programa serão tomadas, tais como não fazer nada ou reiniciar o caminhamento. Esse processo se perpetua até que a saída (?) da matriz seja encontrada.
- ```Movimento``` : Função usada no final do processo de busca, ou seja, quando a saída for encontrada, o caminhamento será iniciado, seguindo as coorrdenadas analizadas e armazenadas na "Fila".
- ```CriaTrajetoria``` : Função utilizada no final do processo, a qual cria o caminho percorrido que se origina através do uso de um marcador (x), sendo que, todas as posições nas quais o marcador está presente são as posições acessadas no processo.
- ```VerMatriz``` : Função responsável por mostrar o caminho percorrido após o processo de movimentação.
  
<strong><h4>Profundidade.cpp (DFS):</h4></strong>
  
- ```LendoMatriz``` : Função que possui como objetivo ler o arquivo do tipo ".data" e carregá-lo em uma matriz.
- ```Andando``` :  Função responsável por escolher uma determinada direção e continuar o caminhamento naquele sentido até que o limite seja atingido. Essa função também determina se existe algum empecilho no caminho escolhido (parede - # ou perigo - *). Caso exista, as atitudes em acordo com as regras do programa serão tomadas, tais como não fazer nada ou reiniciar o caminhamento. Vale salientar que as possições possíveis são armazenadas na "Pilha". Tal processo se perpetua até que a saída (?) da matriz seja encontrada.
- ```CriaTrajetoria``` : Função utilizada no final do processo, a qual cria o caminho percorrido que se origina através do uso de um marcador (x), sendo que, todas as posições nas quais o marcador está presente são as posições acessadas no processo.
- ```VerMatriz``` : Função responsável por mostrar o caminho percorrido após o processo de movimentação.
  
<strong><h4>Randômico.cpp (RAND):</h4></strong>
  
- ```Leitura``` : Função que possui como objetivo ler o arquivo do tipo ".data" e carregá-lo em uma matriz.
- ```Movimento``` :  Função responsável por escolher, aleatoriamente, uma determinada direção para o caminhamento, sendo que tal processo se perpetua até que a saída (?) da matriz seja encontrada. Por fim, vale exibir a relação entre o sorteio randômico e as 4 direções cardeais:
  * 0 - Leste
  * 1 - Sul
  * 2 - Oeste
  * 3 - Norte
- ```AndarMatriz``` : Função responsável por realizar o caminhamento, analisando se a posição da matriz é acessável ou não. Caso exista algum empecilho no caminho escolhido (parede - # ou perigo - *), as atitudes em acordo com as regras do programa serão tomadas, tais como não fazer nada ou reiniciar o caminhamento. Vale ressaltar que as posições possíveis são armazenadas na "Pilha".
- ```CriaTrajetoria``` : Função utilizada no final do processo, a qual cria o caminho percorrido que se origina através do uso de um marcador (x), sendo que, todas as posições nas quais o marcador está presente são as posições acessadas no processo.
- ```VerMatriz``` : Função responsável por mostrar o caminho percorrido após o processo de movimentação.
  
Com a interconexão de todas essas classes e funções, os três tipos de caminhamentos da matriz se tornam possíveis e reais.<br><br>
<div align=center>
<img src="https://github.com/Guiliard/BFS-DFS-RAND/assets/127882640/834960e6-6e86-4876-8caf-f08a7f6a38cd.png" width="850px">
</div>
<p  align="center">
Ilustração dos três tipos de caminhamento em uma matriz quadrada (3x3). Os números representam os movimentos ordenados a serem seguidos em cada um dos casos. É importante salientar que, no caminhamento aleatório (RAND), qualquer número poderia assumir a identidade de qualquer número, tendo em vista que a aleatoriedade não possui um padrão de deslocamento.
</p>
<br>

# Casos Especiais
<p>Em primeiro lugar, vale ressaltar que os casos especiais foram tratados de acordo com o comportamento do algoritmo. Com excessão do randômico (RAND), tanto o  caminhamento em largura (BFS) quanto o caminhamento em profundidade (DFS) foram tratados de forma a se atingir um performace otimizada, visando encontrar, de maneira rápida, a saída da matriz.</p>
<p>Em relação ao DFS (profundidade), sempre que o código achasse um "beco sem saída", ele determinaria a posição em que o marcador estivesse como preto e começaria a voltar até que encontrasse uma posição que o programa pudesse continuar sua trajetória. É importante dizer que o "beco sem saída" não precisa ser, necessariamente, um lugar cheio de paredes, tendo em vista que ele pode ser um caminho em que o próprio algoritmo foi se fechando e não encontrou o objetivo (saída - ?). A partir disso, o marcador começaria a voltar cada uma das posições, as quais foram armazenadas na Pilha, até que conseguisse chegar em um local que ele tivesse opções de movimento.</p>
<p>Já o BFS (largura), foi tratado de outra forma, tendo em vista que, nesse caso, não existiriam "becos sem saída", pois a própria naturalidade da exploração do algoritmo elimina essa possibilidade. Seu tipo de tratamento está relacionado à forma que sua procura se dá, já que, ao invés de explorar apenas duas direções, como é o natural desse tipo de código, acrescentou-se mais duas direções, para que seu caminhamento ficasse mais completo e eficiente. Tal fato foi vantajoso porque caso houver, na matriz, uma grande parede e apenas um pequeno espaço possível de se passar, o programa terá um comportamento espelhado, ou seja, ele fará o mesmo processo que ele fez para chegar naquele local só que invertendo uma das direções, isto é, se ele desceu e não encontrou a saída, ele subirá em busca dela.</p>

<div align=center>
<img src="https://github.com/Guiliard/BFS-DFS-RAND/assets/127882640/bc45bb83-f0a1-4350-b9af-c74d0b3f8c32.png" hspace="50px" width="420px"/>
<img src="https://github.com/Guiliard/BFS-DFS-RAND/assets/127882640/d21cd510-60d7-4534-99f7-e6b23e7b557c.png" width="420px"/>
</div>
<p  align="center">
Representação dos casos especiais contidos no DFS e no BFS.
</p>
<br>

# Casos Sem Tratamento
<p>Existem três casos sem tratamento que se destacam no algoritmo em questão, tendo em vista que, se eles ocorrerem, a busca não é finalizada, e um looping eterno é inicializado. O primeiro deles é se toda a matriz é constituída de paredes (#). O segundo caso advém do cercamento do objetivo (saída) por passagens inacessecíveis (#). Já a terceira situação é caso apenas a posição de início (linha 0 - coluna 0) for possível de ser acessada, o que deixa o marcador "preso".</p>
<p>Uma forma de consertar o código seria adicionar algumas condicionais antes mesmo de iniciar a busca, verificando se, pelo menos, há uma passagem para a saída. Outra forma de prevenir esses possíveis erros seria adicionar as diagonais ao movimento do marcador, uma vez que existem alguns casos que se resolvem com a utilização de novas coordenadas (Nordeste, Sudoeste, Sudeste, Noroeste).</p>

<div align=center>
<img src="https://github.com/Guiliard/BFS-DFS-RAND/assets/127882640/158a7698-dcea-471b-937e-902225ea1a7b.png" width="850px">
</div>
<p  align="center">
Ilustração dos três casos sem tratamento em uma matriz quadrada (3x3). Ambos os casos representam caminhamentos impossíveis.
</p>
<br>

# Implementação

# Conclusão
<p>De forma geral, o programa, orientado à objeto, se mostra eficiente para resolver o caminhamento de matrizes. Seu custo computacional é diretamente proporcional ao tamanho da entrada, visto que um grande número de matrizes maiores demandará mais iterações e operações do que um pequeno número de matrizes menores. Além disso, afirma-se que o objetivo do trabalho foi cumprido com exelência, porém, o código é passivo de melhorias e otimizações, tais como aquelas discutidas na seção "Casos Sem Tratamento".<p>
<p>Por fim, neste trabalho foi observado as diferentes formas de exploração de matriz, cada uma possuindo uma determinada particularidade. Diferentemente do RAND, o BFS e o DFS possuem a mesma função, a qual é a de explorar a matriz até achar seu objetivo ou até passar por todas as posições da matriz. Tendo dois algoritmos de mesmo objetivo, é possível compará-los para observar quais são seus melhores e piores casos, de acordo com as mudanças na matriz. Vale ressaltar que a média do tempo de execução do código inteiro foi de 18,88 milisegundos.</p>

# Especificações dos Dispositivos Utilizados

| Componentes            | Detalhes                                                                                         |
| -----------------------| -----------------------------------------------------------------------------------------------  |
|  `Processador`         | Intel(R) Core(TM) i7-1065G7 CPU @ 1.30GHz   1.50 GHz                                             |
|  `RAM Instalada`       | 8.0 GB (Utilizável: 7.8 GB)                                                                      |
|  `Tipo de Sistema`     | Sistema Operacional de 64 bits, processador baseado em x64                                       |
|  `Sistema Operacional` | Edição Windows 11 Home Single Language, versão 22H2                                              |

<br>

| Componentes            | Detalhes                                                                                         |
| -----------------------| -----------------------------------------------------------------------------------------------  |
|  `Processador`         | AMD Ryzen 5 4600H with Radeon Graphics            3.00 GHz                                       |
|  `RAM Instalada`       | 16.0 GB (Utilizável: 15.4 GB)                                                                    |
|  `Tipo de Sistema`     | Sistema Operacional de 64 bits, processador baseado em x64                                       |
|  `Sistema Operacional` | Edição Windows 11 Home Single Language, versão 22H2                                              |

# Compilação e Execução
  
Um arquivo Makefile que realiza todo o procedimento de compilação e execução está disponível no código. Para utilizá-lo, siga as diretrizes de execução no terminal:

| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
