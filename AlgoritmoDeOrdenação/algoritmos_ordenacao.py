import time
import os
import sys
from typing import List


def selection_sort(arr: List[int]) -> List[int]:
    """
    Implementação do algoritmo Selection Sort:
    Complexidade de tempo: O(n²) - Complexidade de espaço: O(1)
    """
    arr_copy = arr.copy()
    n = len(arr_copy)
    
    for i in range(n):
        # Encontra o índice do menor elemento no subarray não ordenado
        min_idx = i
        for j in range(i + 1, n):
            if arr_copy[j] < arr_copy[min_idx]:
                min_idx = j
        
        # Troca o menor elemento com o primeiro elemento do subarray não ordenado
        arr_copy[i], arr_copy[min_idx] = arr_copy[min_idx], arr_copy[i]
    
    return arr_copy


def insertion_sort(arr: List[int]) -> List[int]:
    """
    Implementação do algoritmo Insertion Sort.
    Complexidade de tempo: O(n²) no pior caso, O(n) no melhor caso
    Complexidade de espaço: O(1)
    """
    arr_copy = arr.copy()
    n = len(arr_copy)
    
    for i in range(1, n):
        key = arr_copy[i]
        j = i - 1
        
        # Move elementos maiores que key uma posição à frente
        while j >= 0 and arr_copy[j] > key:
            arr_copy[j + 1] = arr_copy[j]
            j -= 1
        
        # Insere key na posição correta
        arr_copy[j + 1] = key
    
    return arr_copy


def load_test_data(filename: str) -> List[int]:
    try:
        with open(filename, 'r') as file:
            lines = file.readlines()
            n = int(lines[0].strip())
            numbers = []
            
            for i in range(1, n + 1):
                numbers.append(int(lines[i].strip()))
            
            return numbers
    except FileNotFoundError:
        print(f"Erro: Arquivo '{filename}' não encontrado.")
        return []
    except ValueError as e:
        print(f"Erro ao processar arquivo '{filename}': {e}")
        return []


def measure_sorting_time(sort_function, arr: List[int], algorithm_name: str) -> tuple:
    print(f"Executando {algorithm_name}...")
    
    start_time = time.time()
    sorted_arr = sort_function(arr)
    end_time = time.time()
    
    execution_time = end_time - start_time
    print(f"{algorithm_name} executado em {execution_time:.6f} segundos")
    
    return sorted_arr, execution_time


def verify_sorting(original: List[int], sorted_arr: List[int]) -> bool:
    # Verifica se a ordenação foi realizada corretamente.

    # Verifica se todos os elementos estão presentes
    if sorted(original) != sorted_arr:
        return False
    
    # Verifica se está ordenado crescente
    for i in range(1, len(sorted_arr)):
        if sorted_arr[i] < sorted_arr[i-1]:
            return False
    
    return True


def run_tests():
   # Executa os testes com todos os arquivos de instância disponíveis.

    instances_dir = "instancias-num"
    
    if not os.path.exists(instances_dir):
        print(f"Erro: Diretório '{instances_dir}' não encontrado.")
        return
    
    # Lista todos os arquivos de teste
    test_files = [f for f in os.listdir(instances_dir) if f.endswith('.in')]
    test_files.sort()
    
    print("=== TESTES DOS ALGORITMOS DE ORDENAÇÃO ===\n")
    
    results = []
    
    for test_file in test_files:
        filepath = os.path.join(instances_dir, test_file)
        print(f"\n--- Testando arquivo: {test_file} ---")
        
        # Carrega os dados de teste
        test_data = load_test_data(filepath)
        
        if not test_data:
            print(f"Pulando arquivo {test_file} devido a erro de carregamento.")
            continue
        
        print(f"Tamanho do array: {len(test_data)} elementos")
        
        # Teste Selection Sort
        selection_result, selection_time = measure_sorting_time(
            selection_sort, test_data, "Selection Sort"
        )
        
        # Teste Insertion Sort
        insertion_result, insertion_time = measure_sorting_time(
            insertion_sort, test_data, "Insertion Sort"
        )
        
        # Verificação da correção dos algoritmos
        selection_correct = verify_sorting(test_data, selection_result)
        insertion_correct = verify_sorting(test_data, insertion_result)
        
        print(f"Selection Sort correto: {'✓' if selection_correct else '✗'}")
        print(f"Insertion Sort correto: {'✓' if insertion_correct else '✗'}")
        
        # Comparação de performance
        if selection_time < insertion_time:
            faster = "Selection Sort"
            difference = insertion_time - selection_time
        else:
            faster = "Insertion Sort"
            difference = selection_time - insertion_time
        
        print(f"Algoritmo mais rápido: {faster} (diferença: {difference:.6f}s)")
        
        results.append({
            'file': test_file,
            'size': len(test_data),
            'selection_time': selection_time,
            'insertion_time': insertion_time,
            'faster': faster
        })
    
    print("\n" + "="*60)
    print("RESUMO DOS RESULTADOS")
    print("="*60)
    
    print(f"{'Arquivo':<20} {'Tamanho':<10} {'Selection':<12} {'Insertion':<12} {'Mais Rápido':<15}")
    print("-" * 70)
    
    for result in results:
        print(f"{result['file']:<20} {result['size']:<10} "
              f"{result['selection_time']:.6f}s   {result['insertion_time']:.6f}s   "
              f"{result['faster']:<15}")
    
    selection_wins = sum(1 for r in results if r['faster'] == 'Selection Sort')
    insertion_wins = sum(1 for r in results if r['faster'] == 'Insertion Sort')
    
    print(f"\nEstatísticas gerais:")
    print(f"Selection Sort foi mais rápido em: {selection_wins} casos")
    print(f"Insertion Sort foi mais rápido em: {insertion_wins} casos")


def main():
    if len(sys.argv) > 1:
        test_file = sys.argv[1]
        print(f"Testando arquivo específico: {test_file}")
        
        test_data = load_test_data(test_file)
        if test_data:
            print(f"Tamanho do array: {len(test_data)} elementos")
            
            # Teste Selection Sort
            selection_result, selection_time = measure_sorting_time(
                selection_sort, test_data, "Selection Sort"
            )
            
            # Teste Insertion Sort
            insertion_result, insertion_time = measure_sorting_time(
                insertion_sort, test_data, "Insertion Sort"
            )
            
            # Verificação e comparação
            selection_correct = verify_sorting(test_data, selection_result)
            insertion_correct = verify_sorting(test_data, insertion_result)
            
            print(f"\nResultados:")
            print(f"Selection Sort correto: {'✓' if selection_correct else '✗'}")
            print(f"Insertion Sort correto: {'✓' if insertion_correct else '✗'}")
            
            if selection_time < insertion_time:
                print(f"Selection Sort foi mais rápido por {insertion_time - selection_time:.6f}s")
            else:
                print(f"Insertion Sort foi mais rápido por {selection_time - insertion_time:.6f}s")
    else:
        run_tests()


if __name__ == "__main__":
    main()
