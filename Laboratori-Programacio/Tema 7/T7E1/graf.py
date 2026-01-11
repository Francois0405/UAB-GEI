# -*- coding: utf-8 -*-

class Graf:
    __slots__ = {'__nodes'}
        
    def __init__(self, nodes, arestes, pesos):
        self.__nodes = [[node, []] for node in nodes]
        for aresta, pes in zip(arestes, pesos):
            self.__nodes[aresta[0]][1].append([aresta[1], pes])
            self.__nodes[aresta[1]][1].append([aresta[0], pes])
            
    def __str__(self):
        s = ""
        for node in self.__nodes:
            s = s + "Comment :=>> Etiqueta: " + str(node[0]) + "\n"
            s = s + "Comment :=>> Arestes: " + str(node[1]) + "\n"
        return s
    
    def cicles(self):
        cicles = []
        for i in range(len(self.__nodes)):
            nodo_i = self.__nodes[i]
            for aresta_i in nodo_i[1]:
                j = aresta_i[0]
                nodo_j = self.__nodes[j]
                for aresta_j in nodo_j[1]:
                    k = aresta_j[0]
                    nodo_k = self.__nodes[k]
                    for aresta_k in nodo_k[1]:
                        if (aresta_k[0] == i):
                            cicle = []
                            cicle.append(nodo_i[0])
                            cicle.append(nodo_j[0])
                            cicle.append(nodo_k[0])
                            cicle.sort()
                            if (cicle not in cicles):
                                cicles.append(cicle)
        return cicles

    def nodeMaxArestes(self):
        max = -1
        eMax = '?'
        for nodo in self.__nodes:
            if (len(nodo[1]) > max):
                max = len(nodo[1])
                eMax = nodo[0]
        return eMax

    def nodesAillats(self):
        aillats = []
        for nodo in self.__nodes:
            if (len(nodo[1]) == 0):
                aillats.append(nodo[0])
        return aillats

    def etiquetesAdjacents(self, node):
        etiAdjacents = []
        for nodo in self.__nodes:
            if (nodo[0] == node):
                for aresta in nodo[1]:
                    etiAdjacents.append(self.__nodes[aresta[0]][0])
        return etiAdjacents