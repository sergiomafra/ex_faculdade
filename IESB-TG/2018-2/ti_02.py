def createDigraph(V, A):
    digrafo = {}
    for vertex in V:
        digrafo[vertex] = []

    for arc in A:
        digrafo[arc[0]].append(arc[1])
        if arc[0] not in digrafo[arc[1]]:
            digrafo[arc[1]].append(arc[0])

    return digrafo

def printDigraph(digrafo):
    for key, value in digrafo.items():
        print('{}: '.format(key), end='')
        for element in value:
            print('{} '.format(element), end='')
        print()

if __name__ == '__main__':
    V = [1,2,3,4,5,6]
    A = [ [1,2] , [1,3] , [2,4] , [3,4] , [4,5] , [5,6] ]
    digrafo = createDigraph(V, A)

    printDigraph(digrafo)
