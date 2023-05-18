#include "Randomico.hpp"

Randomico :: Randomico()
{
    FPVazia(&trajetoria);
    coordenada.linha = 0;
    coordenada.coluna = 0;
    Push(&trajetoria, coordenada);
}

void Randomico :: setTamanho(short int tamanho)
{
    this->tamanho=tamanho;
}

short int Randomico :: getTamanho()
{
    return tamanho;
}

void Randomico ::Leitura(fstream& arq, Regiao **mat)
{
    char letra;
    for(short int i = 0;i < getTamanho(); i++)
    {
        for(short int j = 0; j < getTamanho(); j++)
        {
            arq >> letra;
            mat[i][j].caracter = letra;
            mat[i][j].cor = "Branco";
        }
    }
}

void Randomico :: CriaTrajetoria(Regiao **mat)
{
    cout << "\nTRAJETÓRIA\n";
    Block *aux = trajetoria.top;

    for(short int i = 0;i < getTamanho(); i++)
    {
        for(short int j = 0; j < getTamanho(); j++)
            mat[i][j].caracter = '0';
    }

    while(aux != trajetoria.base)
    {
        short int linha = aux->data.linha;
        short int coluna = aux->data.coluna;
        mat[linha][coluna].caracter = 'x';
        aux = aux->prox;
    }   
}

void Randomico ::VerMatriz(Regiao **mat)
{
    for(short int i=0; i<getTamanho(); i++)
    {
        for(short int j=0; j<getTamanho(); j++)
        {
            cout << mat[i][j].caracter <<" ";
        }
        cout<<"\n";
    }
}

void Randomico :: Movimento(Regiao **mat)
{
    unsigned seed = time(0);
    short int lugar;
    short int linha = 0, coluna = 0;
    short int maislinha = 0, maiscoluna = 0;
    srand(seed);
    while (mat[linha][coluna].caracter != '?')
    {
        lugar = rand() % 4;
        if (lugar == 0)
        {
            if (coluna != getTamanho() - 1)
            {
                maislinha = 0;
                maiscoluna = 1;
                AndarMatriz(mat, &linha, &coluna, maislinha, maiscoluna);
            }
        }
        else if (lugar == 1)
        {
            if (linha != getTamanho() - 1)
            {
                maislinha = 1;
                maiscoluna = 0;
                AndarMatriz(mat, &linha, &coluna, maislinha, maiscoluna);
            }
        }
        else if (lugar == 2)
        {
            if (coluna != 0)
            {
                maislinha = 0;
                maiscoluna = -1;
                AndarMatriz(mat, &linha, &coluna, maislinha, maiscoluna);
            }
        }
        else if (lugar == 3)
        {
            if (linha != 0)
            {
                maislinha = -1;
                maiscoluna = 0;
                AndarMatriz(mat, &linha, &coluna, maislinha, maiscoluna);
            }
        }
    }
}

void Randomico :: AndarMatriz(Regiao **mat, short int *linha, short int *coluna, short int maislinha, short int maiscoluna)
{

    if (mat[*linha + maislinha][*coluna + maiscoluna].caracter == '?')
    {
        *linha = *linha + maislinha;
        *coluna = *coluna + maiscoluna;
        coordenada.linha = *linha;
        coordenada.coluna = *coluna;
        Push(&trajetoria, coordenada);
        cout << "Saída encontrada!\n";
    }
    else if (mat[*linha + maislinha][*coluna + maiscoluna].caracter == '#')
        mat[*linha + maislinha][*coluna + maiscoluna].cor = "Preto";

    else if (mat[*linha + maislinha][*coluna + maiscoluna].caracter == '*')
    {
        mat[*linha + maislinha][*coluna + maiscoluna].caracter = '1';
        PopAll(&trajetoria, &coordenada);
        *linha = 0;
        *coluna = 0;
        coordenada.linha = 0;
        coordenada.coluna = 0;
        Push(&trajetoria, coordenada);

    }
    else
    {
        *linha = *linha + maislinha;
        *coluna = *coluna + maiscoluna;
        coordenada.linha = *linha;
        coordenada.coluna = *coluna;
        Push(&trajetoria, coordenada);
    }
}