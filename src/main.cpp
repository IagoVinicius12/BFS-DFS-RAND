#include "Randomico.hpp"
#include "Profundidade.hpp"
#include "Largura.hpp"

int main()
{
    Randomico *randomico = new Randomico();
    Profundidade *profundo = new Profundidade();
    Largura *largura = new Largura();
    short int tamanho;
    string nomearq = "dataset/input.data";
    fstream arq;

    arq.open(nomearq);
    arq >> tamanho;
    arq >> tamanho;

    largura->settamanho(tamanho);

    Regiao **mat = new Regiao *[tamanho];
    for (short int i = 0; i < tamanho; i++)
        mat[i] = new Regiao[tamanho];

    cout << "\nLARGURA" << endl;
    largura->Leitura(arq,mat);
    largura->andando(mat);
    largura->criatrajetoria(mat);
    largura->vermatriz(mat);
    arq.close();

    arq.open(nomearq);
    arq >> tamanho;
    arq >> tamanho;

    profundo->settamanho(tamanho);

    cout << "\nPROFUNDIDADE" << endl;
    profundo->lendomatriz(arq, mat);
    profundo->andando(mat);
    profundo->criatrajetoria(mat);
    profundo->vermatriz(mat);
    arq.close();

    arq.open(nomearq);
    arq >> tamanho;
    arq >> tamanho;

    randomico->setTamanho(tamanho);

    cout << "\nRANDÔMICO" << endl;
    randomico->Leitura(arq, mat);
    randomico->Movimento(mat);
    randomico->CriaTrajetoria(mat);
    randomico->VerMatriz(mat);
    arq.close();
}
