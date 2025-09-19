#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Q1) Inverter String
void trocar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

//Função recursiva que inverte uma string no proprio local.
void inverter_recursivo_interno(char str[], int inicio, int fim) {
    // Se os ponteiros se encontrarem, a string tá invertida.
    if (inicio >= fim) {
        return;
    }
    // Passo recursivo: troca o primeiro com o último caractere.
    trocar(&str[inicio], &str[fim]);
    // Chama a recursão para o restante da string.
    inverter_recursivo_interno(str, inicio + 1, fim - 1);
}

void inverter(char str[]) {
    inverter_recursivo_interno(str, 0, strlen(str) - 1);
}

//Q2) Máximo em Lista
int maximo(int lista[], int tamanho) {
    // Se a lista tem apenas um elemento, ele é o máximo.
    if (tamanho == 1) {
        return lista[0];
    }
    // Encontra o máximo do restante da lista.
    int max_do_resto = maximo(lista, tamanho - 1);
    // Compara o máximo do resto com o último elemento atual.
    if (lista[tamanho - 1] > max_do_resto) {
        return lista[tamanho - 1];
    } else {
        return max_do_resto;
    }
}

//Q3) Soma de Lista Recursiva
int soma(int lista[], int tamanho) {
    if (tamanho <= 0) {
        return 0;
    }
    // Soma o último elemento com a soma do resto da lista.
    return lista[tamanho - 1] + soma(lista, tamanho - 1);
}

// PARA TESTES!!
int main() {
    // Q1) Inverter String
    char minha_string[] = "recursao";
    printf("1) Inverter String:\n");
    printf("   Original: %s\n", minha_string);
    inverter(minha_string);
    printf("   Invertida: %s\n\n", minha_string);

    // Q2) Máximo em Lista
    int lista_nums[] = {3, 7, 2, 9, 1};
    int tam_lista = sizeof(lista_nums) / sizeof(lista_nums[0]);
    printf("2) Maximo em Lista [3, 7, 2, 9, 1]:\n");
    printf("   Maximo: %d\n\n", maximo(lista_nums, tam_lista));

    // Q3) Soma de Lista
    int lista_soma[] = {1, 2, 3, 4};
    int tam_soma = sizeof(lista_soma) / sizeof(lista_soma[0]);
    printf("3) Soma de Lista [1, 2, 3, 4]:\n");
    printf("   Soma: %d\n\n", soma(lista_soma, tam_soma));

    return 0;
}