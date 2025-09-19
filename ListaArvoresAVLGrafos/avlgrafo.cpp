#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Q5) Estrutura Node para a BST (e AVL)
typedef struct Node {
    int valor;
    struct Node *esquerda;
    struct Node *direita;
    int altura; // Campo adicional para a AVL
} Node;

// Func para retornar o maior entre dois numeros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Func para obter a altura do nó
int altura(Node *no) {
    if (no == NULL)
        return -1;
    return no->altura;
}

// Func para criar um novo nó
Node* criar_no(int valor) {
    Node* novo_no = (Node*) malloc(sizeof(Node));
    novo_no->valor = valor;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    novo_no->altura = 0;
    return novo_no;
}

// Q5) Implemente o método inserir(valor)
Node* inserir_bst(Node* raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserir_bst(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_bst(raiz->direita, valor);
    }
    return raiz;
}

// Q6) Implemente o método buscar(valor)
bool buscar_bst(Node* raiz, int valor) {
    if (raiz == NULL) {
        return false;
    }
    if (raiz->valor == valor) {
        return true;
    }
    if (valor < raiz->valor) {
        return buscar_bst(raiz->esquerda, valor);
    } else {
        return buscar_bst(raiz->direita, valor);
    }
}

// Q7) Implemente os métodos de percurso
void pre_ordem(Node* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

void em_ordem(Node* raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esquerda);
        printf("%d ", raiz->valor);
        em_ordem(raiz->direita);
    }
}

void pos_ordem(Node* raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}


// QUESTÃO 8: ÁRVORE AVL

// Letra c). Fator de Balanceamento
int fator_balanceamento(Node *no) {
    if (no == NULL)
        return 0;
    return altura(no->esquerda) - altura(no->direita);
}

// Letra d). Rotações
Node* rotacao_direita(Node *y) {
    Node *x = y->esquerda;
    Node *T2 = x->direita;

    // Realiza a rotação
    x->direita = y;
    y->esquerda = T2;

    // Atualiza as alturas
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;

    return x;
}

Node* rotacao_esquerda(Node *x) {
    Node *y = x->direita;
    Node *T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

    return y;
}

// Letras a, e) Inserir e já com Balanceamento Automático
Node* inserir_avl(Node* no, int valor) {
    // 1- Inserção normal de BST
    if (no == NULL)
        return criar_no(valor);

    if (valor < no->valor)
        no->esquerda = inserir_avl(no->esquerda, valor);
    else if (valor > no->valor)
        no->direita = inserir_avl(no->direita, valor);
    else
        return no;

    // 2- Atualiza a altura do nó ancestral
    no->altura = 1 + max(altura(no->esquerda), altura(no->direita));

    // 3- Calcula o fator de balanceamento para ver se precisa rotacionar
    int fb = fator_balanceamento(no);

    // 4- Se o nó ficou desbalanceado verifica em 4 casos
    // Caso Esquerda-Esquerda (LL)
    if (fb > 1 && valor < no->esquerda->valor)
        return rotacao_direita(no);

    // Caso Direita-Direita (RR)
    if (fb < -1 && valor > no->direita->valor)
        return rotacao_esquerda(no);

    // Caso Esquerda-Direita (LR)
    if (fb > 1 && valor > no->esquerda->valor) {
        no->esquerda = rotacao_esquerda(no->esquerda);
        return rotacao_direita(no);
    }

    // Caso Direita-Esquerda (RL)
    if (fb < -1 && valor < no->direita->valor) {
        no->direita = rotacao_direita(no->direita);
        return rotacao_esquerda(no);
    }

    return no;
}

// Letra f) Verificação de Balanceamento
bool verificacao_balanceada(Node* raiz) {
    if (raiz == NULL) {
        return true; // Árvore vazia já é balanceada
    }
    int fb = fator_balanceamento(raiz);
    if (abs(fb) > 1) {
        printf("Nó com valor %d está desbalanceado! FB = %d\n", raiz->valor, fb);
        return false;
    }
    // Verifica recursivamente as sub-árvores
    return verificacao_balanceada(raiz->esquerda) && verificacao_balanceada(raiz->direita);
}

// PARA TESTE!!
int main() {
    printf("--- Testando Arvore Binaria de Busca (BST) ---\n");
    Node* raiz_bst = NULL;
    raiz_bst = inserir_bst(raiz_bst, 45);
    inserir_bst(raiz_bst, 20);
    inserir_bst(raiz_bst, 60);
    inserir_bst(raiz_bst, 15);
    inserir_bst(raiz_bst, 25);
    
    printf("Percurso Em-Ordem (BST): ");
    em_ordem(raiz_bst);
    printf("\n");

    printf("Buscar valor 25: %s\n", buscar_bst(raiz_bst, 25) ? "Encontrado" : "Nao Encontrado");
    printf("Buscar valor 99: %s\n", buscar_bst(raiz_bst, 99) ? "Encontrado" : "Nao Encontrado");
    printf("\n");

    printf("--- Testando Arvore AVL ---\n");
    Node* raiz_avl = NULL;
    int valores[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(valores)/sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        raiz_avl = inserir_avl(raiz_avl, valores[i]);
        printf("Inserido %d. Percurso Em-Ordem: ", valores[i]);
        em_ordem(raiz_avl);
        printf("\n");
    }

    printf("\nAltura final da arvore AVL: %d\n", altura(raiz_avl));
    printf("Verificacao de Balanceamento: A arvore esta balanceada? %s\n",
           verificacao_balanceada(raiz_avl) ? "Sim" : "Nao");

    return 0;
}