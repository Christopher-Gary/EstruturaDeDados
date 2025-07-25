#include "ListaSequencial.h"
#include <iostream>
#include <stdexcept>
using namespace std;

ListaSequencial::ListaSequencial() {
    tamanho = 0;
}

bool ListaSequencial::vazia() {
    return tamanho == 0;
}

bool ListaSequencial::cheia() {
    return tamanho == CAPACIDADE_MAXIMA;
}

int ListaSequencial::getTamanho() {
    return tamanho;
}

int ListaSequencial::getElemento(int posicao) {
    if (posicao < 1 || posicao > tamanho) {
        throw out_of_range("Posição inválida");
    }
    return dados[posicao - 1];
}

void ListaSequencial::setElemento(int posicao, int valor) {
    if (posicao < 1 || posicao > tamanho) {
        throw out_of_range("Posição inválida");
    }
    dados[posicao - 1] = valor;
}

void ListaSequencial::InserirElemento(int posicao, int valor) {
    if (cheia()) {
        throw overflow_error("Lista está cheia");
    }
    
    if (posicao < 1 || posicao > tamanho + 1) {
        throw out_of_range("Posição inválida");
    }
    
    for (int i = tamanho; i >= posicao; i--) {
        dados[i] = dados[i - 1];
    }
    
    dados[posicao - 1] = valor;
    tamanho++;
}

void ListaSequencial::RemoverElemento(int posicao) {
    if (vazia()) {
        throw underflow_error("Lista está vazia");
    }
    
    if (posicao < 1 || posicao > tamanho) {
        throw out_of_range("Posição inválida");
    }
    
    for (int i = posicao - 1; i < tamanho - 1; i++) {
        dados[i] = dados[i + 1];
    }
    
    tamanho--;
}

void ListaSequencial::ImprimirLista() {
    if (vazia()) {
        cout << "Lista vazia" << endl;
        return;
    }
    
    cout << "[";
    for (int i = 0; i < tamanho; i++) {
        cout << dados[i];
        if (i < tamanho - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}
