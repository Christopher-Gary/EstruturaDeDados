#ifndef FILA_H
#define FILA_H

class Fila {
private:
    int *vetor;
    int capacidade;
    int inicio;
    int fim;
    int tamanho;

public:
    Fila(int capacidade);
    ~Fila();
    bool enfileirar(int valor);
    bool desenfileirar(int &valor);
    bool primeiro(int &valor) const;
    bool estaVazia() const;
    bool estaCheia() const;
    int getTamanho() const;
};

#endif // FILA_H