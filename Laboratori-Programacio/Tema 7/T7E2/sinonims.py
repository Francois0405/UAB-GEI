# -*- coding: utf-8 -*-
"""
Created on Wed Jan 24 10:43:25 2018

@author: ernest
"""
import random

def afegeixSinonim(diccionari, paraula, sinonim):
    if paraula not in diccionari:
        sinonims = []
        diccionari[paraula] = sinonims
        diccionari[paraula].append(sinonim)
    else:
        if sinonim not in diccionari[paraula]:
            diccionari[paraula].append(sinonim)

def conversioSinonims(frase, diccionari):
    fraseConvertida = []
    for paraula in frase:
        if paraula in diccionari:
            nSinonims = len(diccionari[paraula])
            i = random.randrange(0, nSinonims)
            fraseConvertida.append(diccionari[paraula][i])
        else:
            fraseConvertida.append(paraula)
    return fraseConvertida