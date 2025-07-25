#include "ListaSequencial.h"
#include <iostream>
using namespace std;

int main() {
    // Criando lista e alocando memória
    ListaSequencial *vetor = new ListaSequencial();
    cout << "Teste de posicoes extremas (primeira e ultima)" << endl;

    // Inserindo na primeira posição
    cout << "Inserindo 100 na primeira posicao..." << endl;
    vetor->InserirElemento(1, 100);
    cout << "Lista: ";
    vetor->ImprimirLista();

    // Inserindo na última posição (segunda posição atual)
    cout << "Inserindo 200 na ultima posicao..." << endl;
    vetor->InserirElemento(2, 200);
    cout << "Lista: ";
    vetor->ImprimirLista();

    // Inserindo no meio
    cout << "Inserindo 150 no meio..." << endl;
    vetor->InserirElemento(2, 150);
    cout << "Lista: ";
    vetor->ImprimirLista();

    // Removendo da primeira posição
    cout << "Removendo da primeira posicao..." << endl;
    vetor->RemoverElemento(1);
    cout << "Lista: ";
    vetor->ImprimirLista();
    
    // Removendo da última posição
    cout << "Removendo da ultima posicao..." << endl;
    vetor->RemoverElemento(vetor->getTamanho());
    cout << "Lista: ";
    vetor->ImprimirLista();

    // Testando inserção em lista com um elemento
    cout << "Inserindo 300 na primeira posicao..." << endl;
    vetor->InserirElemento(1, 300);
    cout << "Lista: ";
    vetor->ImprimirLista();

    cout << "Inserindo 400 na ultima posicao..." << endl;
    vetor->InserirElemento(vetor->getTamanho() + 1, 400);
    cout << "Lista: ";
    vetor->ImprimirLista();

    // Limpando a memória
    delete vetor;
    
    return 0;
}
