# Class Aluno --------------------------------------------------------------------------------------------------------------------
class Aluno(object):
    
    def __init__(self, nome: str, nota: float):
        self.nome = nome
        self.nota = nota
        
    def inserirAluno(self, lista, posicao):
        return lista.insereNaPos(self, posicao)
    
    def excluirAluno(self, lista):
        return lista.excluiLista(self)
    
    def modificaNota(self, lista, nota):
        self.nota = nota
        busca = lista.buscaLista(self)
        if busca[0]:
            lista.modifica(self, busca[1])
            return (True, "Aluno modificado com sucesso e atualizado na lista")
        return (False, "Aluno modificado com sucesso")
    
    @staticmethod
    def ordernaLista(lista):
        return lista.ordenaLista()

# Class Lista --------------------------------------------------------------------------------------------------------------------
class Lista(object):  # Objeto Lista

    def __init__(self):  # Inicia e cria self.alunos(list) e self.tamanho(int)
        self._alunos = []
        self._tamanho = None
        self._tamanhoMaximo = None
    
    def criaLista(self, tamanho):  # Pede o tamanho e cria a lista
        if self._alunos == [] and self._tamanho is None:
            self._alunos = [None for c in range(0, tamanho)]
            self._tamanho = 0
            self._tamanhoMaximo = tamanho
            return (True, f"Lista de tamanho {tamanho} criada com sucesso")
        return (False, f"Erro ao criar a Lista. Talvez já tenha sido criada")
    
    def vaziaLista(self):  # Verifica se a Lista está vazia
        if self._tamanho is None and self._alunos == []:
            return (False, "Lista ainda não foi criada")
        for item_lista in self._alunos:
            if item_lista is not None:
                return (False, "Lista não está vazia")
        return (True, "Lista está vazia")
               
    
    def cheiaLista(self):  # Verifica se a Lista está cheia
        if self._tamanho is None and self._alunos == []:
            return (False, "Lista ainda não foi criada")
        for item_lista in self._alunos:
            if item_lista is None:
                return (False, "Lista não está cheia")
        return (True, "Lista está cheia")
    
    def insereLista(self, aluno):
        if not self.cheiaLista()[0]:
            self._alunos[self._tamanho] = aluno
            self._tamanho += 1
            return (True, "Aluno inserido com sucesso")
        return (False, "Erro ao tentar inserir aluno. Verifique se a lista está cheia")
    
    def buscaLista(self, aluno=None, posicao=None):  # Pesquisa se o aluno está na lista
        for index_lista, item_lista in enumerate(self._alunos):
            if posicao is None:
                if item_lista == aluno:
                    return (True, index_lista, f"Aluno encontrado na lista")
            else:
                if index_lista == posicao:
                    return (True, index_lista, f"Aluno encontrado na lista")
        return (False, f"Aluno não foi encontrado a lista")
    
    def excluiLista(self, aluno):  # Remove um aluno da lista e arruma a lista
        busca = self.buscaLista(aluno)
        if busca[0]:
            index_aluno_excluir = self.buscaLista(aluno)[1]
            for index_aluno, item_aluno in enumerate(self._alunos):
                if index_aluno >= index_aluno_excluir:
                    if index_aluno == self._tamanho - 1:
                        self._alunos[index_aluno] = None
                        continue
                    self._alunos[index_aluno_excluir] = self._alunos[index_aluno_excluir + 1]
                    index_aluno_excluir += 1
            self._tamanho -= 1
            return (True, f"Aluno {aluno.nome} excluido com sucesso")
        return (False, f"Erro ao tentar excluir o aluno {aluno.nome}. Talvez não esteja na lista")
    
    def imprimeLista(self):  # Mostra todos os elementos da Lista
        for aluno in self._alunos:
            if aluno is not None:
                nome = getattr(aluno, 'nome')
                nota = getattr(aluno, 'nota')
            else:
                nome = 'Vazio'
                nota = 'Vazio'
            print(f"{nome} - {nota}\n")
            
    def insereNaPos(self, aluno, posicao: int):  # Insere aluno na posição, se válida
        if self.cheiaLista()[0]:
            return (False, "Lista cheia")
        elif posicao >= self._tamanhoMaximo:
            return (False, f"Posição inválida. Tente de 0 a {self._tamanhoMaximo - 1}")
        elif posicao < self._tamanho:   
            nova_lista_alunos = self._alunos.copy()
            for index, item in enumerate(self._alunos):
                if index == self._tamanhoMaximo - 1:
                    continue
                if index >= posicao:
                    nova_lista_alunos[index + 1] = self._alunos[index]

            nova_lista_alunos[posicao] = aluno
            self._alunos = nova_lista_alunos.copy()
            self._tamanho += 1
            return (True, f"Aluno {aluno.nome} inserido na posição {posicao}")
        elif posicao == self._tamanhoMaximo - 1:
            return self.insereLista(aluno)    
        return (False, f"Erro ao excluir aluno")
    
    def excluiDaPos(self, posicao):  # Remove da lista o lemente na posicao
        if self.vaziaLista()[0]:
            return (False, "Lista vazia")
        elif posicao < 0 or posicao >= self._tamanhoMaximo:
            return (False, f"Posição inválida. Tente de 0 a {self._tamanho - 1}")
        elif posicao >= self._tamanho:
            return (False, f"Posição inválida. Tente de 0 a {self._tamanho - 1}")
        else:
            busca = self.buscaLista(posicao=posicao)
            if busca[0]:
                index_aluno_excluir = posicao
                for index_aluno, item_aluno in enumerate(self._alunos):
                    if index_aluno >= index_aluno_excluir:
                        if index_aluno == self._tamanho - 1:
                            self._alunos[index_aluno] = None
                            continue
                        self._alunos[index_aluno_excluir] = self._alunos[index_aluno_excluir + 1]
                        index_aluno_excluir += 1
                self._tamanho -= 1
                return (True, f"Aluno excluido com sucesso")
            return (False, f"Erro ao tentar excluir aluno")
        
    def modifica(self, aluno, posicao):
        if self.vaziaLista()[0]:
            return self.vaziaLista()
        elif posicao < 0 or posicao >= self._tamanhoMaximo:
            return (False, f"Posição inválida. Tente de 0 a {self._tamanho - 1}")
        else:
            self._alunos[posicao] = aluno
            return (True, "Aluno modificado com sucesso")
        
    def ordenaLista(self):
        nova_lista_alunos = [aluno.nome for aluno in self._alunos if aluno is not None]
        nova_lista_alunos.sort()
        return nova_lista_alunos


