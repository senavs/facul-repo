class Balanco(object):
    CHAR_ABERTO = ['(', '[', '{']
    CHAR_FECHADO = [')', ']', '}']
    CHARS = {')': '(', ']': '[', '}': '{'}
    
    def __init__(self, frase):
        self.frase = frase
        self.apenas_chave = str()
        self.se_balanciado = self.balanciar_frase(self.frase)
    
    def balanciar_frase(self, frase):
        pilha = list()
        for caractere in frase:
            if caractere not in Balanco.CHAR_ABERTO + Balanco.CHAR_FECHADO:
                continue
            elif caractere in Balanco.CHAR_ABERTO:
                pilha.append(caractere)
                self.apenas_chave += caractere
            elif caractere in Balanco.CHAR_FECHADO:
                self.apenas_chave += caractere
                if len(pilha) == 0:
                    return False  
                elif pilha[-1] != Balanco.CHARS[caractere]:
                    return False
                else:
                    pilha.pop()
        if len(pilha) > 0:
            return False
        return True


# Teste 1
teste_01 = Balanco("C + (AB * (C + [B - A * {A - B}]) * {A + (B * A) + C})")
print(teste_01.frase)
# >> C + (AB * (C + [B - A * {A - B}]) * {A + (B * A) + C})
print(teste_01.se_balanciado)
# >> True 
print(teste_01.apenas_chave)
# >> (([{}]){()})

# Teste 2
teste_02 = Balanco("C + (AB * (C + [B - A * {A - B}]) * {A + B * A) + C})")
print(teste_02.frase)
# >> C + (AB * (C + [B - A * {A - B}]) * {A + B * A) + C})
print(teste_02.se_balanciado)
# >> False
print(teste_02.apenas_chave)
# >> (([{}]){)

# Teste 3
teste_03 = Balanco("C + (AB * (C + [B - A * {A - B}]) * {A + (B * A + C})")
print(teste_03.frase)
# >> C + (AB * (C + [B - A * {A - B}]) * {A + (B * A + C})
print(teste_03.se_balanciado)
# >> False
print(teste_03.apenas_chave)
# >> (([{}]){(}