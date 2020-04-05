from chainedlist import ChainedList

# Cria lista
lista_dupla_encadeada = ChainedList()
print(f"1º >> {lista_dupla_encadeada}")

# Se está vazia
print(f"2º >> {lista_dupla_encadeada.is_empty()}")

# Insere no final da lista
lista_dupla_encadeada.append("item 1")
lista_dupla_encadeada.append("item 2")
lista_dupla_encadeada.append("item 3")
print(f"3º >> {lista_dupla_encadeada}")

# Insere em qualquer posição
lista_dupla_encadeada.insert("item 4", 0)
lista_dupla_encadeada.insert("item 5", 2)
lista_dupla_encadeada.insert("item 6", -1)
print(f"4º >> {lista_dupla_encadeada}")

# Remover da lista - Se não existir ele levante um erro ("ValueError: ChainedList.remove(x): x not in list")
lista_dupla_encadeada.remove("item 2")
print(f"5º >> {lista_dupla_encadeada}")

# Tamanho da lista
print(f"6º >> {lista_dupla_encadeada.length}")
print(f"6º >> {len(lista_dupla_encadeada)}")

# Se um elemento está na lista
print(f"7º >> {'item 1' in lista_dupla_encadeada}")
print(f"7º >> {'item X' in lista_dupla_encadeada}")

# Mostrar a lista
print(f"8º >> {lista_dupla_encadeada}")

# Mostrar a lista invertida
print(f"9º >> {reversed(lista_dupla_encadeada)}")


# ----------OUTPUT----------
# 1º >> []
# 2º >> True
# 3º >> ['item 1', 'item 2', 'item 3']
# 4º >> ['item 4', 'item 1', 'item 5', 'item 2', 'item 3', 'item 6']
# 5º >> ['item 4', 'item 1', 'item 5', 'item 3', 'item 6']
# 6º >> 5
# 6º >> 5
# 7º >> True
# 7º >> False
# 8º >> ['item 4', 'item 1', 'item 5', 'item 3', 'item 6']
# 9º >> ['item 6', 'item 3', 'item 5', 'item 1', 'item 4']