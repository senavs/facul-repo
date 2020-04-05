import random

class Aeronave(object):

	def __init__(self):
		self.nome = f'Boeing {random.randint(100, 999)}'
		self.combustivel = random.randint(1, 10)	
