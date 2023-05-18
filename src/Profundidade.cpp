#include "Profundidade.hpp"

Profundidade :: Profundidade()
{
    FPVazia(&trajetoria);
    coordenada.linha = 0;
    coordenada.coluna = 0;
    Push(&trajetoria, coordenada);
}

short int Profundidade :: gettamanho()
{
    return this->tamanho;
}

void Profundidade :: settamanho(short int tamanho)
{
    this->tamanho = tamanho;
}

void Profundidade :: lendomatriz(fstream& arq, Regiao **mat)
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

void Profundidade :: criatrajetoria(Regiao **mat)
{
    cout << "\nTRAJETÓRIA\n";
    Block *aux = trajetoria.top;

    for(short int i = 0;i < gettamanho(); i++)
    {
        for(short int j = 0; j < gettamanho(); j++)
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

void Profundidade :: vermatriz(Regiao **mat)
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

void Profundidade :: andando(Regiao **mat)
{
    short int linha = 0, coluna = 0;
    mat[linha][coluna].cor = "Cinza";
    while (mat[linha][coluna].caracter != '?')
    {
        if (linha != gettamanho() - 1 && mat[linha + 1][coluna].caracter != '#' && mat[linha + 1][coluna].cor == "Branco")
        {
            while (mat[linha + 1][coluna].caracter != '#')
            {
                if (mat[linha + 1][coluna].cor != "Branco")
                    break;
                linha++;
                if (mat[linha][coluna].caracter == '?')
                {
                    coordenada.linha = linha;
                    coordenada.coluna = coluna;
                    Push(&trajetoria, coordenada);
                    cout << "Saída encontrada!\n";
                    break;
                }
                mat[linha][coluna].cor = "Cinza";
                coordenada.linha = linha;
                coordenada.coluna = coluna;
                Push(&trajetoria, coordenada);
                if (mat[linha][coluna].caracter == '*')
                {
                    mat[linha][coluna].caracter = '1';
                    for (int linha = 0; linha < gettamanho(); linha++)
                    {
                        for (int coluna = 0; coluna < gettamanho(); coluna++)
                        {
                            mat[linha][coluna].cor = "Branco";
                        }
                    }
                    PopAll(&trajetoria, &coordenada);
                    mat[0][0].cor = "Cinza";
                    coluna = 0;
                    linha = 0;
                    coordenada.linha = linha;
                    coordenada.coluna = coluna;
                    Push(&trajetoria, coordenada);
                    break;
                }
                if (linha == gettamanho() - 1)
                    break;
            }
        }
        else if (coluna != gettamanho() - 1 && mat[linha][coluna + 1].caracter != '#'&& mat[linha][coluna + 1].cor == "Branco")
        {
            while (mat[linha][coluna + 1].caracter != '#')
            {
                if (mat[linha][coluna + 1].cor != "Branco")
                    break;
                coluna++;
                if (mat[linha][coluna].caracter == '?')
                {
                    coordenada.linha = linha;
                    coordenada.coluna = coluna;
                    Push(&trajetoria, coordenada);
                    cout << "Saída encontrada!\n";
                    break;
                }
                mat[linha][coluna].cor="Cinza";
                coordenada.linha = linha;
                coordenada.coluna = coluna;
                Push(&trajetoria, coordenada);
                if (mat[linha][coluna].caracter == '*')
                {
                    mat[linha][coluna].caracter = '1';
                    for (int linha = 0; linha < gettamanho(); linha++)
                    {
                        for (int coluna = 0; coluna < gettamanho(); coluna++)
                        {
                            mat[linha][coluna].cor = "Branco";
                        }
                    }
                    PopAll(&trajetoria, &coordenada);
                    mat[0][0].cor = "Cinza";
                    coluna = 0;
                    linha = 0;
                    coordenada.linha = linha;
                    coordenada.coluna = coluna;
                    Push(&trajetoria, coordenada);
                    break;
                }
                if (coluna == gettamanho() - 1)
                    break;
            }
        }
        else if (linha != 0 && mat[linha - 1][coluna].caracter != '#'&& mat[linha - 1][coluna].cor == "Branco")
        {
            while (mat[linha - 1][coluna].caracter != '#')
            {
                if (mat[linha - 1][coluna].cor != "Branco")
                    break;
                linha--;
                if (mat[linha][coluna].caracter == '?')
                {
                    coordenada.linha = linha;
                    coordenada.coluna = coluna;
                    Push(&trajetoria, coordenada);
                    cout << "Saída encontrada!\n";
                    break;
                }
                mat[linha][coluna].cor = "Cinza";
                coordenada.linha = linha;
                coordenada.coluna = coluna;
                Push(&trajetoria, coordenada);
                if (mat[linha][coluna].caracter == '*')
                {
                    mat[linha][coluna].caracter = '1';
                    for (int linha = 0; linha < gettamanho(); linha++)
                    {
                        for (int coluna = 0; coluna < gettamanho(); coluna++)
                        {
                            mat[linha][coluna].cor = "Branco";
                        }
                    }
                    PopAll(&trajetoria, &coordenada);
                    mat[0][0].cor = "Cinza";
                    coluna = 0;
                    linha = 0;
                    coordenada.linha = linha;
                    coordenada.coluna = coluna;
                    Push(&trajetoria, coordenada);
                    break;
                }
                if (linha == 0)
                    break;
            }
        }
        else if (coluna != 0 && mat[linha][coluna - 1].caracter != '#' && mat[linha][coluna - 1].cor == "Branco")
        {
            while (mat[linha][coluna - 1].caracter != '#')
            {
                if (mat[linha][coluna - 1].cor != "Branco")
                    break;
                coluna--;
                if (mat[linha][coluna].caracter == '?')
                {
                    coordenada.linha = linha;
                    coordenada.coluna = coluna;
                    Push(&trajetoria, coordenada);
                    cout << "Saída encontrada!\n";
                    break;
                }
                mat[linha][coluna].cor = "Cinza";
                coordenada.linha = linha;
                coordenada.coluna = coluna;
                Push(&trajetoria, coordenada);
                if (mat[linha][coluna].caracter == '*')
                {
                    mat[linha][coluna].caracter = '1';
                    for (int linha = 0; linha < gettamanho(); linha++)
                    {
                        for (int coluna = 0; coluna < gettamanho(); coluna++)
                        {
                            mat[linha][coluna].cor = "Branco";
                        }
                    }
                    PopAll(&trajetoria, &coordenada);
                    mat[0][0].cor = "Cinza";
                    coluna = 0;
                    linha = 0;
                    coordenada.linha = linha;
                    coordenada.coluna = coluna;
                    Push(&trajetoria, coordenada);
                    break;
                }
                if (coluna == 0)
                    break;
            }
        }
        else
        {
            mat[linha][coluna].cor = "Preto";
            Pop(&trajetoria, &coordenada);
            linha = trajetoria.top->data.linha;
            coluna = trajetoria.top->data.coluna;
        }
    }
    //PopAll(&trajetoria, &coordenada);
}