#ifndef PILHA_HPP 
#define PILHA_HPP

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

typedef struct Item Item;
typedef struct Block Block;
typedef struct Pilha Pilha;

struct Item
{
	short int linha;
	short int coluna;
};

struct Block
{
	Item data;
	Block *prox;
};

struct Pilha
{
	Block *base;
	Block *top;
};

typedef struct Regiao
{
    char caracter;
    string cor;
    
} Regiao;

void FPVazia(Pilha *p);
void Push(Pilha *p, Item d);
void Pop(Pilha *p, Item *d);
void PImprime(Pilha *p);
void PopAll(Pilha *p, Item *d);

#endif