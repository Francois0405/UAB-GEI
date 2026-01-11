# -*- coding: utf-8 -*-


import copy as cp
import numpy as np

class Graf:
    __slots__ = {'__nodes', '__arestes'}
        
    def __init__(self, nodes, arestes, pesos):
        self.__nodes = cp.deepcopy(nodes)
        self.__arestes = np.zeros([len(nodes), len(nodes)])
        for aresta, pes in zip(arestes, pesos):
            self.__arestes[aresta[0],aresta[1]] = pes
            self.__arestes[aresta[1],aresta[0]] = pes
            
    def __str__(self):
        s = ""
        for posNode, node in enumerate(self.__nodes):
            s = s + "Etiqueta: " + str(node) + "\n"
            s = s + "Arestes: " + str([[vei[0], pes] for vei, pes in np.ndenumerate(self.__arestes[posNode,:]) if pes != 0]) + "\n"
        return s
    
    def cicles(self):
        cicles = []
        n = len(self.__nodes)

        for i in range(n):
            for j in range(n):
                if self.xº[i][j] != 0:
                    for k in range(n):
                        if self.__arestes[j][k] != 0 and self.__arestes[k][i] != 0:
                            cicle = [
                                self.__nodes[i],
                                self.__nodes[j],
                                self.__nodes[k]
                            ]
                            cicle.sort()
                            if cicle not in cicles:
                                cicles.append(cicle)
        return cicles

          
    def nodeMaxArestes(self):
        maxArestes = -1
        iMax = 0
        for i in range(len(self.__nodes)):
            numArestes = 0
            for pes in self.__arestes[i]:
                if pes != 0:
                    numArestes += 1

            if numArestes > maxArestes:
                maxArestes = numArestes
                iMax = i
        return self.__nodes[iMax]

    def nodesAillats(self):
        aillats = []
        # numNodes = len(self.__nodes)
        # Més pythonic
        for i in range(len(self.__nodes)):
            if all(aresta == 0 for aresta in self.__arestes[i]):
                aillats.append(self.__nodes[i])
        return aillats
        
        """for i in range(len(self.__nodes)):
            node = self.__arestes[i]
            etiNode = self.__nodes[i]
            counter = 0
            for aresta in node:
                if aresta == 0:
                    counter += 1
            if counter == numNodes:
                aillats.append(etiNode)
        return aillats"""
            

    def etiquetesAdjacents(self, node):
        adjacents = []

        # obtener índice del nodo a partir de la etiqueta
        i = self.__nodes.index(node)

        # recorrer la fila i de la matriz
        for j in range(len(self.__nodes)):
            if self.__arestes[i][j] != 0:
                adjacents.append(self.__nodes[j])

        return adjacents