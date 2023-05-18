#ifndef RANDOMICO_HPP
#define RANDOMICO_HPP
#include "pilha.hpp"

using namespace std;

class Randomico
{
    private: 
        short int tamanho;
        Pilha trajetoria; 
        Item coordenada;

    public:
        Randomico();
        void setTamanho(short int tamanho);
            short int getTamanho();
        void Leitura(fstream& arq, Regiao **mat);
        void VerMatriz(Regiao **mat);
        void Movimento(Regiao **mat);
        void AndarMatriz(Regiao **mat, short int *linha, short int *coluna, short int maislinha, short int maiscoluna);
        void CriaTrajetoria(Regiao **mat);
};
#endif
