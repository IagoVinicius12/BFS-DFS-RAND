#include "Fila.hpp"

void FFVazia(Fila *f){
	f->first = (Blockf*) malloc (sizeof(Blockf));
	f->last  = f->first;
	f->first->prox = NULL;
}

bool isVazia(Fila *f){
	return f->first == f->last;
}

void Enfileira(Fila *f, Itemf d){
	f->last->prox = (Blockf*) malloc (sizeof(Blockf));
	f->last = f->last->prox;
	f->last->data = d;
	f->last->prox = NULL;
}

void Desenfileira(Fila *f, Itemf *d){
	Blockf *aux;

	if(f->first == f->last){
		printf("FILA VAZIA!\n");
		return;
	}
	
	aux = f->first->prox;
	f->first->prox = aux->prox;
	
	if (f->first->prox == NULL)
		f->last = f->first;
	
	*d = aux->data;
	free(aux);
}

void DesenfileiraAll(Fila *f, Itemf *d){
	Blockf *aux;

	while(f->first!=f->last || f->last!=NULL){
		if(f->first == f->last){
			return;
		}
		
		aux = f->first->prox;
		f->first->prox = aux->prox;
		
		if (f->first->prox == NULL)
			f->last = f->first;
		
		*d = aux->data;
		free(aux);
	}
}

void FImprime(Fila *f){
	Blockf *aux;

	aux = f->first->prox;
	while(aux != NULL){
		printf("%d.%d\n", aux->data.linha, aux->data.coluna);
		aux = aux->prox;
	}

}