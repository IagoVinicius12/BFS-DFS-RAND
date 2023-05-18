#ifndef FILA_H 
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct Itemf Itemf;
typedef struct Blockf Blockf;
typedef struct Fila Fila;

struct Itemf{
	int linha;
	int coluna;
};

struct Blockf{
	Itemf data;
	Blockf *prox;
};

struct Fila{
	Blockf *first;
	Blockf *last;
};

void FFVazia(Fila *f);
void Enfileira(Fila *f, Itemf d);
void Desenfileira(Fila *f, Itemf *d);
void FImprime(Fila *f);
void DesenfileiraAll(Fila *f, Itemf *d);

#endif