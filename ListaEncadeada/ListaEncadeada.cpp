#include "ListaEncadeada.h"
#include <iostream>
#include <stdexcept>
using namespace std;

ListaEncadeada::ListaEncadeada() {
    inicio = nullptr;
    tamanho = 0;
}

ListaEncadeada::~ListaEncadeada() {
    while (!vazia()) {
        RemoverElemento(1);
    }
}

bool ListaEncadeada::vazia() {
    return tamanho == 0;
}

int ListaEncadeada::getTamanho() {
    return tamanho;
}

int ListaEncadeada::getElemento(int posicao) {
    if (posicao < 1 || posicao > tamanho) {
        throw out_of_range("Posição inválida");
    }
    No* atual = inicio;
    for (int i = 1; i < posicao; i++) {
        atual = atual->prox;
    }
    return atual->valor;
}

void ListaEncadeada::setElemento(int posicao, int valor) {
    if (posicao < 1 || posicao > tamanho) {
        throw out_of_range("Posição inválida");
    }
    No* atual = inicio;
    for (int i = 1; i < posicao; i++) {
        atual = atual->prox;
    }
    atual->valor = valor;
}

void ListaEncadeada::InserirElemento(int posicao, int valor) {
    if (posicao < 1 || posicao > tamanho + 1) {
        throw out_of_range("Posição inválida");
    }
    No* novo = new No{valor, nullptr};
    if (posicao == 1) {
        novo->prox = inicio;
        inicio = novo;
    } else {
        No* anterior = inicio;
        for (int i = 1; i < posicao - 1; i++) {
            anterior = anterior->prox;
        }
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }
    tamanho++;
}

void ListaEncadeada::RemoverElemento(int posicao) {
    if (vazia()) {
        throw underflow_error("Lista está vazia");
    }
    if (posicao < 1 || posicao > tamanho) {
        throw out_of_range("Posição inválida");
    }
    No* removido;
    if (posicao == 1) {
        removido = inicio;
        inicio = inicio->prox;
    } else {
        No* anterior = inicio;
        for (int i = 1; i < posicao - 1; i++) {
            anterior = anterior->prox;
        }
        removido = anterior->prox;
        anterior->prox = removido->prox;
    }
    delete removido;
    tamanho--;
}

void ListaEncadeada::ImprimirLista() {
    if (vazia()) {
        cout << "Lista vazia" << endl;
        return;
    }
    cout << "[";
    No* atual = inicio;
    for (int i = 0; i < tamanho; i++) {
        cout << atual->valor;
        if (i < tamanho - 1) cout << ", ";
        atual = atual->prox;
    }
    cout << "]" << endl;
}
