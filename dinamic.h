#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

// Estrutura do item armazenado nas células da fila
typedef struct {
    int cod;
    float valor; // 1 a 10000
    int op;      // 0- Saque; 1- Depósito; 2- Pagamento
} TipoItem;

// Célula da fila
typedef struct CelulaStr *TipoApontador;
typedef struct CelulaStr {
    TipoItem item;
    TipoApontador prox;
} TipoCelula;

// Estrutura da fila
typedef struct {
    TipoApontador frente, tras;
    int tamanho;
} TipoFila;

// Estrutura do Caixa do banco
typedef struct {
    int clientesAtendidos;
    float valorSaque;
    float valorDeposito;
    float valorPagamento;
} TipoCaixa;

// Inicializa a fila
void FFVazia(TipoFila *fila) {
    fila->frente = (TipoCelula *)malloc(sizeof(TipoCelula));
    fila->tras = fila->frente;
    fila->frente->prox = NULL;
    fila->tamanho = 0;
}

// Verifica se a fila está vazia
int Vazia(TipoFila fila) {
    return (fila.frente == fila.tras);
}

// Insere um item na fila
void Enfileira(TipoItem x, TipoFila *fila) {
    fila->tras->prox = (TipoCelula *)malloc(sizeof(TipoCelula));
    fila->tras = fila->tras->prox;
    fila->tras->item = x;
    fila->tras->prox = NULL;
    fila->tamanho++;
}

// Remove um item da fila
void Desenfileira(TipoFila *fila, TipoItem *item) {
    TipoApontador q;
    if (Vazia(*fila)) {
        cout << "Erro: fila vazia" <<endl;
        return;
    }
    q = fila->frente;
    fila->frente = fila->frente->prox;
    *item = fila->frente->item;
    free(q);
    fila->tamanho--;
}
