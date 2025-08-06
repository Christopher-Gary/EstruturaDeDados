#include <iostream>
#include "Fila.h"

void imprimirStatus(const Fila& fila) {
    std::cout << "Fila vazia? " << (fila.estaVazia() ? "Sim" : "Nao") << std::endl;
    std::cout << "Fila cheia? " << (fila.estaCheia() ? "Sim" : "Nao") << std::endl;
    std::cout << "Tamanho da fila: " << fila.getTamanho() << std::endl;
    int primeiro;
    if (fila.primeiro(primeiro)) {
        std::cout << "Primeiro elemento: " << primeiro << std::endl;
    } else {
        std::cout << "Nao ha primeiro elemento." << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
}

int main() {
    Fila fila(5);

    std::cout << "### Testes com Fila ###" << std::endl;
    imprimirStatus(fila);

    std::cout << "Enfileirando 10, 20, 30..." << std::endl;
    fila.enfileirar(10);
    fila.enfileirar(20);
    fila.enfileirar(30);
    imprimirStatus(fila);

    std::cout << "Enfileirando 40, 50..." << std::endl;
    fila.enfileirar(40);
    fila.enfileirar(50);
    imprimirStatus(fila);

    std::cout << "Tentando enfileirar com a fila cheia..." << std::endl;
    if (!fila.enfileirar(60)) {
        std::cout << "Nao foi possivel enfileirar, a fila esta cheia." << std::endl;
    }
    imprimirStatus(fila);

    int valorRemovido;
    std::cout << "Desenfileirando um elemento..." << std::endl;
    if (fila.desenfileirar(valorRemovido)) {
        std::cout << "Elemento removido: " << valorRemovido << std::endl;
    }
    imprimirStatus(fila);

    std::cout << "Enfileirando 60..." << std::endl;
    fila.enfileirar(60);
    imprimirStatus(fila);

    std::cout << "Desenfileirando todos os elementos..." << std::endl;
    while (!fila.estaVazia()) {
        if (fila.desenfileirar(valorRemovido)) {
            std::cout << "Elemento removido: " << valorRemovido << std::endl;
        }
    }
    imprimirStatus(fila);

    std::cout << "Tentando desenfileirar com a fila vazia..." << std::endl;
    if (!fila.desenfileirar(valorRemovido)) {
        std::cout << "Nao foi possivel desenfileirar, a fila esta vazia." << std::endl;
    }
    imprimirStatus(fila);

    return 0;
}