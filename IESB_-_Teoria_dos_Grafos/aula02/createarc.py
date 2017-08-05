from graph import V, A

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

class CreateArc():

	def __init__(self, base, arrow):
		self.arc = Arc(base, arrow)

	def __repr__(self):
		return self.arc
		

class Graph():

	def __init__(self, vertexes_list, arcs_list):
		self.vertexes_list = vertexes_list
		self.arcs_list = arcs_list
		self.graph = []
		self._createGraph()

	def _createGraph(self):
		for (base, arrow) in self.arcs_list:
			self.graph.append(CreateArc(base, arrow).__repr__())

	def __str__(self):
		print("\n\tList of vertexes: {}".format(self.vertexes_list))
		w = []
		for arc in self.graph:
			w.append(arc.__str__())
		print("\tList of arcs: {}".format(w))
		print('')


if __name__ == '__main__':
	Grapho = Graph(V, A)
	Grapho.__str__()