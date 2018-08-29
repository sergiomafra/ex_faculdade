from .Vertex import Vertex

class Arc:

    def __init__(self, base, arrow):
        self.base = Vertex(base)
        self.arrow = Vertex(arrow)

    def __str__(self):
        return '{} -> {}'.format(self.base.__str__(), self.arrow.__str__())
