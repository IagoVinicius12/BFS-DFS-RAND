#ifndef LARGURA_HPP
#define LARGURA_HPP
#include "Fila.hpp"
#include "pilha.hpp"

class Largura
{
    private:

        Fila trajetoria;
        Itemf coordenada;
        Blockf *posicao;
        short int tamanho;
    public:

        Largura();
        void settamanho(short int tamanho);
        short int gettamanho();
        void Leitura(fstream& arq, Regiao **mat);
        void vermatriz(Regiao **mat);
        void andando(Regiao **mat);
        void Movimento(short int *linha, short int *coluna, Regiao **mat);
        void criatrajetoria(Regiao **mat);
};
#endif
