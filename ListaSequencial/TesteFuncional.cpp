#include "ListaSequencial.h"
#include <iostream>
using namespace std;

int main() {
    try {
        // Criação da lista vazia
        ListaSequencial *vetor = new ListaSequencial();
        cout << "Lista criada." << endl;

        // Verificar se a lista está vazia
        cout << "A lista esta vazia? " << (vetor->vazia() ? "Sim" : "Nao") << endl;

        // Verificar se a lista está cheia
        cout << "A lista esta cheia? " << (vetor->cheia() ? "Sim" : "Nao") << endl;

        // Obter o tamanho da lista
        cout << "Tamanho da lista: " << vetor->getTamanho() << endl;

        // Inserir elementos em posições específicas
        vetor->InserirElemento(1, 9);
        vetor->InserirElemento(2, 10);
        vetor->InserirElemento(3, 11);
        vetor->InserirElemento(4, 12);
        vetor->InserirElemento(5, 13);
        cout << "Elementos inseridos." << endl;

        // Imprimir os elementos de toda a lista
        cout << "Lista atual: ";
        vetor->ImprimirLista();

        // Obter/modificar o valor do elemento de uma determinada posição
        cout << "Elemento na posicao 3: " << vetor->getElemento(3) << endl;
        cout << "Modificando elemento da posicao 3 para 99." << endl;
        vetor->setElemento(3, 99);
        cout << "Novo elemento na posicao 3: " << vetor->getElemento(3) << endl;

        // Retirar um elemento de uma determinada posição
        cout << "Removendo elemento da posicao 2." << endl;
        vetor->RemoverElemento(2);
        cout << "Lista apos remocao: ";
        vetor->ImprimirLista();
        cout << "Tamanho da lista: " << vetor->getTamanho() << endl;

        // Verificar se a lista está vazia
        cout << "A lista esta vazia? " << (vetor->vazia() ? "Sim" : "Nao") << endl;

        // Inserindo valores até encher a lista
        int i = 5;
        while (!vetor->cheia()) {
            vetor->InserirElemento(i, i);
            i++;
        }
        cout << "Lista apos preencher: ";
        vetor->ImprimirLista();

        // Verificar se a lista está cheia
        cout << "A lista esta cheia? " << (vetor->cheia() ? "Sim" : "Nao") << endl;

        // Limpando a memória
        delete vetor;
    } catch (const std::exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
    
    return 0;
}
