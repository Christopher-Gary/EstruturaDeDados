# -*- coding: utf-8 -*-

from jogador import Jogador
from tabuleiro import Tabuleiro

class JogadorIA(Jogador):
    def __init__(self, tabuleiro : Tabuleiro, tipo : int):
        super().__init__(tabuleiro, tipo)
            

    def getJogada(self):
        # R1: Se você ou seu oponente tiver duas marcações em sequência, marque o quadrado restante
        jogada = self.regra1()
        if jogada:
            return jogada
            
        # R2: Se houver uma jogada que crie duas sequências de duas marcações, use-a
        jogada = self.regra2()
        if jogada:
            return jogada
            
        # R3: Se o quadrado central estiver livre, marque-o
        jogada = self.regra3()
        if jogada:
            return jogada
            
        # R4: Se seu oponente tiver marcado um dos cantos, marque o canto oposto
        jogada = self.regra4()
        if jogada:
            return jogada
            
        # R5: Se houver um canto vazio, marque-o
        jogada = self.regra5()
        if jogada:
            return jogada
            
        # R6: Marque arbitrariamente um quadrado vazio
        return self.regra6()
    
    def regra1(self):
        # Primeiro verifica se pode vencer
        for linha in range(3):
            for col in range(3):
                if self.matriz[linha][col] == Tabuleiro.DESCONHECIDO:
                    # Testa a jogada
                    self.matriz[linha][col] = self.tipo
                    if self.tabuleiro.tem_campeao() == self.tipo:
                        self.matriz[linha][col] = Tabuleiro.DESCONHECIDO  # Desfaz
                        return (linha, col)
                    self.matriz[linha][col] = Tabuleiro.DESCONHECIDO  # Desfaz
        
        # Se não pode vencer, verifica se precisa bloquear o oponente
        oponente = Tabuleiro.JOGADOR_X if self.tipo == Tabuleiro.JOGADOR_0 else Tabuleiro.JOGADOR_0
        for linha in range(3):
            for col in range(3):
                if self.matriz[linha][col] == Tabuleiro.DESCONHECIDO:
                    # Testa se o oponente venceria
                    self.matriz[linha][col] = oponente
                    if self.tabuleiro.tem_campeao() == oponente:
                        self.matriz[linha][col] = Tabuleiro.DESCONHECIDO  # Desfaz
                        return (linha, col)
                    self.matriz[linha][col] = Tabuleiro.DESCONHECIDO  # Desfaz
        
        return None
    
    def regra2(self):
        # Verifica se uma jogada cria duas linhas com duas marcações
        for linha in range(3):
            for col in range(3):
                if self.matriz[linha][col] == Tabuleiro.DESCONHECIDO:
                    self.matriz[linha][col] = self.tipo
                    ameacas = self.contar_ameacas()
                    self.matriz[linha][col] = Tabuleiro.DESCONHECIDO
                    if ameacas >= 2:
                        return (linha, col)
        return None
    
    def contar_ameacas(self):
        """
        Conta quantas "ameaças" a IA tem no tabuleiro.
        Uma ameaça é uma linha/coluna/diagonal onde a IA já tem 2 peças
        e a terceira posição está vazia (ou seja, pode vencer na próxima jogada).
        
        Como a IA é sempre JOGADOR_0 (valor 1), uma ameaça tem soma = 2 (1+1+0).
        
        """
        ameacas = 0
        
        # Verifica linhas
        for linha in range(3):
            soma = self.matriz[linha][0] + self.matriz[linha][1] + self.matriz[linha][2]
            if soma == 2:
                ameacas += 1
        
        # Verifica colunas
        for coluna in range(3):
            soma = self.matriz[0][coluna] + self.matriz[1][coluna] + self.matriz[2][coluna]
            if soma == 2:
                ameacas += 1
        
        # Verifica diagonal principal
        soma = self.matriz[0][0] + self.matriz[1][1] + self.matriz[2][2]
        if soma == 2:
            ameacas += 1
        
        # Verifica diagonal secundária
        soma = self.matriz[0][2] + self.matriz[1][1] + self.matriz[2][0]
        if soma == 2:
            ameacas += 1
            
        return ameacas
    
    def regra3(self):
        if self.matriz[1][1] == Tabuleiro.DESCONHECIDO:
            return (1, 1)
        return None
    
    def regra4(self):
        oponente = Tabuleiro.JOGADOR_X if self.tipo == Tabuleiro.JOGADOR_0 else Tabuleiro.JOGADOR_0
        cantos = [(0,0), (0,2), (2,0), (2,2)]
        opostos = [(2,2), (2,0), (0,2), (0,0)]
        
        for i, (l, c) in enumerate(cantos):
            if self.matriz[l][c] == oponente:
                ol, oc = opostos[i]
                if self.matriz[ol][oc] == Tabuleiro.DESCONHECIDO:
                    return (ol, oc)
        return None
    
    def regra5(self):
        cantos = [(0,0), (0,2), (2,0), (2,2)]
        for l, c in cantos:
            if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                return (l, c)
        return None
    
    def regra6(self):
        for l in range(3):
            for c in range(3):
                if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                    return (l, c)
        return None