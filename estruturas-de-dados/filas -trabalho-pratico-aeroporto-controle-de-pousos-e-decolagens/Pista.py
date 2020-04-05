from Queue import Queue, FullQueue, EmptyList
from Aeronave import Aeronave
from Particao import particionar

import random
import time
import os

class Pista(object):

    def __init__(self, porcentagem_inicial = 0.7):
        self.fila_pouso = Queue(10)
        self.fila_pouso_emergencia = Queue(2)
        self.fila_decolagem = Queue(10)
        
        self._hora = 0
        self._dia = 1
        self._distribuicao = [x for x in range(100)]
        self._porcentagem = porcentagem_inicial

    def _chegada_pouso(self, nova_aeronave):
        # if nova_aeronave.combustivel < len(self.fila_pouso) + len(self.fila_decolagem) - 2:
        if nova_aeronave.combustivel <= 3:
            self.fila_pouso_emergencia.enqueue(nova_aeronave.nome)
        else:
            self.fila_pouso.enqueue(nova_aeronave.nome)
                
    def _chegada_decolagem(self, nova_aeronave):
        self.fila_decolagem.enqueue(nova_aeronave.nome)
        
    def _pousar(self):
        if not self.fila_pouso.is_empty:
            self.fila_pouso.dequeue()
        
    def _decolar(self):
        if not self.fila_decolagem.is_empty:
            self.fila_decolagem.dequeue()
    
    def _get_evento_aleatorio(self):
        return random.randint(0, len(self._distribuicao) - 1)
    
    def _proxima_hora(self):
        if self._hora < 24:
            self._hora += 1
            if self._hora == 24:
                self._hora = 0
                self._dia += 1
    
    def sortear_evento(self, nova_aeronave):
        # Muda porcentagem da distribuição para uma nova aeronave de acordo com a hora
        if 9 <= self._hora <= 16:
            porcentagem_nova_aeronave = random.choice([0.2, 0.3, 0.4])
        else:
            porcentagem_nova_aeronave = random.choice([0.4, 0.5, 0.6])      

        evento = self._get_evento_aleatorio()
        
        print('Evento nº:', evento)
        print('Distribuição:', porcentagem_nova_aeronave)
        
        if not self.fila_pouso_emergencia.is_empty:  # forçar pouso de emergência
            self.fila_pouso_emergencia.dequeue()
            return 'FORÇAR POUSO DE EMERGÊNCIA! AERONAVE SEM COMBUSTÍVEL'
        else:
            try:
                if evento in particionar(particionar(self._distribuicao, porcentagem_nova_aeronave)[0], 0.5)[0]:  # Chegada de uma nova aeronave para pouso
                    self._chegada_pouso(nova_aeronave)
                    return 'Chegada de uma NOVA aernova para POUSO'
                elif evento in particionar(particionar(self._distribuicao, porcentagem_nova_aeronave)[0], 0.5)[1]:  # Chegada de uma nova aeronave para decolagem
                    self._chegada_decolagem(nova_aeronave)
                    return 'Chegada de uma NOVA aernova para DECOLAGEM'
                elif evento in particionar(particionar(self._distribuicao, porcentagem_nova_aeronave)[1], 0.4)[0]:  # Pousar uma aernonave
                    self._pousar()
                    return 'POUSAR uma aeronave'
                else:  # Decolar uma aeronave
                    self._decolar()
                    return 'DECOLAR UMA AERNOAVE'
            except FullQueue:
                return 'AEROPORTO SUPER LOTADO\nMELHORE SUA GESTÃO'

    def print_log_evento(self, nova_aeronave):
        evento_sorteado = self.sortear_evento(nova_aeronave)
        print('-' * 50)
        print(f'HORA: {self._hora:0>2}:00')
        print(f'DIA: {self._dia}')
        print('-' * 50)
        print(f'EVENTO: {evento_sorteado}')
        print(f'AERONAVE: {nova_aeronave.nome}')
        print(f'COMBUST. AERONAVE: {nova_aeronave.combustivel}')
        print('-' * 50)
        print('Pouso -', self.fila_pouso.to_list())
        print('Emergência -', self.fila_pouso_emergencia.to_list())
        print('Decolagem -', self.fila_decolagem.to_list())
        print('-' * 50)
        self._proxima_hora()
        if evento_sorteado == 'AEROPORTO SUPER LOTADO\nMELHORE SUA GESTÃO':
            return 0
        else:
            return 1


if __name__ == '__main__':
    pista = Pista()
    
    while True:
        nova_aeronave = Aeronave() 
        if not pista.print_log_evento(nova_aeronave):
            input()
            break
        # time.sleep(1)
        os.system('cls')
