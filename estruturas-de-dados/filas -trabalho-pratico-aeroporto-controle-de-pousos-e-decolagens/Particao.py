def particionar(lista: list, porcent: float):
    metade_1 = round(float(porcent) * len(lista))
    return lista[:metade_1], lista[metade_1:]