# Outputs Pela Classe Lista --------------------------------------------------------------------------------------------------------------------

# Cria alunos
aluno_1 = Aluno('Pedro', 10)
aluno_2 = Aluno('João', 3)
aluno_3 = Aluno('Paulo', 0)
aluno_4 = Aluno('Maria', 9)
aluno_5 = Aluno('Ana', 4)
aluno_6 = Aluno('Rafael', 8)
aluno_7 = Aluno('Paulo', 0)

# Cria Lista
lista_1 = Lista()
lista_1.criaLista(5)
# >> (True, 'Lista de tamanho 5 criada com sucesso')

# Verifica se a lsita está vazia
lista_1.vaziaLista()
# >> (True, 'Lista está vazia')

# Verifica se a lsita está cheia
lista_1.cheiaLista()
# >> (False, 'Lista não está cheia')

# Insere Alunos
lista_1.insereLista(aluno_1)
# >> (True, 'Aluno inserido com sucesso')
lista_1.insereLista(aluno_2)
# >> (True, 'Aluno inserido com sucesso')
lista_1.insereLista(aluno_3)
# >> (True, 'Aluno inserido com sucesso')

# Busca Aluno
lista_1.buscaLista(aluno_1)
# >> (True, 0, 'Aluno encontrado na lista')

# Exclui da lsita
lista_1.excluiLista(aluno_1)
# >> (True, 'Aluno Pedro excluido com sucesso')

# Imprime Lista
lista_1.imprimeLista()
# >> João - 3
# >> Paulo - 0
# >> Vazio - Vazio
# >> Vazio - Vazio
# >> Vazio - Vazio

# Insere Aluno na posição
lista_1.insereNaPos(aluno_4, 1)
# >> (True, 'Aluno Maria inserido na posição 1')
lista_1.imprimeLista()
# >> João - 3
# >> Maria - 9
# >> Paulo - 0
# >> Vazio - Vazio
# >> Vazio - Vazio

# Exclui Aluno na posição
lista_1.excluiDaPos(2)
# >> (True, 'Aluno excluido com sucesso')
lista_1.imprimeLista()
# >> João - 3
# >> Maria - 9
# >> Vazio - Vazio
# >> Vazio - Vazio
# >> Vazio - Vazio

# Modifica Aluno
lista_1.modifica(aluno_6, 0)
# >> (True, 'Aluno modificado com sucesso')
lista_1.imprimeLista()
# >> Rafael - 8
# >> Maria - 9
# >> Vazio - Vazio
# >> Vazio - Vazio
# >> Vazio - Vazio

# Ordena lista
lista_1.insereLista(aluno_3)
lista_1.insereLista(aluno_4)
lista_1.insereLista(aluno_5)
lista_1.ordenaLista()
# >> ['Ana', 'Maria', 'Maria', 'Paulo', 'Rafael']

# Outputs Pela Classe Aluno --------------------------------------------------------------------------------------------------------------------

# Excluir aluino
aluno_5.excluirAluno(lista_1)
# >> (True, 'Aluno Ana excluido com sucesso')
lista_1.imprimeLista()
# >> Rafael - 8
# >> Maria - 9
# >> Paulo - 0
# >> Maria - 9
# >> Vazio - Vazio

# Inserir Aluno
aluno_5.inserirAluno(lista_1, 4)
# >> True, 'Aluno inserido com sucesso')
lista_1.imprimeLista()
# >> Rafael - 8
# >> Maria - 9
# >> Paulo - 0
# >> Maria - 9
# >> Ana - 4

# Modifica Nota do aluno e se estiver na lista, atualiza o aluno na lista
aluno_5.modificaNota(lista_1, 7)
# >> (True, 'Aluno modificado com sucesso e atualizado na lista')
lista_1.imprimeLista()
# >> Rafael - 8
# >> Maria - 9
# >> Paulo - 0
# >> Maria - 9
# >> Ana - 7

# Ordena Lista
aluno_5.ordernaLista(lista_1)
# >> ['Ana', 'Maria', 'Maria', 'Paulo', 'Rafael']