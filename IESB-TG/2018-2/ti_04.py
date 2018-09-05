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

    def __init__(self, filename):
        self.filename = filename
        self.arcs = self._create_digraph_from_va(2)
        self.vertex = self._create_digraph_from_va(1)

    def _create_digraph_from_va(self, num):
        with open(self.filename, 'r') as graphfile:
            for i, line in enumerate(graphfile.readlines()):
                # Vertexes
                if num == 1 and i == 0:
                    aux = [Vertex(element) for element in list(map(int,
                        line.strip('\n V = [ ]').split(',')))]
                    return tuple(aux)
                if num == 2 and i == 1:
                    aux = [Arc(element[0],element[2]) for element in
                            line.strip('\n A = [ ]').split(',')]
                    return tuple(aux)

    def len(self):
        return len(self.vertex)

class BFS:

    def __init__(self, digraph, initial_vertex):
        self.visitation_vector = []
        self.queue = []
        self.digraph = digraph
        self.initial_vertex = initial_vertex

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
        self.put(self.initial_vertex)
        counter = 1

        while self.empty() is not 0:
            cur_vertex = self.get()
            for element in self.digraph.arcs:
                if int(element.base.vertex) == int(cur_vertex):
                    element = element.arrow.vertex
                    if element not in self.visitation_vector:
                        self.put(element)
                        counter += 1

        self.print_queue()

if __name__ == '__main__':

    bfs = BFS(Digraph('ti_04.txt'),3)
    bfs.run()
