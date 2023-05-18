#include "Largura.hpp"

Largura :: Largura()
{
    FFVazia(&trajetoria);
    coordenada.linha = 0;
    coordenada.coluna = 0;
    Enfileira(&trajetoria, coordenada);
    posicao=trajetoria.first->prox;
}

short int Largura :: gettamanho()
{
    return this->tamanho;
}

void Largura :: settamanho(short int tamanho)
{
    this->tamanho = tamanho;
}

void Largura :: Leitura(fstream& arq, Regiao **mat)
{
    char letra;
    for(short int i = 0;i < gettamanho(); i++)
    {
        for(short int j = 0; j < gettamanho(); j++)
        {
            arq >> letra;
            mat[i][j].caracter = letra;
            mat[i][j].cor = "Branco";
        }
    }
}

void Largura :: criatrajetoria(Regiao **mat)
{
    cout << "\nTRAJETÓRIA\n";
    Blockf *aux = trajetoria.first->prox;

    for(short int i = 0;i < gettamanho(); i++)
    {
        for(short int j = 0; j < gettamanho(); j++)
            mat[i][j].caracter = '0';
    }

    while(aux != NULL)
    {
        short int linha = aux->data.linha;
        short int coluna = aux->data.coluna;
        mat[linha][coluna].caracter = 'x';
        aux = aux->prox;
    }   
}

void Largura :: vermatriz(Regiao **mat)
{
    for(short int i=0; i<gettamanho(); i++)
    {
        for(short int j=0; j<gettamanho(); j++)
        {
            cout << mat[i][j].caracter <<" ";
        }
        cout<<"\n";
    }
}

void Largura :: andando(Regiao **mat)
{
    short int linha=posicao->data.linha, coluna=posicao->data.coluna;
    mat[linha][coluna].cor = "Cinza";
    while(mat[linha][coluna].caracter!='?')
    {
        if((linha != gettamanho() - 1 && mat[linha + 1][coluna].caracter != '#' && mat[linha + 1][coluna].cor == "Branco") || (coluna != gettamanho() - 1 && mat[linha][coluna + 1].caracter != '#'&& mat[linha][coluna + 1].cor == "Branco") || (linha != 0 && mat[linha - 1][coluna].caracter != '#'&& mat[linha - 1][coluna].cor == "Branco") || (coluna != 0 && mat[linha][coluna - 1].caracter != '#' && mat[linha][coluna - 1].cor == "Branco"))
        {
            if (linha != gettamanho() - 1 && mat[linha + 1][coluna].caracter != '#' && mat[linha + 1][coluna].cor == "Branco")
            {
                mat[linha+1][coluna].cor = "Cinza";
                coordenada.linha=linha+1;
                coordenada.coluna=coluna;
                Enfileira(&trajetoria,coordenada);
            }
            if (coluna != gettamanho() - 1 && mat[linha][coluna + 1].caracter != '#'&& mat[linha][coluna + 1].cor == "Branco")
            {
                mat[linha][coluna+1].cor = "Cinza";
                coordenada.linha=linha;
                coordenada.coluna=coluna+1;
                Enfileira(&trajetoria,coordenada);
            }
            if (linha != 0 && mat[linha - 1][coluna].caracter != '#'&& mat[linha - 1][coluna].cor == "Branco")
            {
                mat[linha-1][coluna].cor = "Cinza";
                coordenada.linha=linha-1;
                coordenada.coluna=coluna;
                Enfileira(&trajetoria,coordenada);
            }
            if (coluna != 0 && mat[linha][coluna - 1].caracter != '#' && mat[linha][coluna - 1].cor == "Branco")
            {
                mat[linha][coluna-1].cor = "Cinza";
                coordenada.linha=linha;
                coordenada.coluna=coluna-1;
                Enfileira(&trajetoria,coordenada);
            }
        }
        else
            Movimento(&linha,&coluna, mat);
    }
    cout << "Saída encontrada!\n";
}

void Largura :: Movimento(short int *linha, short int * coluna, Regiao **mat)
{
    if(mat[*linha][*coluna].caracter=='*')
    {
        mat[*linha][*coluna].caracter='1';
        *linha=0;
        *coluna=0;
        coordenada.linha=*linha;
        coordenada.coluna=*coluna;
        for(short int i = 0; i < gettamanho(); i++)
        {
            for(short int j = 0 ;j < gettamanho(); j++)
                mat[i][j].cor = "Branco";
        }
        mat[0][0].cor = "Cinza";
        DesenfileiraAll(&trajetoria,&coordenada);
        Enfileira(&trajetoria,coordenada);
        posicao=trajetoria.first->prox;
    }
    else
    {
        posicao=posicao->prox;
        *linha=posicao->data.linha;
        *coluna=posicao->data.coluna;
    }
}