#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

class ListaSequencial {
private:
    static const int CAPACIDADE_MAXIMA = 100;
    int dados[CAPACIDADE_MAXIMA];
    int tamanho;

public:
    ListaSequencial();
    
    bool vazia();
    
    bool cheia();
    
    int getTamanho();
    
    int getElemento(int posicao);
    
    void setElemento(int posicao, int valor);
    
    void InserirElemento(int posicao, int valor);
    
    void RemoverElemento(int posicao);
    
    void ImprimirLista();
};

#endif
