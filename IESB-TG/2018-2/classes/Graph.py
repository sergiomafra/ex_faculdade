from .BaseGraph import BaseGraph

class Graph(BaseGraph):

    def __init__(self, graphfilename):

        self.edges = []
        super().__init__(self)

    def _import_straight_segments_from_va(self, line):

        super()._import_straight_segments_from_va()

        edges = []
        for element in ss:
            elements = element.split(',')
            edges.append( Edge(elements[0], elements[1]) )

        return edges

    def _create_graph_from_va(self):

        super()._create_graph_from_va()

        # Importing edges
        self.edges = _import_straight_segments_from_va(line[1])

    def _create_graph_from_matrix(self):
        pass



