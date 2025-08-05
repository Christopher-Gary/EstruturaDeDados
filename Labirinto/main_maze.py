# -*- coding: utf-8 -*-
import time
from maze import Maze
from collections import deque

s = deque()

maze_csv_path = "labirinto1.txt"  # Substitua pelo caminho correto
maze = Maze()

maze.load_from_csv(maze_csv_path)

# Inicia a visualização e posiciona o jogador e o premio
maze.run()
maze.init_player()

# 2. Localiza a posição inicial do jogador
p = maze.get_init_pos_player()

# 3. Insere sua localização na pilha
s.append(p)

path_found = False

# 4. Enquanto a pilha não estiver vazia
while len(s) > 0:
    # Adiciona um pequeno atraso para visualizar o processo
    time.sleep(0.1)

    # 5. Retira uma localização (linha, coluna) da pilha
    current_pos = s.pop()

    # 6. Se a posição tiver o premio no local então
    if maze.find_prize(current_pos):
        # 7. Caminho foi encontrado
        print("Caminho encontrado!")
        # Move o jogador para a posição final para destacar
        maze.mov_player(current_pos)
        path_found = True
        break

    # 8. Caso contrário, se o local não contiver o premio e se for uma posição livre (corredor)
    if maze.is_free(current_pos):
        # 9. Move o jogador para o local (marcando como visitado)
        maze.mov_player(current_pos)

        # 10. Examina se as casas adjacentes estão livres
        (row, col) = current_pos
        
        # Ordem dos vizinhos: Sul, Leste, Norte, Oeste
        neighbors = [(row + 1, col), (row, col + 1), (row - 1, col), (row, col - 1)]

        for neighbor in neighbors:
            if maze.is_free(neighbor):
                # 11. Se sim insira sua posição na pilha
                s.append(neighbor)

# 12. Retorne False (se o loop terminar sem encontrar o premio)
if not path_found:
    print("Nenhum caminho foi encontrado.")