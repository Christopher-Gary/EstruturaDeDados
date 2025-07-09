# -*- coding: utf-8 -*-

class Tabuleiro:
    DESCONHECIDO = 0
    JOGADOR_0 = 1
    JOGADOR_X = 4

    def __init__(self):
        self.matriz = [ [Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO], 
                        [Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO],
                        [Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO]]
       
        
    def tem_campeao(self):
        # Verifica linhas
        for linha in range(3):
            soma = self.matriz[linha][0] + self.matriz[linha][1] + self.matriz[linha][2]
            if soma == 12:
                return Tabuleiro.JOGADOR_X
            elif soma == 3:
                return Tabuleiro.JOGADOR_0
        
        # Verifica colunas
        for coluna in range(3):
            soma = self.matriz[0][coluna] + self.matriz[1][coluna] + self.matriz[2][coluna]
            if soma == 12:
                return Tabuleiro.JOGADOR_X
            elif soma == 3:
                return Tabuleiro.JOGADOR_0
        
        # Verifica diagonal principal
        soma = self.matriz[0][0] + self.matriz[1][1] + self.matriz[2][2]
        if soma == 12:
            return Tabuleiro.JOGADOR_X
        elif soma == 3:
            return Tabuleiro.JOGADOR_0
        
        # Verifica diagonal secundária
        soma = self.matriz[0][2] + self.matriz[1][1] + self.matriz[2][0]
        if soma == 12:
            return Tabuleiro.JOGADOR_X
        elif soma == 3:
            return Tabuleiro.JOGADOR_0
        
        return Tabuleiro.DESCONHECIDO