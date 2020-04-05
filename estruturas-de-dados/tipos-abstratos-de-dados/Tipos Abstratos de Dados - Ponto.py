# Importa PI
from math import pi

# "Banco de dados"
class Registro(object):
    def __init__(self):
        self.pontos = list()
        self.circulos = list()
        
    def registrar(self, ponto=None, circulo=None):
        if isinstance(circulo, Circulo):
            self.circulos.append([circulo.centro, circulo.raio])
        if isinstance(ponto, Ponto):
            self.pontos.append([ponto.x, ponto.y])
    
    def get_registros_pontos(self):
        return self.pontos
    
    def get_registros_circulos(self):
        return self.circulos
    
    def del_registro_circulos(self, index):
        self.circulos.pop(index)

# Class Ponto
class Ponto(object):
    def __init__(self, x: float, y: float, registro):
        self.x = float()
        self.y = float()
        if self.se_ponto(x, y, registro):
            self.x = x
            self.y = y
            registro.registrar(ponto=self)
        
    def se_ponto(self, x, y, registro):
        registros = registro.get_registros_pontos()
        ponto = [x, y]
        for reg in registros:
            if ponto == reg:
                return False
        return True
    
    def get_ponto(self):
        return (self.x, self.y)
        
# Class DiatanciaPontos
class DistanciaPontos(object):
    def __init__(self, p1: Ponto, p2: Ponto):
        self.ponto1 = p1
        self.ponto2 = p2
        
    def get_distancia_ponto(self):
        dx = abs(self.ponto2.x - self.ponto1.x)
        dy = abs(self.ponto2.y - self.ponto1.y)
        return pow(pow(dx, 2) + pow(dy, 2), (1/2))

# Class Círculo
class Circulo(object):
    def __init__(self, centro: Ponto, ponto: Ponto, registro: Registro):
        self.centro_class = centro
        self.ponto_class = ponto
        self.centro = [centro.x, centro.y]
        self.ponto = [ponto.x, ponto.y]
        self.raio = DistanciaPontos(centro, ponto).get_distancia_ponto()
        if self.se_circulo(self.centro, self.raio, registro):
            registro.registrar(circulo=self)
        else:
            self.centro = None
            self.ponto = None
            self.raio = None
    
    def se_circulo(self, centro, raio, registro):
        registros = registro.get_registros_circulos()
        circulo = [centro, raio]
        for reg in registros:
            if circulo == reg:
                return False
        return True
    
    def destruir_circulo(self, registro):
        for index, reg in enumerate(registro.get_registros_circulos()):
            if [self.centro, self.raio] == reg:
                registro.del_registro_circulos(index)
                
    def get_area(self):
        return round(pi * pow(self.raio, 2))
    
    def __lt__(self, other):
        distancia = DistanciaPontos(self.centro_class, other).get_distancia_ponto()
        if self.raio == distancia:
            return True
        else:
            return False
        
    def __sub__(self, other):
        distancia = DistanciaPontos(self.centro_class, other).get_distancia_ponto()
        if distancia < self.raio:
            return True
        else:
            return False
            
# Cria "Banco de dados" (registro)
registro = Registro()
# Cria Pontos
ponto1 = Ponto(0, 0, registro)
ponto2 = Ponto(0, 5, registro)
ponto3 = Ponto(5, 0, registro)

# 1/2) Cria Círculos / Verifica Círculos
circulo1 = Circulo(ponto1, ponto2, registro)
circulo2 = Circulo(ponto2, ponto1, registro)

# 3) Deleta Círculos
circulo2.destruir_circulo(registro)

# 4) Area do Círculo
circulo1.get_area()

# 5) Pertence ao Círculo
circulo1 < ponto1

# 6) Interno ao Círculo
circulo1 - ponto1