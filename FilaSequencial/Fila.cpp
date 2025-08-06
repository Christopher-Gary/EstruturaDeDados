#include "Fila.h"

Fila::Fila(int capacidade) {
    this->capacidade = capacidade;
    vetor = new int[capacidade];
    inicio = 0;
    fim = 0;
    tamanho = 0;
}

Fila::~Fila() {
    delete[] vetor;
}

bool Fila::enfileirar(int valor) {
    if (estaCheia()) {
        return false;
    }
    vetor[fim] = valor;
    fim = (fim + 1) % capacidade;
    tamanho++;
    return true;
}

bool Fila::desenfileirar(int &valor) {
    if (estaVazia()) {
        return false;
    }
    valor = vetor[inicio];
    inicio = (inicio + 1) % capacidade;
    tamanho--;
    return true;
}

bool Fila::primeiro(int &valor) const {
    if (estaVazia()) {
        return false;
    }
    valor = vetor[inicio];
    return true;
}

bool Fila::estaVazia() const {
    return tamanho == 0;
}

bool Fila::estaCheia() const {
    return tamanho == capacidade;
}

int Fila::getTamanho() const {
    return tamanho;
}