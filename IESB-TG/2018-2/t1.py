## Para alterar os dados de entrada,
## basta ir na linha 93 e alterar a
## variável entry para a lista desejada

class Vertex:
    ''' Creates a Vertex '''

    def __init__(self, vertex):
        self.vertex = vertex

    def __str__(self):
        return self.vertex

class Arc:
    ''' Creates an Arc '''

    def __init__(self, base, arrow):
        self.base = Vertex(base)
        self.arrow = Vertex(arrow)

    def __str__(self):
        return '{} -> {}'.format(self.base.__str__(), self.arrow.__str__())

class Digraph:

    def __init__(self, entry):
        self.entry = entry
        self.capital = 0
        self.vertex = [Vertex(index) for index in range(0, len(entry))]
        self.arcs = self._create_digraph_from_entry()

    def _create_digraph_from_entry(self):

        arcs = []
        for i, element in enumerate(self.entry):
            if element != i:
                arcs.append(Arc(element, i))
            else:
                self.capital = i

        return arcs

    def len(self):
        return len(self.vertex)

class BFS:

    def __init__(self, digraph):
        self.visitation_vector = []
        self.exit_vector = []
        self.queue = []
        self.digraph = digraph

    def put(self, value):
        self.queue.append(value)
        self.visitation_vector.append(value)

    def get(self):
        return self.queue.pop(0)

    def empty(self):
        return len(self.queue)

    def print_queue(self):
        print(self.visitation_vector)

    def run(self):
        self.put(self.digraph.capital)
        distance_to_capital = [0 for i in range(0,len(self.digraph.vertex))]
        exit_vector = [0 for i in range(0,len(self.digraph.vertex)-1)]
        counter = 1

        while self.empty() is not 0:
            cur_vertex = self.get()
            for element in self.digraph.arcs:
                if int(element.base.vertex) == cur_vertex:
                    arrow = element.arrow.vertex
                    base = element.base.vertex
                    if arrow not in self.visitation_vector:
                        distance_to_capital[arrow] = distance_to_capital[base] + 1
                        self.put(arrow)
                        counter += 1


        for element in distance_to_capital:
            if element != 0:
                exit_vector[element-1] = exit_vector[element-1] + 1

        print(exit_vector)

if __name__ == '__main__':

    entry = [9,1,4,9,0,4,8,9,0,1]
    bfs = BFS(Digraph(entry))
    bfs.run()
