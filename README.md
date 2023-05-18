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
<p>Foi proposto um problema de caminhamento de matrizes quadradas (NxN) de três formas distintas: largura, profundidade e randômica. A primeira forma analisa quais direções são possíveis de ir, explorando, sempre, as posições vizinhas das escolhidas. A segunda opta por uma determinada direção e continua o caminhamento até que o limite daquela movimentação seja atingido. Já a terceira caminha de forma alatória, com possibilidade de retorno. Nesse exercício, todas as três formas de movimentação se dão nas quatro direções cardeais (Norte, Sul, Leste, Oeste).</p> 

# Descrição do Problema
<p>Em um arquivo do tipo ".data", localiza-se uma matriz quadrada, a qual possui, em suas posições, quatro tipos de elementos: inteiro positivo (1), paredes (#), perigos (*) e saída (?). Os inteiros positivos representados por "1" significam pontos de passagens livres da matriz, as paredes significam as posições que não podem ser acessadas, os asteriscos, os perigos a serem enfrentados, e a saída, a posição que se quer atingir.<br>
Na matriz, os três tipos de caminhamentos realizados devem seguir, além de suas regras principais descritas na "Introdução", as seguintes orientações:

- A posição inicial deve ser a mesma para todos os tipos de caminhamento (linha 0 - coluna 0).
- Caso, durante a movimentação, seja encontrado um inteiro positivo (1), tal processo poderá seguir normalmente.
- Caso, no caminhamento, seja encontrado uma parede (#), a movimentação não poderá continuar naquela posição.
- Caso, durante o deslocamento, seja encontrado um perigo (*), todo o processo de caminhamento terá que ser reiniciado, começando, novamente, na posição primária (linha 0 - coluna 0). Após isso, o perigo que se encontrava naquela posição deve ser substituído por um ponto de acesso possível (inteiro positivo "1").
- Caso, na movimentação, seja encontrado a saída (?), a exploração se encerra.<br>

Todos os elementos da matriz devem ser escaneados e transferidos para o código de programação, que tem como objetivo realizar o caminhamento e salvar todos os dados obtidos. É importante salientar que, terminado um tipo de exploração, os outros devem ser inicados, ou seja, expera-se explorar a matriz de três formas diferentes.

# Solução Proposta

# Casos Especiais

# Casos Sem Tratamento

# Implementação

# Conclusão

# Especificações do Dispositivo Utilizado

# Compilação e Execução
