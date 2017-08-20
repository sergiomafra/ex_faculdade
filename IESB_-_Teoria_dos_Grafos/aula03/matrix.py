import re
from numpy import loadtxt

class Vertex():

    def __init__(self, vertex):
        self.vertex = vertex

    def __str__(self):
        return self.vertex

class Arc():

    def __init__(self, base, arrow):
        self.base = Vertex(base)
        self.arrow = Vertex(arrow)

    def __str__(self):
        return (self.base.__str__(), self.arrow.__str__())
        
class Graph():

    def __init__(self, graph_file):
        self.vertexes_list = []
        self.arc_list = []
        self._graph_initiation(graph_file)
        self.graph = []

    def _graph_initiation(self, graph_file):
        if graph_file == 'va.txt': self._create_graph_from_va(graph_file)
        if graph_file == 'matrix.txt': self._create_graph_from_matrix(graph_file)

    def _create_graph_from_va(self, graph_file):
        with open(graph_file) as va:
            lines = va.readlines()
        
        vertexes = lines[0].strip('V A \n = [ ]').split(',')
        arcs = [(base, arrow) for base, arrow in (re.split(',', basearrow) for basearrow in re.findall('(\w+,\w+)', lines[1].strip('V A = [ ]')))]

        self.vertexes_list = [Vertex(vertex) for vertex in vertexes]
        self.arc_list = [Arc(base, arrow) for (base, arrow) in arcs]

    def _create_graph_from_matrix(self, graph_file):
        matrix = loadtxt(graph_file, dtype='int')

        vertexes = matrix[0][1:]

        arcs = []
        for (y, element_y) in enumerate(matrix):
            for (x, element_x) in enumerate(element_y):
                if x > 0 and y > 0 and element_x == 1:
                    arcs.append( (matrix[y][0], matrix[0][x]) )

        self.vertexes_list = [Vertex(vertex) for vertex in vertexes]
        self.arc_list = [Arc(base, arrow) for (base, arrow) in arcs]

    def __str__(self):
        vertexes_list_print = [vertex.__str__() for vertex in self.vertexes_list]
        print("\n\t{:18}{}".format('List of vertexes:', vertexes_list_print))
        arc_list_print = [arc.__str__() for arc in self.arc_list]
        print("\t{:18}{}\n".format('List of arcs:', arc_list_print))


if __name__ == '__main__':
    graph_va = Graph('va.txt')
    graph_va.__str__()

    graph_matrix = Graph('matrix.txt')
    graph_matrix.__str__()