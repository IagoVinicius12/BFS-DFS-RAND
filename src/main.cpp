#include <chrono>
#include "Randomico.hpp"
#include "Profundidade.hpp"
#include "Largura.hpp"

int main()
{
    chrono :: steady_clock :: time_point inicio_total = chrono::steady_clock :: now();
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
    chrono :: steady_clock :: time_point inicio_largura = chrono::steady_clock :: now();
    largura->Leitura(arq,mat);
    largura->andando(mat);
    largura->criatrajetoria(mat);
    largura->vermatriz(mat);
    chrono :: steady_clock :: time_point fim_largura = chrono :: steady_clock :: now();
    arq.close();

    arq.open(nomearq);
    arq >> tamanho;
    arq >> tamanho;

    profundo->settamanho(tamanho);

    cout << "\nPROFUNDIDADE" << endl;
    chrono :: steady_clock :: time_point inicio_profundidade = chrono::steady_clock :: now();
    profundo->lendomatriz(arq, mat);
    profundo->andando(mat);
    profundo->criatrajetoria(mat);
    profundo->vermatriz(mat);
    chrono :: steady_clock :: time_point fim_profundidade = chrono :: steady_clock :: now();
    arq.close();

    arq.open(nomearq);
    arq >> tamanho;
    arq >> tamanho;

    randomico->setTamanho(tamanho);

    cout << "\nRANDÔMICO" << endl;
    chrono :: steady_clock :: time_point inicio_randomico = chrono::steady_clock :: now();
    randomico->Leitura(arq, mat);
    randomico->Movimento(mat);
    randomico->CriaTrajetoria(mat);
    randomico->VerMatriz(mat);
    chrono :: steady_clock :: time_point fim_randomico = chrono :: steady_clock :: now();
    arq.close();

    chrono :: steady_clock :: time_point fim_total = chrono :: steady_clock :: now();

    chrono :: duration <double, milli> tempo_largura = fim_largura - inicio_largura;
    chrono :: duration <double, milli> tempo_profundidade = fim_profundidade - inicio_profundidade;
    chrono :: duration <double, milli> tempo_randomico = fim_randomico - inicio_randomico;
    chrono :: duration <double, milli> tempo_total = fim_total - inicio_total;

    cout << "\nTEMPO DE EXECUÇÃO" << endl;
    cout << "BFS: " << fixed << tempo_largura.count() << " ms"<< endl;
    cout << "DFS: " << fixed << tempo_profundidade.count() << " ms"<< endl;
    cout << "RAND: " << fixed << tempo_randomico.count() << " ms"<< endl;
    cout << "TOTAL: " << fixed << tempo_total.count() << " ms"<< endl;
}
