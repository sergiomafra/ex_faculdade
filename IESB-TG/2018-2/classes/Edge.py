from .Vertex import Vertex

class Edge:

    def __init__(self, vertex1, vertex2):

        self.edge = (Vertex(vertex1), Vertex(vertex2))

    def __str__(self):
        return '{} - {}'.format(self.edge[0].__str__(), self.edge[1].__str__())
