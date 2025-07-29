#include "ListaEncadeada.h"
#include <iostream>
using namespace std;

int main() {
    try {
        // Passo 1 - Criação da Lista Vazia
        ListaEncadeada lista;
        cout << "Lista criada." << endl;

        // Passo 2 - Verificação se a Lista está Vazia
        cout << "A lista esta vazia? " << (lista.vazia() ? "Sim" : "Nao") << endl;
        
        // Passo 3 - Obter o Tamanho da Lista
        cout << "Tamanho da lista: " << lista.getTamanho() << endl;

        // Passo Intermediário - Inserção de Elementos para Futuras Operações
        lista.InserirElemento(1, 10);
        lista.InserirElemento(2, 20);
        lista.InserirElemento(3, 30);
        lista.InserirElemento(2, 15);
        cout << "Elementos inseridos." << endl;

        // Passo Intermediário - Imprimir Lista Atual para Verificação
        cout << "Lista atual: ";
        lista.ImprimirLista();

        // Passo 4 - Obter/modificar o valor do elemento de uma determinada posição na lista
        cout << "Elemento na posicao 3: " << lista.getElemento(3) << endl;
        cout << "Modificando elemento da posicao 3 para 99." << endl;
        lista.setElemento(3, 99);
        cout << "Novo elemento na posicao 3: " << lista.getElemento(3) << endl;

        // Passo 5 - Inserir um novo elemento na lista
        cout << "Inserindo elemento 40 na posicao 4." << endl;
        lista.InserirElemento(4, 40);

        // Passo Intermédiário - Imprimir lista após modificações para verificação
        cout << "Lista apos modificacao: ";
        lista.ImprimirLista();

        // Passo 6 - Remover um elemento da lista
        cout << "Removendo elemento da posicao 2." << endl;
        lista.RemoverElemento(2);
        cout << "Lista apos todas as modificacoes: ";
        
        // Passo 7 - Imprimir lista final e verificar tamanho
        lista.ImprimirLista();
        cout << "Tamanho da lista: " << lista.getTamanho() << endl;

        cout << "A lista esta vazia? " << (lista.vazia() ? "Sim" : "Nao") << endl;
    } catch (const std::exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
    return 0;
}
