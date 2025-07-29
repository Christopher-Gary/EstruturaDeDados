#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

struct No {
    int valor;
    No* prox;
};

class ListaEncadeada {
private:
    No* inicio;
    int tamanho;

public:
    ListaEncadeada();
    ~ListaEncadeada();

    bool vazia();
    int getTamanho();
    int getElemento(int posicao);
    void setElemento(int posicao, int valor);
    void InserirElemento(int posicao, int valor);
    void RemoverElemento(int posicao);
    void ImprimirLista();
};

#endif
