#include "ListaSequencial.h"
#include <iostream>
using namespace std;

int main() {
    // Criando lista e alocando memória
    ListaSequencial *vetor = new ListaSequencial();
    cout << "Teste de limites (lista vazia e cheia)" << endl;

    // Testando lista vazia
    cout << "Estado inicial - ";
    cout << (vetor->vazia() ? "Vazia" : "Nao vazia") << endl;
    cout << "Tamanho: " << vetor->getTamanho() << endl;
    vetor->ImprimirLista();

    // Inserindo até encher
    cout << "\nPreenchendo a lista..." << endl;
    int i = 1;
    while (!vetor->cheia()) {
        vetor->InserirElemento(i, i * 10);
        if (i % 20 == 0) {
            cout << "Inseridos " << i << " elementos..." << endl;
        }
        i++;
    }

    // Verificando lista cheia
    cout << "Lista cheia: " << (vetor->cheia() ? "Sim" : "Nao") << endl;
    cout << "Tamanho final: " << vetor->getTamanho() << endl;
    cout << "Primeiros elementos: ";
    for (int j = 1; j <= 5; j++) {
        cout << vetor->getElemento(j) << " ";
    }
    cout << "..." << endl;
    cout << "Ultimos elementos: ";
    for (int j = vetor->getTamanho() - 4; j <= vetor->getTamanho(); j++) {
        cout << vetor->getElemento(j) << " ";
    }
    cout << endl;

    // Removendo todos os elementos...
    cout << "\nEsvaziando a lista..." << endl;
    int contador = 0;
    while (!vetor->vazia()) {
        vetor->RemoverElemento(1);
        contador++;
        if (contador % 20 == 0) {
            cout << "Removidos " << contador << " elementos..." << endl;
        }
    }

    // Testando lista vazia novamente
    cout << "Lista vazia: " << (vetor->vazia() ? "Sim" : "Nao") << endl;
    cout << "Tamanho: " << vetor->getTamanho() << endl;
    vetor->ImprimirLista();

    // Limpando a memória
    delete vetor;
    
    return 0;
}
