#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

//Q1) Construção de Árvore Binária
typedef struct No {
    int info;
    struct No* esquerda;
    struct No* direita;
} No;

//Função auxiliar para criar um novo nó.
No* criar_no(int valor) {
    No* novo_no = (No*) malloc(sizeof(No));
    novo_no->info = valor;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    return novo_no;
}

//Função para inserir novos nós que cria uma Árvore Binária de Busca (BST),
No* inserir(No* raiz, int valor) {
    // Caso default: se a árvore (ou sub-árvore) está vazia, o novo nó se torna a raiz.
    if (raiz == NULL) {
        return criar_no(valor);
    }
    // Passo recursivo: decide se vai para a sub-árvore esquerda ou direita.
    if (valor < raiz->info) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->info) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

//Q2) Percursos em Árvore

// Pré-ordem (Raiz, Esquerda, Direita)
void percurso_pre_ordem(No* raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->info);
    percurso_pre_ordem(raiz->esquerda);
    percurso_pre_ordem(raiz->direita);
}

// In-ordem (Esquerda, Raiz, Direita)
void percurso_in_ordem(No* raiz) {
    if (raiz == NULL) return;
    percurso_in_ordem(raiz->esquerda);
    printf("%d ", raiz->info);
    percurso_in_ordem(raiz->direita);
}

// Pós-ordem (Esquerda, Direita, Raiz)
void percurso_pos_ordem(No* raiz) {
    if (raiz == NULL) return;
    percurso_pos_ordem(raiz->esquerda);
    percurso_pos_ordem(raiz->direita);
    printf("%d ", raiz->info);
}

//Q3) Altura da Árvore
int altura(No* raiz) {
    // Altura de uma árvore vazia é -1.
    if (raiz == NULL) {
        return -1;
    }
    // Passo recursivo: calcula a altura das sub-árvores.
    int altura_esq = altura(raiz->esquerda);
    int altura_dir = altura(raiz->direita);
    // A altura da árvore é 1 + a maior das alturas das sub-árvores.
    return 1 + (altura_esq > altura_dir ? altura_esq : altura_dir);
}

//Q4) Contagem de Nós e Folhas

// a) Conta o número total de nós.
int contar_nos(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contar_nos(raiz->esquerda) + contar_nos(raiz->direita);
}

// b) Conta o número de nós folha (sem filhos).
int contar_folhas(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    // Se não tem filhos, é uma folha.
    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        return 1;
    }
    // Passo recursivo: soma as folhas das sub-árvores.
    return contar_folhas(raiz->esquerda) + contar_folhas(raiz->direita);
}

//Q5) Busca em Árvore Binária de Busca (BST)
bool buscar_bst(No* raiz, int valor) {
    // Chegou a uma folha e não encontrou.
    if (raiz == NULL) {
        return false;
    }
    // Encontrou o valor.
    if (raiz->info == valor) {
        return true;
    }
    // Passo recursivo: busca na sub-árvore apropriada.
    if (valor < raiz->info) {
        return buscar_bst(raiz->esquerda, valor);
    } else {
        return buscar_bst(raiz->direita, valor);
    }
}

//Q6) Menor e Maior Elemento em BST

// Encontra o menor valor (Esquerda Max).
No* menor_elemento_bst(No* raiz) {
    No* atual = raiz;
    while (atual != NULL && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

// Encontra o maior valor (Direita Max).
No* maior_elemento_bst(No* raiz) {
    No* atual = raiz;
    while (atual != NULL && atual->direita != NULL) {
        atual = atual->direita;
    }
    return atual;
}

//Q7) Verificar se é BST
bool eh_bst_util(No* no, int min, int max) {
    // Uma árvore vazia é uma BST.
    if (no == NULL) {
        return true;
    }
    // O valor do nó deve estar dentro dos limites min/max.
    if (no->info < min || no->info > max) {
        return false;
    }
    // Verifica recursivamente as sub-árvores, atualizando os limites.
    // Para a esquerda, o valor máximo passa a ser o valor do nó atual.
    // Para a direita, o valor mínimo passa a ser o valor do nó atual.
    return eh_bst_util(no->esquerda, min, no->info - 1) &&
           eh_bst_util(no->direita, no->info + 1, max);
}

bool verificar_se_eh_bst(No* raiz) {
    // Usa os maiores e menores valores possíveis para int como limites iniciais.
    return eh_bst_util(raiz, INT_MIN, INT_MAX);
}


// PARA TESTES!!
int main() {
    // Q1) Construção da Árvore
    No* raiz_bst = NULL;
    raiz_bst = inserir(raiz_bst, 50);
    inserir(raiz_bst, 30);
    inserir(raiz_bst, 20);
    inserir(raiz_bst, 40);
    inserir(raiz_bst, 70);
    inserir(raiz_bst, 60);
    inserir(raiz_bst, 80);
    printf("1) Arvore Binaria de Busca construida com os valores: 50, 30, 20, 40, 70, 60, 80\n\n");

    // Q2) Percursos
    printf("2) Percursos na Arvore:\n");
    printf("   Pre-ordem: ");
    percurso_pre_ordem(raiz_bst);
    printf("\n");
    printf("   In-ordem:  ");
    percurso_in_ordem(raiz_bst);
    printf("\n");
    printf("   Pos-ordem: ");
    percurso_pos_ordem(raiz_bst);
    printf("\n\n");

    // Q3) Altura
    printf("3) Altura da Arvore:\n");
    printf("   Altura: %d\n\n", altura(raiz_bst));

    // Q4) Contagem
    printf("4) Contagem de Nos e Folhas:\n");
    printf("   Total de nos: %d\n", contar_nos(raiz_bst));
    printf("   Nos folha: %d\n\n", contar_folhas(raiz_bst));

    // Q5) Busca em BST
    printf("5) Busca em BST:\n");
    printf("   Buscando 40: %s\n", buscar_bst(raiz_bst, 40) ? "Encontrado" : "Nao Encontrado");
    printf("   Buscando 99: %s\n\n", buscar_bst(raiz_bst, 99) ? "Encontrado" : "Nao Encontrado");

    // Q6) Menor e Maior
    No* menor = menor_elemento_bst(raiz_bst);
    No* maior = maior_elemento_bst(raiz_bst);
    printf("6) Menor e Maior Elemento em BST:\n");
    printf("   Menor: %d\n", menor ? menor->info : -1);
    printf("   Maior: %d\n\n", maior ? maior->info : -1);
    
    // Q7) Verificar se é BST
    printf("7) Verificar se a arvore construida eh uma BST:\n");
    printf("   A arvore eh BST? %s\n", verificar_se_eh_bst(raiz_bst) ? "Sim" : "Nao");
    
    // Árvore que NÃO é BST para teste para a Questão 7.
    No* raiz_nao_bst = criar_no(50);
    raiz_nao_bst->esquerda = criar_no(30);
    raiz_nao_bst->direita = criar_no(70);
    raiz_nao_bst->esquerda->direita = criar_no(60); // Errado! 60 > 50, deveria estar na direita.

    printf("   Verificar arvore invalida eh uma BST? %s\n\n", verificar_se_eh_bst(raiz_nao_bst) ? "Sim" : "Nao");

    return 0;
}