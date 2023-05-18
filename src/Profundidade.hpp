#ifndef PROFUNDIDADE_HPP
#define PROFUNDIDADE_HPP
#include "pilha.hpp"

class Profundidade
{
    private:
        short int tamanho;
        Pilha trajetoria;
        Item coordenada;

    public:
        Profundidade();
        short int gettamanho();
        void settamanho(short int tamanho);
        void lendomatriz(fstream& arq, Regiao **mat);
        void vermatriz(Regiao **mat);
        void andando(Regiao **mat);
        void criatrajetoria(Regiao **mat);
};
#endif